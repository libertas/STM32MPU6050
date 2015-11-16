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
