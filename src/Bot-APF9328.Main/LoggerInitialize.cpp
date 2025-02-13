/*!
 * \file
 * \brief Ce fichier contient l'initialisation du système de Log.
 */

#include "../Log/Appender/ConsoleAppender.hpp"
#include "../Log/Appender/FileAppender.hpp"
#include "../Log/Appender/SvgAppender.hpp"
#include "../Log/Level.hpp"
#include "../Log/LoggerFactory.hpp"

void logs::LoggerFactory::initialize()
{
	add("console", new ConsoleAppender());
	add("svg", new SvgAppender("svgAPF.svg"));
	add("memory", new MemoryAppender());
	//add("file", new FileAppender("logAPF.csv"));

	add(logs::Level::ERROR, "", "console");

	add(logs::Level::INFO, "Robot", "console");
	add(logs::Level::INFO, "APF9328RobotExtended", "console");

	//COMMON
	add(logs::Level::INFO, "Tirette", "console");


	//SVG
	add(logs::Level::INFO, "Svg4APF9328Robot", "svg");


	//File
	//add(logs::Level::DEBUG, "logFileAsservInsa", "file");


	//State
	add(logs::Level::INFO, "A_State1", "console");
	add(logs::Level::INFO, "A_State_decisionMaker", "console");
	add(logs::Level::INFO, "A_State_Wait90SecAction", "console");


	//TESTS
	add(logs::Level::INFO, "A_LedBarTest", "console");
	add(logs::Level::INFO, "A_ButtonBarTest", "console");
	add(logs::Level::INFO, "A_MovingBaseTest", "console");
	add(logs::Level::INFO, "A_LcdBoardTest", "console");
	add(logs::Level::INFO, "A_TiretteTest", "console");
	add(logs::Level::INFO, "A_SensorsTest", "console");
	add(logs::Level::INFO, "A_ServoTest", "console");
	add(logs::Level::INFO, "A_ServoStepTest", "console");
	add(logs::Level::INFO, "A_Asserv_SetResolutionTest", "console");
	add(logs::Level::INFO, "A_Asserv_FindPIDTest", "console");
	add(logs::Level::INFO, "A_AsservInsaTest", "console");
	add(logs::Level::INFO, "A_AsservRunTest", "console");
	add(logs::Level::INFO, "A_Asserv_SquareTest", "console");
	add(logs::Level::INFO, "A_IATest", "console");


	//DRIVERS SIMU
	add(logs::Level::INFO, "LedDriver.SIMU", "console");
	add(logs::Level::INFO, "ButtonDriver.SIMU", "console");
	add(logs::Level::INFO, "SoundDriver.SIMU", "console");
	add(logs::Level::INFO, "SwitchDriver.SIMU", "console");
	add(logs::Level::INFO, "AsservDriver.SIMU", "console");
	add(logs::Level::INFO, "AsservDriverMemory.SIMU", "memory");

	//DRIVERS EV3
	add(logs::Level::INFO, "LedDriver.ARM", "console");
	add(logs::Level::INFO, "ButtonDriver.ARM", "console");
	add(logs::Level::INFO, "SoundDriver.ARM", "console");
	add(logs::Level::INFO, "SwitchDriver.ARM", "console");
	add(logs::Level::INFO, "AsservDriver.ARM", "console");
	add(logs::Level::INFO, "GpioPCA9555", "console");
	add(logs::Level::INFO, "ExtEncoder", "console");
	add(logs::Level::INFO, "SensorsDriver.ARM", "console");
	add(logs::Level::INFO, "IrSensor", "console");
	add(logs::Level::INFO, "as_adc", "console");


}
