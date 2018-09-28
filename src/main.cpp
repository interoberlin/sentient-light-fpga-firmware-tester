
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "SerialPort.hpp"


int main(void)
{
    SerialPort uart("/dev/ttyUSB1");
    uart.open();

    uart.setRTS(true);
    uart.write("\1\0\2\xff\xff\xff", 6);
    uart.setRTS(false);

    uart.close();
}
