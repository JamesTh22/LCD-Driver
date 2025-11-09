#ifndef LCD_OPCODES_H
#define LCD_OPCODES_H

#define LCD_OPCODE_CLEAR             0x01
#define LCD_OPCODE_HOME              0x02
#define LCD_OPCODE_ENTRY_MODE        0x04
#define LCD_OPCODE_DISPLAY_CTRL      0x08
#define LCD_OPCODE_SHIFT             0x10
#define LCD_OPCODE_FUNCTION_SET      0x20
#define LCD_OPCODE_SET_CGRAM         0x40
#define LCD_OPCODE_SET_DDRAM         0x80


#define LCD_OPCODE_ENTRY_INC         0x02
#define LCD_OPCODE_ENTRY_DEC         0x00
#define LCD_OPCODE_ENTRY_SHIFT_ON    0x01
#define LCD_OPCODE_ENTRY_SHIFT_OFF   0x00


#define LCD_OPCODE_DISPLAY_ON        0x04
#define LCD_OPCODE_DISPLAY_OFF       0x00
#define LCD_OPCODE_CURSOR_ON         0x02
#define LCD_OPCODE_CURSOR_OFF        0x00
#define LCD_OPCODE_BLINK_ON          0x01
#define LCD_OPCODE_BLINK_OFF         0x00


#define LCD_OPCODE_8BIT              0x10
#define LCD_OPCODE_4BIT              0x00
#define LCD_OPCODE_2LINE             0x08
#define LCD_OPCODE_1LINE             0x00
#define LCD_OPCODE_FONT_5x10         0x04
#define LCD_OPCODE_FONT_5x8          0x00

#endif

