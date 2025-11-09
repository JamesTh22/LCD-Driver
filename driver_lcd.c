#ifdef __XC8
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

static inline void ports_initialize_lcd(void) {
    ANSELB=0x00; TRISB=0X00; LATB=0x00;
}
 // function to send a nibble inline is just a hint to the compiler :) "this function is tiny"  
 // clocks one 4-bit nibble onto D4–D7 and strobes E with safe timing
static inline void send_lcd_4bit(unsigned char data) {
    LCD_D4 = (data >> 0) & 0x01;
    LCD_D5 = (data >> 1) & 0x01;
    LCD_D6 = (data >> 2) & 0x01;
    LCD_D7 = (data >> 3) & 0x01;
    
    LCD_E = 1;
    __delay_us(1);      // E high >= 450 ns
    LCD_E = 0;
    __delay_us(40); 
}

static inline void lcd_command(unsigned char data) {
    LCD_RS = 0;
    send_lcd_4bit(data >> 4);
    send_lcd_4bit(data);
    if (data == 0x01 || data == 0x02) __delay_ms(2);
}
