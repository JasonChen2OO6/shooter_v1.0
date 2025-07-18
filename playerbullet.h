#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <QDebug>
#include <QPointF>
#include <QPainter>
#include <cmath>
#include <vector>

#include "config.h"

#include "enemy.h"

class PlayerBullet {
public:
    PlayerBullet(QPointF _position, float _angle, float _velocity, int _attack, int _bulletSize, int _bounceTime);

    void draw(QPainter &painter);
    void update();
    bool isInScreen();

    QPointF getPosition();
    int getAttack();
    bool checkEnemy(Enemy *enemy);
    void updateEnemyArray(std::vector<Enemy*> array);

private:
    QPointF position;
    float angle;
    float velocity;

    float dx, dy;

    int attack;
    int bulletSize;

    int bounceTime;

    std::vector<Enemy*> lastCollidEnemyArray;
};

#endif // PLAYERBULLET_H
