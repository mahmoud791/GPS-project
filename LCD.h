#ifndef LCD_H_
#define LCD_H_

#include <Macros.h>
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "tm4c123gh6pm_registers.h"





#define LCD_ControlDirection GPIO_PORTA_DIR_REG
#define LCD_ControlData GPIO_PORTA_DATA_REG
#define RS  2
#define RW 3
#define E 4

#define LCD_dataPort GPIO_PORTB_DATA_REG
#define LCD_dataPortDir GPIO_PORTB_DIR_REG


#define clearScreen  0X01
#define cursorOff 0X0C
#define cursorOn 0X0E
#define twoLines8BitMode 0X38
#define SetCursorLocation 0X80
#define shiftCursorPositionRight 0x14
#define wakeUp 0X30
#define incrment 0x06
#define startDisplay 0x0F


void delay_ms(unsigned long long n);

void LCD_init(void);

static void LCD_ControlPort_init (void);

static void LCD_Dataport_init (void);

void LCD_sendCommand (uint8);

void LCD_displayCharacter (uint8);

void LCD_displayString (sint8*);

void LCD_goToRowColumn(uint8,uint8);

void LCD_displayStringRowColumn(uint8,uint8,sint8*);

void LCD_clearScreen (void);

void LCD_intgerToStringDisplay (int);




#endif
