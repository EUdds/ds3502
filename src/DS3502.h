#ifndef __DS3502_H__
#define __DS3502_H__

#include "mbed.h"

#define DS3502_DEFAULT_ADDR (0x28)
#define DS3502_WIPER_REG (0x00)
#define DS3502_MODE_REG (0x02)

class DS3502 {
    private:
        I2C* i2c;
        uint8_t addr;
        uint8_t wiper_value;
    public:
        DS3502(I2C* i2c, uint8_t addr);
        void set_wiper(uint8_t wipe_value);
        uint8_t get_wiper(void);
};


#endif // __DS3502_H__