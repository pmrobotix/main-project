#ifndef COMMON_ASSERV_HPP_
#define COMMON_ASSERV_HPP_

#include <cmath>
#include <string>
#include <tuple>

#include "../../Log/LoggerFactory.hpp"
#include "../Interface.Driver/AAsservDriver.hpp"
#include "../Interface.Driver/ARobotPositionShared.hpp"

class AAsservDriver;
class AsservEsialR;
class Robot;

/*!
 * Asservissement of the robot.It contains default elements.
 */
class Asserv
{
private:

    /*!
     * \brief Return \ref Logger linked to \ref Asserv.
     */
    static inline const logs::Logger& logger()
    {
        static const logs::Logger &instance = logs::LoggerFactory::logger("Asserv");
        return instance;
    }

protected:

    /*!
     * \brief type d'asservissement utilisé
     * \0=Asserdriver 1=ESIAL internal 2=INSA internal (deprecated)
     */
    //int useAsservType_;
    enum AsservType
    {
        ASSERV_EXT, ASSERV_INT_ESIALR
    };

    AsservType useAsservType_;

    std::string botId_;

    AAsservDriver *asservdriver_;

    /*!
     * \brief asservissement interne ESIAL.
     * NULL si non defini
     */
    AsservEsialR *pAsservEsialR_;

    bool temp_ignoreRearCollision_;
    bool temp_ignoreFrontCollision_;
    bool temp_forceRotation_;

    //0=>LEFT with coordinate x, y, angle
    //1=>RIGHT with coordinate 3000-x, y , -angle
    bool matchColorPosition_;

    Robot *probot_; //reference du parent

    ROBOTPOSITION adv_pos_centre_;

    //automatic conversion
    int x_ground_table_;

    int lowSpeedvalue_;

public:

    /*!
     * \brief Constructor.
     *
     */
    Asserv(std::string botId, Robot *robot); //TODO robot is deprecated ?

    /*!
     * \brief Destructor.
     */
    virtual ~Asserv();

    //FONCTIONS DE BASE de l'ASSERV
    /*!
     * \brief reset Encoders.
     */
    void resetEncoders();
    /*!
     * \brief get accumulated ticks of encoders
     */
    void getEncodersCounts(int *countR, int *countL);
    /*!
     * \brief get delta ticks of encoders since last call.
     */
    void getDeltaEncodersCounts(int *deltaCountR, int *deltaCountL);
    /*!
     * \brief run Left Motor.
     * timems < 0 => use duty_cycle, run forever
     * timems = 0 => use speed (include internal regulation for lego)
     * timems > 0 => use speed with a running time (include internal regulation for lego)
     */
    void runMotorLeft(int power, int timems);
    /*!
     * \brief run Right Motor.
     * timems < 0 => use duty_cycle, run forever
     * timems = 0 => use speed (include internal regulation for lego)
     * timems > 0 => use speed with a running time (include internal regulation for lego)
     */
    void runMotorRight(int power, int timems);
    /*!
     * \brief stop Motors.
     */
    void stopMotors();

    //FONCTIONS SUPLLEMENTAIRES de l'ASSERV

    int getLowSpeedvalue();

    void setLowSpeedvalue(int value);

//    ROBOTPOSITION convertPositionToRepereTable(float d_mm, float x_mm, float y_mm, float theta_deg, float *x_botpos,
//            float *y_botpos);
    virtual bool filtre_IsInsideTableXY(int x_botpos, int y_botpos) = 0;

    virtual void endWhatTodo();

    //Gestion de l'asservissement
    virtual void startMotionTimerAndOdo(bool assistedHandlingEnabled);

    void setLowSpeedForward(bool enable, int percent = 0);
    virtual void setLowSpeedBackward(bool enable, int percent = 0);
    virtual void setPositionAndColor(float x_mm, float y_mm, float theta_degrees, bool matchColor); //matchColor = 0 =>en bas à gauche du log svg
    virtual void setPositionReal(float x_mm, float y_mm, float thetaInRad);

    virtual bool filtre_IsInsideTable(int dist_detect_mm, int lateral_pos_sensor_mm, std::string desc = ""); //TODO acorriger
    //virtual bool filtre_IsInFront(int threshold_mm, int dist_mm, int x_mm, int y_mm, float theta);
    //virtual bool filtre_IsInBack(int threshold_mm, int dist_mm, int x_mm, int y_mm, float theta);

    virtual void warnFrontCollisionOnTraj(int frontlevel, float x_adv__mm, float y_adv_mm); // X, Y dans le repère du robot
    virtual void warnBackCollisionOnTraj(int backlevel, float x_adv_mm, float y_adv_mm); // X, Y dans le repère du robot

    virtual void update_adv(); //TODO remove

    void resetEmergencyOnTraj(std::string message = "default");

    void setEmergencyStop();

    //modes d'arret de l'asservissement
    virtual void stopMotionTimerAndOdo();
    void disablePID(); //TODO deprecated ? utiliser pour activer la QuadRamp
    void freeMotion();
    void assistedHandling();

    ROBOTPOSITION pos_getAdvPosition();
    ROBOTPOSITION pos_getPosition();
    float pos_getX_mm();
    float pos_getY_mm();
    // angle in radian
    float pos_getTheta();
    // angle in degrees
    float pos_getThetaInDegree();

//FONCTIONS de DEPLACEMENT
    TRAJ_STATE gotoChain(float xMM, float yMM);
    TRAJ_STATE gotoXY(float xMM, float yMM);
    TRAJ_STATE gotoReverse(float xMM, float yMM);
    TRAJ_STATE gotoReverseChain(float xMM, float yMM);

