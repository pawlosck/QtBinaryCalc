#ifndef QTBINARYCALC_H
#define QTBINARYCALC_H

#include <QtWidgets/QMainWindow>
#include "pushbuttonbit.h"
#include "byte.h"
#include "chooser.h"
#include "numbers.h"

namespace Ui {
class QtBinaryCalc;
}

class QtBinaryCalc : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtBinaryCalc(QWidget *parent = 0);
    ~QtBinaryCalc();
    
private:
    Ui::QtBinaryCalc *ui;

	Chooser *chooser;

	Numbers *numberA;
	Numbers *numberB;
	Numbers *numberResult;

    private slots:
		void slot_test();

	public slots:
		void slot_operatorChanged(int op = -1);	//Parametr domyslny "-1". Uzywane przy slocie slot_operatorChanged

	public:
		int calculateResult();	//funkcja wykonujaca obliczenia binarne. Funkcja obecnie nieuzywana

};

#endif // QTBINARYCALC_H
