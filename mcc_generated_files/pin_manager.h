/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.1
        Device            :  PIC18F46K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set AN_BOARD_TEMP aliases
#define AN_BOARD_TEMP_TRIS               TRISAbits.TRISA0
#define AN_BOARD_TEMP_LAT                LATAbits.LATA0
#define AN_BOARD_TEMP_PORT               PORTAbits.RA0
#define AN_BOARD_TEMP_ANS                ANSELAbits.ANSA0
#define AN_BOARD_TEMP_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define AN_BOARD_TEMP_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define AN_BOARD_TEMP_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define AN_BOARD_TEMP_GetValue()           PORTAbits.RA0
#define AN_BOARD_TEMP_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define AN_BOARD_TEMP_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define AN_BOARD_TEMP_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define AN_BOARD_TEMP_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set AN_CURRENT aliases
#define AN_CURRENT_TRIS               TRISAbits.TRISA1
#define AN_CURRENT_LAT                LATAbits.LATA1
#define AN_CURRENT_PORT               PORTAbits.RA1
#define AN_CURRENT_ANS                ANSELAbits.ANSA1
#define AN_CURRENT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define AN_CURRENT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define AN_CURRENT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define AN_CURRENT_GetValue()           PORTAbits.RA1
#define AN_CURRENT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define AN_CURRENT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define AN_CURRENT_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define AN_CURRENT_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set AN_HUMIDITY aliases
#define AN_HUMIDITY_TRIS               TRISAbits.TRISA2
#define AN_HUMIDITY_LAT                LATAbits.LATA2
#define AN_HUMIDITY_PORT               PORTAbits.RA2
#define AN_HUMIDITY_ANS                ANSELAbits.ANSA2
#define AN_HUMIDITY_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define AN_HUMIDITY_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define AN_HUMIDITY_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define AN_HUMIDITY_GetValue()           PORTAbits.RA2
#define AN_HUMIDITY_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define AN_HUMIDITY_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define AN_HUMIDITY_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define AN_HUMIDITY_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_CS aliases
#define IO_CS_TRIS               TRISAbits.TRISA5
#define IO_CS_LAT                LATAbits.LATA5
#define IO_CS_PORT               PORTAbits.RA5
#define IO_CS_ANS                ANSELAbits.ANSA5
#define IO_CS_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_CS_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_CS_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_CS_GetValue()           PORTAbits.RA5
#define IO_CS_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_CS_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_CS_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define IO_CS_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_IMD_M_HS aliases
#define IO_IMD_M_HS_TRIS               TRISBbits.TRISB0
#define IO_IMD_M_HS_LAT                LATBbits.LATB0
#define IO_IMD_M_HS_PORT               PORTBbits.RB0
#define IO_IMD_M_HS_WPU                WPUBbits.WPUB0
#define IO_IMD_M_HS_ANS                ANSELBbits.ANSB0
#define IO_IMD_M_HS_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_IMD_M_HS_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_IMD_M_HS_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_IMD_M_HS_GetValue()           PORTBbits.RB0
#define IO_IMD_M_HS_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_IMD_M_HS_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_IMD_M_HS_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_IMD_M_HS_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_IMD_M_HS_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_IMD_M_HS_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_IMD_M_LS aliases
#define IO_IMD_M_LS_TRIS               TRISBbits.TRISB1
#define IO_IMD_M_LS_LAT                LATBbits.LATB1
#define IO_IMD_M_LS_PORT               PORTBbits.RB1
#define IO_IMD_M_LS_WPU                WPUBbits.WPUB1
#define IO_IMD_M_LS_ANS                ANSELBbits.ANSB1
#define IO_IMD_M_LS_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_IMD_M_LS_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_IMD_M_LS_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_IMD_M_LS_GetValue()           PORTBbits.RB1
#define IO_IMD_M_LS_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_IMD_M_LS_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_IMD_M_LS_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_IMD_M_LS_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_IMD_M_LS_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_IMD_M_LS_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_IMD_OK_HS aliases
#define IO_IMD_OK_HS_TRIS               TRISBbits.TRISB2
#define IO_IMD_OK_HS_LAT                LATBbits.LATB2
#define IO_IMD_OK_HS_PORT               PORTBbits.RB2
#define IO_IMD_OK_HS_WPU                WPUBbits.WPUB2
#define IO_IMD_OK_HS_ANS                ANSELBbits.ANSB2
#define IO_IMD_OK_HS_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_IMD_OK_HS_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_IMD_OK_HS_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_IMD_OK_HS_GetValue()           PORTBbits.RB2
#define IO_IMD_OK_HS_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_IMD_OK_HS_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_IMD_OK_HS_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_IMD_OK_HS_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_IMD_OK_HS_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_IMD_OK_HS_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IO_SHUTDOWN_CTRL aliases
#define IO_SHUTDOWN_CTRL_TRIS               TRISBbits.TRISB5
#define IO_SHUTDOWN_CTRL_LAT                LATBbits.LATB5
#define IO_SHUTDOWN_CTRL_PORT               PORTBbits.RB5
#define IO_SHUTDOWN_CTRL_WPU                WPUBbits.WPUB5
#define IO_SHUTDOWN_CTRL_ANS                ANSELBbits.ANSB5
#define IO_SHUTDOWN_CTRL_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_SHUTDOWN_CTRL_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_SHUTDOWN_CTRL_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_SHUTDOWN_CTRL_GetValue()           PORTBbits.RB5
#define IO_SHUTDOWN_CTRL_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_SHUTDOWN_CTRL_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_SHUTDOWN_CTRL_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_SHUTDOWN_CTRL_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_SHUTDOWN_CTRL_SetAnalogMode()  do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_SHUTDOWN_CTRL_SetDigitalMode() do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_PUMP_ENABLE aliases
#define IO_PUMP_ENABLE_TRIS               TRISCbits.TRISC1
#define IO_PUMP_ENABLE_LAT                LATCbits.LATC1
#define IO_PUMP_ENABLE_PORT               PORTCbits.RC1
#define IO_PUMP_ENABLE_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_PUMP_ENABLE_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_PUMP_ENABLE_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_PUMP_ENABLE_GetValue()           PORTCbits.RC1
#define IO_PUMP_ENABLE_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_PUMP_ENABLE_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set IO_FAN_CTRL_PWM aliases
#define IO_FAN_CTRL_PWM_TRIS               TRISCbits.TRISC2
#define IO_FAN_CTRL_PWM_LAT                LATCbits.LATC2
#define IO_FAN_CTRL_PWM_PORT               PORTCbits.RC2
#define IO_FAN_CTRL_PWM_ANS                ANSELCbits.ANSC2
#define IO_FAN_CTRL_PWM_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_FAN_CTRL_PWM_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_FAN_CTRL_PWM_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_FAN_CTRL_PWM_GetValue()           PORTCbits.RC2
#define IO_FAN_CTRL_PWM_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_FAN_CTRL_PWM_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_FAN_CTRL_PWM_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_FAN_CTRL_PWM_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()    do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()   do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()  do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetAnalogMode() do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()    do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()   do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()   do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()         PORTCbits.RC5
#define RC5_SetDigitalInput()   do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()  do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetAnalogMode() do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode() do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set IO_BMS_ERROR aliases
#define IO_BMS_ERROR_TRIS               TRISDbits.TRISD2
#define IO_BMS_ERROR_LAT                LATDbits.LATD2
#define IO_BMS_ERROR_PORT               PORTDbits.RD2
#define IO_BMS_ERROR_ANS                ANSELDbits.ANSD2
#define IO_BMS_ERROR_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_BMS_ERROR_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_BMS_ERROR_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_BMS_ERROR_GetValue()           PORTDbits.RD2
#define IO_BMS_ERROR_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_BMS_ERROR_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_BMS_ERROR_SetAnalogMode()  do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_BMS_ERROR_SetDigitalMode() do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_STATUS_1 aliases
#define IO_STATUS_1_TRIS               TRISDbits.TRISD4
#define IO_STATUS_1_LAT                LATDbits.LATD4
#define IO_STATUS_1_PORT               PORTDbits.RD4
#define IO_STATUS_1_ANS                ANSELDbits.ANSD4
#define IO_STATUS_1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_STATUS_1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_STATUS_1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_STATUS_1_GetValue()           PORTDbits.RD4
#define IO_STATUS_1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_STATUS_1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_STATUS_1_SetAnalogMode()  do { ANSELDbits.ANSD4 = 1; } while(0)
#define IO_STATUS_1_SetDigitalMode() do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IO_STATUS_2 aliases
#define IO_STATUS_2_TRIS               TRISDbits.TRISD5
#define IO_STATUS_2_LAT                LATDbits.LATD5
#define IO_STATUS_2_PORT               PORTDbits.RD5
#define IO_STATUS_2_ANS                ANSELDbits.ANSD5
#define IO_STATUS_2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_STATUS_2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_STATUS_2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_STATUS_2_GetValue()           PORTDbits.RD5
#define IO_STATUS_2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_STATUS_2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_STATUS_2_SetAnalogMode()  do { ANSELDbits.ANSD5 = 1; } while(0)
#define IO_STATUS_2_SetDigitalMode() do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set IO_STATUS_3 aliases
#define IO_STATUS_3_TRIS               TRISDbits.TRISD6
#define IO_STATUS_3_LAT                LATDbits.LATD6
#define IO_STATUS_3_PORT               PORTDbits.RD6
#define IO_STATUS_3_ANS                ANSELDbits.ANSD6
#define IO_STATUS_3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_STATUS_3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_STATUS_3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_STATUS_3_GetValue()           PORTDbits.RD6
#define IO_STATUS_3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_STATUS_3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_STATUS_3_SetAnalogMode()  do { ANSELDbits.ANSD6 = 1; } while(0)
#define IO_STATUS_3_SetDigitalMode() do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set IO_STATUS_4 aliases
#define IO_STATUS_4_TRIS               TRISDbits.TRISD7
#define IO_STATUS_4_LAT                LATDbits.LATD7
#define IO_STATUS_4_PORT               PORTDbits.RD7
#define IO_STATUS_4_ANS                ANSELDbits.ANSD7
#define IO_STATUS_4_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_STATUS_4_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_STATUS_4_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_STATUS_4_GetValue()           PORTDbits.RD7
#define IO_STATUS_4_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_STATUS_4_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_STATUS_4_SetAnalogMode()  do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_STATUS_4_SetDigitalMode() do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set IO_TSAL_ENABLE aliases
#define IO_TSAL_ENABLE_TRIS               TRISEbits.TRISE0
#define IO_TSAL_ENABLE_LAT                LATEbits.LATE0
#define IO_TSAL_ENABLE_PORT               PORTEbits.RE0
#define IO_TSAL_ENABLE_ANS                ANSELEbits.ANSE0
#define IO_TSAL_ENABLE_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define IO_TSAL_ENABLE_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define IO_TSAL_ENABLE_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define IO_TSAL_ENABLE_GetValue()           PORTEbits.RE0
#define IO_TSAL_ENABLE_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define IO_TSAL_ENABLE_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define IO_TSAL_ENABLE_SetAnalogMode()  do { ANSELEbits.ANSE0 = 1; } while(0)
#define IO_TSAL_ENABLE_SetDigitalMode() do { ANSELEbits.ANSE0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/