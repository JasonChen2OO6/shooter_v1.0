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
    Enemy(QPointF _position, float _angle, float _velocity, int health, int _interval, int _attack);

    virtual void draw(QPainter &painter) = 0;
    virtual void update(QPointF playPosition) = 0;
    virtual std::vector<EnemyBullet> shoot() = 0;
    virtual void repel(QPointF enemyPosition) = 0;
    QPointF getPosition();
    int getExperience();
    bool isAlive();
    void hurt(int attack);

    virtual ~Enemy();

protected:
    QPointF position;
    float angle;

    float dx, dy;
    float velocity;
    int health;

    int interval;
    int lastShoot;
    int attack;

    int experience;

    int life;
};

class Enemy01 : public Enemy{
public:
    Enemy01(QPointF _position);

    virtual void draw(QPainter &painter);
    virtual void update(QPointF playPosition);
    virtual std::vector<EnemyBullet> shoot();
    virtual void repel(QPointF enemyPosition);

    virtual ~Enemy01();
};

#endif // ENEMY_H
