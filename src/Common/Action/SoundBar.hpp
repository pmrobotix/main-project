#ifndef SOUNDBAR_HPP_
#define SOUNDBAR_HPP_

#include <string>

#include "../../Log/LoggerFactory.hpp"
#include "AActionsElement.hpp"
#include "IAction.hpp"

class ASoundDriver;

/*!
 * \brief Enumération des libellés des actions de la barre de son.
 */
enum SoundBarActionName
{
    /*!
     * \brief Libellé de l'action permettant d'effectuer un beep.
     */
    SOUNDBARBEEP
};

class SoundBar: public AActionsElement
{
private:

    /*!
     * \brief Retourne le \ref Logger associé à la classe \ref SoundBar.
     */
    static inline const logs::Logger & logger()
    {
        static const logs::Logger & instance = logs::LoggerFactory::logger("SoundBar");
        return instance;
    }

    /*!
     * \brief Permet de stopper l'action et qu'elle se termine à la prochaine itération des actions.
     */
    bool actionStopped_;

    ASoundDriver* sounddriver_;

public:

    /*!
     * \brief Constructor.
     */
    SoundBar(Actions & actions);

    /*!
     * \brief Destructor.
     */
    ~SoundBar();

    inline bool stop() const
    {
        return actionStopped_;
    }

    /*!
     * \brief The Imperial March (Darth Vader's theme).
     */
    void toneImperialMarchDarthVader();

    /*!
     * \brief Prononce PMX.
     */
    void speakPMX();

    /*!
     * \brief Prononce un beep.
     */
    void beep();

    /*!
     * \brief Lance l'action d'effecter un beep.
     */
    void startBeep();

};

/*!
 * \brief Cette action permet de definir les actions pour donner des sons.
 *
 */
class SoundBarAction: public IAction
{
private:

    /*!
     * \brief Retourne le \ref Logger associé à la classe \ref SoundBarAction.
     */
    static const logs::Logger & logger()
    {
        static const logs::Logger & instance = logs::LoggerFactory::logger("SoundBarAction");
        return instance;
    }

    /*!
     * \brief Référence vers la SoundBar associée.
     */
    SoundBar & soundBar_;

    /*!
     * \brief libellé de l'action à exécuter.
     */
    SoundBarActionName action_;

public:

    /*!
     * \brief Constructeur de la classe.
     * \param ledBar
     *        Reference vers la SoundBar associée.
     */
    SoundBarAction(SoundBar & soundBar, SoundBarActionName action);

    /*!
     * \brief Destructeur de la classe.
     */
    virtual inline ~SoundBarAction()
    {
    }

    /*!
     * \brief Execution de l'action.
     */
    virtual bool execute();

    /*!
     * \brief Retourne la description de l'action.
     */
    virtual inline std::string info()
    {
        return "SoundBarAction";
    }
};

#endif
