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
    Enemy(int _size, QPointF _position, float _angle,  float _mass, float _velocity,
          int health, int _interval, int _attack, int _experience);

    virtual void draw(QPainter &painter) = 0;
    virtual void update(QPointF playerPosition) = 0;
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition) = 0;

    QPointF getPosition();
    int getExperience();
    int getAttack();
    int getSize();

    void repel(QPointF playerPosition, int repelForce);
    void repulse(QPointF enemyPosition);
    virtual bool isAlive();
    void hurt(int attack, bool isRetard);

    virtual ~Enemy();

protected:
    int size;
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

    int restRetardTime;
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

class Boss01 : public Enemy {
public:
    Boss01(QPointF _position);

    virtual void update(QPointF playerPosition);
    virtual void draw(QPainter &painter);
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    ~Boss01();
private:
    int interval;
    int moveInterval;
};

class SubEnemy : public Enemy {
public:
    SubEnemy(QPointF position, float angle);

    void update(QPointF playerPosition);
    void draw(QPainter &painter);
    std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    bool isAlive();

    ~SubEnemy();

private:
    QPointF startPosition;
    int interval;
    int moveInterval;
};

class Boss02 : public Enemy {
public:
    Boss02(QPointF _position);

    virtual void update(QPointF playerPosition);
    virtual void draw(QPainter &painter);
    virtual std::vector<EnemyBullet*> shoot(QPointF playerPosition);

    ~Boss02();
private:
    int interval;
    int moveInterval;
};



#endif // ENEMY_H
