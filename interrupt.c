#include"tm4c123gh6pm_registers.h"
#include"interrupt.h"
#include "hashs.h"
float32 total_distance = 0;

#define Enable_Interrupts() __asm("CPSIE I")
#define Disable_Interrupts() __asm("CPSID I")
void SystemInit(){}

void EdgeCounter_Init(void){

    GPIO_PORTF_DEN_REG|=0X10;
    GPIO_PORTF_PUR_REG|=0X10;
    GPIO_PORTF_DIR_REG &= ~0x10; // make PF4 in (built-in button)
    GPIO_PORTF_AFSEL_REG &=~0x10;
    GPIO_PORTF_PCTL_REG=0x00;
    GPIO_PORTF_IS_REG &= ~0x10; // PF4 is edge-sensitive
    GPIO_PORTF_IBE_REG &= ~0x10; // PF4 is not both edges
    //PortF Interrupt Initialization

    GPIO_PORTF_IEV_REG &= ~0x10; // PF4 falling edge event
    GPIO_PORTF_ICR_REG |= 0x10; // clear flag4
    GPIO_PORTF_IM_REG |= 0x10; // arm interrupt on PF4
    NVIC_PRI7_REG = (NVIC_PRI7_REG&0xFF00FFFF)|0x00A00000; // (g) priority 5
    NVIC_EN0_REG = 0x40000000; // (h) enable interrupt 30 in NVIC

}

//ISR function of GPIO PortF interrupt

void GPIOPortF_Handler(void)
{

    GPIO_PORTF_ICR_REG=0x10;
    total_distance = 0;
    LCD_displayStringRowColumn(0,0 ,"Distance = 000M" );


}
