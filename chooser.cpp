#include "chooser.h"
#include "ui_chooser.h"

Chooser::Chooser(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Chooser)
{
	ui->setupUi(this);



	ui->pushButtonNot->setText("NOT A");
	ui->pushButtonNot->setID(1);

	ui->pushButtonAnd->setText("A AND B");
	ui->pushButtonAnd->setID(2);

	ui->pushButtonOr->setText("A OR B");
	ui->pushButtonOr->setID(3);

	ui->pushButtonXor->setText("A XOR B");
	ui->pushButtonXor->setID(4);




	//Ustawianie parametrow startowych
	//Na poczatku jest wybrany operator OR i dlatego na dzien dobry ustawiany jest IDOperator i setButtonState na 3, a funkcja ui->pushButtonOr->setChecked na true
	//Chcac zmienic operator ktory jest ustawiany na starcie, to trzeba zmienic IDOperator i setButtonState (1-not,2-and,3-or lub 4-xor) i ustawic dany przycisk (pushButtonNot, And, Or lub Xor) na checked
	this->IDOperator = 3;
	setButtonState(3);
	ui->pushButtonOr->setChecked(true);

}

Chooser::~Chooser()
{
	delete ui;
}


void Chooser::setButtonState(int IDButton)
{
	if(IDButton == 1)	//Wcisnieto buttona NOT. wykonanie obliczen i zmiana wartosci w widgetach
	{
		//Obsluga przycisku (wylaczenie przycisku, ktory jest wcisniety i uaktywnienie przyciskow, ktore nie sa wybrane)
		ui->pushButtonNot->setDisabled(true);

		ui->pushButtonAnd->setDisabled(false);
		ui->pushButtonOr->setDisabled(false);
		ui->pushButtonXor->setDisabled(false);

		ui->pushButtonAnd->setChecked(false);
		ui->pushButtonOr->setChecked(false);
		ui->pushButtonXor->setChecked(false);

		/////////////////////////////////////////////////////

		this->IDOperator = 1;

		emit operatorChanged(1);


	}
	else
	if(IDButton == 2)	//Wcisnieto buttona AND. wykonanie obliczen i zmiana wartosci w widgetach
	{
		//Obsluga przycisku (wylaczenie przycisku, ktory jest wcisniety i uaktywnienie przyciskow, ktore nie sa wybrane)
		ui->pushButtonAnd->setDisabled(true);

		ui->pushButtonNot->setDisabled(false);
		ui->pushButtonOr->setDisabled(false);
		ui->pushButtonXor->setDisabled(false);

		ui->pushButtonNot->setChecked(false);
		ui->pushButtonOr->setChecked(false);
		ui->pushButtonXor->setChecked(false);

		this->IDOperator = 2;

		emit operatorChanged(2);

	}
	else
	if(IDButton == 3)	//Wcisnieto buttona OR. wykonanie obliczen i zmiana wartosci w widgetach
	{
		//Obsluga przycisku (wylaczenie przycisku, ktory jest wcisniety i uaktywnienie przyciskow, ktore nie sa wybrane)
		ui->pushButtonOr->setDisabled(true);

		ui->pushButtonNot->setDisabled(false);
		ui->pushButtonAnd->setDisabled(false);
		ui->pushButtonXor->setDisabled(false);

		ui->pushButtonNot->setChecked(false);
		ui->pushButtonAnd->setChecked(false);
		ui->pushButtonXor->setChecked(false);


		this->IDOperator = 3;

		emit operatorChanged(3);
	}
	else
	if(IDButton == 4)	//Wcisnieto buttona XOR. wykonanie obliczen i zmiana wartosci w widgetach
	{
		//Obsluga przycisku (wylaczenie przycisku, ktory jest wcisniety i uaktywnienie przyciskow, ktore nie sa wybrane)
		ui->pushButtonXor->setDisabled(true);

		ui->pushButtonNot->setDisabled(false);
		ui->pushButtonAnd->setDisabled(false);
		ui->pushButtonOr->setDisabled(false);

		ui->pushButtonNot->setChecked(false);
		ui->pushButtonAnd->setChecked(false);
		ui->pushButtonOr->setChecked(false);


		this->IDOperator = 4;

		emit operatorChanged(4);
	}

}


int Chooser::getOperator()
{
	return this->IDOperator;
}
