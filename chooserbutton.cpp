#include "chooserbutton.h"
#include "debug.h"


ChooserButton::ChooserButton()
{
}


ChooserButton::ChooserButton(QWidget *parent):QPushButton(parent)
{


	if (this->isChecked() == true )
	{
		SHOW(TRUE);
	}
	else
	{
		SHOW(FALSE);
	}




	connect(this, SIGNAL( clicked() ), this, SLOT(setIDClicked()) );
	connect(this, SIGNAL( clickedStatus(int) ), parent, SLOT(setButtonState(int)) );
}


int ChooserButton::setID(int IDButton)
{

	if(IDButton >= 1 && IDButton <= 4 )
	{
		this->IDButton = IDButton;

		return IDButton;
	}
	else
	{
		return -1;
	}
}

int ChooserButton::getID()
{
	return this->IDButton;
}

void ChooserButton::setIDClicked()
{
	emit clickedStatus(getID());
}

ChooserButton::~ChooserButton()
{

}
