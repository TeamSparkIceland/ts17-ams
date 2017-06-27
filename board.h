/* 
 * File:   board.h
 * Author: dreamware
 *
 * Created on 16. júní 2017, 22:19
 */

#ifndef BOARD_H
#define	BOARD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <stdint.h>

    #define MIN_CURRENT 0 // A
    #define MAX_CURRENT 100 // A
    #define MIN_BOARD_TEMP 10 // °C
    #define MAX_BOARD_TEMP 60 // °C
    #define MIN_BOARD_HUMIDITY 0 // %
    #define MAX_BOARD_HUMIDITY 60 // %

    void Board_Initialize();
    
    uint8_t Board_run_diagnostics();
    
    uint16_t Board_read_current();
    uint16_t Board_read_temperature();
    uint16_t Board_read_humidity();
    void Board_set_status(uint8_t status);

#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_H */

