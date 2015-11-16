#include <mpu6050.h>

void 	mpu6050_init(void)
{
	i2c1_write(SlaveAddress, PWR_MGMT_1, 0x00);
	i2c1_write(SlaveAddress, SMPLRT_DIV, 0x07);
	i2c1_write(SlaveAddress, CONFIG, 0x06);
	i2c1_write(SlaveAddress, GYRO_CONFIG, 0x18);
	i2c1_write(SlaveAddress, ACCEL_CONFIG, 0x01);
}

uint8_t mpu6050_read(uint8_t reg)
{
	return i2c1_read(SlaveAddress, reg);
}

signed int mpu6050_get_data(uint8_t reg)
{
	return ((uint16_t)mpu6050_read(reg) << 8) | mpu6050_read(reg + 1);
}

#define MPU_SUM 250
void mpu6050_print_default(void)
{
	uint16_t i;
	double axd, ayd, azd;
	double wxd, wyd, wzd;
	
	for(i = 0; i < MPU_SUM; i++)
	{
		axd = (double)mpu6050_get_data(ACCEL_XOUT_H) / MPU_SUM;
		ayd = (double)mpu6050_get_data(ACCEL_YOUT_H) / MPU_SUM;
		azd = (double)mpu6050_get_data(ACCEL_ZOUT_H) / MPU_SUM;
		wxd = (double)mpu6050_get_data(GYRO_XOUT_H) / MPU_SUM;
		wyd = (double)mpu6050_get_data(GYRO_YOUT_H) / MPU_SUM;
		wzd = (double)mpu6050_get_data(GYRO_ZOUT_H) / MPU_SUM;
	}
	
	printf("\naxd = %lf \n", axd);
	printf("\nayd = %lf \n", ayd);
	printf("\nazd = %lf \n", azd);
	printf("\nwxd = %lf \n", wxd);
	printf("\nwyd = %lf \n", wyd);
	printf("\nwzd = %lf \n", wzd);
}
