#include "circlewidget.h"
#include <QPainter>
#include <QPen>
circlewidget::circlewidget(QWidget *parent) : QWidget(parent),
    m_painter(new QPainter),
    m_width(0)
{

}

void circlewidget::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);
    m_painter->setPen(m_pen);
    m_painter->drawEllipse(circlewidget::width()/2 - 50, circlewidget::height()/2 - 50, 100, 100);
    m_painter->end();
}

void circlewidget::changeWidth(int newValue)
{
    m_pen.setWidth(newValue);
    repaint();
}
