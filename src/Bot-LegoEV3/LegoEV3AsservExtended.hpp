#ifndef LegoEV3_ASSERVEXTENDED_HPP_
#define LegoEV3_ASSERVEXTENDED_HPP_

#include <string>

#include "../Common/Asserv/Asserv.hpp"
#include "../Log/LoggerFactory.hpp"

class LegoEV3RobotExtended;

class LegoEV3AsservExtended: public Asserv
{
private:
    /*!
     * \brief Return \ref Logger linked to \ref LegoEV3AsservExtended.
     */
    static inline const logs::Logger& logger()
    {
        static const logs::Logger &instance = logs::LoggerFactory::logger("LegoEV3AsservExtended");
        return instance;
    }

    LegoEV3RobotExtended *pRobotExt_;

    int B3_is_taken;
    int B4_is_taken;
    int A5_is_taken;
    int D5_is_taken;
    int taken_max;

public:
    LegoEV3AsservExtended(std::string botId, LegoEV3RobotExtended *robot);

    ~LegoEV3AsservExtended()
    {
    }

    inline LegoEV3RobotExtended* getRobot()
    {
        return pRobotExt_;
    }

    //surcharged function
    void startMotionTimerAndOdo(bool assistedHandlingEnabled);

    bool filtre_IsInsideTableXY(int x_botpos_reperetable, int y_botpos_reperetable);

    bool filtre_IsInsideTable(int dist_detect_mm, int lateral_pos_sensor_mm, std::string desc = "");

//    void setLowSpeedForward(bool enable, int percent=30);
//    void setLowSpeedBackward(bool enable, int percent =30);
};

#endif

