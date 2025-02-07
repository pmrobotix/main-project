#include "L_LedBarTest.hpp"

#include <unistd.h>
#include <string>

#include "../Common/Action/LedBar.hpp"
#include "../Common/Interface.Driver/ALedDriver.hpp"
#include "../Log/Logger.hpp"
#include "LegoEV3ActionsExtended.hpp"
#include "LegoEV3RobotExtended.hpp"

using namespace std;

void L_LedBarTest::run(int argc, char** argv)
{
    configureConsoleArgs(argc, argv);

    logger().info() << "N° " << this->position() << " - Executing - " << this->desc() << logs::end;

    LegoEV3RobotExtended &robot = LegoEV3RobotExtended::instance();

    robot.actions().ledBar().resetAll();
/*
    robot.actions().ledBar().rainbow(2, 900000);

    robot.actions().ledBar().setOff(0);
    robot.actions().ledBar().setOff(1);

    robot.actions().ledBar().setOn(0);
    robot.actions().ledBar().setOn(1);

    robot.actions().ledBar().setOff(0);
    robot.actions().ledBar().setOff(1);

    robot.actions().ledBar().set(0, LED_RED);

    robot.actions().ledBar().set(0, LED_ORANGE);

    robot.actions().ledBar().set(0, LED_GREEN);

    robot.actions().ledBar().setOff(0);


    robot.actions().ledBar().blink(5, 200000, LED_ORANGE);

    robot.actions().ledBar().k2mil(4, 100000, LED_YELLOW);
*/
    logger().info() << "Start Actions..." << logs::end;
    robot.actions().start();
    logger().info() << "Startset..." << logs::end;
    robot.actions().ledBar().startSet(0, LED_ORANGE);

    logger().info() << "startTimerAlternate..." << logs::end;
    robot.actions().ledBar().startTimerAlternate(100, 20000, 0x03, 0x01, LED_GREEN, false);
    logger().info() << "startTimerAlternate  finished" << logs::end;
    utils::sleep_for_micros(500000);
    robot.actions().ledBar().stop(true);


    logger().info() << "startTimerK2mil 1..." << logs::end;
    robot.actions().ledBar().startTimerK2mil(10, 300000, LED_RED, true);
    logger().info() << "startTimerK2mil  finished" << logs::end;

    utils::sleep_for_micros(2000000);
/*
    logger().info() << "startTimerK2mil 2..." << logs::end;
    robot.actions().ledBar().startTimerK2mil(20, 60000, LED_GREEN, false);
    utils::sleep_for_micros(1000000);

    logger().info() << "startTimerBlinkPin 3..." << logs::end;
    robot.actions().ledBar().startTimerBlinkPin(15, 80000, 0, LED_RED, false);
    utils::sleep_for_micros(1000000);
*/
    logger().info() << "stopAndWait..." << logs::end;
    robot.actions().ledBar().stop(true);


    robot.actions().clearAll();
    robot.actions().ledBar().resetAll();

    logger().info() << "Happy End." << logs::end;

}

