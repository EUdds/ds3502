#ifndef __i2cwrapper_h__
#define __i2cwrapper_h__
#include "mbed.h"

int writeI2CWrapper(I2C *i2cBus, int addr, uint8_t reg, char data[], int numBytes);
int readI2CWrapper(I2C *i2cBus, int addr, uint8_t reg, char buffer[], int numBytes);
void i2cdetect(I2C *i2cBus);


#endif // __i2cwrapper_h__