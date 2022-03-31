#ifndef PELOTA_H
#define PELOTA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class pelota : public QObject, public QGraphicsPixmapItem
{
public:
    pelota(int width, int heigth);
    int get_h();

private:
    int w,h;
};

#endif // PELOTA_H
