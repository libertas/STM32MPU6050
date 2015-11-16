#include "stm32f10x.h"
#include "i2c.h"
#include "mpu6050.h"
#include "usart.h"

int main(void)
{
	usart1_init();
	i2c1_init();
	
	while(1)
	{
		printf("\nax = %d \n",mpu6050_get_data(ACCEL_XOUT_H));
		printf("\nay = %d \n",mpu6050_get_data(ACCEL_YOUT_H));	
		printf("\naz = %d \n",mpu6050_get_data(ACCEL_ZOUT_H));	
		printf("\nwx = %d \n",mpu6050_get_data(GYRO_XOUT_H));	
		printf("\nwy = %d \n",mpu6050_get_data(GYRO_YOUT_H));	
		printf("\nwz = %d \n",mpu6050_get_data(GYRO_ZOUT_H));
	}
	return 0;
}
