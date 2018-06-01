#include "nave.h"
#define R 14
#define R1 R*2

Nave::Nave(int x, int y)
{
    i=x;
    j=y;
    setPos(i,j);
}


QRectF Nave::boundingRect() const
{
    return QRectF(-14, -28, 28, 56);
}

/*
QPainterPath Nave::shape() const
{
    QPainterPath path;
    path.addRect(-28, -55, 56, 110);
    return path;
}
*/

void Nave::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-14, -28, 28, 56,QPixmap (":/Image/N1.png"));
}

void Nave::advance(int step){
    setPos(i,j);
}

int Nave::getJ(void){
    return j;
}

int Nave::getI(void){
    return i;
}

void Nave::setI(int z){
    i=z;
}

void Nave::setJ(int z){
    j=z;
}
