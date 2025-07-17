#ifndef TITLE_H
#define TITLE_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>

#include "config.h"

class Title {
public:
    Title();

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // TITLE_H
