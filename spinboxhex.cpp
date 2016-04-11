#include "spinboxhex.h"

SpinBoxHex::SpinBoxHex(QWidget *parent):QSpinBox(parent)
{
	setRange(0, 65535);
	validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}

SpinBoxHex::~SpinBoxHex()
{

}

QString SpinBoxHex::textFromValue(int value) const
{
//    setStyleSheet(QString::fromUtf8("background-color: yellow;"));
	return QString::number(value, 16).toUpper();
}

int SpinBoxHex::valueFromText(const QString &text) const
{
	return text.toInt(0, 16);
}

QValidator::State SpinBoxHex::validate(QString &text, int &pos) const
{
	return validator->validate(text, pos);
}
