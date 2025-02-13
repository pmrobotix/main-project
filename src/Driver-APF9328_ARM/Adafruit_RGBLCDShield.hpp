/*************************************************** 
 This is a library for the Adafruit RGB 16x2 LCD Shield
 Pick one up at the Adafruit shop!
 ---------> http://http://www.adafruit.com/products/714

 The shield uses I2C to communicate, 2 pins are required to
 interface
 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, all text above must be included in any redistribution
 ****************************************************/

#ifndef Adafruit_RGBLCDShield_h
#define Adafruit_RGBLCDShield_h

//#include <inttypes.h>

#include <stddef.h>
#include <stdint.h>

#include "../Log/LoggerFactory.hpp"
#include "Adafruit_MCP23017.hpp"

//COLOR LCD
#define LCD_ON 0x1
#define LCD_OFF 0x6

#define LCD_RED 0x1
#define LCD_YELLOW 0x3
#define LCD_GREEN 0x2
#define LCD_TEAL 0x6
#define LCD_BLUE 0x4
#define LCD_VIOLET 0x5
#define LCD_WHITE 0x7

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define BUTTON_UP 0x08
#define BUTTON_DOWN 0x04
#define BUTTON_LEFT 0x10
#define BUTTON_RIGHT 0x02
#define BUTTON_SELECT 0x01

class Adafruit_RGBLCDShield : public utils::Mutex //: public Print
{
private:
	/*!
	 * \brief Retourne le \ref Logger associé à la classe \ref Adafruit_RGBLCDShield.
	 */
	static const logs::Logger & logger()
	{
		static const logs::Logger & instance = logs::LoggerFactory::logger("Adafruit_RGBLCDShield");
		return instance;
	}

	utils::Mutex mutex_;
	bool connected_;

	uint8_t _rs_pin; // LOW: command.  HIGH: character.
	uint8_t _rw_pin; // LOW: write to LCD.  HIGH: read from LCD.
	uint8_t _enable_pin; // activated by a HIGH pulse.
	uint8_t _data_pins[8];
	uint8_t _button_pins[5];
	uint8_t _displayfunction;
	uint8_t _displaycontrol;
	uint8_t _displaymode;

	//uint8_t _initialized;

	uint8_t _numlines, _currline;

	uint8_t _i2cAddr;
	Adafruit_MCP23017 _i2c;

	Adafruit_RGBLCDShield();

	void send(uint8_t, uint8_t);
	void write4bits(uint8_t);
	void write8bits(uint8_t);
	void pulseEnable();
	void _digitalWrite(uint8_t, uint8_t);
	void _pinMode(uint8_t, uint8_t);

public:

	static Adafruit_RGBLCDShield & instance()
	{
		static Adafruit_RGBLCDShield instance;
		return instance;
	}

	~Adafruit_RGBLCDShield()
	{
	}

	void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

	void clear();
	void home();

	void noDisplay();
	void display();
	void noBlink();
	void blink();
	void noCursor();
	void cursor();
	void scrollDisplayLeft();
	void scrollDisplayRight();
	void leftToRight();
	void rightToLeft();
	void autoscroll();
	void noAutoscroll();

	// only if using backpack
	void setBacklight(uint8_t status);

	void createChar(uint8_t, uint8_t[]);
	void setCursor(uint8_t, uint8_t);
	/*#if ARDUINO >= 100
	 size_t write(uint8_t);
	 #else*/

	size_t write__(uint8_t value); //virtual

	//#endif
	void command(uint8_t);
	uint8_t readButtons();

};

#endif
