#ifndef ACTIONS_HPP_
#define ACTIONS_HPP_

#include <string>

#include "../../Log/Logger.hpp"
#include "../../Log/LoggerFactory.hpp"
#include "ActionManagerTimer.hpp"
#include "LedBar.hpp"

class IAction;

/*!
 * List of robot actions. It contains all common RobotElement.
 */
class Actions
{
private:

    /*!
     * \brief Return \ref Logger linked to \ref Actions.
     */
    static inline const logs::Logger& logger()
    {
        static const logs::Logger &instance = logs::LoggerFactory::logger("Actions");
        return instance;
    }

    /*!
     * \brief Assure la gestion des actions/timers du robot en mode asynchrone.
     */
    ActionManagerTimer actionManagerTimer_;

public:

    /*!
     * \brief Constructor.
     *
     */
    Actions();

    /*!
     * \brief Destructor.
     */
    ~Actions()
    {
    }

    /*!
     * \brief Ajout d'une action.
     * \param action
     *        L'action à ajouter.
     */
    inline void addAction(IAction *action)
    {
        if (!this->is_started()) {
            logger().error() << "addAction ACTIONTIMER NOT STARTED !!" << logs::end;
        }
        actionManagerTimer_.addAction(action);
    }

    inline void addTimer(ITimerListener *timer)
    {
        if (!this->is_started()) {
            logger().error() << "addTimer ITimerListener ACTIONTIMER NOT STARTED !!" << logs::end;
        }
        actionManagerTimer_.addTimer(timer);
    }

    inline void addTimer(ITimerPosixListener *timer)
    {
        if (!this->is_started()) {
            logger().error() << "addTimerITimerPosixListener ACTIONTIMER NOT STARTED !!" << logs::end;
        }
        actionManagerTimer_.addTimer(timer);
    }

    inline void stopTimer(std::string name)
    {
        actionManagerTimer_.stopTimer(name);
    }

    inline void stopPTimer(std::string name)
    {
        actionManagerTimer_.stopPTimer(name);
    }

    inline bool findPTimer(std::string name)
    {
        return actionManagerTimer_.findPTimer(name);
    }

    /*!
     * \brief Active les actions.
     *
     * Cette méthode lance le thread gérant le ActionManager.
     */
    void start();

    bool is_started();

    /*!
     * \brief supprime toutes les actions et les timers.
     */
    void clearAll();
    /*!
     * \brief Arrete le thread sensorManager et actionManager.
     */
    void waitAndStopManagers();

    /*!
     * \brief Annule le thread en cours.
     */
    void cancel();

};

#endif
