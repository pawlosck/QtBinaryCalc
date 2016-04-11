#ifndef CHOOSER_H
#define CHOOSER_H

#include <QWidget>

namespace Ui {
	class Chooser;
}

class Chooser : public QWidget
{

		Q_OBJECT

	private:
		int IDOperator; //identyfikator operatora. od 1-4 -> NOT, AND itd
		
	public:
		explicit Chooser(QWidget *parent = 0);
		~Chooser();

		int getOperator();	//zwraca identyfikator operatora. Od 1 do 4 -> NOT, AND, OR, XOR

	public slots:
		void setButtonState(int IDButton);

	private:
		Ui::Chooser *ui;

	signals:
		void operatorChanged(int whichOperator);	//sygnal ktory jest generowany, gdy wcisnie sie button w chooser, ktory odpowiada za zmiane operatora bitowego uzywanego do obliczen. Sygnal przekazuje identyfikator operatora (od 1 do 4)
};
#endif // CHOOSER_H
