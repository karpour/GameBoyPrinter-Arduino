# GameBoyPrinter-Arduino

A library that allows an Arduino or Arduino-compatible to interface with a Nintendo GameBoy Printer.
Includes font support and a small example program that takes commands from a PC over the serial port.

Porting this library should be an easy task, as there are no other dependencies than digitalRead() and digitalWrite()

## Initializing

Connect the GBPrinter to 3 digital pins and create an instance. No further initialization is required.

```c++
GBPrinter gbprinter(GB_In, GB_Out, GB_Clk);
```

## Printing an image

The GameBox Printer expects 640 byte of image data at a time. This corresponds to 160x16 pixels of image data at 2bpp.

Reading data from the serial port, the flushing the buffer:

```c++
for (int i = 0; i < 640; i++) {
    while (Serial.available() == 0){}
    gb_buffer[i] = Serial.read();
}
gbprinter.flushBuffer();
```
Flushing the buffer in this library automatically prints the buffer contents. The GameBoy printer supports buffering multiple bands of image data, in case this is required it can be achieved by using lower-level methods.

## Printing characters
The library supports printing characters. These are written into the image buffer. Once the end of the buffer is reached, the buffer is flushed and emptied.
For immediately printing the text, call flushBuffer()

```c++
printCharacter('H');
printCharacter('a');
printCharacter('l');
printCharacter('l');
printCharacter('o');
printCharacter('!');
flushBuffer();
```