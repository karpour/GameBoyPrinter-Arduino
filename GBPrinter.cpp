#include "Arduino.h"
#include "GBPrinter.h"

const unsigned char font[] PROGMEM={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // <Space>
	0x18,0x3C,0x3C,0x18,0x18,0x00,0x18,0x00, // !
	0x66,0x66,0x24,0x00,0x00,0x00,0x00,0x00, // "
	0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00, // #
	0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00, // $
	0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00, // %
	0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00, // &
	0x18,0x18,0x30,0x00,0x00,0x00,0x00,0x00, // '
	0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00, // (
	0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00, // )
	0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00, // *
	0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00, // +
	0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30, // ,
	0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00, // -
	0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00, // .
	0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00, // /
	0x7C,0xC6,0xCE,0xD6,0xE6,0xC6,0x7C,0x00, // 0
	0x18,0x38,0x18,0x18,0x18,0x18,0x7E,0x00, // 1
	0x7C,0xC6,0x06,0x1C,0x30,0x66,0xFE,0x00, // 2
	0x7C,0xC6,0x06,0x3C,0x06,0xC6,0x7C,0x00, // 3
	0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00, // 4
	0xFE,0xC0,0xC0,0xFC,0x06,0xC6,0x7C,0x00, // 5
	0x38,0x60,0xC0,0xFC,0xC6,0xC6,0x7C,0x00, // 6
	0xFE,0xC6,0x0C,0x18,0x30,0x30,0x30,0x00, // 7
	0x7C,0xC6,0xC6,0x7C,0xC6,0xC6,0x7C,0x00, // 8
	0x7C,0xC6,0xC6,0x7E,0x06,0x0C,0x78,0x00, // 9
	0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00, // :
	0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30, // ;
	0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00, // <
	0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00, // =
	0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00, // >
	0x7C,0xC6,0x0C,0x18,0x18,0x00,0x18,0x00, // ?
	0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00, // @
	0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0xC6,0x00, // A
	0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00, // B
	0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00, // C
	0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00, // D
	0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00, // E
	0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00, // F
	0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3A,0x00, // G
	0xC6,0xC6,0xC6,0xFE,0xC6,0xC6,0xC6,0x00, // H
	0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00, // I
	0x1E,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,0x00, // J
	0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00, // K
	0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00, // L
	0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00, // M
	0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00, // N
	0x7C,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00, // O
	0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00, // P
	0x7C,0xC6,0xC6,0xC6,0xC6,0xCE,0x7C,0x0E, // Q
	0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00, // R
	0x7C,0xC6,0x60,0x38,0x0C,0xC6,0x7C,0x00, // S
	0x7E,0x7E,0x5A,0x18,0x18,0x18,0x3C,0x00, // T
	0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00, // U
	0xC6,0xC6,0xC6,0xC6,0xC6,0x6C,0x38,0x00, // V
	0xC6,0xC6,0xC6,0xD6,0xD6,0xFE,0x6C,0x00, // W
	0xC6,0xC6,0x6C,0x38,0x6C,0xC6,0xC6,0x00, // X
	0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00, // Y
	0xFE,0xC6,0x8C,0x18,0x32,0x66,0xFE,0x00, // Z
	0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00, // [
	0xC0,0x60,0x30,0x18,0x0C,0x06,0x02,0x00, // <Backslash>
	0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00, // ]
	0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00, // ^
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF, // _
	0x30,0x18,0x0C,0x00,0x00,0x00,0x00,0x00, // '
	0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00, // a
	0xE0,0x60,0x7C,0x66,0x66,0x66,0xDC,0x00, // b
	0x00,0x00,0x7C,0xC6,0xC0,0xC6,0x7C,0x00, // c
	0x1C,0x0C,0x7C,0xCC,0xCC,0xCC,0x76,0x00, // d
	0x00,0x00,0x7C,0xC6,0xFE,0xC0,0x7C,0x00, // e
	0x3C,0x66,0x60,0xF8,0x60,0x60,0xF0,0x00, // f
	0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8, // g
	0xE0,0x60,0x6C,0x76,0x66,0x66,0xE6,0x00, // h
	0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00, // i
	0x06,0x00,0x06,0x06,0x06,0x66,0x66,0x3C, // j
	0xE0,0x60,0x66,0x6C,0x78,0x6C,0xE6,0x00, // k
	0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00, // l
	0x00,0x00,0xEC,0xFE,0xD6,0xD6,0xD6,0x00, // m
	0x00,0x00,0xDC,0x66,0x66,0x66,0x66,0x00, // n
	0x00,0x00,0x7C,0xC6,0xC6,0xC6,0x7C,0x00, // o
	0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0, // p
	0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0x1E, // q
	0x00,0x00,0xDC,0x76,0x60,0x60,0xF0,0x00, // r
	0x00,0x00,0x7E,0xC0,0x7C,0x06,0xFC,0x00, // s
	0x30,0x30,0xFC,0x30,0x30,0x36,0x1C,0x00, // t
	0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00, // u
	0x00,0x00,0xC6,0xC6,0xC6,0x6C,0x38,0x00, // v
	0x00,0x00,0xC6,0xD6,0xD6,0xFE,0x6C,0x00, // w
	0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00, // x
	0x00,0x00,0xC6,0xC6,0xC6,0x7E,0x06,0xFC, // y
	0x00,0x00,0x7E,0x4C,0x18,0x32,0x7E,0x00, // z
	0x0E,0x18,0x18,0x70,0x18,0x18,0x0E,0x00, // {
	0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00, // |
	0x70,0x18,0x18,0x0E,0x18,0x18,0x70,0x00, // }
	0x76,0xDC,0x00,0x00,0x00,0x00,0x00,0x00, // ~
};


