#ifndef systick_driver

#define systick_driver

void systick_init (void);

static void systick_wait(uint32 delay);

void systick_wait_ms(uint32 delay);

void systick_wait_sec(uint32 delay);


#endif

