
#ifndef SERIAL_PORT_HPP
#define SERIAL_PORT_HPP

#include <stdint.h>
#include <stdbool.h>

using namespace std;


class SerialPort
{
private:
    int fd = -1;
    char* path;

public:
    SerialPort(char* arg) { path = arg; }

    void open();
    bool isOpen() { return (fd != -1); }
    void close();

    void write(char*, uint8_t);
    void setRTS(bool);
    void setRTS() { setRTS(true); }
    void clearRTS() { setRTS(false); }
};

#endif
