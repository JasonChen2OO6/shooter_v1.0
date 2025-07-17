#ifndef ENEMY_H
#define ENEMY_H

#include <QDebug>
#include <vector>
#include <QPointF>
#include <QPainter>
#include <QKeyEvent>
#include <cmath>

#include "config.h"
#include "enemybullet.h"

class Enemy {
public:
    Enemy();

    void draw(QPainter &painter);
    void update();
    std::vector<EnemyBullet> shoot();
    QPointF getPosition();

private:
    QPointF position;
    float angle;

    float velocity;
    int health;

    int interval;
    int lastShoot;
    int attack;
};

#endif // ENEMY_H
