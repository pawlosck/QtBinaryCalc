#include "numbers.h"
#include "ui_numbers.h"
#include "asciispinbox.h"
#include "asciiwidget.h"
#include "byte.h"
#include "QApplication"
#include <stdlib.h>

Numbers::Numbers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Numbers)
{
    ui->setupUi(this);

	this->setFixedSize(760,50);


    byteA1 = new Byte(this);
    byteA1->show();
    byteA1->setNameByte("A");
    byteA1->move(0,0);
    byteA1->firstBit(8);

    byteA2 = new Byte(this);
    byteA2->show();
	byteA2->setNameByte("A");
    byteA2->setOnlyByte(true);
	byteA2->move(byteA1->pos().x() + 250 + 1, byteA1->pos().y());
    byteA2->firstBit(0);

    //////////////////
//DEC SPINBOX
    this->decNumber = new QSpinBox(this);
    this->decNumber->setRange(0, 65535);
	decNumber->setGeometry(460, 0, 65, 25);

    QFont fontDecNumber;
    fontDecNumber.setPointSize(10);
    fontDecNumber.setBold(false);
    decNumber->setFont(fontDecNumber);
    //////////////////
//DEC LABEL
    this->decLabel = new QLabel("Dec", this);
	decLabel->setGeometry(460, 25, 65, 25);

    QFont fontDecLabel;
    fontDecLabel.setPointSize(10);
    fontDecLabel.setBold(true);
    decLabel->setFont(fontDecLabel);
    //////////////////
//HEX SPINBOX
    this->hexNumber = new SpinBoxHex(this);
	hexNumber->setGeometry(525, 0, 65, 25);

    QFont fontHexNumber;
    fontHexNumber.setPointSize(10);
    fontHexNumber.setBold(false);
    hexNumber->setFont(fontHexNumber);
    //////////////////
//HEX LABEL
    this->hexLabel = new QLabel("Hex", this);
	hexLabel->setGeometry(525, 25, 65, 25);

    QFont fontHexLabel;
    fontHexLabel.setPointSize(10);
    fontHexLabel.setBold(true);
    hexLabel->setFont(fontHexLabel);
    //////////////////
//ASCII SPINBOX LEFT
    this->asciiNumberLeft = new AsciiSpinBox(this);
	asciiNumberLeft->setGeometry(590, 0, 65, 25);

    QFont fontAsciiNumberLeft;
    fontAsciiNumberLeft.setPointSize(10);
    fontAsciiNumberLeft.setBold(false);
    asciiNumberLeft->setFont(fontAsciiNumberLeft);
    //////////////////
//ASCII LABEL LEFT
    this->asciiLabelLeft = new QLabel("Ascii Left", this);
	asciiLabelLeft->setGeometry(590, 25, 85, 25);

    QFont fontAsciiLabelLeft;
    fontAsciiLabelLeft.setPointSize(10);
    fontAsciiLabelLeft.setBold(true);
    this->asciiLabelLeft->setFont(fontAsciiLabelLeft);

//ASCII BUTTON LEFT
    this->asciiButtonLeft = new QPushButton(this);
    this->asciiButtonLeft->show();
	this->asciiButtonLeft->setGeometry(655, 0, 20,25);
    this->asciiButtonLeft->setText("^");

    //////////////////
//ASCII SPINBOX RIGHT
    this->asciiNumberRight = new AsciiSpinBox(this);
	this->asciiNumberRight->setGeometry(675, 0, 65, 25);

    QFont fontAsciiNumberRight;
    fontAsciiNumberRight.setPointSize(10);
    fontAsciiNumberRight.setBold(false);
    asciiNumberRight->setFont(fontAsciiNumberRight);
    //////////////////
//ASCII LABEL RIGHT
    this->asciiLabelRight = new QLabel("Ascii Right", this);
	asciiLabelRight->setGeometry(675, 25, 85, 25);

    QFont fontAsciiLabelRight;
    fontAsciiLabelRight.setPointSize(10);
    fontAsciiLabelRight.setBold(true);
    this->asciiLabelRight->setFont(fontAsciiLabelRight);

//ASCII BUTTON RIGHT
    this->asciiButtonRight = new QPushButton(this);
    this->asciiButtonRight->show();
	this->asciiButtonRight->setGeometry(740, 0, 20,25);
    this->asciiButtonRight->setText("^");

    *this->byteA1 = "0000000";
    *this->byteA2 = "0000000";



    this->asciiWidgetLeft = new AsciiWidget();
    this->asciiWidgetRight = new AsciiWidget();
//    this->asciiWidgetLeft->setPointerNumbers(this);

    connect(this->asciiButtonLeft, SIGNAL(clicked()), this, SLOT(slot_asciiButtonLeft_clicked()));
    connect(this->asciiButtonRight, SIGNAL(clicked()), this, SLOT(slot_asciiButtonRight_clicked()));

    connect(this->asciiWidgetLeft, SIGNAL(clicked(int)), this, SLOT(slot_updateAsciiCodeGUILeft(int)));
    connect(this->asciiWidgetRight, SIGNAL(clicked(int)), this, SLOT(slot_updateAsciiCodeGUIRight(int)));

    connect(this->asciiNumberLeft, SIGNAL(valueChanged(int)), this, SLOT(slot_updateAsciiSpinBoxGUILeft(int)));
    connect(this->asciiNumberRight, SIGNAL(valueChanged(int)), this, SLOT(slot_updateAsciiSpinBoxGUIRight(int)));

    connect(this->byteA1, SIGNAL(byteChanged(int)), this, SLOT(slot_updateByteGUI(int)));
    connect(this->byteA2, SIGNAL(byteChanged(int)), this, SLOT(slot_updateByteGUI(int)));

    connect(this->byteA1, SIGNAL(byteChanged()), this, SLOT(slot_updateByteGUI()));
    connect(this->byteA2, SIGNAL(byteChanged()), this, SLOT(slot_updateByteGUI()));

    connect(this->decNumber, SIGNAL(valueChanged(int)), this, SLOT(slot_updateDecNumberGUI(int)));

    connect(this->hexNumber, SIGNAL(valueChanged(int)), this, SLOT(slot_updateHexNumberGUI(int)));

    connect(this, SIGNAL(valueChanged(int)), this, SLOT( slot_setValue(int)) );



}

