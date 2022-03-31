#include "grafica.h"

Grafica::Grafica(float x, float y, float vx, float vy, float m, float r):escala(0.05)
{
    esf = new cuerpo(x,y,vx,vy,m,r);
}

QRectF Grafica::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void Grafica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}


void Grafica::actualizar(float dt)
{

    esf->actualizar(dt);
    setPos(esf->getPX()*escala,-esf->getPY()*escala);
}

cuerpo *Grafica::getEsf()
{
    return esf;
}
