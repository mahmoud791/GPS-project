#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS

/*****************************************************************************
GPIO registers base addresses
 *****************************************************************************/
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/*****************************************************************************
GPIO registers offset addresses
 *****************************************************************************/
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

/*****************************************************************************
GPIO registers (PORTA)
 *****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile unsigned long *)0x4000452C))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile unsigned long *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile unsigned long *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile unsigned long *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile unsigned long *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile unsigned long *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile unsigned long *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
 *****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile unsigned long *)0x4000552C))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile unsigned long *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile unsigned long *)0x4000541C))

/*****************************************************************************
GPIO registers (PORTC)
 *****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile unsigned long *)0x4000652C))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile unsigned long *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile unsigned long *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile unsigned long *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile unsigned long *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile unsigned long *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile unsigned long *)0x4000641C))

/*****************************************************************************
GPIO registers (PORTD)
 *****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile unsigned long *)0x4000752C))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile unsigned long *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile unsigned long *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile unsigned long *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile unsigned long *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile unsigned long *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile unsigned long *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
 *****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile unsigned long *)0x4002452C))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile unsigned long *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
 *****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile unsigned long *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile unsigned long *)0x4002541C))

#define SYSCTL_REGCGC2_REG        (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_PRGPIO_REG         (*((volatile unsigned long *)0x400FEA08))
#define SYSCTL_RCGCUART_REG       (*((volatile unsigned long *)0x400FE618))                    //UART CLOCK
#define SYSCTL_PRUART_REG         (*((volatile unsigned long *)0x400FEA18))

/*****************************************************************************
Systick Timer Registers
 *****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile unsigned long *)0xE000E018))

/*****************************************************************************
PLL Registers
 *****************************************************************************/
#define SYSCTL_RIS_REG            (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_RCC_REG            (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC2_REG           (*((volatile unsigned long *)0x400FE070))



/*****************************************************************************
 UART registers (UART0)
 *****************************************************************************/

#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))
#define UART0_RSR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_ECR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_ILPR_R            (*((volatile unsigned long *)0x4000C020))
#define UART0_IBRD_R            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_R            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH_R            (*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))
#define UART0_IFLS_R            (*((volatile unsigned long *)0x4000C034))
#define UART0_IM_R              (*((volatile unsigned long *)0x4000C038))
#define UART0_RIS_R             (*((volatile unsigned long *)0x4000C03C))
#define UART0_MIS_R             (*((volatile unsigned long *)0x4000C040))
#define UART0_ICR_R             (*((volatile unsigned long *)0x4000C044))
#define UART0_DMACTL_R          (*((volatile unsigned long *)0x4000C048))
#define UART0_9BITADDR_R        (*((volatile unsigned long *)0x4000C0A4))
#define UART0_9BITAMASK_R       (*((volatile unsigned long *)0x4000C0A8))
#define UART0_PP_R              (*((volatile unsigned long *)0x4000CFC0))
#define UART0_CC_R              (*((volatile unsigned long *)0x4000CFC8))


/*****************************************************************************
 UART registers (UART1)
 *****************************************************************************/

#define UART1_DR_R              (*((volatile unsigned long *)0x4000D000))
#define UART1_RSR_R             (*((volatile unsigned long *)0x4000D004))
#define UART1_ECR_R             (*((volatile unsigned long *)0x4000D004))
#define UART1_FR_R              (*((volatile unsigned long *)0x4000D018))
#define UART1_ILPR_R            (*((volatile unsigned long *)0x4000D020))
#define UART1_IBRD_R            (*((volatile unsigned long *)0x4000D024))
#define UART1_FBRD_R            (*((volatile unsigned long *)0x4000D028))
#define UART1_LCRH_R            (*((volatile unsigned long *)0x4000D02C))
#define UART1_CTL_R             (*((volatile unsigned long *)0x4000D030))
#define UART1_IFLS_R            (*((volatile unsigned long *)0x4000D034))
#define UART1_IM_R              (*((volatile unsigned long *)0x4000D038))
#define UART1_RIS_R             (*((volatile unsigned long *)0x4000D03C))
#define UART1_MIS_R             (*((volatile unsigned long *)0x4000D040))
#define UART1_ICR_R             (*((volatile unsigned long *)0x4000D044))
#define UART1_DMACTL_R          (*((volatile unsigned long *)0x4000D048))
#define UART1_9BITADDR_R        (*((volatile unsigned long *)0x4000D0A4))
#define UART1_9BITAMASK_R       (*((volatile unsigned long *)0x4000D0A8))
#define UART1_PP_R              (*((volatile unsigned long *)0x4000DFC0))
#define UART1_CC_R              (*((volatile unsigned long *)0x4000DFC8))


/*****************************************************************************
 UART registers (UART2)
 *****************************************************************************/

#define UART2_DR_R              (*((volatile unsigned long *)0x4000E000))
#define UART2_RSR_R             (*((volatile unsigned long *)0x4000E004))
#define UART2_ECR_R             (*((volatile unsigned long *)0x4000E004))
#define UART2_FR_R              (*((volatile unsigned long *)0x4000E018))
#define UART2_ILPR_R            (*((volatile unsigned long *)0x4000E020))
#define UART2_IBRD_R            (*((volatile unsigned long *)0x4000E024))
#define UART2_FBRD_R            (*((volatile unsigned long *)0x4000E028))
#define UART2_LCRH_R            (*((volatile unsigned long *)0x4000E02C))
#define UART2_CTL_R             (*((volatile unsigned long *)0x4000E030))
#define UART2_IFLS_R            (*((volatile unsigned long *)0x4000E034))
#define UART2_IM_R              (*((volatile unsigned long *)0x4000E038))
#define UART2_RIS_R             (*((volatile unsigned long *)0x4000E03C))
#define UART2_MIS_R             (*((volatile unsigned long *)0x4000E040))
#define UART2_ICR_R             (*((volatile unsigned long *)0x4000E044))
#define UART2_DMACTL_R          (*((volatile unsigned long *)0x4000E048))
#define UART2_9BITADDR_R        (*((volatile unsigned long *)0x4000E0A4))
#define UART2_9BITAMASK_R       (*((volatile unsigned long *)0x4000E0A8))
#define UART2_PP_R              (*((volatile unsigned long *)0x4000EFC0))
#define UART2_CC_R              (*((volatile unsigned long *)0x4000EFC8))


#endif