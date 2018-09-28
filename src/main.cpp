
#include <stdio.h>
#include "SerialPort.hpp"


int main(void)
{
    SerialPort uart("/dev/ttyUSB1");
    uart.open();

    uart.write("\0", 1);

    uart.close();
}