const unsigned char img[640] PROGMEM = { 0xC0, 0xE0, 0xC0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0xC0,
		0x80, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
		0x00, 0x0F, 0x00, 0x0F, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07,
		0x00, 0xFE, 0x07, 0xFA, 0x07, 0xFA, 0x07, 0xFA, 0x07, 0xFA, 0x07, 0xFA, 0x07, 0xFA,
		0x07, 0xFE, 0x07, 0x70, 0xF8, 0x30, 0xF8, 0x3C, 0xF8, 0x18, 0xFC, 0x18, 0xFC, 0x1E,
		0xFC, 0x0C, 0xFE, 0x0C, 0xFE, 0x1F, 0x00, 0x0F, 0x00, 0x0F, 0x00, 0x0F, 0x00, 0x07,
		0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFC, 0x00, 0xF8,
		0x00, 0xF0, 0x00, 0xF0, 0x00, 0xE0, 0x00, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x03, 0x01, 0x05, 0x03, 0x03, 0x07, 0x0F, 0x07, 0x07, 0x0F, 0x0E,
		0x1F, 0x77, 0xFF, 0xE7, 0xFF, 0xCF, 0xFF, 0xCF, 0xFF, 0x9F, 0xFF, 0x9F, 0xFF, 0x1E,
		0xFF, 0x3E, 0xFF, 0xC0, 0x80, 0xC0, 0x80, 0x01, 0x80, 0x0D, 0x83, 0x87, 0x1F, 0xCF,
		0x3F, 0x9F, 0x7F, 0x7C, 0xFF, 0x0C, 0x03, 0x4F, 0x3F, 0x7F, 0xFF, 0xFC, 0xFF, 0xE0,
		0xFF, 0x83, 0xFF, 0x0F, 0xFF, 0x3F, 0xFF, 0x01, 0xFE, 0xFC, 0xFF, 0xFF, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xF0, 0xFF, 0x80, 0xFF, 0xC8, 0x07, 0x3F, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x06, 0xFC, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0x00, 0xE0, 0x00, 0x98, 0xE0, 0xE4, 0xF8, 0xF9, 0xFE, 0xFF, 0xFF, 0x3F, 0xFF, 0x07,
		0xFF, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x01, 0x00, 0x03, 0x00, 0x02, 0x01, 0x02, 0x01, 0x20, 0x40, 0x80, 0x60, 0xC0,
		0x60, 0x50, 0xE0, 0x50, 0xE0, 0x50, 0xE0, 0x60, 0xF0, 0xE8, 0xF0, 0x07, 0x00, 0x03,
		0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0xFF,
		0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xF6, 0x0F, 0xF6,
		0x0F, 0x0F, 0xFE, 0x07, 0xFE, 0x06, 0xFF, 0x07, 0xFF, 0x03, 0xFF, 0x03, 0xFF, 0x03,
		0xFF, 0x01, 0xFF, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x83, 0x00, 0x81, 0x00, 0x01,
		0x80, 0x81, 0x80, 0xC1, 0x80, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFE, 0x00, 0xFC, 0x00, 0xFC,
		0x00, 0xF8, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x01, 0x05, 0x03, 0x3E, 0x1F, 0x18,
		0x3F, 0x30, 0x7F, 0xF0, 0x7F, 0x70, 0xFF, 0xE0, 0xFF, 0xC0, 0xFF, 0xC1, 0xFF, 0x3E,
		0xFF, 0x3D, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFC, 0xFF, 0xF8,
		0xFF, 0xF8, 0xFF, 0xF0, 0xFF, 0xC1, 0xFF, 0x80, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0xFF, 0x00, 0xFF, 0x7C, 0xFF, 0xF0, 0xFF, 0x80, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x0F,
		0xFF, 0xFF, 0xFF, 0x08, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x3F,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
		0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF };

