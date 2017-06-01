
#ifndef AT24C32_H_
#define AT24C32_H_

#include <stdint.h>

#include "stm32f1xx_hal.h"

#define	AT24C32SlaveAddress	0xAE
#define AT24C32SIZE 4096

void at24c32_init(I2C_HandleTypeDef *device);
uint8_t at24c32_read(uint16_t addr, uint8_t *data, uint16_t length);
uint8_t at24c32_write(uint16_t addr, uint8_t *data, uint16_t length);


#endif
