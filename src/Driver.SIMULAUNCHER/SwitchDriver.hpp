#ifndef SIMULAUNCHER_SWITCHDRIVER_HPP_
#define SIMULAUNCHER_SWITCHDRIVER_HPP_

#include "../Common/Action.Driver/ASwitchDriver.hpp"
#include "../Log/LoggerFactory.hpp"

using namespace std;

class SwitchDriver: public ASwitchDriver
{
private:

	/*!
	 * \brief Retourne le \ref Logger associé à la classe \ref SwitchDriver(SIMULAUNCHER).
	 */
	static inline const logs::Logger & logger()
	{
		static const logs::Logger & instance = logs::LoggerFactory::logger(
				"SwitchDriver.SIMULAUNCHER");
		return instance;
	}

public:

	/*!
	 * \brief Constructor.
	 */
	SwitchDriver();

	/*!
	 * \brief Destructor.
	 */
	~SwitchDriver();

	int tirettePressed();
	int backLeftPressed();
	int backRightPressed();

	int pressed(unsigned char pin);

};

#endif
