#include "mbed.h"
#include "i2cwrapper.h"
/* Reads bytes from the specified register at the specified address
 * It does this by first writing the register offset to the address of the device, then
 * reading the number of bytes from that address. 
 * 
 * return 0 if no errors, 1 if there were errors. 
 */
int readI2CWrapper(I2C *i2cBus, int addr, uint8_t reg, char buffer[], int numBytes) {
    char writeBuffer[1] = {reg};
    // check if the I2C write and read throw errors. 
    if (i2cBus->write(addr, writeBuffer, 1) != 0) {
        return 1; 
    }
    if (i2cBus->read(addr, buffer, numBytes) != 0) {
        return 1; 
    }
    return 0; // no errors
}

/* Writes bytes to the specified register at the specified address
 * Does this by prepending the register offset to the buffer, then writing that 
 * to the address of the device. 
 * 
 * returns 0 if no errors, 1 if there were errors
 */
int writeI2CWrapper(I2C *i2cBus, int addr, uint8_t reg, char data[], int numBytes) {
    // create a new buffer which is just the input buffer with the register offset prepended.
    char newBuffer[numBytes + 1];
    newBuffer[0] = reg;
    // for (int i = 1; i <= numBytes; i++) {
    //     newBuffer[i] = buffer[i-1];
    // }
    memcpy(newBuffer+1, data, numBytes);
    // check if the I2C write throws an error 
    if(i2cBus->write(addr, newBuffer, numBytes + 1)) {
        return 1;
    }
    return 0; // no errors 
}