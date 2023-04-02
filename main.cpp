/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "DS3502.h"
#include "i2cwrapper.h"

#define F767ZI

#ifdef F767ZI
#define PIN_SCL (PF_1)
#define PIN_SDA (PF_0)
#elif F303K8
#define PIN_SDA (PB_7)
#define PIN_SCL (PB_6)
#endif // F767ZI



// static float curr_duty_cycle = 0.0f;
// // InterruptIn main_telem(D5); // fixme
// AnalogOut accel(A5);




int main()
{
    // Clear the screen
    printf("\033[2J\033[;H");
    I2C i2c(PIN_SDA, PIN_SCL);
    i2c.frequency(100000);
    i2cdetect(&i2c);
    DS3502 pot(&i2c, DS3502_DEFAULT_ADDR);

    pot.set_wiper(33);
    printf("Wiper is %d\n\r", pot.get_wiper());
    // // main_telem.rise(&alertme);
    // // main_telem.fall(&alertme);   
    // printf("Pull the lever, Kronk!\t");
    // // accel.period(0.02f);
    // accel.write(.01); // Change this [0, 1] 0f or 1f
    // printf("[PASS]\n\r");
    // // while(1);
    // while(1) {
    //     // Clear the screen
    //     printf("\033[2J\033[;H");
    //     printf("Main Telem is %d", main_telem.read());
    //     wait_us(1000000);
    //     // // Accept user input to set the new duty cycle
    //     // printf("Enter a new duty cycle [0, 1]: ");
    //     // scanf("%f", &curr_duty_cycle);
    //     // accel.write(curr_duty_cycle);
    //     // printf("Duty cycle set to %f\n\r", curr_duty_cycle);
    // }

}
