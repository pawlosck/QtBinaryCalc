#include "pushbuttonbit.h"

PushButtonBit::PushButtonBit(QWidget *parent):QPushButton(parent)
{
    this->bit = 1;
    this->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));


    connect(this, SIGNAL(clicked()), this, SLOT(slot_pushButtonBit_clicked()));

}

PushButtonBit::~PushButtonBit()
{

}

void PushButtonBit::slot_pushButtonBit_clicked()
{
//    emit bitChanged();

    if(this->bit == 1)
    {
        this->setText("0");
        bit = 0;
        this->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));

    }
    else
    if(this->bit == 0)
    {
        this->setText("1");
        bit = 1;
        this->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
    }
	emit clicked(this->numberBit);

}

bool PushButtonBit::getValueBit()
{
	return this->bit;
}

void PushButtonBit::setValueBit( bool  bit )
{
	this->bit = bit;
}

int PushButtonBit::getNumberBit()
{
	return this->numberBit;
}


void PushButtonBit::setNumberBit(int numberBit)
{
	this->numberBit = numberBit;
}
