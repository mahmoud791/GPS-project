#include "tm4c123gh6pm_registers.h"
#include "typedef.h"
#include "systick.h"

void systick_init (void)
{
    SYSTICK_CTRL_REG = 0;
    SYSTICK_RELOAD_REG = 0X00FFFFFF;
    SYSTICK_CURRENT_REG = 0;
    SYSTICK_CTRL_REG = 0X05;
}



static void systick_wait (uint32 delay){
    SYSTICK_RELOAD_REG = delay-1;
    SYSTICK_CURRENT_REG =0;
    while ((SYSTICK_CTRL_REG & 0X00010000)==0);
}

void systick_wait1ms(uint32 delay){
    uint32 i;

    for(i=0; i<delay ;i++){
        systick_wait(80000);
    }
}
