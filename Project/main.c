#include "stm32f10x.h"
#include "i2c.h"
#include "mpu6050.h"
#include "usart.h"

int main(void)
{
	int8_t ax, ay, az;
	int8_t wx, wy, wz;
	
	usart1_init();
	i2c1_init();
	
	mpu6050_init();
	mpu6050_print_default();

	while(1)
	{
		ax = mpu6050_get_data(ACCEL_XOUT_H);
		ay = mpu6050_get_data(ACCEL_YOUT_H);
		az = mpu6050_get_data(ACCEL_ZOUT_H);
		wx = mpu6050_get_data(GYRO_XOUT_H);
		wy = mpu6050_get_data(GYRO_YOUT_H);
		wz = mpu6050_get_data(GYRO_ZOUT_H);
		printf("\nax = %d \n", ax);
		printf("\nay = %d \n", ay);
		printf("\naz = %d \n", az);
		printf("\nwx = %d \n", wx);
		printf("\nwy = %d \n", wy);
		printf("\nwz = %d \n", wz);
	}
	return 0;
}
