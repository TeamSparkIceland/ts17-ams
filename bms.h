/* 
 * File:   bms.h
 * Author: Olafur Gislason
 *
 * Created on June 14, 2017, 9:55 AM
 */

#ifndef BMS_H
#define	BMS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <stdbool.h>
    #include <stdint.h>

    #define TOTAL_SENSORS 12
    #define TEMP_COUNT 5
    #define VOLTAGE_COUNT 5

    typedef struct Cells {
        float voltage;
        float temperature;
        bool voltage_pec_failure;
        bool temperature_pec_failure;
        uint8_t voltage_error_count;
        uint8_t temperature_error_count;
        bool discharge_enabled;
    } Cell;
    
    typedef struct dischargeState {
        uint8_t state;
    } DischargeState;
    
    void BMS_Initialize();

    void BMS_set_reporting(bool debug_state, bool data_state);
    
    bool BMS_check();
    
    void BMS_gather();

    bool BMS_is_error();

    uint16_t BMS_get_error_code();
    
    void BMS_set_thresholds(float cell_low, float cell_high, float sensor_low, float sensor_high);
    
    void BMS_test_stuff();
    
    bool BMS_is_discharge_enabled();
    float BMS_get_target_voltage();
    void BMS_set_discharge(bool state);
    void BMS_handle_discharge();
    void BMS_clear_discharge();

#ifdef	__cplusplus
}
#endif

#endif	/* BMS_H */

