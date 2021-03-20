#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H
#include <QPainter>
#include <QPen>
#include <QWidget>

class circlewidget : public QWidget
{
    Q_OBJECT
private:
    int m_width;
    QPen m_pen;
    QPainter* m_painter;
public:
    explicit circlewidget(QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent* event);
public slots:
    void changeWidth(int newValue);
};

#endif // CIRCLEWIDGET_H
