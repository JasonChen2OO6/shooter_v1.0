#ifndef PAUSE_H
#define PAUSE_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>

#include "config.h"

#include "player.h"

class Pause {
public:
    Pause(Player *_player);

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Player *player;

    int id1, id2, id3;
    void getId();
    void printData(int x, int y, int w, int h, QPainter &painter, int id);
    void printData2(int x, int y, int w, int h, QPainter &painter, int id);

    int pressCode;
};

#endif // PAUSE_H