uint8_t gb_buffer[640];

/**
 * Constructor, sets pin modes and pull-up resistors
 * 	in_pin ... connected to SOUT of the GameBoy Printer
 * 	out_pin .. connected to SIN of the GameBoy Printer
 * 	clk_pin .. connected to SCLK of the GameBoy Printer
 */
GBPrinter::GBPrinter(int in_pin, int out_pin, int clk_pin) {
	crc = 0;
	in = in_pin;
	out = out_pin;
	clk = clk_pin;
	charpointer = 0;
	exposure = GB_EXPOSURE_DEFAULT;
	pinMode(out, OUTPUT);
	pinMode(clk, OUTPUT);
	pinMode(in, INPUT);
	digitalWrite(in, HIGH);
	digitalWrite(out, HIGH);
}

/**
 * Sends a print command to the GameBoy Printer after which the Printer starts printing the previously received data.
 * Before the print command is sent, 640 bytes of image data need to be transferred.
 * 	leftMargin ... empty space before the print
 * 	rightMArgin .. empty space after the print
 * 	palette	...... palette to be used. Default palette is 0b11100100 (black, dark grey, light grey, white)
 * 	exposure ..... Exposure (heat) applied to the thermal paper, value between 0 and 127
 */
bool GBPrinter::sendPrint(uint8_t leftMargin, uint8_t rightMargin,
		uint8_t palette, uint8_t exposure) {
	sendSync();
	sendHeader(GB_CMD_PRINT, GB_COMPRESSION_FALSE, 4); // The body in a Print command is always four bytes in length.

	writeByte(0x01); // The first byte is always set to 0x01, its purpose is unknown.
	writeByte((leftMargin << 4) + rightMargin); // Margin before and after the page, defined by 2 4-bit values
	writeByte(palette); // Palette (Default: 11100100 - black, dark grey, light grey, white)
	writeByte(exposure);  // Exposure

	sendChecksum();
	return getAcknowledgement();
}

/**
 * Sends a print command to the GameBoy Printer using default palette and exposure settings.
 * Before the print command is sent, 640 bytes of image data need to be transferred.
 * 	leftMargin ... empty space before the print
 * 	rightMargin .. empty space after the print
 */
bool GBPrinter::sendPrint(uint8_t leftMargin, uint8_t rightMargin) {
	return sendPrint(leftMargin, rightMargin, GB_PALETTE_DEFAULT,
	GB_EXPOSURE_DEFAULT);
}

/**
 * Sends a print command to the GameBoy Printer using default palette and exposure settings and no margin.
 * Before the print command is sent, 640 bytes of image data need to be transferred.
 */
bool GBPrinter::sendPrint() {
	return sendPrint(GB_MARGIN_NONE, GB_MARGIN_NONE, GB_PALETTE_DEFAULT,
	GB_EXPOSURE_DEFAULT);
}

/**
 * Sends a byte to the GameBoy Printer
 */
