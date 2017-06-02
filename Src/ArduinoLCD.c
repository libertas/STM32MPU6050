/*
 * A driver module for LCD1602 driven by Arduino
 * The source code is here:
 * https://github.com/libertas/MyArduinoWork/tree/master/I2CLCD
 */


#include <ArduinoLCD.h>

I2C_HandleTypeDef *arduinolcd_i2c_device;

char lcd_empty_msg[32];

void arduinolcd_init(I2C_HandleTypeDef *device)
{
	arduinolcd_i2c_device = device;

	for(int i = 0; i < 32; i++) {
		lcd_empty_msg[i] = ' ';
	}
}

void arduinolcd_write(char data[], uint8_t length)
{
	if(length <= 32) {
		HAL_I2C_Master_Transmit_DMA(arduinolcd_i2c_device, I2CLCD_ADDRESS, data, length);
		osDelay(1);
		HAL_I2C_Master_Transmit_DMA(arduinolcd_i2c_device, I2CLCD_ADDRESS, lcd_empty_msg, 32 - length);
		osDelay(1);
	}
}
