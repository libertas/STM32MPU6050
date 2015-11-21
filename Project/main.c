#include "stm32f10x.h"
#include "i2c.h"
#include "mpu6050.h"
#include "usart.h"
#include "clock.h"
#include "config.h"

int main(void)
{
	uint8_t flag = 0;
	
	rcc_init();
	clock_init();
	gpio_init();
	usart1_init();
	i2c1_init();
	
	mpu6050_init();
	mpu6050_print_default();

	while(1)
	{
		printf("%ld\n", get_ms());
	}
	return 0;
}
