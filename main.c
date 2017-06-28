#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "bms.h"
#include "imd.h"
#include "board.h"

#define VERSION "1.1"

void bootup_checks();
void prod_loop();
void test_loop_2();
void test_loop();

uint8_t counter=1;
bool reverse = false;

void main(void) {
    SYSTEM_Initialize();
    
    printf("\r\nAMS v. %s\r\n", VERSION);
    
    BMS_Initialize();
    BMS_set_reporting(false, true);
    BMS_set_thresholds(3.2, 4.18, 5.0, 55.0);
    
    IMD_Initialize();
    
    Board_Initialize();
    
    //bootup_checks();
    
    IO_SHUTDOWN_CTRL_SetHigh();

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
        Board_set_status(0xF);
        IO_SHUTDOWN_CTRL_SetLow();
    } else {
        IO_SHUTDOWN_CTRL_SetHigh();
        Board_set_status(0x1);
    }
    
    if (IO_TSAL_ENABLE_GetValue() == 1) {
        IO_FAN_CTRL_PWM_SetHigh();
        IO_PUMP_ENABLE_SetHigh();
    } else {
        IO_FAN_CTRL_PWM_SetLow();
        IO_PUMP_ENABLE_SetLow();
    }
}

void test_loop_2() {
    printf("%u\r\n", counter++);
}

void test_loop() {
    BMS_check();
    //printf(".");
    return;
}