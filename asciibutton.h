#ifndef ASCIIBUTTON_H
#define ASCIIBUTTON_H

#include <QtWidgets/QPushButton>

class AsciiButton : public QPushButton
{

    Q_OBJECT




    private:
		int asciiCode;
		QRect geometryBeforeEnter;
		int sizeLetter;
        QFont normalFont;   //font jaki normalnie widoczny, gdy nie najedzie sie na niego mycha
        QFont markedFont;   //font jaki jest widoczny, gdy najedzie sie na niego mycha

	public:
		AsciiButton(QWidget *parent = 0);
		~AsciiButton();

		void setCode(int code);
		void setSizeLetter(int size);

	private slots:
        void on_asciiButton_clicked();
		void enterEvent(QEvent *event);
		void leaveEvent(QEvent *event);


    signals:
        void clicked(int asciiCode);


};

#endif // ASCIIBUTTON_H
