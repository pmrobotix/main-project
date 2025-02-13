/*!
 * \file
 * \brief Ce fichier contient l'initialisation du système de Log.
 */

#include "../../src/Log/Appender/ConsoleAppender.hpp"
#include "../../src/Log/Level.hpp"
#include "../../src/Log/LoggerFactory.hpp"
#include "../Suite/UnitTestAppender.hpp"
#include "../../src/Log/Appender/SvgAppender.hpp"

void logs::LoggerFactory::initialize()
{
    //set minimum thread priority FIFO
    utils::set_realtime_priority(1);

    this->add("console", new ConsoleAppender());
    this->add("unittestconsole", new UnitTestAppender());
    this->add("memory", new MemoryAppender());
    this->add("svg", new SvgAppender("svgDriverSIMU.svg"));

    add(logs::Level::INFO, "", "unittestconsole");

    add(logs::Level::DEBUG, "AsservDriver.SIMU", "console");
    add(logs::Level::DEBUG, "AsservDriverTest.SIMU", "console");
    add(logs::Level::DEBUG, "LedDriverTest.SIMU", "console");
    add(logs::Level::DEBUG, "AsservDriverMemory.SIMU", "memory");

    add(logs::Level::INFO, "Svg4SIMU", "svg");
    add(logs::Level::INFO, "SensorsDriver.SIMU.SVG", "svg");

}
