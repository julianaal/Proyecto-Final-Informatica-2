#ifndef BALA_H
#define BALA_H

#include <QGraphicsItem>
#include <QPainter>

class Bala : public QGraphicsItem
{
public:
    Bala(int,int);

    int getJ(void);
    int getI(void);
    void setJ(int);
    void setI(int);

private:
    QRectF boundingRect() const;
    //QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *win);
    int i,j;
    qreal q,w;

private slots:
    void advance (int step);


};

#endif // BALA_H