Numbers::~Numbers()
{
    delete ui;

    delete byteA1;
    delete byteA2;

    delete hexNumber;
    delete hexLabel;

    delete decNumber;
    delete decLabel;

    delete asciiNumberLeft;
    delete asciiLabelLeft;
    delete asciiButtonLeft;

    delete asciiNumberRight;
    delete asciiLabelRight;
    delete asciiButtonRight;

    delete asciiWidgetLeft;
    delete asciiWidgetRight;
}

//jak sie nacisnie przycisk przy lewym asciispinbox, to sie otworzy obiekt klasy asciiwidget
void Numbers::slot_asciiButtonLeft_clicked()
{
    this->asciiWidgetLeft->show();
    this->asciiWidgetLeft->setGeometry(
                QCursor::pos().x(),
                QCursor::pos().y(),
                15,
                25);

}

//Wcisniety prawy przycisk wywolujacy asciiwidget. przycisk obok prawego asciispinbox
void Numbers::slot_asciiButtonRight_clicked()
{
    this->asciiWidgetRight->show();
    this->asciiWidgetRight->setGeometry(
                QCursor::pos().x(),
                QCursor::pos().y(),
                15,
                25);

}
//nacisniecie znaku ascii (pushbuttonbit) w asciiwidget otwartym z przycsku obok lewegoasciispinvbox
//Po nacisnieciu przycisku w asciiwidget, zamyka sie asciiwidget i nastepnie uaktualniaja sie pozostale pola (decnumberspinbox, hexnumberspinbox itd)
void Numbers::slot_updateAsciiCodeGUILeft(int asciiCode)
{
    *this->byteA1 = QString::number(asciiCode,2);

    this->decNumber->blockSignals(true);
    this->hexNumber->blockSignals(true);
    this->asciiNumberLeft->blockSignals(true);
    this->asciiNumberRight->blockSignals(true);


    this->decNumber->setValue(this->getBytesAsDec());
    this->hexNumber->setValue(this->getBytesAsDec());
    this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());
    this->asciiNumberRight->setValue(this->byteA2->getByteAsInt());


    this->decNumber->blockSignals(false);
    this->hexNumber->blockSignals(false);
    this->asciiNumberLeft->blockSignals(false);
    this->asciiNumberRight->blockSignals(false);

	emit valueChanged(this->getBytesAsBin());
	emit valueChanged(this->getBytesAsDec());
}

