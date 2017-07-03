#include <stdbool.h>
#include <stdio.h>
#include <pic18.h>
#include "mcc_generated_files/mcc.h"
#include "bms.h"
#include "linear/LTC68041.h"
#include "tmap.h"

bool BMS_report;
bool BMS_data_report;
float BMS_low_voltage = 3.2;
float BMS_high_voltage = 4.18;
float BMS_low_temperature = 5.0; // Degrees C
float BMS_high_temperature = 58.0; // Degrees C
float lowest_voltage;
float BMS_discharge_voltage;
bool BMS_discharge_enabled = false;

static DischargeState discharge_state;

uint8_t discharge_part = 0;
uint8_t discharge_completed = 0;

static uint8_t configs[TOTAL_IC][6];
static uint16_t aux_codes[TOTAL_IC][6];

static Cell cell_data[TOTAL_IC][12];

// VUV (3.2V) = 1999d = 0x7CF
// VOV (4.2V) = 2625d = 0xA41
//uint8_t BMS_default_config[6] = {0xF8, 0x7C, 0xAF, 0x41, 0x00, 0x00};  
uint8_t BMS_default_config[6] = {0x0E, 0x00, 0x00, 0x00, 0x00, 0x00};  

void reset_configs() {
    //uint16_t vuv = (((BMS_low_voltage * 10000)/16)-1)
    //uint16_t vov = 0;
    for (uint8_t i = 0; i<TOTAL_IC; i++) {
        for (uint8_t j = 0; j<6; j++) {
            configs[i][j] = BMS_default_config[j];
        }   
    }
}

/**
 * Initializes the AMS isoSPI module and the BMSs.
 */
void BMS_Initialize() {
    printf("Initializing BMS\r\n") && BMS_report;
    LTC6804_initialize();
    BMS_report = false;
    BMS_data_report = false;
    
    reset_configs();
}

/**
 * Set failure thresholds for measurements of cell voltages and temperatures.
 * @param cell_low is the minimum allowed voltage as mA.
 * @param cell_high is the maximum allowed voltage as mA.
 * @param sensor_low is the minimum temperature as °C.
 * @param sensor_high is the maximum temperature as °C.
 */
void BMS_set_thresholds(float cell_low, float cell_high, float sensor_low, float sensor_high) {
    BMS_low_voltage = cell_low;
    BMS_high_voltage = cell_high;
    BMS_low_temperature = sensor_low;
    BMS_high_temperature = sensor_high;
    reset_configs();
}

/**
 * Controls the reporting of the BMS system to USART.
 * @param state defines if reporting should be on or off.
 */
void BMS_set_reporting(bool debug_state, bool data_state) {
    BMS_report = debug_state;
    BMS_data_report = data_state;
}

/**
 * Checks the voltages of all cells on all BMSs. This is a time-consuming
 * operation as the system has to talk to all the BMSs multiple times to get
 * all the measurements.
 * @return the code of the last detected failure. 0 = success.
 */
uint8_t check_cell_voltages() {
    static uint16_t cell_codes[TOTAL_IC][12];
    uint8_t result;
    uint16_t cell_code;
    bool pec_error = false;
    lowest_voltage = BMS_high_voltage;
    
    BMS_report && printf("Voltages\r\n");  
    wakeup_idle();
    LTC6804_adcv();
    __delay_us(10);
    
    // Read each cell voltage register
    result = LTC6804_rdcv(CELL_CH_ALL, cell_codes);
    
    if (result != 0) {
        pec_error = true;
    }
    
    for (uint8_t k = 0; k<TOTAL_IC; k++) {
        for (uint8_t l = 0; l<12; l++) {
            cell_code = cell_codes[k][l];
            cell_data[k][l].voltage = (float)(cell_code/10000.0);
            if (cell_data[k][l].voltage < lowest_voltage) {
                lowest_voltage = cell_data[k][l].voltage;
            }
            cell_data[k][l].voltage_pec_failure = pec_error;
            BMS_report && printf("\r\n");
        }
        BMS_report && printf("\r\n");
    }
    
    return result;
}

