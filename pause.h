#ifndef PAUSE_H
#define PAUSE_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>

#include "config.h"

class Pause {
public:
    Pause();

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PAUSE_H
