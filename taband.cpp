#include "taband.h"
#include "ui_taband.h"
#include "spinboxhex.h"
#include "asciiwidget.h"
#include "asciispinbox.h"

TabAnd::TabAnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabAnd)
{
    ui->setupUi(this);



}

TabAnd::~TabAnd()
{
    delete ui;
}



void TabAnd::on_pushButton_clicked()
{



}

void TabAnd::resizeEvent(QResizeEvent *event)
{

//    this->numberA->resize(this->size());

}
