#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <QPointF>
#include <QPainter>
#include <cmath>

#include "config.h"

class PlayerBullet {
public:
    PlayerBullet(QPointF _position, float _angle, float _velocity, int _attack, int _bulletSize);

    void draw(QPainter &painter);
    void update();
    bool isInScreen();

    QPointF getPosition();
    int getAttack();

private:
    QPointF position;
    float angle;
    float velocity;

    int attack;
    int bulletSize;
};

#endif // PLAYERBULLET_H
