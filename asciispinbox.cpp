#include "asciispinbox.h"
#include "asciiwidget.h"
#include <QTextCodec>

AsciiSpinBox::AsciiSpinBox(QWidget *parent):QSpinBox(parent)
{
    setRange(0, 255);

    QFont font;
    font.setFamily("arial");
    font.setBold(false);
    font.setPointSize(12);

    this->setFont(font);
}

AsciiSpinBox::~AsciiSpinBox()
{

}

void AsciiSpinBox::focusInEvent ( QFocusEvent * event )
{

}

QString AsciiSpinBox::textFromValue(int value) const
{
    char asciiLetter[2];
    asciiLetter[0] = value;
    asciiLetter[1] = '\0';
    QTextCodec* codec = QTextCodec::codecForName("IBM 850");
    QString str = codec->toUnicode(asciiLetter);

    if( ( value >= 0 && value <= 31 ) || value == 127)
    {
        return AsciiWidget::asciiControlCharacters(value);
    }
    else
    {
        return str;
    }
}

int AsciiSpinBox::valueFromText(const QString &text) const
{


    for (int i = 0 ; i < 256 ; i++)
    {
        char asciiLetter[2];
        asciiLetter[0] = i;
        asciiLetter[1] = '\0';
        QTextCodec* codec = QTextCodec::codecForName("IBM 850");
        QString str = codec->toUnicode(asciiLetter);

        if ( text == str)
        {
            return i;
        }

    }
    return 0;
}

QValidator::State AsciiSpinBox::validate(QString &text, int &pos) const
{
    return QValidator::Acceptable;
}

