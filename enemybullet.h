#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QPointF>
#include <QPainter>
#include <cmath>

#include "config.h"

class EnemyBullet {
public:
    EnemyBullet(QPointF _position, float _angle, float _velocity, int _attack);

    int getAttack();
    QPointF getPosition();

    void draw(QPainter &painter);
    void update();
    bool isInScreen();

private:
    QPointF position;
    float angle;

    float velocity;
    int attack;
};

#endif // ENEMYBULLET_H