//nacisniecie znaku ascii (pushbuttonbit) w asciiwidget, otwartym z przycsku obok prawego asciispinvbox
//Po nacisnieciu przycisku w asciiwidget, zamyka sie asciiwidget i nastepnie uaktualniaja sie pozostale pola (decnumberspinbox, hexnumberspinbox itd)
void Numbers::slot_updateAsciiCodeGUIRight(int asciiCode)
{
    *this->byteA2 = QString::number(asciiCode,2);

    this->decNumber->blockSignals(true);
    this->hexNumber->blockSignals(true);
    this->asciiNumberLeft->blockSignals(true);
    this->asciiNumberRight->blockSignals(true);


    this->decNumber->setValue(this->getBytesAsDec());
    this->hexNumber->setValue(this->getBytesAsDec());
    this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());
    this->asciiNumberRight->setValue(this->byteA2->getByteAsInt());


    this->decNumber->blockSignals(false);
    this->hexNumber->blockSignals(false);
    this->asciiNumberLeft->blockSignals(false);
    this->asciiNumberRight->blockSignals(false);

	emit valueChanged(this->getBytesAsBin());
	emit valueChanged(this->getBytesAsDec());
}

void Numbers::slot_updateAsciiSpinBoxGUILeft(int asciiCode)
{
    *this->byteA1 = QString::number(asciiCode,2);

    this->decNumber->blockSignals(true);
    this->hexNumber->blockSignals(true);
//    this->asciiNumberLeft->blockSignals(true);
    this->asciiNumberRight->blockSignals(true);


    this->decNumber->setValue(this->getBytesAsDec());
    this->hexNumber->setValue(this->getBytesAsDec());
//    this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());
    this->asciiNumberRight->setValue(this->byteA2->getByteAsInt());


    this->decNumber->blockSignals(false);
    this->hexNumber->blockSignals(false);
//        this->asciiNumberLeft->blockSignals(false);
    this->asciiNumberRight->blockSignals(false);

	emit valueChanged(this->getBytesAsBin());
	emit valueChanged(this->getBytesAsDec());
}

void Numbers::slot_updateAsciiSpinBoxGUIRight(int asciiCode)
{
    *this->byteA2 = QString::number(asciiCode,2);

    this->decNumber->blockSignals(true);
    this->hexNumber->blockSignals(true);
    this->asciiNumberLeft->blockSignals(true);


    this->decNumber->setValue(this->getBytesAsDec());
    this->hexNumber->setValue(this->getBytesAsDec());
    this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());


    this->decNumber->blockSignals(false);
    this->hexNumber->blockSignals(false);
    this->asciiNumberLeft->blockSignals(false);


	emit valueChanged(this->getBytesAsBin());
	emit valueChanged(this->getBytesAsDec());
}

void Numbers::slot_updateByteGUI(int whichBit) //slot ktory jest uruchamiany, gdy zmieni sie ktorys z bitow w zmiennej byte (klasa Byte - klasa w ktorej poszczegolne bity reprezentowane sa przez pushbuttony)
{
    SHOWVALUE(this->byteA1->getByteAsBin(), this->byteA1->getByteAsBin());
    SHOWVALUE(this->byteA2->getByteAsBin(), this->byteA2->getByteAsBin());

    QString byteA1AndA2QString = this->byteA1->getByteAsBin() + this->byteA2->getByteAsBin();

    SHOWVALUE(this->byteA1->getByteAsBin(), this->byteA1->getByteAsBin());
    SHOWVALUE(this->byteA2->getByteAsBin(), this->byteA2->getByteAsBin());

    SHOWVALUE(this->byteA1->getByteAsInt(), this->byteA1->getByteAsInt());
    SHOWVALUE(this->byteA2->getByteAsInt(), this->byteA2->getByteAsInt());

    SHOWVALUE(byteA1AndA2QString.toInt(2), byteA1AndA2QString.toInt(0, 2));

    this->decNumber->setValue(byteA1AndA2QString.toInt(0,2));
    this->hexNumber->setValue(byteA1AndA2QString.toInt(0,2));
    this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());
    this->asciiNumberRight->setValue(this->byteA2->getByteAsInt());

	emit valueChanged(this->getBytesAsBin());
	emit valueChanged(this->getBytesAsDec());
}

void Numbers::slot_updateByteGUI()
{

}

