# FPGA firmware tester

This program opens a serial port to an iCEstick (Lattice iCE40 FPGA + FTDI FT2232H) and
send a command according to the syntax specified in the Sentient Light documentation.
The expected result is flickering of the red LEDs on the iCEstick
indicating data reception on the FPGA.

## How to build and run

~~~
make run
~~~