/**
 * Modify the BMS configuration variable with the right MUX address to read
 * from.
 * @param sensor_id is the sensor (0-11) to read from next.
 */
void set_mux_address(uint8_t sensor_id) {
  uint8_t mux_address = sensor_id;
  uint8_t mod;
  for (uint8_t current_ic = 0; current_ic < TOTAL_IC; current_ic++) {
    mod = (uint8_t)((configs[current_ic][0] & 0x0F) | (mux_address << 4));
    configs[current_ic][0] = mod;
  }
}

/**
 * Checks the temperatures of all cells on all BMSs. This is a VERY
 * time-consuming operation as the system has to talk to all the BMSs multiple
 * times to get all the measurements.
 * @return true if all measurements were within range, else false.
 */
bool check_cell_temperatures() {
    bool result = true;
    bool pec_error = false;
    int8_t error;
    uint16_t temp_code;
    float temp_code_div;
    float convVal;
    static uint8_t rx_cfg[TOTAL_IC][8];

    // To avoid a false first reading, do a dummy adc conversion
    LTC6804_adax();
    __delay_ms(3);
    
    BMS_report && printf("Temperatures: \r\n");

    for (uint8_t sensor_id = 0; sensor_id < TOTAL_SENSORS; sensor_id++)
    {
        // ----- BROKEN CODE -----
        set_mux_address(sensor_id);

        LTC6804_wrcfg(configs);
        __delay_ms(3);
        // -----------------------
        /*
        error = LTC6804_rdcfg(rx_cfg);
        if (error == -1)
        {
            BMS_report && printf("PEC error while reading config\r\n");
            break;
        }
        __delay_ms(3);
        */
        //BMS_report && printf("DEBUG: SENSOR %d: RDCFG: 0x%x\r\n", sensor_id, rx_cfg[0][0]);

        // ADAX
        LTC6804_clraux();
        __delay_ms(3);

        // ADAX
        
        LTC6804_adax();
        __delay_ms(3);

        error = LTC6804_rdaux(1, aux_codes); // Set to read back aux register 1
        if (error == -1)
        {
            printf("RDAUX error\r\n");
            result = false;
            pec_error = true;
            //break;
        }
        for (uint8_t current_ic = 0; current_ic < TOTAL_IC; current_ic++)
        {
            temp_code = (uint16_t)((aux_codes[current_ic][1]<<8) + aux_codes[current_ic][0]);
            temp_code_div = (float)(temp_code/10000.0);
            convVal = LookupTemperature(temp_code_div);
            BMS_report && printf("B%d C%d %u %fC\r\n", current_ic, sensor_id, temp_code, convVal);
            cell_data[current_ic][sensor_id].temperature = convVal;
            cell_data[current_ic][sensor_id].temperature_pec_failure = pec_error;
        }
    }
    
    return false;
}

void send_data_packet() {
    if (!BMS_data_report) {
        return;
    }
    for (uint8_t ic = 0; ic != TOTAL_IC; ic++) {
        printf("D%d|", ic);
        for (uint8_t cell = 0; cell != TOTAL_SENSORS; cell++) {
            printf("%d|", cell);
            
            if (cell_data[ic][cell].voltage_pec_failure == true) {
                printf("PEC|");
            } else {
                printf("%d|", (uint16_t)(cell_data[ic][cell].voltage * 1000));
            }
            
            if (cell_data[ic][cell].temperature_pec_failure == true) {
                printf("PEC|");
            } else {
                printf("%d|", (uint16_t)(cell_data[ic][cell].temperature));
            }
            
            if (cell_data[ic][cell].discharge_enabled == true) {
                printf("1|");
            } else {
                printf("0|");
            }
        }
        printf("\r\n");
    }
}

