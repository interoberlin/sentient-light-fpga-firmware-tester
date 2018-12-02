
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
        // Command code: SET_LED (8 bit)
        s[0] = 1;
        // Index of the LED to change (16 bit)
        s[1] = index >> 8;
        s[2] = index & 0xff;
        // New LED value (24 bit)
        s[3] = (value & 0xff0000) >> 16;
        s[4] = (value & 0xff00) >> 8;
        s[5] = value & 0xff;

        port->setDTR(true);
        port->write(s, 6);
        port->setDTR(false);
    }

};


#endif
