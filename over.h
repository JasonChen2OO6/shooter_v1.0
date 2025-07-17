#ifndef OVER_H
#define OVER_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>

#include "config.h"

class Over {
public:
    Over();

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // OVER_H
