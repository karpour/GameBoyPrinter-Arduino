#include "Arduino.h"
#include "GBPrinter.h"

#define GB_In	9
#define GB_Out	13
#define GB_Clk	8

GBPrinter gbprinter(GB_In, GB_Out, GB_Clk);

void setup() {
	Serial.begin(57600);
	//Serial.println("Gameboy Printer Test\n----------------------");
	/*
	 for(int i=0;i<640;i++){
	 gb_buffer[i] = img[i];
	 }*/
	/*for (int i = 0; i < 40; i++) {
	 for(int j=0;j<16;j++){
	 uint8_t c = gb_buffer[i*16+j];
	 if(c<16){
	 Serial.print("0");
	 }
	 Serial.print(c,HEX);
	 Serial.print(" ");
	 }
	 Serial.println();
	 }
	 */
	//gbprinter.flushBuffer();
	//gbprinter.printTest();
}

void loop() {
	char cmd, cmd2 = 0;
	while (true) {
		if (Serial.available()) {
			cmd = cmd2;
			cmd2 = Serial.read();

			if (cmd2 == '\n') { // previous character must've been a command
				switch (cmd) {
				case 'B': // Band transmission
					Serial.write('1'); // Send ack
					for (int i = 0; i < 640; i++) {
						while (Serial.available() == 0){}
						gb_buffer[i] = Serial.read();
					}
					gbprinter.flushBuffer();
					break;
				case 'F': // Flush buffer
					Serial.write('1'); // Send ack
					gbprinter.flushBuffer();
					break;
				case 'N': // Newline
					Serial.write('1'); // Send ack
					gbprinter.printCharacter('\n');
					break;
				case 'Z': // Print page end, followed by one ascii numeral indicating how many blank lines to print
					Serial.write('1'); // Send ack
					while (Serial.available() == 0){}
					gbprinter.printBlank(Serial.read());
					break;
				case 'E': // Set Exposure
					Serial.write('1'); // Send ack
					while (Serial.available() == 0){}
					gbprinter.setExposure(Serial.read());
					break;
				case 'T': // Transfer a line of text
					Serial.write('1'); // Send ack
					for (;;) {
						while (Serial.available() == 0){}
						char tc = Serial.read();
						if (tc == '\n')
							break;
						gbprinter.printCharacter(tc);
					}
					break;
				case 'R': // Send buffer contents to PC
					Serial.write('1'); // Send ack
					for (int i = 0; i < 640; i++) {
						Serial.write(gb_buffer[i]);
					}
					break;
				default:
					break;
				}
			}
		}
	}
}
