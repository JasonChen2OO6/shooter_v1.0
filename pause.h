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

private:
    Player *player;
};

#endif // PAUSE_H
