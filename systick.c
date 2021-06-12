#include "tm4c123gh6pm_registers.h"
#include "typedef.h"
#include "systick.h"

//initialize systick peripheral

void systick_init (void)
{
    SYSTICK_CTRL_REG = 0;
    SYSTICK_RELOAD_REG = 0X00FFFFFF;
    SYSTICK_CURRENT_REG = 0;
    SYSTICK_CTRL_REG = 0X05;
}

//delay using systick

static void systick_wait (uint32 delay){
    SYSTICK_RELOAD_REG = delay-1;
    SYSTICK_CURRENT_REG =0;
    while ((SYSTICK_CTRL_REG & 0X00010000) == 0);
}


void systick_wait_ms(uint32 delay){

    uint32 i;

    for(i=0;i<delay;i++)
    {
        systick_wait(16000);
    }

}


void systick_wait_sec(uint32 delay){

    uint32 i;
    for(i=0;i<delay;i++){
        systick_wait_ms(1000);
    }

}