bool BMS_check() {
    Cell cell;
    for (uint8_t i = 0; i<TOTAL_IC; i++) {
        for (uint8_t j = 0; j<TOTAL_SENSORS; j++) {
            
            cell = cell_data[i][j];
            
            if (cell.voltage >= BMS_high_voltage) {
                cell_data[i][j].voltage_error_count++;
            } else if (cell.voltage <= BMS_low_voltage) {
                cell_data[i][j].voltage_error_count++;
            } else if (cell.voltage_pec_failure == true) {
                cell_data[i][j].voltage_error_count++;
            } else {
                cell_data[i][j].voltage_error_count = 0;
            }
            
            if (cell.voltage_error_count == VOLTAGE_COUNT) {
                cell_data[i][j].voltage_error_count--;
                return true;
            }
            
            if (cell.temperature >= BMS_high_temperature) {
                cell_data[i][j].temperature_error_count++;
            } else if (cell.temperature <= BMS_low_temperature) {
                cell_data[i][j].temperature_error_count++;
            } else if (cell.temperature_pec_failure == true) {
                cell_data[i][j].temperature_error_count++;
            } else {
                cell_data[i][j].temperature_error_count = 0;
            }
            
            if (cell.temperature_error_count == TEMP_COUNT) {
                cell_data[i][j].temperature_error_count--;
                return true;
            }
    
        }
    }
    return false;
}

/**
 * Run all measurements 
 * for the BMSs, voltages and temperatures. This also 
 * prepares the BMS configurations as the chips will forget their configurations
 * when they go to sleep.
 */
void BMS_gather() {
    //static uint8_t rx_cfg[TOTAL_IC][8];
   
    wakeup_sleep();
    
    /*for (uint8_t j = 0; j != 12; j++) {
        set_mux_address(j);
        LTC6804_wrcfg(configs);
        __delay_ms(1);

        LTC6804_rdcfg(rx_cfg);
        __delay_ms(1);

        printf("BMS 0: %d: 0x%x\r\n", j, rx_cfg[0][0]);
        printf("BMS 1: %d: 0x%x\r\n", j, rx_cfg[1][0]);
        
    }*/
    
    check_cell_voltages();
    check_cell_temperatures();
    send_data_packet();
}

float BMS_get_target_voltage() {
    return BMS_discharge_voltage;
}

/**
 * @return true if there was an error during last BMS_check call.
 */
bool BMS_is_error() { return false; }

/**
 * Gets the error code from the last failure.
 * @return the error code (currently undefined behaviour).
 */
uint16_t BMS_get_error_code() { return 0; }

bool discharge(uint8_t part) {
    uint16_t discharge_bits = 0; // Needs to have bits >= TOTAL_SENSORS
    bool completed = true;
    
    for (uint8_t bms_id = 0; bms_id != TOTAL_IC; bms_id++) {
    
        discharge_bits = 0; // Reset between bms modules
    
        for (uint8_t cell_id = part; cell_id < TOTAL_SENSORS; cell_id = cell_id + 3) {
            
            if (cell_data[bms_id][cell_id].discharge_enabled == false) { continue; }
            
            if ((cell_id != part) && (cell_id != part+3) && (cell_id != part+6) && cell_id != part+9) {
                cell_data[bms_id][cell_id].discharge_enabled = false;
                continue;
            }
        
            if (cell_data[bms_id][cell_id].voltage <= BMS_discharge_voltage) {
                cell_data[bms_id][cell_id].discharge_enabled = false;
            } else {
                completed = false;
                cell_data[bms_id][cell_id].discharge_enabled = true;
                discharge_bits |= 1u << cell_id;
            }
            
        }
        
        // For CFGR4 we have DCC8 DCC7 DCC6 DCC5 DCC4  DCC3  DCC2  DCC1
        // For CFGR5 we have x    x    x    x    DCC12 DCC11 DCC10 DCC9
        
        // Discharge_bits = xxxx1111 11111111 (12 to 1) or (11 to 0))
        
        /*
         *   00000010 01001001 (stage 0)
         *   00000100 10010010 (stage 1)
         *   00001001 00100100 (stage 2)
         * 
         * Stage 1
         *   00000000 11111111 (0x00FF)
         * & 00000010 01001001 (stage 1)
         * -------------------
         *   00000000 01001001 (stage 1 saved)
         * 
         *   00000000 11111111 (0x00FF)
         * & 00000100 10010010 (stage 2)
         * -------------------
         *   00000000 10010010
         * | 00000000 01001001 (stage 1 saved)
         * -------------------
         *   00000000 11011011
         * 
         * 
         * 
         * Better to take the top half of the config
         * 
         *   xxxxxxxx 00000000
         * | 00000000 ssssssss
         * 
         */
        
        // Simulate for now
        configs[bms_id][4] = 0x00FF & discharge_bits;
        configs[bms_id][5] = (0x0F00 & discharge_bits) >> 8u;
    }
    return completed;
}



