#ifndef LCD_PINMAP_H
#define LCD_PINMAP_H

#include <xc.h>

#define LCD_RS   LATBbits.LATB0
#define LCD_E    LATBbits.LATB1
#define LCD_D4   LATBbits.LATB4
#define LCD_D5   LATBbits.LATB5
#define LCD_D6   LATBbits.LATB6
#define LCD_D7   LATBbits.LATB7

static inline void ports_initialize_lcd(void) {
    ANSELB=0x00; TRISB=0X00; LATB=0x00;
}

#endif