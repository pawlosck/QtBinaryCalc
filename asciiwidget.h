#ifndef ASCIIWIDGET_H
#define ASCIIWIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <asciibutton.h>

class Numbers;

namespace Ui {
	class AsciiWidget;
}

class AsciiWidget : public QWidget
{
		Q_OBJECT
		
	public:
		explicit AsciiWidget(QWidget *parent = 0);
		~AsciiWidget();

        void setPointerNumbers (Numbers *numbersObject);
        static  QString asciiControlCharacters (int asciiCode, bool name = false);	//parametr name - jak true, to zwraca nazwe znaku ascii np "DELETE",jak ma wartosc false, to zwraca skrot np: "DEL"

		
	private:
		Ui::AsciiWidget *ui;

		AsciiButton *asciiCode;
        Numbers *pointerNumbersObject;

    private slots:
        void keyPressEvent ( QKeyEvent * event );
        bool event(QEvent* aEvent);
        void slot_asciiButton_clicked(int asciiCode);

    signals:
        void clicked(int asciiCode);
};

#endif // ASCIIWIDGET_H
