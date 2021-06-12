#include <Macros.h>
#include "LCD.h"
#include "systick.h"
#include <stdlib.h>
#include <stdio.h>



void delay_ms(unsigned long long n)
{
    volatile unsigned long long i = 0;
    while(i++ < (1600 * n) );


}





void LCD_sendCommand(uint8 command)
{
    CLEAR_BIT(GPIO_PORTA_DATA_REG, RW);
    CLEAR_BIT(GPIO_PORTA_DATA_REG,RS);
    systick_wait_ms(2);
    SET_BIT(GPIO_PORTA_DATA_REG,E);
    systick_wait_ms(2);
    GPIO_PORTB_DATA_REG = command;
    systick_wait_ms(2);
    CLEAR_BIT(GPIO_PORTA_DATA_REG,E);
    systick_wait_ms(2);

}





static void LCD_Dataport_init (void){

    GPIO_PORTB_DIR_REG = 0XFFFFFFFF;
    GPIO_PORTB_AFSEL_REG = 0;
    GPIO_PORTB_AMSEL_REG = 0;
    GPIO_PORTB_DEN_REG = 0XFFFFFFFF;
    GPIO_PORTB_PCTL_REG = 0;

}


static void LCD_ControlPort_init (void){

    GPIO_PORTA_DIR_REG |= (0X1C);
    GPIO_PORTA_AFSEL_REG &= ~(0X1C);  // 0001 1100
    GPIO_PORTA_AMSEL_REG &= ~(0X1C);
    GPIO_PORTA_DEN_REG |= (0X1C); // 0001 1100
    GPIO_PORTA_PCTL_REG &= ~(0XFFF00); // 000fff00

}

void LCD_init (void)
{

    LCD_Dataport_init();
    LCD_ControlPort_init();




    LCD_sendCommand(twoLines8BitMode);

    LCD_sendCommand(cursorOff);

    LCD_sendCommand(clearScreen);
}





void LCD_displayCharacter (uint8 Char)
{
    CLEAR_BIT(GPIO_PORTA_DATA_REG, RW);
    SET_BIT(GPIO_PORTA_DATA_REG,RS);
    systick_wait_ms(2);
    SET_BIT(GPIO_PORTA_DATA_REG,E);
    systick_wait_ms(2);
    GPIO_PORTB_DATA_REG = Char;
    systick_wait_ms(2);
    CLEAR_BIT(GPIO_PORTA_DATA_REG,E);
    systick_wait_ms(2);

}

void LCD_displayString (sint8* str){
    uint8 i=0;
    while(str[i] != '\0')
    {
        LCD_displayCharacter(str[i]);
        i++;
    }
}


void LCD_goToRowColumn(uint8 row,uint8 col){
    uint8 address;
    switch (row){
    case 0:
        address = col;
        break;
    case 1:
        address = col + 0X40;
        break;
    case 2:
        address = col + 0X10;
        break;
    case 3:
        address = col + 0X50;
        break;
    }

    LCD_sendCommand(address | SetCursorLocation);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,sint8* str){

    LCD_goToRowColumn(row, col);
    LCD_displayString(str);

}

void LCD_clearScreen (void){
    LCD_sendCommand(clearScreen);
}


void LCD_intgerToStringDisplay (int data){

    sint8 str [15];
    ltoa(data,str,10);
    LCD_displayString(str);

}

