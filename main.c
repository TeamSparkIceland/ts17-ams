#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "bms.h"
#include "imd.h"
#include "board.h"

#define VERSION "2.1"

#define PERIOD 0x0001
#define ZERO 0x0000

#define DISCHARGE_CYCLE 60
#define REST_CYCLE 30

void bootup_checks();
void prod_loop();
void test_loop_2();
void test_loop();

uint8_t counter=1;
bool reverse = false;
uint8_t timer_counter;
uint8_t inbound_data;

bool enable_discharge = false;

bool discharge_rest_period = false;

void main(void) {
    SYSTEM_Initialize();
    
    printf("\r\nAMS v. %s\r\n", VERSION);
 
    BMS_Initialize();
    BMS_set_reporting(false, true);
    BMS_set_thresholds(3.2, 4.18, 5.0, 55.0);
    BMS_set_discharge(true);
    
    IMD_Initialize();
    
    Board_Initialize();
    
    //bootup_checks();
    
    IO_SHUTDOWN_CTRL_SetHigh();

    TMR0_StartTimer();
    
    timer_counter = DISCHARGE_CYCLE;
    
    while (1) {
        prod_loop();
    }
}

/**
 * Runs all the required boot-up checks for the system, providing a report
 * via the USART.
 */
void bootup_checks() {
    printf("\r\n");
    Board_run_diagnostics();    
    printf("\r\n");
}

void prod_loop() {
    BMS_gather();
    if (BMS_check() == true) {
        printf("E|BMS Shutdown triggered|\r\n");
        //Board_set_status(0xF);
        IO_SHUTDOWN_CTRL_SetLow();
    } else {
        IO_SHUTDOWN_CTRL_SetHigh();
        //Board_set_status(0x1);
    }
    
    if (IO_TSAL_ENABLE_GetValue() == 1) {
        IO_FAN_CTRL_PWM_SetHigh();
        IO_PUMP_ENABLE_SetHigh();
    } else {
        IO_FAN_CTRL_PWM_SetLow();
        IO_PUMP_ENABLE_SetLow();
    }
    
    if ((enable_discharge) && (!BMS_is_discharge_enabled())) {
        BMS_set_discharge(true);
        printf("S|%d|", (uint16_t)(BMS_get_target_voltage() * 1000));
    } else if ((!enable_discharge) && (BMS_is_discharge_enabled())) {
        BMS_set_discharge(false);
    }
    
    if (TMR0IF) {
        timer_counter--;
        if (timer_counter == 0) {
            discharge_rest_period = !discharge_rest_period;
            if (discharge_rest_period) {
                timer_counter = REST_CYCLE;
            } else {
                timer_counter = DISCHARGE_CYCLE;
            }
        }
        
        TMR0IF = 0;
        
        // Command detection
        if (EUSART1_DataReady) {
            inbound_data = EUSART1_Read();
            switch (inbound_data) {
                case 'D':
                    enable_discharge = false;
                    break;
                case 'E':
                    enable_discharge = true;
                    break;
            }
        }
    }
    
    if (discharge_rest_period == false) {
        BMS_handle_discharge();
    } else {
        BMS_clear_discharge();
    }
}