uint8_t GBPrinter::writeByte(uint8_t cmd) {
	uint8_t command = cmd;
	crc += command; // update CRC
	uint8_t reply = 0;
	for (uint8_t clock = 0; clock < 8; ++clock) {
		reply <<= 1;			// Shift Printer gbReply
		digitalWrite(clk, 0);   // Send clock signal

		// Send data bit to printer
		//TODO improve
		if ((command << clock) & 0x80) {
			digitalWrite(out, 1);
		} else {
			digitalWrite(out, 0);
		}

		delayMicroseconds(delayMs);	// Wait 20-60us
		digitalWrite(clk, 1);       // End clock
		if (digitalRead(in)) {
			reply |= 1; 			// Read reply bit
		}
		delayMicroseconds(delayMs);	// Wait 20-60us
	}
	delayMicroseconds(delayMs);		// Wait 20-60us

	/*Serial.print(command, HEX);
	 Serial.print(' ');
	 Serial.print(reply, HEX);
	 Serial.print('\n');
	 */
	return reply;
}

/**
 * Sends the magic bytes 0x88 and 0x33 to the GameBoy printer to indicate the start of a command.
 */
void GBPrinter::sendSync() {
	writeByte(0x88);	//10001000
	writeByte(0x33);	//00110011
}

/**
 * Sends header data to the GameBoy Printer
 * The data consists of four bytes. A command, a compression indicator and the length of the body that follows the header.
 * 	0000 XXXX Command
 * 	0000 000X Compression indicator
 * 	XXXX XXXX LSB of 16-bit length variable
 * 	XXXX XXXX MSB of 16-bit length variable
 *
 * 	The body length can be zero to indicate an empty body.
 */
void GBPrinter::sendHeader(uint8_t commandCode,
		uint8_t compressionIndicator, uint16_t bodyLength) {
	//Serial.print("\nCMD: ");
	//Serial.println(commandCode,HEX);
	crc = 0; // reset CRC
	writeByte(commandCode);
	writeByte(compressionIndicator);
	writeByte(bodyLength); 		// LSB
	writeByte(bodyLength >> 8); 	// MSB

	crc = commandCode + compressionIndicator + (uint8_t) bodyLength
			+ ((uint8_t) (bodyLength >> 8));
}

/**
 * Sends a command to the GameBoy Printer.
 * A command has the following structure: [Sync mark][Header][Body][Checksum]
 * Example Command:
 *	0x88 // Magic Sync Byte 1
 *	0x33 // Magic Sync Byte 2
 *	0x01 // Command
 *	0x00 // Length
 *	0x00 //	Length
 *	0x01 // Sum of everything bar magic packet
 */
bool GBPrinter::sendCommand(uint8_t command, uint16_t bodyLength) {
	boolean result = false;
	sendSync();
	sendHeader(command, GB_COMPRESSION_FALSE, bodyLength);

	sendChecksum(bodyLength + command); // sendCommand CRC
	result = getAcknowledgement();

	return result;
}

/**
 * Sends a command to the GameBoy Printer.
 * A command has the following structure: [Sync mark][Header][Body][Checksum]
 * Example Command:
 *		0x88 // Magic Sync Byte 1
 *		0x33 // Magic Sync Byte 2
 *		0x01 // Command
 *		0x00 // Length
 *		0x00 //	Length
 *		0x01 // Sum of everything bar magic packet
 */
bool GBPrinter::sendCommand(uint8_t command) {
	sendSync();
	sendHeader(command, GB_COMPRESSION_FALSE, 0);

	sendChecksum(command); // sendCommand CRC
	return getAcknowledgement();
}

/**
 * Sends a print data command to the GameBoy printer.
 * The compression indicator in Header is set to zero (0x00.) The length field in Header is set to 0x280, or 640 in decimal.
 * Since 16 bit values are transmitted in LSB-first byte order, it is actually transmitted as 0x80 0x02.
 * The Body in plain printing Data command represents a band (160x16 dots or 20x2 tiles) of printing image in plain (uncompressed) format.
 * Since each pixel is represented by 2 bits, 160x16x2 = 640 bits of data need to be sent after this header.
 */
void GBPrinter::beginData() {
	sendSync();
	sendHeader(GB_CMD_DATA, GB_COMPRESSION_FALSE, 0x280);
}

/**
 * End transmission of a band with sending of checksum and retrieving of the Acknowledgement code.
 */
