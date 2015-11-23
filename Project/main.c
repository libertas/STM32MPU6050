#include "stm32f10x.h"
#include "i2c.h"
#include "mpu6050.h"
#include "usart.h"
#include "clock.h"
#include "config.h"
#include <complex.h>

int main(void)
{
	double complex dc;
	rcc_init();
	clock_init();
	gpio_init();
	usart1_init();
	usart2_init();
	i2c1_init();

	mpu6050_init();
	mpu6050_print_default();

	while(1)
	{
		dc = 1 + 2 * I;
		dc *= dc;
		uprintf(USART2, "%lf + %lfj\n", creal(dc), cimag(dc));
	}
	return 0;
}
