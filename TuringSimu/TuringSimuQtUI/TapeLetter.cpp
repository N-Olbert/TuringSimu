#include "TapeLetter.hpp"


TapeLetter::TapeLetter(QWidget *parent)
{
	setReadOnly(true);
	setUndoRedoEnabled(false);
	setMaximumHeight(32);
	setMaximumWidth(32);
	setSizePolicy(QSizePolicy{QSizePolicy::Fixed, QSizePolicy::Fixed});
	QFont font;
	font.setFamily(QString::fromUtf8("Segoe UI"));
	font.setPointSize(14);
	font.setBold(true);
	font.setWeight(75);
	setFont(font);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	auto textBlockFormat = textCursor().blockFormat();
	textBlockFormat.setAlignment(Qt::AlignCenter);
	textCursor().mergeBlockFormat(textBlockFormat);
}

void TapeLetter::DisplayLetter(char c)
{
	DisplayLetter(QString{ c });
}

void TapeLetter::DisplayLetter(QString c)
{
	clear();
	append(c);
}