void Numbers::slot_updateDecNumberGUI(int asciiCode)
{
        this->hexNumber->blockSignals(true);
        this->asciiNumberLeft->blockSignals(true);
        this->asciiNumberRight->blockSignals(true);

    QString asciiCodeBinQString = QString::number(asciiCode, 2);

    *this->byteA1 = "00000000";
    if(asciiCode <= 255)
    {

        *this->byteA2 = asciiCodeBinQString;
        SHOWVALUE (asciiCodeBinQString, asciiCodeBinQString);
    }
    else
    if(asciiCode > 255 && asciiCode <= 65535)//liczba binarnie zajmuje wiecej niz 8 bitow 255=8bitow. liczba zajmuje mniej niz 65535=16bitow(2xbyte)
    {

        *this->byteA2 = asciiCodeBinQString.right(8);

        QString byteA1QString = asciiCodeBinQString.left(asciiCodeBinQString.count()-8);
        QBitArray byteA1QBitArray;
        byteA1QBitArray.resize(byteA1QString.count());
        byteA1QBitArray.fill(0);
        for(int i = 0 ; i < byteA1QString.count() ; i++)
        {
            byteA1QBitArray.setBit(i, byteA1QString.at(i).digitValue() );
        }
        byteA1QBitArray = Byte::invertBits(&byteA1QBitArray);
        *this->byteA1 = byteA1QBitArray;
    }

    this->hexNumber->setValue(this->getBytesAsDec());
    this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());
    this->asciiNumberRight->setValue(this->byteA2->getByteAsInt());


    this->hexNumber->blockSignals(false);
    this->asciiNumberLeft->blockSignals(false);
    this->asciiNumberRight->blockSignals(false);

	emit valueChanged(this->getBytesAsBin());
	emit valueChanged(this->getBytesAsDec());

}

void Numbers::slot_updateHexNumberGUI(int asciiCode)
{
            this->decNumber->blockSignals(true);
            this->asciiNumberLeft->blockSignals(true);
            this->asciiNumberRight->blockSignals(true);

        QString asciiCodeBinQString = QString::number(asciiCode, 2);

        *this->byteA1 = "00000000";
        if(asciiCode <= 255)
        {

            *this->byteA2 = asciiCodeBinQString;
            SHOWVALUE (asciiCodeBinQString, asciiCodeBinQString);
        }
        else
        if(asciiCode > 255 && asciiCode <= 65535)//liczba binarnie zajmuje wiecej niz 8 bitow 255=8bitow. liczba zajmuje mniej niz 65535=16bitow(2xbyte)
        {

            *this->byteA2 = asciiCodeBinQString.right(8);

            QString byteA1QString = asciiCodeBinQString.left(asciiCodeBinQString.count()-8);
            QBitArray byteA1QBitArray;
            byteA1QBitArray.resize(byteA1QString.count());
            byteA1QBitArray.fill(0);
            for(int i = 0 ; i < byteA1QString.count() ; i++)
            {
                byteA1QBitArray.setBit(i, byteA1QString.at(i).digitValue() );
            }
            byteA1QBitArray = Byte::invertBits(&byteA1QBitArray);
            *this->byteA1 = byteA1QBitArray;
        }

        this->decNumber->setValue(this->getBytesAsDec());
        this->asciiNumberLeft->setValue(this->byteA1->getByteAsInt());
        this->asciiNumberRight->setValue(this->byteA2->getByteAsInt());


        this->decNumber->blockSignals(false);
        this->asciiNumberLeft->blockSignals(false);
        this->asciiNumberRight->blockSignals(false);


		emit valueChanged(this->getBytesAsBin());
		emit valueChanged(this->getBytesAsDec());


}

QString Numbers::getBytesAsBin()
{
    QString byteA1AndA2BinQString;
    byteA1AndA2BinQString = this->byteA1->getByteAsBin() + this->byteA2->getByteAsBin();

    return byteA1AndA2BinQString;
}

int Numbers::getBytesAsDec()
{
    return this->getBytesAsBin().toInt(0, 2);
}

void Numbers::setNameByte(QString nameByte, int fontSize)
{
	this->nameByte = nameByte;
	this->byteA1->setNameByte(nameByte, fontSize);
	this->byteA2->setNameByte(nameByte, fontSize);


}

//Funkcja ktora ustawia zadana wartosc we wszystkich obiektach (dec, hex, ascii itp).
//Wystarczy ustawic wartosc dla jednego obiektu, a reszte zalatwiaja sygnaly, ktore wywoluja odpowiednie sloty,
//ktore modyfikuja pozostale obiekty
void Numbers::slot_setValue(int number)
{
	this->decNumber->setValue(number);
}


void Numbers::slot_test(QString text)
{
	SHOWONLYVALUE(text);
}

void Numbers::slot_test(int text)
{
	SHOWONLYVALUE(text);
}
