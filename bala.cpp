#include "bala.h"

Bala::Bala(int x,int y)
{
    i=x;
    j=y;
    setPos(i,j);
}

QRectF Bala::boundingRect() const
{
    return QRectF(-3, -7, 6, 14);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-3, -7, 6, 14,QPixmap (":/Image/S1.png"));
}

void Bala::advance(int step){
    setPos(i,j);
    j=j-4;
}

int Bala::getJ(void){
    return j;
}

int Bala::getI(void){
    return i;
}

void Bala::setI(int z){
    i=z;
}

void Bala::setJ(int z){
    j=z;
}
