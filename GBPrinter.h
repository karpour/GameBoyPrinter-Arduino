#ifndef AVR_GBPrinter_H_
#define AVR_GBPrinter_H_
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

// Defines
#define GB_CMD_INIT 			0x01
#define GB_CMD_DATA				0x04
#define GB_CMD_PRINT			0x02
#define GB_CMD_INQUIRY			0x0F

/** Default Palette **/
#define GB_PALETTE_DEFAULT		0xE4
#define GB_PALETTE_INVERTED		0x1B

#define GB_COMPRESSION_FALSE	0x00
#define GB_COMPRESSION_TRUE		0x01

#define GB_STATUS_LOWBAT		0x80
#define GB_STATUS_TEMPBAD		0x40
#define GB_STATUS_JAM			0x20
#define GB_STATUS_BUSY			0x10
#define GB_STATUS_GOOD			0x00

#define GB_MARGIN_NONE			0x00
#define GB_MARGIN_MIN			0x01 // 1
#define GB_MARGIN_MAX			0x0F // 15

#define GB_EXPOSURE_DEFAULT		0x40 // 64
#define GB_EXPOSURE_MAX			0x7F // 127

// TODO rename to delayUs
#define delayMs 20 // between 20 and 60us

extern uint8_t gb_buffer[640];
//extern const unsigned char img[640] PROGMEM;

class GBPrinter {
public:
	// Constructor
	GBPrinter(int in_pin, int out_pin, int clk_pin);

	// Low-level write methods
	uint8_t writeByte(uint8_t command);
	void sendSync();
	void sendHeader(uint8_t commandCode, uint8_t compressionIndicator, uint16_t bodyLength);
	void sendChecksum(uint16_t checksum);
	void sendChecksum();
	bool sendCommand(uint8_t command, uint16_t bodyLength);
	//bool sendCommand(uint8_t command);
	uint8_t getStatusCode();
	bool getAcknowledgement();
	void waitForPrinterReady();

	// Various commands
	uint8_t sendInitialize();
	uint8_t sendInquiry();
	void setExposure(uint8_t exposure);
	void beginData();
	uint8_t endData();
	bool endPage();
	bool sendPrint(uint8_t leftMargin, uint8_t rightMargin, uint8_t palette, uint8_t exposure);
	//bool sendPrint(uint8_t leftMargin, uint8_t rightMargin);
	//bool sendPrint();
	void printBlank(uint8_t numBands);
	void clearBuffer();
	bool flushBuffer();
	void feed();

	// Methods to print text
	bool printCharacter(unsigned char c);
	bool print(String s);
	bool println(String s);

	// Test methods
	void printTest();
	void printStatusCode();

private:
	int in;  // Input pin
	int out; // Putput pin
	int clk; // Clock pin
	uint8_t exposure;
	uint16_t crc;
	int charpointer;
};

#endif /* AVR_GBPrinter_H_ */
