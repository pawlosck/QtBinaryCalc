#include "asciiwidget.h"
#include "ui_asciiwidget.h"
#include <QtWidgets/QPushButton>
#include <QChar>
#include <QLatin1Char>
#include <QTextCodec>
#include <asciibutton.h>
#include <QKeyEvent>
#include "qtbinarycalc.h"
#include "numbers.h"
#include "taband.h"


AsciiWidget::AsciiWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AsciiWidget)
{
	ui->setupUi(this);



	int heightButton = 35;
	int widthButton = 35;
	int numberColumns = 16;
	int numberAsciiLetters = 256;
	int sizeLetter = 13;

	QList<QPushButton*> asciiList;

	char asciiLetter[2];
	this->setFixedSize(widthButton*numberColumns, heightButton*numberColumns);


	QFont font;
	font.setFamily("arial");
	font.setBold(false);
	font.setPointSize(sizeLetter);
    for (int i = 0, y = -heightButton, x = 0 ; i < numberAsciiLetters ; i++, x++)	//i - numer znaku ascii, y - pozycja buttona(os y), x - polozenie buttona (os x)
	{
		if((i%numberColumns) == 0)//przejscie do nowej linii, gdy w rzedzie bedzie 16 znakow
		{
			y = y + heightButton;	//przesueniecie buttona na nowe miejsce w osi y
			x = 0;		//przejscie do nowej linii
		}
		asciiCode = new AsciiButton(this);


		asciiCode->setCode(i);
		asciiCode->setSizeLetter(sizeLetter);
		asciiCode->show();
		asciiCode->setFont(font);
		asciiLetter[0] = i;
		asciiLetter[1] = '\0';
		QTextCodec* codec = QTextCodec::codecForName("IBM 850");
		QString str = codec->toUnicode(asciiLetter);
		if ( i == 127 || ( i >= 0 && i <= 31 ) )	//znaki sterujace
		{
			QFont font;
			font.setFamily("arial");
			font.setBold(false);
			font.setPointSize(sizeLetter-4);
			asciiCode->setFont(font);
//			asciiCode->setText(str);
			QString sign = asciiControlCharacters(i);
			QString signName = asciiControlCharacters(i, true);
			asciiCode->setText(sign);
            asciiCode->setStyleSheet(QString::fromUtf8("background-color: white;"));
            asciiCode->setToolTip("Kod ascii: " + QString::number(i) + "\nSkrot: " + sign + "\nNazwa: " + signName);

		}
		else
		if( i >= 32 && i <= 126  )	//znaki drukowane standard ASCII
		{
			QFont font;
			font.setFamily("arial");
			font.setBold(false);
			font.setPointSize(sizeLetter);
			asciiCode->setFont(font);

			asciiCode->setText(str);
            asciiCode->setStyleSheet(QString::fromUtf8("background-color: yellow;"));
            asciiCode->setToolTip("Znaki ASCII\nKod ASCII: " + QString::number(i));

		}
		else	//znaki extended ASCII
		{
			QFont font;
			font.setFamily("arial");
			font.setBold(false);
			font.setPointSize(sizeLetter);
			asciiCode->setFont(font);

			asciiCode->setText(str);
            asciiCode->setStyleSheet(QString::fromUtf8("background-color: cyan;"));
            asciiCode->setToolTip("Znaki extended ASCII\nKod ASCII: " + QString::number(i));

		}

		asciiCode->setGeometry(x * widthButton, y, widthButton,heightButton);
		asciiList.append(asciiCode);
	}
}

AsciiWidget::~AsciiWidget()
{
	delete ui;

    delete asciiCode;
    delete pointerNumbersObject;

}

