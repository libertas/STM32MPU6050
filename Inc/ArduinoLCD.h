
#ifndef ARDUINOLCD_H_
#define ARDUINOLCD_H_

/*
 * A driver module for LCD1602 driven by Arduino
 * The source code is here:
 * https://github.com/libertas/MyArduinoWork/tree/master/I2CLCD
 */

#include "stm32f1xx_hal.h"

#define I2CLCD_ADDRESS (0x12 << 1)

void arduinolcd_write(char data[], uint8_t length);

#endif /* ARDUINOLCD_H_ */
