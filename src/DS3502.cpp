#include "DS3502.h"

#include "mbed.h"
#include "i2cwrapper.h"
#include <cstdint>

DS3502::DS3502(I2C* i2c, uint8_t addr) {
    this->i2c = i2c;
    this->addr = addr << 1; // 7 bit to 8 bit addr
    char buf[] = {0x80};
    writeI2CWrapper(this->i2c, this->addr, DS3502_MODE_REG, buf, 1);
}

void DS3502::set_wiper(uint8_t wiper_value) {
    if (wiper_value > 127) wiper_value = 127;
    if (wiper_value < 0) wiper_value = 0;
    char buf[] = {wiper_value};
    writeI2CWrapper(this->i2c, this->addr, DS3502_WIPER_REG, buf, 1);

}

uint8_t DS3502::get_wiper() {
    char buf[] = {};
    readI2CWrapper(this->i2c, this->addr, DS3502_WIPER_REG, buf, 1);
    return (uint8_t)buf[0];
}