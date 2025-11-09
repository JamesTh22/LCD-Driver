#ifdef __XC8
#include <xc.h>
#include "lcd_opcodes.h"
#include "lcd_pinmap.h"

#pragma config FOSC = HSHP      // HS, high-power crystal (20 MHz)
#pragma config PLLCFG = OFF     // No 4x PLL (20 MHz stays 20 MHz)
#pragma config PRICLKEN = ON
#pragma config WDTEN = OFF
#pragma config MCLRE = EXTMCLR  // Keep MCLR enabled (recommended)
#pragma config LVP = OFF    // IMPORTANT: frees RB5 as normal pin

#define _XTAL_FREQ 20000000UL //20MHz crystal
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
    if (data == LCD_OPCODE_CLEAR || data == LCD_OPCODE_HOME) {__delay_ms(2);}
}
static inline void lcd_write_to(unsigned char data) {
    LCD_RS = 1;
    send_lcd_4bit(data >> 4);
    send_lcd_4bit(data);
}
static inline void lcd_clear(void) {lcd_command(LCD_CMD_CLEAR)}

static inline void lcd_initialize_power_up(void) {
    port_initialize_lcd(); __delay_ms(50);
    LCD_RS = 0; LCD_E = 0;
    send_lcd_4bit(0x03); __delay_ms(5);
    send_lcd_4bit(0x03); __delay_us(150);
    send_lcd_4bit(0x03); __delay_us(150);
    send_lcd_4bit(0x02); __delay_us(150);
    lcd_command(LCD_OPCODE_FUNCTION_SET | LCD_OPCODE_4BIT | LCD_OPCODE_2LINE | LCD_OPCODE_FONT_5x8);
    lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_OFF);
    lcd_clear();
    lcd_command(LCD_OPCODE_ENTRY_MODE | LCD_OPCODE_ENTRY_INC | LCD_OPCODE_ENTRY_SHIFT_OFF);
    lcd_command(LCD_OPCODE_DISPLAY_CTRL | LCD_OPCODE_DISPLAY_ON | LCD_OPCODE_CURSOR_OFF | LCD_OPCODE_BLINK_OFF);
}