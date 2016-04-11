#ifndef BYTE_H
#define BYTE_H

#include <QtWidgets/QWidget>



#include <QBitArray>

#include "debug.h"

namespace Ui {
class Byte;
}

class Byte : public QWidget
{
    Q_OBJECT
    
    public:
        explicit Byte(QWidget *parent = 0);
        ~Byte();

        void setNameByte(QString nameByte, int FontSize=38);    //FontSize = 38 jak jest jedna litera, FontSize = 10 jak jest napisa Maska
        void setOnlyByte(bool mode = true);  //tryb "OnlyByte" - tryb gdzie nie jest pokazywa nazwa bajtu ("A" lub "Maska")
        void firstBit (int firstBit = 0);   //od jakiego numeru ma sie zaczac numeracja danego bajtu. Czy pierwszy bajt ma miec numer 0, czy 8(gdy sa zlaczone dwa bajty)

        Byte& operator= (const QBitArray &x);
        Byte& operator= (const QString &x);
        void updateBit(int whichBit, bool value);

        int getByteAsInt(); //zwraca wartosc dziesietna bajtu
        QString getByteAsBin(); //zwraca wartosc binarna bajtu

        static QBitArray invertBits( QBitArray *byte = 0);

    private slots:
        void updateByte(int whichBit);
        void slot_updateByteGUI();  //aktualizuje wartosci na przyciskach na podstawie zmiennej byte (qbitaray)

    private:
        Ui::Byte *ui;

        bool *bit0;
        bool *bit1;
        bool *bit2;
        bool *bit3;
        bool *bit4;
        bool *bit5;
        bool *bit6;
        bool *bit7;

        bool onlyByte;

        int firstBitInt;

        QBitArray *byte;

    signals:
        void byteChanged(int whichBit);    //sygnal ktory bedzie wyemitowany, gdy zmieni sie ktorys z bitow.
        void byteChanged();    //sygnal ktory bedzie wyemitowany, gdy zmieni sie caly bajt jednoczesnie, np w operatorze przypisania zmieniaja sie jednoczesnie wszystkie bity za jednym razem.

};

#endif // BYTE_H
