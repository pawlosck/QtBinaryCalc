#ifndef NUMBERS_H
#define NUMBERS_H

#include <QtWidgets/QWidget>
#include "spinboxhex.h"
#include "byte.h"
#include <QtWidgets/QLabel>
#include "asciispinbox.h"
#include <QtWidgets/QPushButton>
#include "asciiwidget.h"

#include "debug.h"


namespace Ui {
class Numbers;
}

class Numbers : public QWidget
{
    Q_OBJECT

    public:
        explicit Numbers(QWidget *parent = 0);
        ~Numbers();

		int getBytesAsDec();    //funkcja ktora podaje wartosc dziesietna pobrana z obu bajtow, czyli moze zwracac wartosc od 0-65535
		QString getBytesAsBin();    //funkcja ktora podaje wartosc binarna pobrana z obu bajtow, czyli moze zwracac wartosc od 0-1111111111111111

		void setNameByte(QString nameByte, int fontSize = 38);



    private:
        Ui::Numbers *ui;

        Byte *byteA1;   //bajt A bity od 0 do 7
        Byte *byteA2;   //bajt A bity od 8 do 15

        SpinBoxHex *hexNumber;
        QLabel *hexLabel;

        QSpinBox *decNumber;
        QLabel *decLabel;

        AsciiSpinBox *asciiNumberLeft;
        QLabel *asciiLabelLeft;
        QPushButton *asciiButtonLeft;

        AsciiSpinBox *asciiNumberRight;
		QLabel *asciiLabelRight;
        QPushButton *asciiButtonRight;

        AsciiWidget *asciiWidgetLeft;
        AsciiWidget *asciiWidgetRight;

		QString nameByte;		//Nazwa bajtu. Moga to byc wartosci A, B lub maska



    private slots:
		void slot_test(QString text);
		void slot_test(int text);
		void slot_asciiButtonLeft_clicked();
		void slot_asciiButtonRight_clicked();

		void slot_updateAsciiCodeGUILeft(int asciiCode);    //wywoluje sie, gdy nacisnie sie pushbutton w asciiwidget
		void slot_updateAsciiCodeGUIRight(int asciiCode);

		void slot_updateAsciiSpinBoxGUILeft(int asciiCode);
		void slot_updateAsciiSpinBoxGUIRight(int asciiCode);

		void slot_updateByteGUI(int whichBit); //slot ktory sie wywola, gdy sie zmieni jakis bit w obiekcie byte (signal byteChanged(whichBit))
		void slot_updateByteGUI(); //slot ktory sie wywola, gdy zmienia sie wszystkie bity w obiekcie byte (signal byteChanged())

		void slot_updateDecNumberGUI(int asciiCode);    //slot ktory bedzie wywolywany, gdy sie zmieni wartossc w qspinbox decNumber

		void slot_updateHexNumberGUI(int asciiCode);    //slot ktory bedzie wywolywany, gdy sie zmieni wartossc w qspinbox hexNumber

    public slots:
		void slot_setValue(int number);				//Ustawia we wszystkich obiektach ta sama wartosc. Potrzebne to jest do oobiektu numberResult


	signals:
	   void valueChanged(QString bits);
	   void valueChanged(int number);


};

#endif // NUMBERS_H
