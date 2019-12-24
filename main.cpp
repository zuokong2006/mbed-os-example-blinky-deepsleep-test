/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                5000


int main()
{
    printf("\r\n\r\nmbed-os-example-blinky start...\r\n");
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    led = 1;

    while (true) {
        printf("Deep sleep: thread_sleep_for\r\n");
        thread_sleep_for(BLINKING_RATE_MS);

        printf("sleep_manager_lock_deep_sleep\r\n");
        sleep_manager_lock_deep_sleep();
        printf("Sleep: thread_sleep_for\r\n");
        thread_sleep_for(BLINKING_RATE_MS);
        printf("sleep_manager_unlock_deep_sleep\r\n");
        sleep_manager_unlock_deep_sleep();
        
        printf("Active: Cy_SysLib_Delay\r\n");
        Cy_SysLib_Delay(BLINKING_RATE_MS);
    }
}

