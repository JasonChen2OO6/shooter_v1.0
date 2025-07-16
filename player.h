#ifndef PLAYER_H
#define PLAYER_H

#include <QDebug>
#include <vector>
#include <QPointF>
#include <QPainter>
#include <QKeyEvent>
#include <cmath>

#include "config.h"
#include "playerbullet.h"


class Player {
public:
    Player();

    void draw(QPainter &painter);
    void update();
    std::vector<PlayerBullet> shoot();
    QPointF getPosition();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QPointF position;
    float dx, dy;
    bool up, down, left, right;
    float angle;

    float velocity;
    int health;
    int experience;
    int level;

    int interval;
    int lastShoot;
    int attack;
};

#endif // PLAYER_H
