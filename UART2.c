#include <tm4c123gh6pm_registers.h>
#include <typedef.h>
#include <UART2.h>



void UART2_Init (void)
{
    UART2_CTL_R &= ~(1<<0); // DISABLE UART
    PORTD_UART_Init(); //INIT PORTA
    UART2_IBRD_R = 104; // BAUD RATE = 9600 -> 16MHZ/16*9600 = 104.166666 SO IBRD = 104
    UART2_FBRD_R = 11;  // FBRD = (0.16666*64)+0.5 = 11
    UART2_LCRH_R = 0X0070; // 8 BIT TRANSFER DATA + 1 STOP BIT
    UART2_CTL_R = 0X0301;  // ENABLE UART, TX & RX
    UART2_CC_R = 0; // USE CLOCK OF SYSTEM
}


void PORTD_UART_Init (void)
{
    GPIO_PORTD_AFSEL_REG |=0XC0; // ENABLE AF  0X  1100  0000
    GPIO_PORTD_PCTL_REG |= 0X11000000; // ENABLE UART
    GPIO_PORTD_DEN_REG |= 0XC0; // ENABLE DIGITAL TRANSMISSION
    GPIO_PORTD_AMSEL_REG &= ~(0XC0); // DISABLE ANALOG
}



void UART2_SendData (sint8 letter)
{
    while (UART2_FR_R & (1<<5)); // MAKE SURE FIFO IS NOT FULL
    UART2_DR_R = letter; //SEND CHAR
}


uint8 UART2_ReceiveData (void)
{
    while (UART2_FR_R & (1<<4)); // MAKE SURE FIFO IS EMPTY
    return UART2_DR_R;  //RECEIVE CHAR
}


void UART2_SendStr (sint8 *str)
{

    uint8 i=0;
    while (str[i] != '\0')
    {
        UART2_SendData(str[i]);
        i++;
    }
}


void UART2_ReceiveStr_len (uint8 len, sint8 *str)
{

    uint8 i;
    for (i = 0 ; i< len ; i++){
        str[i] = UART2_ReceiveData();
    }

    str[len] = '\0';

}

void UART2_ReceiveStr_SpecialChar (uint8 spec, sint8 *str)
{
    uint8 i=0;
    uint8 checker = UART2_ReceiveData();

    while (checker != spec){
        str[i] = checker;
        checker = UART2_ReceiveData();
        i++;
    }

    str[i] = '\0';

}
