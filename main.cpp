#include <QtWidgets/QApplication>
#include "qtbinarycalc.h"
#include "numbers.h"
#include "taband.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtBinaryCalc w;
    w.setWindowTitle("QtBinaryCalc");
	w.setGeometry(100,150, 860, 154);
	w.show();

    return a.exec();
}
