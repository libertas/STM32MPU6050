#include "cmsis_os.h"

#include "at24c32.h"

I2C_HandleTypeDef *at24c32_i2c_device;

void at24c32_init(I2C_HandleTypeDef *device)
{
	at24c32_i2c_device = device;
}

uint8_t at24c32_read(uint16_t addr, uint8_t *data, uint16_t length)
{
	HAL_I2C_Mem_Read(at24c32_i2c_device, AT24C32SlaveAddress, addr, length, data, length, -1);
}

uint8_t at24c32_write(uint16_t addr, uint8_t *data, uint16_t length)
{
	HAL_I2C_Mem_Write(at24c32_i2c_device, AT24C32SlaveAddress, addr, length, data, length, -1);
	osDelay(10);
}
