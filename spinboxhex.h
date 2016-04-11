#ifndef SPINBOXHEX_H
#define SPINBOXHEX_H

#include <QtWidgets/QSpinBox>
#include "debug.h"
class QRegExpValidator;


class SpinBoxHex : public QSpinBox
{
	private:
		QRegExpValidator *validator;

	protected:
		QValidator::State validate(QString &text, int &pos) const;
		int valueFromText(const QString &text) const;
		QString textFromValue(int value) const;

	public:
		SpinBoxHex(QWidget *parent = 0);
		~SpinBoxHex();
};

#endif // SPINBOXHEX_H
