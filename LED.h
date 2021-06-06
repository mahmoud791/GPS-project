#ifndef LED_DRIVER
#define LED_DRIVER
#include "typedef.h"
#include "tm4c123gh6pm_registers.h"



#define RED 0x02
#define BLUE 0x04
#define GREEN 0X08


void Led_port_init (void);

void led_flash_distance (uint8);





#endif
