#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"

class Grafica: public QGraphicsItem
{
public:
    Grafica(float x, float y, float vx, float vy, float m, float r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar(float dt);
    cuerpo* getEsf();


private:
    cuerpo *esf;
    float escala = 1000.0;
    // Reiniciar las aceleraciones
};

#endif // CUERPOGRAF_H
