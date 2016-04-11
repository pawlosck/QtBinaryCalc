#ifndef TABAND_H
#define TABAND_H


#include <QtWidgets/QWidget>
#include "byte.h"
#include "spinboxhex.h"
#include <QtWidgets/QLabel>
#include "numbers.h"
#include "chooser.h"

namespace Ui {
class TabAnd;
}

class TabAnd : public QWidget
{
    Q_OBJECT
    
public:
    explicit TabAnd(QWidget *parent = 0);
    ~TabAnd();
    
	private slots:
		void on_pushButton_clicked();

	private:
    Ui::TabAnd *ui;
    void resizeEvent(QResizeEvent *event);







};

#endif // TABAND_H
