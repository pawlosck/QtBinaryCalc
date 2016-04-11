#include "qtbinarycalc.h"
#include "ui_qtbinarycalc.h"
#include "byte.h"
#include "chooser.h"
#include "debug.h"


QtBinaryCalc::QtBinaryCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtBinaryCalc)
{
    ui->setupUi(this);


		this->setGeometry(0,0, 865, 154);

		this->chooser = new Chooser(this);




		this->numberA = new Numbers(this);
		this->numberA->setGeometry(100,0, 765,50);
		this->numberA->show();
		this->numberA->setNameByte("A");

		this->numberB = new Numbers(this);
		this->numberB->setGeometry(100,50, 765,50);
		this->numberB->show();
		this->numberB->setNameByte("B");

		this->numberResult = new Numbers(this);
		this->numberResult->setGeometry(100,104, 765,50);
		this->numberResult->show();
		this->numberResult->setNameByte("Result", 10);
		this->numberResult->setEnabled(false);	//Funkcja wylaczajaca mozliwosc edycji obiektu klasy numbers ktora pelni role obiektu wyswietlajacego wynik

	connect(chooser, SIGNAL( operatorChanged( int ) ), this, SLOT(slot_operatorChanged(int)));

	//Te dwa connecty uzywane sa do aktualizacjiNumberResult (trzecia linia w programie - wyswietla wynik operacji bitowych)
	//Slot specjalnie niema parametru, zeby moc uzyc tego slotu w dwoch sytuacjach. Pierwszy raz uzywa sie slotu, gdy zmieni sie
	//recznie operator w klasie chooser (Cztery przyciski po lewej). W tej sytuacji mozna bylo normalnie przekazac do slotu wartosc
	//z sygnalu (pierwotnie tak bylo).
	//Drugim razem uzywa sie tego slotu, gdy zmieni sie wartosc ktoregos pol w numberA lub numberB.
    //Do tej drugiej sytuacji musialem tak zrobic. Jak operator nie otrzyma zadnej wartosci z sygnalu, to do slotu zostanie przekazana
	//domyslna wartosc "-1" (ustawione to jest w deklaracji slotu "void slot_operatorChanged(int op = -1)"). "-1" jest wtedy, gdy zmieni sie ktores pole w numberA lub B.
	//Pozostale wartosci (od 0 do 3) uzywane sa gdy zmieni sie operator. Zrobione to bylo w celu nie dublowania funkcji. Funkcja robi dokladnie to samo.
	//Jedyna roznica tkwi w poinformowaniu funkcji,kiedy zmienia sie operator, a kiedy zmieniaja sie pola. W slocie musialem dodac tylko if-a ( "if(op == -1)" )
	connect(numberA, SIGNAL( valueChanged(int)), this, SLOT ( slot_operatorChanged() ));
	connect(numberB, SIGNAL( valueChanged(int)), this, SLOT ( slot_operatorChanged() ));

}

QtBinaryCalc::~QtBinaryCalc()
{
    delete ui;

    delete chooser;

    delete numberA;
    delete numberB;
    delete numberResult;
}

void QtBinaryCalc::slot_test()
{
	QBitArray *a = new QBitArray();
	QBitArray *b = new QBitArray();
	QBitArray *result = new QBitArray();

	QString *resultString = new QString();

	a->fill(0, 16);
	b->fill(0, 16);
	result->fill(0, 16);

	for(int i = 0 ; i < this->numberA->getBytesAsBin().count() ; i++)
	{
		a->setBit(i, this->numberA->getBytesAsBin().at(i).digitValue() );
	}

	for(int i = 0 ; i < this->numberB->getBytesAsBin().count() ; i++)
	{
		b->setBit(i, this->numberB->getBytesAsBin().at(i).digitValue() );
	}


	*result = ~(*a);
	SHOWVALUE(result, *result);

	for ( int i = result->count()-1 ; i >= 0 ; i-- )
	{
		resultString->append( QString::number( (int)result->at(i) ) );
	}

	SHOWVALUE(resultString, *resultString);
	SHOWVALUE(resultString->toInt(0, 2), resultString->toInt(0,2));//tu trzeba zrobic invert bitow 0->16, 1->15 itd

	this->numberResult->slot_setValue(resultString->toInt());

	SHOWVALUE(a, *a);
	SHOWVALUE(b, *b);

}

//FUNKCJA ODPOWIADA ZA AKTUALIZOWANIE WYNIKU PO ZMIANIE OPERATORA PO LEWEJ STRONIE i za zmiane pol w numberA lub B.
//Dokladniejszy opis w kilkulinijkowym komentarzu pod koniec konstruktora QtBinaryCalc
void QtBinaryCalc::slot_operatorChanged(int op)
{
//int op - identyfikator operatora bitowego (1-NOT, 2-AND itd)
/////////////////////////////////////////////////////////

	QBitArray a;
	QBitArray b;
	QBitArray result;

	QString resultString;

	a.fill(0, 16);
	b.fill(0, 16);
	result.fill(0, 16);

	for(int i = 0 ; i < this->numberA->getBytesAsBin().count() ; i++)
	{
		a.setBit(i, this->numberA->getBytesAsBin().at(i).digitValue() );
	}

	for(int i = 0 ; i < this->numberB->getBytesAsBin().count() ; i++)
	{
		b.setBit(i, this->numberB->getBytesAsBin().at(i).digitValue() );
	}

/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////

	if(op == -1)
	{
		op = chooser->getOperator();
	}


	if (op == 1)
	{
		result = ~(a);
	}
	else
	if (op == 2)
	{
		result = a&b;
	}
	else
	if (op == 3)
	{
		result = a|b;
	}
	else
	if (op == 4)
	{
		result = a^b;
	}

	QString resultQString;

//	SHOWLINE();
	for(int i = 0 ; i <= 15 ; i++)
	{
		SHOWONLYVALUE((int)result.at(i));
		resultQString.append( QString::number(result.at(i)) );
	}

	this->numberResult->slot_setValue( resultQString.toInt(0, 2) );
}


int QtBinaryCalc::calculateResult()
{
	return 0;
}
