
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "LedStick.hpp"


int main(void)
{
    LedStick dongle0("/dev/ttyUSB1");

    dongle0.setLED(0, 0xffffff);
}
