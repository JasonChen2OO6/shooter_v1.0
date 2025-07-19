#ifndef OVER_H
#define OVER_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QDir>
#include <QUrl>

#include "config.h"

class Over {
public:
    Over(QObject *obj);

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QSoundEffect *button;
};

#endif // OVER_H
