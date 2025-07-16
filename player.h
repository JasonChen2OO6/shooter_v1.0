#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <QPointF>
#include <QPainter>

#include "config.h"
#include "playerbullet.h"


class Player
{
public:
    Player();

    void draw(QPainter &painter);
    void update();
    vector<PlayerBullet> shoot();
    QPointF getPosition();

private:
    QPointF position;
    float angle;

    const float velocity;
    int health;
    int experience;
    int level;

    int interval;
    int lastShoot;
    int attack;
};

#endif // PLAYER_H