uint8_t GBPrinter::endData() {
	sendChecksum();
	if(getAcknowledgement()){
		return getStatusCode();
	}
	return 0x01;
}

/**
 * Send the Initialize command to the GameBoy Printer.
 */
uint8_t GBPrinter::sendInitialize() {
	if(sendCommand(GB_CMD_INIT)){
		return getStatusCode();
	}
	return 0x01;
}

/**
 * Sends an inquiry command to the GameBoy Printer, notifying the GameBoy printer of the status of the GameBoy. Usually sent after a Print command.
 * A command packet whose command code is set to 0x0F is an Inquiry command. The compression indicator of the Inquiry command is set to zero (0x00.)
 * The length field is always set to zero (0x00 0x00,) to indicate the Body in the command is empty.
 * Unlike other commands, the Inquiry command may be sent at any time. The GB Printer is expected to respond to an Inquiry command always.
 */
uint8_t GBPrinter::sendInquiry() {
	sendCommand(GB_CMD_INQUIRY);
	return getStatusCode();
}

/**
 * Sends checksum data to the GameBoy Printer
 * A Checksum is a two-byte (16 bit) value to verify a command packet is received properly.
 * It is always appended at the end of a command packet. The Checksum is a 16 bit arithmetic
 * sum over bytes in the command packet, excluding the Synchronization marker (i.e., 0x83 and 0x33 at the beginning of the packet)
 * and the Checksum, regarding each byte as an eight-bit unsigned integer.
 */
void GBPrinter::sendChecksum(uint16_t checksum) {
	//Serial.print("Sending CRC = ");
	//Serial.println(checksum, DEC);
	writeByte(checksum); 		// LSB
	writeByte(checksum >> 8); // MSB
}

/**
 * Sends checksum data to the GameBoy Printer
 * A Checksum is a two-byte (16 bit) value to verify a command packet is received properly.
 * It is always appended at the end of a command packet. The Checksum is a 16 bit arithmetic
 * sum over bytes in the command packet, excluding the Synchronization marker (i.e., 0x83 and 0x33 at the beginning of the packet)
 * and the Checksum, regarding each byte as an eight-bit unsigned integer.
 */
void GBPrinter::sendChecksum() {
	//Serial.print("Sending CRC = ");
	//Serial.println(crc, DEC);
	uint16_t checksum = crc;
	writeByte(checksum); 		// LSB
	writeByte(checksum >> 8); // MSB
}



/**
 * Sends a DATA command without a body after sending the print data.
 * One empty Data command is sent after the last printing Data command for a page and before the Print command for the page.
 * The purpose of this command is unknown.
 */
bool GBPrinter::endPage() {
	sendCommand(GB_CMD_DATA);
	return getStatusCode() == 0x08;
}

/**
 * Retrieves a status code from the GameBoy Printer.
 * A status code is a bitmap to indicate various Printer statuses. It has bit-by-bit meanings.
 */
uint8_t GBPrinter::getStatusCode() {
	return writeByte(0); // Wait for confirmation
}

/**
 * Retrieves an acknowledgment code from the GameBoy Printer
 * A valid acknowledgment code is either 0x80 or 0x81.
 */
bool GBPrinter::getAcknowledgement() {
	uint8_t ack = writeByte(0); // Wait for confirmation
	return (ack == 0x80 || ack == 0x81); // Good otherwise timeout
}

/**
 * Retrieves and prints a status code from the GameBoy Printer
 */
void GBPrinter::printStatusCode() {
	uint8_t result = getStatusCode();

	switch (result) {
	case 0:
		Serial.print("OK: ");
		break;
	case 0x80:
	case 0x81:
		Serial.print("ACK: ");
		break;
	case 0x08:
		Serial.print("OK: ");
		break;
	default:
		Serial.print("ERROR: ");
	}
	Serial.println(result, HEX);
}

/**
 * Writes Zeros to the 640 byte gb_buffer
 */
void GBPrinter::clearBuffer(){
	for (int i = 0; i < 640; i++) {
		gb_buffer[i] = 0x00;
	}
}

/**
 * Appends a character to the buffer. When the buffer is full (40 characters) the buffer gets automatically printed and zeroed.
 * Manual flushing is possible by calling the flushBuffer() function;
 */
