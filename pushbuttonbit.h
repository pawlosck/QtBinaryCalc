#ifndef PUSHBUTTONBIT_H
#define PUSHBUTTONBIT_H

#include <QtWidgets/QPushButton>


class PushButtonBit : public QPushButton
{

    Q_OBJECT

    private:
        bool bit;       //Wartosc bitu. 0 lub 1
        int numberBit;  //ktory bit reprezentuje ten przycisk. Wartosc od 0 do 7

    public:
        PushButtonBit(QWidget *parent = 0);
        ~PushButtonBit();
		void setNumberBit(int numberBit);
		void setValueBit( bool  bit );
		bool getValueBit();
		int getNumberBit();

    private slots:
        void slot_pushButtonBit_clicked();



	signals:
		void clicked(int whichBit);
        void bitChanged();
};

#endif // PUSHBUTTONBIT_H
