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
    int getLevel();

    void addInterval();
    void addVelocity();
    void addAttack();
    void addBulletSize();
    void addRepelForce();
    void addHealth(int point);

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

    bool getCanSplash();            // 1
    bool getCanBounce();            // 2
    bool getCanRetard();            // 3
    bool getCanPenetrate();         // 4
    bool getLongerInvincible();     // 5
    bool getHurtInvincible();       // 6
    bool getAddHealthByDefeat();    // 7
    bool getAddHealthByTime();      // 8
    bool getAddShieldByHurt();      // 9
    bool getAddShieldByTime();      // 10
    bool getCanPassWall();          // 11

    void setCanSplash();            // 1
    void setCanBounce();            // 2
    void setCanRetard();            // 3
    void setCanPenetrate();         // 4
    void setLongerInvincible();     // 5
    void setHurtInvincible();       // 6
    void setAddHealthByDefeat();    // 7
    void setAddHealthByTime();      // 8
    void setAddShieldByHurt();      // 9
    void setAddShieldByTime();      // 10
    void setCanPassWall();          // 11

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
