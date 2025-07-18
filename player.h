#ifndef PLAYER_H
#define PLAYER_H

#include <QDebug>
#include <vector>
#include <QPointF>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <cmath>

#include "config.h"
#include "playerbullet.h"


class Player {
public:
    Player();

    void draw(QPainter &painter);
    void update();
    std::vector<PlayerBullet*> shoot();
    void addExperience(int _experience);

    int getExperience();
    QPointF getPosition();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    bool isAlive();
    void hurt(int attack);

    void reset();

private:
    QPointF position;
    float dx, dy;
    bool up, down, left, right;
    float angle;

    bool canShoot;

    float velocity;
    int health;
    int experience;
    int level;

    int interval;
    int lastShoot;
    int attack;
};

#endif // PLAYER_H