QString AsciiWidget::asciiControlCharacters (int asciiCode, bool name)
{
	if (name == true) //zwracaj nazwe
	{
		switch(asciiCode)
		{
			case 0:
			{
				return "Null Character";
				break;
			}

			case 1:
			{
				return "Start of Header";
				break;
			}
			case 2:
			{
				return "Start of Text";
				break;
			}
			case 3:
			{
				return "End of Text";
				break;
			}
			case 4:
			{
				return "End of Transmis.";
				break;
			}
			case 5:
			{
				return "Enquiry";
				break;
			}
			case 6:
			{
				return "Acknowledgement";
				break;
			}
			case 7:
			{
				return "Bell";
				break;
			}
			case 8:
			{
				return "Backspace";
				break;
			}
			case 9:
			{
				return "Horizontal Tab";
				break;
			}
			case 10:
			{
				return "Line feed";
				break;
			}
			case 11:
			{
				return "Vertical Tab";
				break;
			}
			case 12:
			{
				return "Form feed";
				break;
			}
			case 13:
			{
				return "Carriage return";
				break;
			}
			case 14:
			{
				return "Shift Out";
				break;
			}
			case 15:
			{
				return "Shift In";
				break;
			}
			case 16:
			{
				return "Data link escape";
				break;
			}
			case 17:
			{
				return "Device control 1";
				break;
			}
			case 18:
			{
				return "Device control 2";
				break;
			}
			case 19:
			{
				return "Device control 3";
				break;
			}
			case 20:
			{
				return "Device control 4";
				break;
			}
			case 21:
			{
				return "Negative acknowl.";
				break;
			}
			case 22:
			{
				return "Synchronous idle";
				break;
			}
			case 23:
			{
				return "End of trans. block";
				break;
			}
			case 24:
			{
				return "Cancel";
				break;
			}
			case 25:
			{
				return "End of medium";
				break;
			}
			case 26:
			{
				return "Substitute";
				break;
			}
			case 27:
			{
				return "Escape";
				break;
			}
			case 28:
			{
				return "File separator";
				break;
			}
			case 29:
			{
				return "Group separator";
				break;
			}
			case 30:
			{
				return "Record separator";
				break;
			}
			case 31:
			{
				return "Unit separator";
				break;
			}
			case 127:
			{
				return "Delete";
				break;
			}
			default:
				return "";
		}
	}
	else
	if (name == false)//zwracaj skrot
	{
		switch(asciiCode)
		{
			case 0:
			{
				return "NULL";
				break;
			}

			case 1:
			{
				return "SOH";
				break;
			}
			case 2:
			{
				return "STX";
				break;
			}
			case 3:
			{
				return "ETX";
				break;
			}
			case 4:
			{
				return "EOT";
				break;
			}
			case 5:
			{
				return "ENQ";
				break;
			}
			case 6:
			{
				return "ACK";
				break;
			}
			case 7:
			{
				return "BEL";
				break;
			}
			case 8:
			{
				return "BS";
				break;
			}
			case 9:
			{
				return "HT";
				break;
			}
			case 10:
			{
				return "LF";
				break;
			}
			case 11:
			{
				return "VT";
				break;
			}
			case 12:
			{
				return "FF";
				break;
			}
			case 13:
			{
				return "CR";
				break;
			}
			case 14:
			{
				return "SO";
				break;
			}
			case 15:
			{
				return "SI";
				break;
			}
			case 16:
			{
				return "LE";
				break;
			}
			case 17:
			{
				return "DC1";
				break;
			}
			case 18:
			{
				return "DC2";
				break;
			}
			case 19:
			{
				return "DC3";
				break;
			}
			case 20:
			{
				return "DC4";
				break;
			}
			case 21:
			{
				return "NAK";
				break;
			}
			case 22:
			{
				return "SYN";
				break;
			}
			case 23:
			{
				return "ETB";
				break;
			}
			case 24:
			{
				return "CAN";
				break;
			}
			case 25:
			{
				return "EM";
				break;
			}
			case 26:
			{
				return "SUB";
				break;
			}
			case 27:
			{
				return "ESC";
				break;
			}
			case 28:
			{
				return "FS";
				break;
			}
			case 29:
			{
				return "GS";
				break;
			}
			case 30:
			{
				return "RS";
				break;
			}
			case 31:
			{
				return "US";
				break;
			}
			case 127:
			{
				return "DEL";
				break;
			}
			default:
				return "";
		}
	}
	return "";
}

void AsciiWidget::keyPressEvent ( QKeyEvent * event )
{
    if(event->key() == Qt::Key_Escape)
    {
        this->hide();
    }
}


bool AsciiWidget::event(QEvent* aEvent)
{
    if(aEvent->type() == QEvent::WindowDeactivate)
    {
        aEvent->accept();
        this->hide();

        return true;//obluzony event zwraca true
    }
    else
    {
//        return false; //nieobsluzony event zwraca false   -> przez to nie zmienial sie kolor buttona pod linuksem
        return QWidget::event( aEvent );
    }

}

void AsciiWidget::slot_asciiButton_clicked(int asciiCode)
{
    emit clicked(asciiCode);
}

void AsciiWidget::setPointerNumbers(Numbers *numbersObject)
{
    this->pointerNumbersObject = numbersObject;
}
