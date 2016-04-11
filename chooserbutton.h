#ifndef CHOOSERBUTTON_H
#define CHOOSERBUTTON_H

#include <QtWidgets/QPushButton>

class ChooserButton : public QPushButton
{

		Q_OBJECT

	public:
		ChooserButton();
		ChooserButton(QWidget *parent = 0);
		~ChooserButton();

		int setID(int IDButton);
		int getID();


	private:
		int IDButton;	//1-NOT, 2-AND, 3-OR, 4-XOR


	private slots:
		void setIDClicked();


	signals:
		void clickedStatus(int);
};

#endif // CHOOSERBUTTON_H