    //relative motion (depends on current position of the robot)
    TRAJ_STATE doLineAbs(float dist_mm); // if distance <0, move backward
    TRAJ_STATE doRotateAbs(float degreesRelative);
    TRAJ_STATE doRelativeRotateBy(float thetaInDegreeRelative); //prend automatiquement un angle dans un sens ou dans l'autre suivant la couleur de match
    TRAJ_STATE doCalage(int d, int percent);
    TRAJ_STATE doCalage2(int d, int percent);
    //pivot motion
    void doRunPivotLeft(int powerL, int powerR, int timemsR);
    void doRunPivotRight(int powerL, int powerR, int timemsL);
    //absolute motion (coordinates thinking in the first color of match)
    TRAJ_STATE doFaceTo(float xMM, float yMM);
    TRAJ_STATE doAbsoluteRotateTo(float thetaInDegreeAbsolute, bool rotate_ignored = false);

    TRAJ_STATE doMoveForwardAndRotateTo(float xMM, float yMM, float thetaInDegree, bool rotate_ignored = false);
    TRAJ_STATE doMoveBackwardTo(float xMM, float yMM, bool rotate_ignored = false);
    TRAJ_STATE doMoveBackwardAndRotateTo(float xMM, float yMM, float thetaInDegree);
    TRAJ_STATE doMoveForwardTo(float xMM, float yMM, bool rotate_ignored = false, float adjustment = 0);

    //http://nains-games.com/2014/12/intersection-de-deux-cercles.html
    std::tuple<int, float, float> eq_2CirclesCrossed_getXY(float x1, float y1, float d1, float x2, float y2, float d2,
            float robot_size_l_mm);
    std::tuple<int, float, float> eq_2nd_deg_getXY(float a, float b, float A, float B, float C, float robot_size_l_mm);
    float eq_2nd_deg_getDelta(float A, float B, float C);

    /*!
     * pos_x_start_mm
     * pos_y_start_mm
     * p
     * delta_j_mm
     * delta_k_mm
     * mesure_mm
     * robot_size_l_mm largeur du robot à partir du centre
     */
    int adjustRealPosition(float pos_x_start_mm, float pos_y_start_mm, ROBOTPOSITION p, float delta_j_mm,
            float delta_k_mm, float mesure_mm, float robot_size_l_mm);

    //attention la couleur de match doit deja etre effectué !
    bool calculateDriftRightSideAndSetPos(float d2_theo_bordure_mm, float d2b_bordure_mm, float x_depart_mm,
            float y_depart_mm);
    bool calculateDriftLeftSideAndSetPos(float d2_theo_bordure_mm, float d2b_bordure_mm, float x_depart_mm,
            float y_depart_mm);

    void setMatchColorPosition(bool c)
    {
        matchColorPosition_ = c;
    }

    //transformation suivant la couleur de match
    inline float getRelativeX(float x_mm, float width = 0.0)
    {
        //printf("matchcolor:%d", matchColorPosition_);
        //logger().error() << "color==" << matchColorPosition_ << " width=" << width<< logs::end;
        if (matchColorPosition_ != 0) {
            return x_ground_table_ - x_mm - width;
        }
        return x_mm + width;
    }

    inline float getRelativeXMin(float x_mm, float width = 0.0)
    {
        //printf("matchcolor:%d", matchColorPosition_);
        //logger().error() << "color==" << matchColorPosition_ << " width=" << width<< logs::end;
        if (matchColorPosition_ != 0) {
            return x_ground_table_ - x_mm - width;
        }
        return x_mm;
    }

    inline float getRelativeAngleRad(float rad)
    {
        if (matchColorPosition_ != 0) {
            float limit = (M_PI - rad);

            limit = std::fmod(limit, 2.0 * M_PI);
            if (limit < -M_PI)
                limit += (2.0 * M_PI);
            if (limit > M_PI)
                limit -= (2.0 * M_PI);

            return limit;
        }
        return rad;
    }

    //transformation suivant la couleur de match
//    inline float getRelativeAngle(float degrees)
//    {
//        if (matchColorPosition_ != 0) {
//            float limit = (180.0 - degrees);
//
//            limit = std::fmod(limit, 360.0);
//            if (limit < -180.0)
//                limit += 360.0;
//            if (limit > 180.0)
//                limit -= 360.0;
//
//            return limit;
//        }
//        return degrees;
//    }

//    //TODO a tester
//    inline float limitAngle(float limit)
//    {
//        // On ajuste l'angle à parcourir pour ne pas faire plus d'un demi-tour
//        // Exemple, tourner de 340 degrés est plus chiant que de tourner de -20 degrés
//
//        limit = std::fmod(limit, 360);
//        if (limit < -180)
//            limit += 180;
//        if (limit > 180)
//            limit -= 180;
////        if (degrees >= 180) {
////            degrees -= 2.0 * 180;
////        }
////        else if (degrees < -180) {
////            degrees += 2.0 * 180;
////        }
//        return limit;
//    }


    inline float degToRad(float deg)
    {
        return deg * M_PI / 180.0;
    }

    inline float radToDeg(float rad)
    {
        return rad * 180.0 / M_PI;
    }
};

#endif
