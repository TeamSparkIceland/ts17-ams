#include "mcc_generated_files/mcc.h"
#include "board.h"
#include "mcc_generated_files/pin_manager.h"

/**
 * Initializes the AMS Board module. Status-led state is set to zero.
 */
void Board_Initialize() {
    Board_set_status(0x00);
}

/**
 * Runs diagnostics on the AMS Board, verifying that all sensors are within
 * acceptable ranges.
 * @return the amount of failed tests (0 = all tests succeeded)
 */
uint8_t Board_run_diagnostics() {
    uint8_t failed_tests = 0;
    uint16_t current = Board_read_current();
    uint16_t temperature = Board_read_temperature();
    uint16_t humidity = Board_read_humidity();
    
    /* Expect no current during startup.
     * If anything other than 0 A is read, the sensor might be faulty.
     */
    printf("Current Sensor Check: ");
    if (current == 0) {
        printf("PASSED");
    } else {
        printf("FAILED");
        failed_tests++;
    }
    printf("\r\n");
    
    /* Expect the temperature of the board to be within safe range on startup.
     * Anything else either indicates too hot or cold environment or faulty
     * sensor.
     */
    printf("Board Temperature Check: ");
    if ((temperature > MIN_BOARD_TEMP) & (temperature < MAX_BOARD_TEMP)) {
        printf("PASSED");
    } else {
        printf("FAILED");
        failed_tests++;
    }
    printf("\r\n");
    
    /* Expect the humidity of the board to be within safe range on startup.
     * Anything else either indicates too humid environment or faulty sensor.
     */
    printf("Board Humidity Check: ");
    if ((humidity > MIN_BOARD_HUMIDITY) & (humidity < MAX_BOARD_HUMIDITY)) {
        printf("PASSED");
    } else {
        printf("FAILED");
        failed_tests++;
    }
    printf("\r\n");
    
    return failed_tests;
}

/**
 * Read the current of the High-Voltage system.
 * @return The current as Amperes (A) with resolution of 1A.
 */
uint16_t Board_read_current() {
    return ADC_GetConversion(AN_CURRENT);
}

/**
 * Read the board temperature.
 * @return The temperature as milli-volts (mV) with resolution of 1mA.
 */
uint16_t Board_read_temperature() {
    return ADC_GetConversion(AN_BOARD_TEMP);
}

/**
 * Read the humidity measured at the board.
 * @return The humidity as a percentage (%) with resolution of 1%.
 */
uint16_t Board_read_humidity() {
    return ADC_GetConversion(AN_HUMIDITY);
}

/**
 * Set the 4 status-LED states. These LEDs can be used to provide useful visual
 * indicators when the battery-box is being debugged.
 * @param status where the 4 right-most bits control the led states.
 */
void Board_set_status(uint8_t status) {
    IO_STATUS_1_LAT = (uint8_t)((status & 0x01)>>0);
    IO_STATUS_2_LAT = (uint8_t)((status & 0x02)>>1);
    IO_STATUS_3_LAT = (uint8_t)((status & 0x04)>>2);
    IO_STATUS_4_LAT = (uint8_t)((status & 0x08)>>3);
}