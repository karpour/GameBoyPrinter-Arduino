#include "Arduino.h"
#include "GBPrinter.h"
#include "font.h"

/*const unsigned char img[640] PROGMEM = {0xC0, 0xE0, 0xC0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0xC0,
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
										0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF};*/

/** The buffer that holds 160x16x2 bit of data */
uint8_t gb_buffer[640];

/**
 * @brief Constructor, sets pin modes and pull-up resistors
 * 
 * @param in_pin connected to SOUT of the GameBoy Printer
 * @param out_pin connected to SIN of the GameBoy Printer
 * @param clk_pin connected to SCLK of the GameBoy Printer
 */
GBPrinter::GBPrinter(int in_pin, int out_pin, int clk_pin)
{
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
 * @brief Sends a print command to the GameBoy Printer after which the Printer starts printing the previously received data.
 * Before the print command is sent, 640 bytes of image data need to be transferred.
 * 
 * @param leftMargin empty space before the print
 * @param rightMargin empty space after the print
 * @param palette Palette to be used. Default palette is 0b11100100 (black, dark grey, light grey, white)
 * @param exposure Exposure (heat) applied to the thermal paper, value between 0 and 127
 * @return true 
 * @return false 
 */
bool GBPrinter::sendPrint(uint8_t leftMargin = GB_MARGIN_NONE, uint8_t rightMargin = GB_MARGIN_NONE,
						  uint8_t palette = GB_PALETTE_DEFAULT, uint8_t exposure = GB_EXPOSURE_DEFAULT)
{
	sendSync();
	sendHeader(GB_CMD_PRINT, GB_COMPRESSION_FALSE, 4); // The body in a Print command is always four bytes in length.

	writeByte(0x01);							// The first byte is always set to 0x01, its purpose is unknown.
	writeByte((leftMargin << 4) + rightMargin); // Margin before and after the page, defined by 2 4-bit values
	writeByte(palette);							// Palette (Default: 11100100 - black, dark grey, light grey, white)
	writeByte(exposure);						// Exposure

	sendChecksum();
	return getAcknowledgement();
}

/**
 * @brief Sends a print command to the GameBoy Printer using default palette and exposure settings.
 * Before the print command is sent, 640 bytes of image data need to be transferred.
 * 
 * @param leftMargin empty space before the print
 * @param rightMargin empty space after the print
 * @return true 
 * @return false 
 *
bool GBPrinter::sendPrint(uint8_t leftMargin, uint8_t rightMargin) {
	return sendPrint(leftMargin, rightMargin, GB_PALETTE_DEFAULT,
	GB_EXPOSURE_DEFAULT);
}

/**
 * Sends a print command to the GameBoy Printer using default palette and exposure settings and no margin.
 * Before the print command is sent, 640 bytes of image data need to be transferred.
 *
bool GBPrinter::sendPrint() {
	return sendPrint(GB_MARGIN_NONE, GB_MARGIN_NONE, GB_PALETTE_DEFAULT,
	GB_EXPOSURE_DEFAULT);
}
*/

/**
 * @brief Sends a byte to the GameBoy Printer
 * 
 * @param cmd Command to send
 * @return uint8_t 
 */
uint8_t GBPrinter::writeByte(uint8_t cmd)
{
	uint8_t command = cmd;
	crc += command; // update CRC
	uint8_t reply = 0;
	for (uint8_t clock = 0; clock < 8; ++clock)
	{
		reply <<= 1;		  // Shift Printer gbReply
		digitalWrite(clk, 0); // Send clock signal

		// Send data bit to printer
		//TODO improve
		if ((command << clock) & 0x80)
		{
			digitalWrite(out, 1);
		}
		else
		{
			digitalWrite(out, 0);
		}

		delayMicroseconds(delayMs); // Wait 20-60us
		digitalWrite(clk, 1);		// End clock
		if (digitalRead(in))
		{
			reply |= 1; // Read reply bit
		}
		delayMicroseconds(delayMs); // Wait 20-60us
	}
	delayMicroseconds(delayMs); // Wait 20-60us

	/*Serial.print(command, HEX);
	 Serial.print(' ');
	 Serial.print(reply, HEX);
	 Serial.print('\n');
	 */
	return reply;
}

/**
 * @brief Sends the magic bytes 0x88 and 0x33 to the GameBoy printer to indicate the start of a command.
 */
void GBPrinter::sendSync()
{
	writeByte(0x88); //10001000
	writeByte(0x33); //00110011
}

/**
 * @brief Sends header data to the GameBoy Printer
 * The data consists of four bytes. A command, a compression indicator and the length of the body that follows the header.
 * 	0000 XXXX Command
 * 	0000 000X Compression indicator
 * 	XXXX XXXX LSB of 16-bit length variable
 * 	XXXX XXXX MSB of 16-bit length variable
 *
 * 	The body length can be zero to indicate an empty body.
 */
void GBPrinter::sendHeader(uint8_t commandCode,
						   uint8_t compressionIndicator, uint16_t bodyLength)
{
	//Serial.print("\nCMD: ");
	//Serial.println(commandCode,HEX);
	crc = 0; // reset CRC
	writeByte(commandCode);
	writeByte(compressionIndicator);
	writeByte(bodyLength);		// LSB
	writeByte(bodyLength >> 8); // MSB

	crc = commandCode + compressionIndicator + (uint8_t)bodyLength + ((uint8_t)(bodyLength >> 8));
}

/**
 * @brief Sends a command to the GameBoy Printer.
 * 
 * A command has the following structure: [Sync mark][Header][Body][Checksum]
 * Example Command:
 *	0x88 // Magic Sync Byte 1
 *	0x33 // Magic Sync Byte 2
 *	0x01 // Command
 *	0x00 // Length
 *	0x00 //	Length
 *	0x01 // Sum of everything bar magic packet
 *
 * @param command Command to send
 * @param bodyLength Length of the body. Default 0 for commands without body 
 * @return true 
 * @return false 
 */
bool GBPrinter::sendCommand(uint8_t command, uint16_t bodyLength = 0)
{
	sendSync();
	sendHeader(command, GB_COMPRESSION_FALSE, bodyLength);

	sendChecksum(bodyLength + command); // sendCommand CRC
	return getAcknowledgement();
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
/*bool GBPrinter::sendCommand(uint8_t command)
{
	sendSync();
	sendHeader(command, GB_COMPRESSION_FALSE, 0);

	sendChecksum(command); // sendCommand CRC
	return getAcknowledgement();
}*/

/**
 * @brief Sends a print data command to the GameBoy printer.
 * 
 * The compression indicator in Header is set to zero (0x00.) The length field in Header is set to 0x280, or 640 in decimal.
 * Since 16 bit values are transmitted in LSB-first byte order, it is actually transmitted as 0x80 0x02.
 * The Body in plain printing Data command represents a band (160x16 dots or 20x2 tiles) of printing image in plain (uncompressed) format.
 * Since each pixel is represented by 2 bits, 160x16x2 = 640 bits of data need to be sent after this header.
 */
void GBPrinter::beginData()
{
	sendSync();
	sendHeader(GB_CMD_DATA, GB_COMPRESSION_FALSE, 0x280);
}

/**
 * @brief End transmission of a band with sending of checksum and retrieving of the Acknowledgement code.
 */
uint8_t GBPrinter::endData()
{
	sendChecksum();
	if (getAcknowledgement())
	{
		return getStatusCode();
	}
	return 0x01;
}

/**
 * @brief Sends the Initialize command to the GameBoy Printer.
 */
uint8_t GBPrinter::sendInitialize()
{
	if (sendCommand(GB_CMD_INIT))
	{
		return getStatusCode();
	}
	return 0x01;
}

/**
 * @brief Sends an inquiry command to the GameBoy Printer, notifying the GameBoy printer of the status of the GameBoy. Usually sent after a Print command.
 * A command packet whose command code is set to 0x0F is an Inquiry command. The compression indicator of the Inquiry command is set to zero (0x00.)
 * The length field is always set to zero (0x00 0x00,) to indicate the Body in the command is empty.
 * Unlike other commands, the Inquiry command may be sent at any time. The GB Printer is expected to respond to an Inquiry command always.
 *
 * @returns uint8_t Status code
 */
uint8_t GBPrinter::sendInquiry()
{
	sendCommand(GB_CMD_INQUIRY);
	return getStatusCode();
}

/**
 * @brief Sends checksum data to the GameBoy Printer
 * A Checksum is a two-byte (16 bit) value the GameBoy printer uses to verify that a command packet was received properly.
 * It is always appended at the end of a command packet. The Checksum is a 16 bit arithmetic
 * sum over bytes in the command packet, excluding the Synchronization marker (i.e., 0x83 and 0x33 at the beginning of the packet)
 * and the Checksum, regarding each byte as an eight-bit unsigned integer.
 * 
 * @param checksum 16-bit checksum 
 */
inline void GBPrinter::sendChecksum(uint16_t checksum)
{
	//Serial.print("Sending CRC = ");
	//Serial.println(checksum, DEC);
	writeByte(checksum);	  // LSB
	writeByte(checksum >> 8); // MSB
}

/**
 * @brief Sends checksum data to the GameBoy Printer
 * A Checksum is a two-byte (16 bit) value to verify a command packet is received properly.
 * It is always appended at the end of a command packet. The Checksum is a 16 bit arithmetic
 * sum over bytes in the command packet, excluding the Synchronization marker (i.e., 0x83 and 0x33 at the beginning of the packet)
 * and the Checksum, regarding each byte as an eight-bit unsigned integer.
 */
void GBPrinter::sendChecksum()
{
	//Serial.print("Sending CRC = ");
	//Serial.println(crc, DEC);
	writeByte(crc);	  // LSB
	writeByte(crc >> 8); // MSB
}

/**
 * @brief Sends a DATA command without a body after sending the print data.
 * One empty Data command is sent after the last printing Data command for a page and before the Print command for the page.
 * The purpose of this command is unknown.
 * 
 * @returns true If command succeeds and the GB Printer returns status code 0x08, false If command fails and GB Printer returns a failure status code
 */
bool GBPrinter::endPage()
{
	sendCommand(GB_CMD_DATA);
	return getStatusCode() == 0x08;
}

/**
 * @brief Retrieves a status code from the GameBoy Printer.
 * A status code is a bitmap to indicate various Printer statuses. It has bit-by-bit meanings.
 *
 * @return uint8_t Status code
 */
inline uint8_t GBPrinter::getStatusCode()
{
	return writeByte(0); // Wait for confirmation
}

/**
 * @brief Retrieves an acknowledgment code from the GameBoy Printer
 * A valid acknowledgment code is either 0x80 or 0x81.
 * 
 * @return true If GB Printer returns a valid acknowledgement code
 * @return false If GB Printer returns an invalid acknowledgement code
 */
bool GBPrinter::getAcknowledgement()
{
	uint8_t ack = writeByte(0); // Wait for confirmation
	return (ack == 0x80 || ack == 0x81);
}

/**
 * Retrieves and prints a status code from the GameBoy Printer
 */
void GBPrinter::printStatusCode()
{
	uint8_t result = getStatusCode();

	switch (result)
	{
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
 * @brief Writes zeros to the 640 byte \link gb_buffer \endlink
 */
void GBPrinter::clearBuffer()
{
	for (int i = 0; i < 640; i++)
	{
		gb_buffer[i] = 0x00;
	}
}

/**
 * @brief Appends a character to the buffer. 
 * When the buffer is full (40 characters) the buffer gets automatically printed and zeroed.
 * Manual flushing is possible by calling the flushBuffer() function;
 * 
 * @param c Character to append
 * @return true 
 * @return false 
 */
bool GBPrinter::printCharacter(unsigned char c)
{
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
	if (c < 32)
	{
		if (c == 0x0A)
		{ //newline
			if (charpointer < 20)
			{
				charpointer = 20; //switch charpointer to new line
			}
			else if (charpointer > 20)
			{ // If charpointer is already at the new line, do nothing
				//Serial.println();
				flushBuffer(); // flush Buffer
				clearBuffer();
			}
		}
		c = '?';
	}
	else if (c > 126)
	{
		c = '?'; // Extended ACSII set is not supported.
	}
	else
	{
		//if(charpointer==20) Serial.println();
		int charOffset = (c - 32) * 8; //font array contains 92 characters, starting with Space. Each character is 8 bytes in length and has 1 bit per pixel instead of 2
		for (int i = 0; i < 8; i++)
		{
			uint8_t line = pgm_read_byte_near(font + charOffset + i);
			gb_buffer[bufferOffset + i * 2] = line;
			gb_buffer[bufferOffset + i * 2 + 1] = line;
			//Serial.println((uint16_t)line|(uint16_t)0b100000000,BIN);
		}
		charpointer++;
	}

	if (charpointer >= 40)
	{
		//Serial.println();
		flushBuffer();
		clearBuffer();
	}
	return true;
}

bool GBPrinter::print(String s)
{
	return true;
}

/**
 * @brief Prints a line
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool GBPrinter::println(String s)
{
	print(s);
	printCharacter('\n');
	return true;
}

void GBPrinter::printTest()
{
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
 * @brief Waits until the GB Printer is done with printing.
 */
void GBPrinter::waitForPrinterReady()
{
	while (sendInquiry())
	{
		delay(100);
	}
}

/**
 * @brief Prints an empty band. There might be a way to do this without transmitting actual image data.
 */
void GBPrinter::feed()
{
	waitForPrinterReady();
	sendInitialize();
	beginData();
	for (int i = 0; i < 640; i++)
	{
		writeByte(0x00);
	}
	endData();
	endPage();
	sendPrint();
}

/**
 * @brief Prints the contents of the gb_buffer array.
 * 
 * @return bool result of the sendPrint method
 */
bool GBPrinter::flushBuffer()
{
	charpointer = 0;	   // Reset character pointer
	waitForPrinterReady(); // Send inquiry commands until printer is ready
	sendInitialize();	   // Send initialize command to indicate that data will be transmitted.

	// Transmit 640 bytes of image data
	beginData();
	for (int i = 0; i < 640; i++)
	{
		uint8_t cmd = gb_buffer[i];
		writeByte(cmd);
	}
	//Serial.println("Buffer transmitted");
	endData();
	// End of transmission

	sendInquiry();

	endPage();

	return sendPrint(0, 0, GB_PALETTE_DEFAULT, exposure);
}

void GBPrinter::setExposure(uint8_t newExposure)
{
	exposure = newExposure;
}

void GBPrinter::printBlank(uint8_t numBands)
{
	if (numBands < 1)
		return;
	clearBuffer();
	charpointer = 0;	   // Reset character pointer
	waitForPrinterReady(); // Send inquiry commands until printer is ready
	sendInitialize();	   // Send initialize command to indicate that data will be transmitted.

	// Transmit 640 bytes of image data
	beginData();
	for (int i = 0; i < 640; i++)
	{
		uint8_t cmd = gb_buffer[i];
		writeByte(cmd);
	}
	//Serial.println("Buffer transmitted");
	endData();
	// End of transmission

	sendInquiry();

	endPage();

	sendPrint(0, numBands - 1, GB_PALETTE_DEFAULT, exposure);
}
