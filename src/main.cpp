
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "LedStick.hpp"


int main(void)
{
    LedStick dongle0("/dev/ttyUSB1");

    for (uint8_t i=0; i<22; i++)
    {
        for (uint8_t c=0; c<255; c++)
        {
            dongle0.setLED(i, c);
            usleep(1000);
        }

        for (uint8_t c=255; c>0; c--)
        {
            dongle0.setLED(i, c);
            usleep(1000);
        }
        dongle0.setLED(i, 0);
        sleep(1);
    }
}
