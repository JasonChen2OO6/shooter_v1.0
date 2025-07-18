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
    Enemy(QPointF _position, float _angle,  float _mass, float _velocity,
          int health, int _interval, int _attack, int _experience);

    virtual void draw(QPainter &painter) = 0;
    virtual void update(QPointF playPosition) = 0;
    virtual std::vector<EnemyBullet*> shoot(QPointF playPosition) = 0;

    QPointF getPosition();
    int getExperience();
    int getAttack();

    void repel(QPointF playerPosition);
    void repulse(QPointF enemyPosition);
    bool isAlive();
    void hurt(int attack);

    virtual ~Enemy();

protected:
    QPointF position;
    float angle;

    float mass;
    float dx, dy;
    float velocity;
    int health;

    int interval;
    int lastShoot;
    int attack;

    int experience;

    int life;
};

class Enemy01 : public Enemy {
public:
    Enemy01(QPointF _position);

    virtual void draw(QPainter &painter);
    virtual void update(QPointF playerPosition);
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    virtual ~Enemy01();
};

class Enemy02 : public Enemy {
public:
    Enemy02(QPointF _position);

    virtual void draw(QPainter &painter);
    virtual void update(QPointF playerPosition);
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    virtual ~Enemy02();
};

class Enemy03 : public Enemy {
public:
    Enemy03(QPointF _position);

    virtual void draw(QPainter &painter);
    virtual void update(QPointF playerPosition);
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    virtual ~Enemy03();
private:
    int interval;
};

class EliteEnemy01 : public Enemy {
public:
    EliteEnemy01(QPointF _position);

    virtual void draw(QPainter &painter);
    virtual void update(QPointF playerPosition);
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    virtual ~EliteEnemy01();
private:
    int interval;
};



#endif // ENEMY_H
