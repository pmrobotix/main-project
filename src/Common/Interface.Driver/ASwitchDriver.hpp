#ifndef ASWITCHDRIVER_HPP_
#define ASWITCHDRIVER_HPP_

#include <string>

class ASwitchDriver
{

public:
    /*!
     * \brief SwitchDriver instance creation.
     */
    static ASwitchDriver * create(std::string);

    virtual bool is_connected() = 0;
    /*
     *\brief pressed pour la tirette
     */
    virtual int tirettePressed() = 0;
    virtual int backLeftPressed()= 0;
    virtual int backRightPressed()= 0;

    virtual void setGPIO(int gpio, bool activate) = 0;

    //virtual int pressed(unsigned char pin) = 0;

    /*!
     * \brief Destructor.
     */
    virtual ~ASwitchDriver()
    {
    }

protected:

    /*!
     * \brief Constructor.
     */
    ASwitchDriver()
    {
    }

};

#endif