/**
 * Temporary test function to verify communications between the AMS board and
 * the BMSs.
 */
void BMS_test_stuff() {
    static uint16_t cell_codes[TOTAL_IC][12];
    uint8_t result;
    static uint8_t configs[1][6];
    uint8_t default_config[6] = {0xFE, 0x7C, 0xAF, 0x41, 0x00, 0x00}; 
    for (uint8_t i = 0; i<1; i++) {
        for (uint8_t j = 0; j<6; j++) {
            configs[i][j] = default_config[j];
        }
    }
    wakeup_sleep();
    LTC6804_wrcfg(configs);
    __delay_ms(5);
    LTC6804_adcv();
    __delay_ms(5);
    result = LTC6804_rdcv(CELL_CH_ALL, cell_codes);
    printf("rdcv result: %d\r\n", result);
}

bool BMS_is_discharge_enabled() {
    return BMS_discharge_enabled;
}

void BMS_set_discharge(bool state) {
    if (state == true) {
        if (lowest_voltage > BMS_low_voltage) {
            BMS_discharge_voltage = lowest_voltage;
            BMS_discharge_enabled = true;
            discharge_part = 0;
            discharge_completed = 0;
            // Set enable discharge on all cells
            for (uint8_t i = 0; i<TOTAL_IC; i++) {
                for (uint8_t j = 0; j<TOTAL_SENSORS; j++) {
                    cell_data[i][j].discharge_enabled = true;
                }
            }
        }
    } else {
        BMS_discharge_enabled = false;
        reset_configs();
        for (uint8_t i = 0; i<TOTAL_IC; i++) {
                for (uint8_t j = 0; j<TOTAL_SENSORS; j++) {
                    cell_data[i][j].discharge_enabled = false;
                }
            }
    }
}

void BMS_clear_discharge() {
    reset_configs();
}

void BMS_handle_discharge() {
    if (BMS_discharge_enabled == false) {
        printf("BMS_discharge_enabled is false, lest not do anything.\r\n");
        return;
    }
    
    if (BMS_discharge_voltage < BMS_low_voltage) {
        printf("Discharge cancelled because threshold-voltage is below minimum voltage\r\n");
        BMS_set_discharge(false);
        return;
    }
    
    printf("Discharging...\r\n");
    printf("Target voltage %f V\r\n", BMS_discharge_voltage);
    if (discharge(discharge_part) == true) {
        discharge_completed |= 1u << discharge_part;
    }
    
    if (discharge_completed == 0x07) {
        BMS_set_discharge(false);
        return;
    }
    
    if (discharge_part == 2) {
        discharge_part = 0;
    } else {
        discharge_part++;
    }
}

/*
 * On Discharge Request (CDEA) or (cdea)
 * Go through all cells and pick the lowest voltage as threshold voltage
 * While doing so, switch discharge on for all cells
 * 
 * In BMS loop:
 * if cell voltage is below or equal to threshold voltage, set discharge to
 * false for that cell
 * When discharge is decided for each cell it's added to a bitmask that gets
 * applied to the bms after the cell-loop has finished
 * 
 */



/*
 * Part argument stands for which of 3 possible discharge configurations toad
 * use: 0: discharge 0, 3, 6, 9
 *      1: discharge 1, 4, 7, 10
 *      2: discharge 2, 5, 8, 11
 * 
 * This is done to avoid thermal hot-spots when discharging (making sure that
 * two discharge resistors are inactive between each active one)
 */

