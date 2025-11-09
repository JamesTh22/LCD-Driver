#ifndef LCD_OPCODES_H
#define LCD_OPCODES_H

#include <stdint.h>

//Opcodes
#define LCD_CMD_CLEAR           0x01
#define LCD_CMD_HOME            0x02
#define LCD_CMD_ENTRY_MODE      0x04
#define LCD_CMD_DISPLAY_CTRL    0x08
#define LCD_CMD_SHIFT           0x10
#define LCD_CMD_FUNCTION_SET    0x20
#define LCD_CMD_SET_CGRAM       0x40
#define LCD_CMD_SET_DDRAM       0x80
#define LCD_ENTRY_INC           0x02
#define LCD_ENTRY_DEC           0x00
#define LCD_ENTRY_SHIFT_ON      0x01
#define LCD_ENTRY_SHIFT_OFF     0x00
#define LCD_DISPLAY_ON          0x04
#define LCD_DISPLAY_OFF         0x00
#define LCD_CURSOR_ON           0x02
#define LCD_CURSOR_OFF          0x00
#define LCD_BLINK_ON            0x01
#define LCD_BLINK_OFF           0x00
#define LCD_8BIT                0x10
#define LCD_4BIT                0x00
#define LCD_2LINE               0x08
#define LCD_1LINE               0x00
#define LCD_FONT_5x10           0x04
#define LCD_FONT_5x8            0x00

// API 
void ports_initialize_lcd(void);
void send_lcd_4bit(unsigned char);
void lcd_command(unsigned char);
void lcd_write_to(unsigned char);
void lcd_initialize_power_up(void);


#endif
