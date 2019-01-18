#ifndef TAPELETTER_HPP
#define TAPELETTER_HPP
#include <QPlainTextEdit>
#include <QObject>
/**
 * @brief A class which represents a letter on the tape.
 */
class TapeLetter : public QTextEdit
{
	Q_OBJECT
	public:
		TapeLetter(QWidget *parent = Q_NULLPTR);
        ~TapeLetter() = default;

        /**
         * @brief Displays the given letter
         * @param The letter to display
         */
        void DisplayLetter(char c);

        /**
         * @brief Displays the given letter
         * @param The letter to display
         */
        void DisplayLetter(QString c);
};
#endif // TAPELETTER_HPP
