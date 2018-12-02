
#include "SerialPort.hpp"
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>


void SerialPort::open()
{
    /* O_RDWR Read/Write access to serial port           */
    /* O_NOCTTY - No terminal will control the process   */
    /* O_NDELAY -Non Blocking Mode,Does not care about-  */
    /* -the status of DCD line,Open() returns immediatly */
    fd = ::open(path, O_RDWR | O_NOCTTY | O_NDELAY);

    if(fd == -1)
    {
        printf("Failed to open serial port\n");
        return;
    }


    struct termios settings;

    /* Get the current attributes of the Serial port */
    tcgetattr(fd, &settings);

    cfsetispeed(&settings, B115200);
    cfsetospeed(&settings, B115200);

    // 8 data bits
    settings.c_cflag &= ~CSIZE;
    settings.c_cflag |=  CS8;
    // No parity
    settings.c_cflag &= ~PARENB;
    // 1 stop bit
    settings.c_cflag &= ~CSTOPB;
    // No hardware flow control
    settings.c_cflag &= ~CRTSCTS;
    // Enable receiver, ignore modem control lines
    settings.c_cflag |= CREAD | CLOCAL;
    // Disable XON/XOFF flow control both i/p and o/p
    settings.c_iflag &= ~(IXON | IXOFF | IXANY);
    // Non canonical mode
//    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    // NO output processing
//    settings.c_oflag &= ~OPOST;

    if ((tcsetattr(fd, TCSANOW, &settings)) != 0)
        printf("ERROR while setting attributes\n");
    else
        printf("Attributes set successfully.\n");
}


void SerialPort::close()
{
    ::close(fd);
}


void SerialPort::write(char* buf, uint8_t buflen)
{
    for (uint8_t i=0; i<buflen; i++)
    {
        ::write(fd, buf+i, 1);
        tcflush(fd, TCIOFLUSH);
        usleep(50);
    }
}


void SerialPort::setFlag(int flag, bool state)
{
    usleep(30);
    if (state == true)
        ioctl(fd, TIOCMBIS, &flag);
    else
        ioctl(fd, TIOCMBIC, &flag);
}


void SerialPort::setRTS(bool state)
{
    setFlag(TIOCM_RTS, state);
}


void SerialPort::setDTR(bool state)
{
    setFlag(TIOCM_DTR, state);
}

