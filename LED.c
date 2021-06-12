#include "LED.h"



void Led_port_init (void)
{


    GPIO_PORTF_AMSEL_REG &= 0xFFFFFFF1;         //turn off analog mixed signal for PF1,PF2,PF3
    GPIO_PORTF_PCTL_REG &= 0xFFFFFFF1;          
    GPIO_PORTF_DIR_REG |= 0x0E ;                //Set direction off PF1,PF2,PF3 as output
    GPIO_PORTF_AFSEL_REG &= 0xFFFFFFF1;         //turn off alternative function select for PF1,PF2,PF3
    GPIO_PORTF_DEN_REG |= 0x0E;                 //set PF1,PF2,PF3 as digtal  
    GPIO_PORTF_DATA_REG &= 0xFFFFFFF1;          // LEDS OFF
}


//Function to take a certain distance as attribute and flash LED



void led_flash_distance (uint8 total_distance){

    if(total_distance >= 100)
    {
        GPIO_PORTF_DATA_REG |= 0x02;
    }
    else
    {
        GPIO_PORTF_DATA_REG &= 0xFFFFFFFD;
    }

}
