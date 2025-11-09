#include <xc.h>
#include <stdint.h>

#pragma config FOSC = HSHP      // HS, high-power crystal (20 MHz)
#pragma config PLLCFG = OFF     // No 4x PLL (20 MHz stays 20 MHz)
#pragma config PRICLKEN = ON
#pragma config WDTEN = OFF
#pragma config MCLRE = EXTMCLR  // Keep MCLR enabled (recommended)
#pragma config LVP = OFF    // IMPORTANT: frees RB5 as normal pin

#define _XTAL_FREQ 20000000UL //20MHz crystal

#define LCD_RS   LATBbits.LATB0
#define LCD_E    LATBbits.LATB1
#define LCD_D4   LATBbits.LATB4
#define LCD_D5   LATBbits.LATB5
#define LCD_D6   LATBbits.LATB6
#define LCD_D7   LATBbits.LATB7


static void ports_initialize_lcd(void) {
    ANSELB=0x00; TRISB=0X00; LATB=0x00;
}

