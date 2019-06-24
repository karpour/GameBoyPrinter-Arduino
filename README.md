# GameBoyPrinter-Arduino

A library that allows an Arduino to interface with a Nintendo GameBoy Printer.
Includes font support and a small example program that takes commands from a PC over the serial port.


```c++
GBPrinter gbprinter(GB_In, GB_Out, GB_Clk);
```