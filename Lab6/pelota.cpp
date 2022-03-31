#include "pelota.h"

pelota::pelota(int width, int heigth)
{
    QPixmap j(":/Pelota.jpeg");
    h = heigth;
    w = width;
    setPixmap(j.scaled(w,h));
}

int pelota::get_h()
{
    return h;
}
