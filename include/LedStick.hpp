
#ifndef LED_STICK_HPP
#define LED_STICK_HPP

#include "SerialPort.hpp"


class LedStick
{
private:
    SerialPort* port;

public:
    LedStick(char* port)
    {
        this->port = new SerialPort(port);
        this->port->open();
    }

    ~LedStick()
    {
        port->close();
    }

    bool isConnected()
    {
        return port->isOpen();
    }

    void setLED(uint16_t index, uint32_t value)
    {
        char s[6];
        s[0] = 1;
        s[1] = index >> 8;
        s[2] = index & 0xff;
        s[3] = (value & 0xff0000) >> 16;
        s[4] = (value & 0xff00) >> 8;
        s[5] = value & 0xff;

        port->setRTS(true);
        port->write(s, 6);
        port->setRTS(false);
    }

};


#endif