bool GBPrinter::printCharacter(unsigned char c) {
	//Serial.print("\nPrinting character: ");

	//Serial.print(" (");
	//Serial.print(c);
	//Serial.println(")");


	int bufferOffset = charpointer * 16;


	/*Serial.print("charpointer = ");
	Serial.println(charpointer,DEC);
	Serial.print("bufferOffset  = ");
	Serial.println(bufferOffset,DEC);
	Serial.print("charOffset  = ");
	Serial.println(charOffset,DEC);
*/
	if (c < 32) {
		if (c == 0x0A) { //newline
			if (charpointer < 20) {
				charpointer = 20; //switch charpointer to new line
			} else if (charpointer > 20){ // If charpointer is already at the new line, do nothing
				//Serial.println();
				flushBuffer(); // flush Buffer
				clearBuffer();
			}
		}
		c = '?';
	}else if (c > 126) {
		c = '?'; // Extended ACSII set is not supported.
	}else{
		//if(charpointer==20) Serial.println();
		int charOffset = (c - 32) * 8; //font array contains 92 characters, starting with Space. Each character is 8 bytes in length and has 1 bit per pixel instead of 2
		for (int i = 0; i < 8; i++) {
			uint8_t line = pgm_read_byte_near(font + charOffset + i);
			gb_buffer[bufferOffset + i * 2] = line;
			gb_buffer[bufferOffset + i * 2 + 1] = line;
			//Serial.println((uint16_t)line|(uint16_t)0b100000000,BIN);
		}
		charpointer++;
	}


	if (charpointer >= 40) {
		//Serial.println();
		flushBuffer();
		clearBuffer();
	}
	return true;
}

bool GBPrinter::print(String s){
	return true;
}

bool GBPrinter::println(String s){
	print(s);
	printCharacter('\n');
	return true;
}


void GBPrinter::printTest() {
	/*for (int i = 0; i < 640; i++) {
		gb_buffer[i] = pgm_read_byte_near(img + i);
	}*/
	printCharacter('H');
	printCharacter('a');
	printCharacter('l');
	printCharacter('l');
	printCharacter('o');
	printCharacter('!');
	printCharacter('\n');
	printCharacter('!');
	flushBuffer();
}

/**
 * Waits until the GB Printer is done with printing.
 */
void GBPrinter::waitForPrinterReady(){
	while(sendInquiry()){
		delay(100);
	}
}

/**
 * Prints an empty band. There might be a way to do this without transmitting actual image data.
 */
void GBPrinter::feed() {
	waitForPrinterReady();
	sendInitialize();
	beginData();
	for (int i = 0; i < 640; i++) {
		writeByte(0x00);
	}
	endData();
	endPage();
	sendPrint();
}

/**
 * Prints the contents of the gb_buffer array.
 */
bool GBPrinter::flushBuffer() {
	charpointer = 0; // Reset character pointer
	waitForPrinterReady(); // Send inquiry commands until printer is ready
	sendInitialize(); // Send initialize command to indicate that data will be transmitted.

	// Transmit 640 bytes of image data
	beginData();
	for (int i = 0; i < 640; i++) {
		uint8_t cmd = gb_buffer[i];
		writeByte(cmd);
	}
	//Serial.println("Buffer transmitted");
	endData();
	// End of transmission

	sendInquiry();

	endPage();

	sendPrint(0, 0, GB_PALETTE_DEFAULT, exposure);
	return true;
}

void GBPrinter::setExposure(uint8_t newExposure){
	exposure = newExposure;
}

void GBPrinter::printBlank(uint8_t numBands){
	if(numBands<1) return;
	clearBuffer();
	charpointer = 0; // Reset character pointer
	waitForPrinterReady(); // Send inquiry commands until printer is ready
	sendInitialize(); // Send initialize command to indicate that data will be transmitted.

	// Transmit 640 bytes of image data
	beginData();
	for (int i = 0; i < 640; i++) {
		uint8_t cmd = gb_buffer[i];
		writeByte(cmd);
	}
	//Serial.println("Buffer transmitted");
	endData();
	// End of transmission

	sendInquiry();

	endPage();

	sendPrint(0, numBands-1, GB_PALETTE_DEFAULT, exposure);
}
