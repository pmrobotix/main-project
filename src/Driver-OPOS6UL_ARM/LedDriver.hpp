#ifndef OPOS6UL_LEDDRIVER_HPP_
#define OPOS6UL_LEDDRIVER_HPP_

#include <sys/types.h>

#include "../Common/Interface.Driver/ALedDriver.hpp"
#include "../Log/LoggerFactory.hpp"

#include <as_devices/cpp/as_gpio.hpp>

class LedDriver: public ALedDriver
{
    /*!
     * \brief Retourne le \ref Logger associé à la classe \ref LedDriver(OPOS6UL).
     */
    static inline const logs::Logger & logger()
    {
        static const logs::Logger & instance = logs::LoggerFactory::logger("LedDriver.OPO");
        return instance;
    }

    int nb_;

public:

    /*!
     * \brief Liste des gpio à utiliser.
     */
    AsGpio * gpio[8];

    void setBit(int index, LedColor color);

    void setBytes(uint hex, LedColor color);

    /*!
     * \brief Constructor.
     */
    LedDriver(int nb);

    /*!
     * \brief Destructor.
     */
    ~LedDriver();

};

#endif
