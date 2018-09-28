
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "SerialPort.hpp"


int main(void)
{
    SerialPort uart("/dev/ttyUSB1");
    uart.open();

    uart.write("\0", 1);

    for (uint8_t i=0; i<8; i++)
    {
        uart.setRTS(true);
        sleep(1);
        uart.setRTS(false);
        sleep(1);
    }

    uart.close();
}
