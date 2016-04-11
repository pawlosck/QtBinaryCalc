#include "byte.h"
#include "ui_byte.h"
#include <QBitArray>


Byte::Byte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Byte)
{
    ui->setupUi(this);

    this->setFixedSize(250, 50);
    ui->NameByte->setStyleSheet(QString::fromUtf8("background-color: grey ;"));
    this->setStyleSheet(QString::fromUtf8("background-color: white;"));

    ui->bit0->setText("1");
    ui->bit1->setText("1");
    ui->bit2->setText("1");
    ui->bit3->setText("1");
    ui->bit4->setText("1");
    ui->bit5->setText("1");
    ui->bit6->setText("1");
    ui->bit7->setText("1");

    this->bit0 = new bool(1);
    this->bit1 = new bool(1);
    this->bit2 = new bool(1);
    this->bit3 = new bool(1);
    this->bit4 = new bool(1);
    this->bit5 = new bool(1);
    this->bit6 = new bool(1);
    this->bit7 = new bool(1);

    ui->bit0->setNumberBit(0);
    ui->bit1->setNumberBit(1);
    ui->bit2->setNumberBit(2);
    ui->bit3->setNumberBit(3);
    ui->bit4->setNumberBit(4);
    ui->bit5->setNumberBit(5);
    ui->bit6->setNumberBit(6);
    ui->bit7->setNumberBit(7);

    this->onlyByte = false;

    this->byte = new QBitArray(8, 1);
//    this->byte815 = new QBitArray(8, 1);
	connect(ui->bit0, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
	connect(ui->bit1, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
    connect(ui->bit2, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
    connect(ui->bit3, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
    connect(ui->bit4, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
    connect(ui->bit5, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
    connect(ui->bit6, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );
    connect(ui->bit7, SIGNAL(clicked(int)), this, SLOT(updateByte(int)) );

    connect(this, SIGNAL(byteChanged(int)), this, SLOT(slot_updateByteGUI()));
}

Byte::~Byte()
{
    delete ui;

    delete bit0;
    delete bit1;
    delete bit2;
    delete bit3;
    delete bit4;
    delete bit5;
    delete bit6;
    delete bit7;

    delete byte;
}


void Byte::setNameByte(QString nameByte, int FontSize)
{
    QFont font;
    font.setPointSize(FontSize);
    font.setBold(true);

    ui->NameByte->setFont(font);
    ui->NameByte->setAlignment(Qt::AlignCenter);

    ui->NameByte->setText(nameByte);
}

void Byte::setOnlyByte(bool mode)
{
    if (mode == true)//nie pokazuj nazwy bajtu, czyli litery A, B lub maska
    {
        this->setFixedSize(200, 50);

        ui->NameByte->hide();
        ui->bit0->move(ui->bit0->pos().x() - 50, 0);
        ui->bit1->move(ui->bit1->pos().x() - 50, 0);
        ui->bit2->move(ui->bit2->pos().x() - 50, 0);
        ui->bit3->move(ui->bit3->pos().x() - 50, 0);
        ui->bit4->move(ui->bit4->pos().x() - 50, 0);
        ui->bit5->move(ui->bit5->pos().x() - 50, 0);
        ui->bit6->move(ui->bit6->pos().x() - 50, 0);
        ui->bit7->move(ui->bit7->pos().x() - 50, 0);


        ui->labelBit0->move(ui->labelBit0->pos().x() - 50,25);
        ui->labelBit1->move(ui->labelBit1->pos().x() - 50,25);
        ui->labelBit2->move(ui->labelBit2->pos().x() - 50,25);
        ui->labelBit3->move(ui->labelBit3->pos().x() - 50,25);
        ui->labelBit4->move(ui->labelBit4->pos().x() - 50,25);
        ui->labelBit5->move(ui->labelBit5->pos().x() - 50,25);
        ui->labelBit6->move(ui->labelBit6->pos().x() - 50,25);
        ui->labelBit7->move(ui->labelBit7->pos().x() - 50,25);

        this->onlyByte = true;
    }
    else//pokazuj nazwe bajtu
    {
        this->setFixedSize(250, 50);
        ui->NameByte->show();
        ui->bit7->move(50, 0);
        ui->bit6->move(ui->bit7->pos().x() + 25, 0);
        ui->bit5->move(ui->bit6->pos().x() + 25, 0);
        ui->bit4->move(ui->bit5->pos().x() + 25, 0);
        ui->bit3->move(ui->bit4->pos().x() + 25, 0);
        ui->bit2->move(ui->bit3->pos().x() + 25, 0);
        ui->bit1->move(ui->bit2->pos().x() + 25, 0);
        ui->bit0->move(ui->bit1->pos().x() + 25, 0);

        ui->labelBit7->move(50,25);
        ui->labelBit6->move(ui->labelBit7->pos().x() + 25,25);
        ui->labelBit5->move(ui->labelBit6->pos().x() + 25,25);
        ui->labelBit4->move(ui->labelBit5->pos().x() + 25,25);
        ui->labelBit3->move(ui->labelBit4->pos().x() + 25,25);
        ui->labelBit2->move(ui->labelBit3->pos().x() + 25,25);
        ui->labelBit1->move(ui->labelBit2->pos().x() + 25,25);
        ui->labelBit0->move(ui->labelBit1->pos().x() + 25,25);

        this->onlyByte = false;
    }

}

void Byte::firstBit(int firstBit)
{
	int firstBitBackup = firstBit;
    this->firstBitInt = firstBit;
    ui->labelBit0->setText(QString::number(firstBit++));
    ui->labelBit1->setText(QString::number(firstBit++));
    ui->labelBit2->setText(QString::number(firstBit++));
    ui->labelBit3->setText(QString::number(firstBit++));
    ui->labelBit4->setText(QString::number(firstBit++));
    ui->labelBit5->setText(QString::number(firstBit++));
    ui->labelBit6->setText(QString::number(firstBit++));
    ui->labelBit7->setText(QString::number(firstBit++));


	firstBit = firstBitBackup;

	ui->bit0->setNumberBit(firstBit++);
	ui->bit1->setNumberBit(firstBit++);
	ui->bit2->setNumberBit(firstBit++);
	ui->bit3->setNumberBit(firstBit++);
	ui->bit4->setNumberBit(firstBit++);
	ui->bit5->setNumberBit(firstBit++);
	ui->bit6->setNumberBit(firstBit++);
	ui->bit7->setNumberBit(firstBit++);

}

//uaktualnia wartosc zmiennej byte (qbitarray). wartosc pobierana jest z przycisku
void Byte::updateByte(int whichBit)
{
	qDebug(QString::number(whichBit).toStdString().c_str());
	switch (whichBit)
	{
		case 0:
		{
			if(ui->bit0->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
				qDebug("bit0 clear");
			}
			else
			if(ui->bit0->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
				qDebug("bit0 set");
			}
			break;
		}
		case 1:
		{
			if(ui->bit1->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
				qDebug("bit1 clear");
			}
			else
			if(ui->bit1->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
				qDebug("bit1 set");
			}
			break;
		}
		case 2:
		{
			if(ui->bit2->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
                qDebug("bit2 clear");
			}
			else
			if(ui->bit2->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
                qDebug("bit2 set");
			}
			break;
		}
		case 3:
		{
			if(ui->bit3->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
                qDebug("bit3 clear");
			}
			else
			if(ui->bit3->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
                qDebug("bit3 set");
			}
			break;
		}
		case 4:
		{
			if(ui->bit4->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
                qDebug("bit4 clear");
			}
			else
			if(ui->bit4->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
                qDebug("bit4 set");
			}
			break;
		}
		case 5:
		{
			if(ui->bit5->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
                qDebug("bit5 clear");
			}
			else
				if(ui->bit5->getValueBit() == 1)
				{
                    this->byte->setBit(whichBit);
                    qDebug("bit5 set");
				}
				break;
		}
		case 6:
		{
			if(ui->bit6->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
                qDebug("bit6 clear");
			}
			else
			if(ui->bit6->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
                qDebug("bit6 set");
			}
			break;
		}
		case 7:
		{
			if(ui->bit7->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit);
                qDebug("bit7 clear");
			}
			else
			if(ui->bit7->getValueBit() == 1)
			{
                this->byte->setBit(whichBit);
                qDebug("bit7 set");
			}
			break;
		}
        default:
        {
            qDebug("wartosc wieksza niz 7 w updatebyte");
        }

        case 8: //NOTE: od osmego bitu zaczyna sie drugi byte
		{
			if(ui->bit0->getValueBit() == 0)
			{

                this->byte->clearBit(whichBit-8);
				qDebug("bit8 clear");
			}
			else
			if(ui->bit0->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
				qDebug("bit8 set");
			}
			break;
		}

        case 9:
		{
			if(ui->bit1->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit9 clear");
			}
			else
			if(ui->bit1->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
                qDebug("bit9 set");
			}
			break;
		}
        case 10:
		{
			if(ui->bit2->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit10 clear");
			}
			else
			if(ui->bit2->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
                qDebug("bit10 set");
			}
			break;
		}
        case 11:
		{
			if(ui->bit3->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit11 clear");
			}
			else
			if(ui->bit3->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
                qDebug("bit11 set");
			}
			break;
		}
        case 12:
		{
			if(ui->bit4->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit12 clear");
			}
			else
			if(ui->bit4->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
                qDebug("bit12 set");
			}
			break;
		}
        case 13:
		{
			if(ui->bit5->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit13 clear");
			}
			else
				if(ui->bit5->getValueBit() == 1)
				{
                    this->byte->setBit(whichBit-8);
                    qDebug("bit13 set");
				}
				break;
		}
        case 14:
		{
			if(ui->bit6->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit14 clear");
			}
			else
			if(ui->bit6->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
                qDebug("bit14 set");
			}
			break;
		}
        case 15:
		{
			if(ui->bit7->getValueBit() == 0)
			{
                this->byte->clearBit(whichBit-8);
                qDebug("bit15 clear");
			}
			else
			if(ui->bit7->getValueBit() == 1)
			{
                this->byte->setBit(whichBit-8);
                qDebug("bit15 set");
			}
			break;
		}

        SHOW(a);
        if(this->firstBitInt == 0)
        {
            for (int i=0; i < 8 ; i++)
            {
                SHOW(b);
                this->updateBit( i , this->byte->at(i));
                SHOW(c);
            }
        }
        else
        {
            for (int i=8; i < 16 ; i++)
            {
                SHOW(b);
                this->updateBit( i , this->byte->at(i));
                SHOW(c);
            }
        }

	}
    emit byteChanged(whichBit);

}

void Byte::updateBit(int whichBit, bool value)
{
//emit byteChanged(whichBit);

	switch (whichBit)
	{
		case 0:
		{
			if(value == 0)
			{
				ui->bit0->setText("0");
                *this->bit0 = 0;
				ui->bit0->setValueBit(0);
				ui->bit0->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(0, 0);
			}
			else
			if(value == 1)
			{
				ui->bit0->setText("1");
                *this->bit0 = 1;
				ui->bit0->setValueBit(1);
				ui->bit0->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(0, 1);
			}
			break;

		}
		case 1:
		{
			if(value == 0)
			{
				ui->bit1->setText("0");
				*this->bit1 = 0;
				ui->bit1->setValueBit(0);
				ui->bit1->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(1, 0);
			}
			else
			if(value == 1)
			{
				ui->bit1->setText("1");
				*this->bit1 = 1;
				ui->bit1->setValueBit(1);
				ui->bit1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(1, 1);
			}
			break;

		}
		case 2:
		{
			if(value == 0)
			{
				ui->bit2->setText("0");
				*this->bit2 = 0;
				ui->bit2->setValueBit(0);
				ui->bit2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(2, 0);
			}
			else
			if(value == 1)
			{
				ui->bit2->setText("1");
				*this->bit2 = 1;
				ui->bit2->setValueBit(1);
				ui->bit2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(2, 1);
			}
			break;

		}
		case 3:
		{
			if(value == 0)
			{
				ui->bit3->setText("0");
				*this->bit3 = 0;
				ui->bit3->setValueBit(0);
				ui->bit3->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(3, 0);
			}
			else
			if(value == 1)
			{
				ui->bit3->setText("1");
				*this->bit3 = 1;
				ui->bit3->setValueBit(1);
				ui->bit3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(3, 1);
			}
			break;

		}
		case 4:
		{
			if(value == 0)
			{
				ui->bit4->setText("0");
				*this->bit4 = 0;
				ui->bit4->setValueBit(0);
				ui->bit4->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(4, 0);
			}
			else
			if(value == 1)
			{
				ui->bit4->setText("1");
				*this->bit4 = 1;
				ui->bit4->setValueBit(1);
				ui->bit4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(4, 1);
			}
			break;

		}
		case 5:
		{
			if(value == 0)
			{
				ui->bit5->setText("0");
				*this->bit5 = 0;
				ui->bit5->setValueBit(0);
				ui->bit5->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(5, 0);
			}
			else
			if(value == 1)
			{
				ui->bit5->setText("1");
				*this->bit5 = 1;
				ui->bit5->setValueBit(1);
				ui->bit5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(5, 1);
			}
			break;

		}
		case 6:
		{
			if(value == 0)
			{
				ui->bit6->setText("0");
				*this->bit6 = 0;
				ui->bit6->setValueBit(0);
				ui->bit6->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(6, 0);
			}
			else
			if(value == 1)
			{
				ui->bit6->setText("1");
				*this->bit6 = 1;
				ui->bit6->setValueBit(1);
				ui->bit6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(6, 1);
			}
			break;

		}
		case 7:
		{
			if(value == 0)
			{
				ui->bit7->setText("0");
				*this->bit7 = 0;
				ui->bit7->setValueBit(0);
				ui->bit7->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
                this->byte->setBit(7, 0);
			}
			else
			if(value == 1)
			{
				ui->bit7->setText("1");
				*this->bit7 = 1;
				ui->bit7->setValueBit(1);
				ui->bit7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
                this->byte->setBit(7, 1);
			}
            break;
		}
        default:
        {
        qDebug("wartosc wieksza niz 7 w updatebit");
        }

	}
}

Byte& Byte::operator= (const QBitArray &byte)
{
    if ( byte.size() <= 8 )//Sprawdzenie w razie czego, czy byte napewno nie zaawiera wiecej niz 8 bitow
	{
        for (int i = 0 ; i < byte.size() ; i++) //Wrzucenie do zmiennej byte (klasa Byte) bitow. Wrzucane sa tylko te bity, ktore sa podane w zmiennej byte (QBitArray)
		{
			this->updateBit( i , byte.at(i));
		}
	}

	return *this;
}

Byte& Byte::operator= (const QString &byte)
{

        QString tmp;
        QString tmp2;
        QBitArray byte_tmp;
        byte_tmp.resize(8);


        int fillZero = 8 - byte.size();
        tmp.fill('0', fillZero);

        tmp2 = byte;

        tmp2.prepend(tmp);


        for ( int i = 0, j = 7 ; i < 8 || j >=0 ; i++ , j-- )//tu zmienilem z "i < 8, j >=0" na "i < 8 || j >=0"
        {
            this->updateBit( j , tmp2.at(i).digitValue() );
        }

        emit byteChanged();

        return *this;


}

int Byte::getByteAsInt()
{

    QString byteQString;

    QBitArray byteQBitArray(byte->count());


        byteQBitArray =  *this->byte;


    for ( int i = byteQBitArray.count()-1 ; i >= 0 ; i-- )
    {
        byteQString.append( QString::number((int)byteQBitArray.at(i)) );
//        SHOWVALUE((int)byteQBitArray.at(i), (int)byteQBitArray.at(i));
    }

    SHOWVALUE(byteQString, byteQString);

    return byteQString.toInt(0, 2);
}

QString Byte::getByteAsBin()
{
    QString byteQString;
    for ( int i = this->byte->count()-1 ; i >= 0 ; i-- )
    {
        byteQString.append( QString::number((int)byte->at(i)) );
//        SHOWVALUE((int)byteQBitArray.at(i), (int)byteQBitArray.at(i));
    }
    return byteQString;
}

QBitArray Byte::invertBits(QBitArray *byte)
{

        QBitArray byteTmp(byte->count());// = new QBitArray(8);
        for ( int i = 0, j = (byte->count() - 1) ; i < byte->count() ; i++, j-- )
        {
            byteTmp.setBit(j, byte->at(i));
        }

        for( int i = 0 ; i < byteTmp.count() ; i++  )
        {
            byte->setBit(i, byteTmp.at(i));
        }


        return *byte;

}


void Byte::slot_updateByteGUI()
{
}
