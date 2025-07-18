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
    void drawData(QPainter &painter);
    void update();
    std::vector<PlayerBullet*> shoot();

    void addExperience(int _experience);
    int getExperience();
    QPointF getPosition();

    int getInterval();
    int getVelocity();
    int getAttack();
    int getBulletSize();
    int getRepelForce();

    void addInterval();
    void addVelocity();
    void addAttack();
    void addBulletSize();
    void addRepelForce();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    bool isAlive();
    bool isInvincible();
    void hurt(int attack);
    void addDefeatEnemy();
    void addShield();
    void removeShield();
    bool getHaveShield();
    void reset();

    bool getCanSplash();
    bool getCanBounce();
    bool getCanRetard();
    bool getCanTrace();
    bool getCanPenetrate();
    bool getLongerInvincible();
    bool getHurtInvicible();
    bool getAddHealthByDefeat();
    bool getAddHealthByTime();
    bool getAddShieldByHurt();
    bool getAddShieldByTime();
    bool getCanPassWall();

private:
    QPointF position;
    QPointF mousePosition;
    float dx, dy;
    bool up, down, left, right;
    float angle;

    bool canShoot;

    int health;
    int experience;
    int level;

    int lastShoot;
    int restInvincibleTime;
    int restAddHealthTime;
    int restAddShieldTime;
    bool haveShield;

    int interval;
    int velocity;
    int attack;
    int bulletSize;
    int repelForce;

    int defeatEnemyCount;

    bool canSplash;
    bool canBounce;
    bool canRetard;
    bool canTrace;
    bool canPenetrate;
    bool longerInvincible;
    bool hurtInvicible;
    bool addHealthByDefeat;
    bool addHealthByTime;
    bool addShieldByHurt;
    bool addShieldByTime;
    bool canPassWall;
};

#endif // PLAYER_H
