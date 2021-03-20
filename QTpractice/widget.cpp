#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->setWidth,SIGNAL(valueChanged(int)),ui->draw,SLOT(changeWidth(int)));
}

Widget::~Widget()
{
    delete ui;
}
