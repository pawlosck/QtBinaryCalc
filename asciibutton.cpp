#include "asciibutton.h"

#include "asciiwidget.h"

//Klasa tworzaca przycisk ze znakiem ascii w klasie asciiwidget
AsciiButton::AsciiButton(QWidget *parent):QPushButton(parent)
{

    this->setSizeLetter(13);

    //Ustawienie normalnego fonta
    this->normalFont.setBold(false);
    this->normalFont.setFamily("arial");

    //ustawianie fonta, ktory sie ustawi, gdy sie najedzie mycha na pushbutton
    this->markedFont.setBold(true);

    if ( asciiCode == 127 || ( asciiCode >= 0 && asciiCode <= 31 ) )	//znaki sterujace
    {
//        this->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));
        this->normalFont.setPointSize(this->sizeLetter - 4);
    }
    else
    if( asciiCode >= 32 && asciiCode <= 126  )	//znaki drukowane standard ASCII
    {
//        this->setStyleSheet(QString::fromUtf8("background-color: yellow; color: black;"));
        this->normalFont.setPointSize(this->sizeLetter);
    }
    else	//znaki extended ASCII
    {
//        this->setStyleSheet(QString::fromUtf8("background-color: cyan; color: black;"));
        this->normalFont.setPointSize(this->sizeLetter);
    }
    this->setFont(this->normalFont);

    // po kliknieciu na przycik ma sie zamknac asciiwidget
    connect(this, SIGNAL(clicked()), this, SLOT(on_asciiButton_clicked()) );
    // po kliknieciu na przycisk przekazywany jest kod ascii tego przycisku do klasy asciiwidget, a nastepnie klasa asciiwidget przekazuje go dalej
    connect(this, SIGNAL(clicked(int)), (AsciiWidget*)(this->parentWidget()) , SLOT(slot_asciiButton_clicked(int)));
}

AsciiButton::~AsciiButton()
{

}

void AsciiButton::on_asciiButton_clicked()
{
    emit clicked(this->asciiCode);
    this->parentWidget()->hide();
}

//po najechaniu na przycisk ustawia sie font i wielkosc fontu. Font dla znakow sterujacych jest inny niz dla pozostalych znakow, gdyz znaki sterujace sa napisane wielka litera i nie mieszcza sie na przycisku
void AsciiButton::enterEvent(QEvent *event)
{

    this->setStyleSheet(QString::fromUtf8("background-color:  rgb(170, 255, 255);"));
//    this->setStyleSheet(QString::fromUtf8("background-color:  yellow;"));

	if ( asciiCode == 127 || ( asciiCode >= 0 && asciiCode <= 31 ) )	//znaki sterujace
	{
        this->markedFont.setPointSize(this->sizeLetter - 4);
	}
	else
	{
        this->markedFont.setPointSize(this->sizeLetter);
//        this->setFont(this->markedFont);
	}
    this->setFont(this->markedFont);

//    QWidget::enterEvent ( event );
}
// po wyjechaniu poza przycisk ustawia sie domysly font i tlo przycisku
void AsciiButton::leaveEvent(QEvent *event)
{
	if ( asciiCode == 127 || ( asciiCode >= 0 && asciiCode <= 31 ) )	//znaki sterujace
	{
		this->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));
        this->normalFont.setPointSize(sizeLetter - 4);
	}
	else
	if( asciiCode >= 32 && asciiCode <= 126  )	//znaki drukowane standard ASCII
	{
		this->setStyleSheet(QString::fromUtf8("background-color: yellow; color: black;"));
        this->normalFont.setPointSize(sizeLetter);
	}
	else	//znaki extended ASCII
	{
		this->setStyleSheet(QString::fromUtf8("background-color: cyan; color: black;"));
        this->normalFont.setPointSize(sizeLetter);
	}
this->setFont(this->normalFont);

//    QWidget::leaveEvent ( event );

}

void AsciiButton::setCode(int code)
{
	this->asciiCode = code;
}

void AsciiButton::setSizeLetter(int size)
{
	this->sizeLetter = size;
}

