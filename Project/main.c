#include "stm32f10x.h"
#include "i2c.h"
#include "mpu6050.h"
#include "usart.h"
#include "clock.h"
#include "config.h"
#include "kinestate.h"
#include <complex.h>

int main(void)
{
	struct kine_state ks = {0};
	rcc_init();
	clock_init();
	gpio_init();
	usart1_init();
	usart2_init();
	i2c1_init();
	mpu6050_init();

	while(1)
	{
		ks = get_kine_state(&ks);
		printf("%lf, %lf, %lf\n", ks.ax, ks.ay, ks.az);
	}
	return 0;
}
