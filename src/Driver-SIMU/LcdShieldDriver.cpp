//drivers...SIMU

#include "LcdShieldDriver.hpp"

#include <stddef.h>
#include <cstdint>
#include <string>

using namespace std;

ALcdShieldDriver * ALcdShieldDriver::create(std::string botId)
{
    return new LcdShieldDriver();
}

LcdShieldDriver::LcdShieldDriver()
{

}

LcdShieldDriver::~LcdShieldDriver()
{
}

bool LcdShieldDriver::is_connected()
{
    return true;
}

void LcdShieldDriver::clear()
{

}

void LcdShieldDriver::home()
{

}

void LcdShieldDriver::setBacklightOn()
{
    logger().debug() << "setBacklightOn()" << logs::end;
}

void LcdShieldDriver::setBacklightOff()
{
    logger().debug() << "setBacklightOff()" << logs::end;
}

void LcdShieldDriver::setCursor(uint8_t col, uint8_t row)
{

}

size_t LcdShieldDriver::write(uint8_t value)
{
    logger().debug() << value << logs::end;
    return 1;
}

void LcdShieldDriver::print_content_string(std::string str, int row, int col)
{
    logger().debug() << str << logs::end;
}

void LcdShieldDriver::print_content_integer(int value, int row, int col)
{
    logger().debug() << value << logs::end;
}

