#ifndef TITLE_H
#define TITLE_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QUrl>

#include "config.h"

class Title {
public:
    Title(QObject *obj);

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QSoundEffect *button;
};

#endif // TITLE_H
