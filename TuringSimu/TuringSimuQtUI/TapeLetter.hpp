#ifndef TAPELETTER_HPP
#define TAPELETTER_HPP
#include <QPlainTextEdit>
#include <QObject>

class TapeLetter : public QTextEdit
{
	Q_OBJECT
	public:
		TapeLetter(QWidget *parent = Q_NULLPTR);
	void DisplayLetter(char c);
	void DisplayLetter(QString c);
	~TapeLetter() = default;
};
#endif // TAPELETTER_HPP
