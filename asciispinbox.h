#ifndef ASCIISPINBOX_H
#define ASCIISPINBOX_H

#include <QtWidgets/QSpinBox>


class AsciiSpinBox : public QSpinBox
{
	public:
		AsciiSpinBox(QWidget *parent = 0);
		~AsciiSpinBox();
	private slots:
		void focusInEvent ( QFocusEvent * event );


    private:
        QRegExpValidator *validator;

    protected:
        QValidator::State validate(QString &text, int &pos) const;
        int valueFromText(const QString &text) const;
        QString textFromValue(int value) const;


};

#endif // QLICZNIKDOL_H
