//drivers...EV3

#include "SwitchDriver.hpp"

#include <mutex>
#include <string>

#include "../Log/Logger.hpp"
#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

ASwitchDriver* ASwitchDriver::create(std::string botName)
{
    static SwitchDriver *instance = new SwitchDriver();
    return instance;
}

SwitchDriver::SwitchDriver()
{
    /*
     string input = "ev3-ports:in3:i2c81:mux2"; //avec MUX

     logger().debug() << "TOUCH MUX has to be set to lego-ev3-touch" << logs::end;
     lego_port p = lego_port(input);

     logger().debug() << "p.connected()=" << p.connected() << logs::end;

     //Dans le cas d'un MUX connecté
     if (p.connected()) {

     int todo = 0;
     string temp = "nop";

     try {
     //temp = p.get_attr_string("ev3-ports:in3:i2c81:mux2:lego-ev3-color/modalias");
     temp = p.get_attr_string(string(input + string(":lego-ev3-color/modalias")));

     logger().debug() << "exist driver temp ==  " << temp << logs::end;
     }
     catch (...) {
     //logger().error() << "SwitchDriver()  access to " << temp << logs::end;
     }

     if (temp != "nop") todo = 1;

     if (todo == 0) {
     logger().debug() << "port already set to lego-ev3-touch on " << p.address() << logs::end;
     }
     else {

     logger().debug() << "set uart and device=lego-ev3-touch on " << p.address() << logs::end;

     p.set_mode("analog"); //TOUCH ev3-analog
     usleep(10000);
     p.set_set_device("lego-ev3-touch");
     usleep(500000);

     //verif ev3-ports:in3:i2c81:mux2:lego-ev3-touch
     temp = p.get_attr_string(string(input + string(":lego-ev3-touch/modalias")));
     logger().debug() << "VERIF driver lego-ev3-touch temp ==  " << temp << logs::end;
     }
     }*/

    /*
     //string input = "ev3-ports:in1"; //before
     string input = "ev3-ports:in4";
     touch_ = touch_sensor(input);

     //cas NON MUX
     //touch_ = touch_sensor(INPUT_AUTO);

     if (touch_.connected()) {
     logger().debug() << touch_.type_name() << " connected (device " << touch_.driver_name() << ", port "
     << touch_.address() << ", mode " << touch_.mode() << ")" << logs::end;
     } else {
     logger().error() << "INPUT_1 (Tirette) not Connected !!" << logs::end;
     }

     */

    if (is_connected()) {

    } else {
        logger().error() << "INPUT_4 (Tirette) not Connected !!" << logs::end;
    }

}

bool SwitchDriver::is_connected()
{
    //return touch_.connected();
    return legotouchposix_.connected();
}

SwitchDriver::~SwitchDriver()
{

}
//
//int SwitchDriver::tirettePressedFiltered()
//{
//    int tirettePressedFiltered();
//
//}

int SwitchDriver::tirettePressed()
{
    //std::this_thread::sleep_for(std::chrono::microseconds(100000));
    int v;
    lock();
    v = legotouchposix_.custom_get_value();
    unlock();
    return v;

    /*
     //Sleep obligatoire sur le bouton LEGO, si le temps est très court (1ms),pd de thread qui crashe
     //std::this_thread::sleep_for(std::chrono::microseconds(300000)); // 250000
     std::this_thread::sleep_for(std::chrono::microseconds(300000));

     return touch_.value();
     //if (touch_.connected()) { //TEST 20230911 de retirer ce test pour alléger le touch
     //    if (touch_.value() == 1) //in case of MUX : 257
     //    {
     //        return 1;
     //    } else if (touch_.value() == 0) { //in case of MUX : 256
     //        return 0;
     //    } else {
     //        return -1;
     //    }
     //    } else {
     //        return -2;
     //    }

     */
}

int SwitchDriver::backLeftPressed()
{
    return 0;
}
int SwitchDriver::backRightPressed()
{
    return 0;
}

//int SwitchDriver::pressed(unsigned char pin) {
//    return 0;
//}

void SwitchDriver::setGPIO(int gpio, bool activate)
{

}
