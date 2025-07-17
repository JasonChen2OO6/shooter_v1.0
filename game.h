#ifndef GAME_H
#define GAME_H

#include <vector>
#include <QKeyEvent>
#include <QMouseEvent>

#include "enemy.h"
#include "player.h"
#include "enemybullet.h"
#include "playerbullet.h"

class Game {
public:
    Game();

    void draw(QPainter &painter);
    void update();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    int getExperience();

    ~Game();

private:
    int timer;

    Player *player;
    std::vector<Enemy*> enemyArray;
    std::vector<PlayerBullet*> playerBulletArray;
    std::vector<EnemyBullet*> enemyBulletArray;

    bool checkCollision(Player *player, Enemy *enemy);
    bool checkCollision(PlayerBullet *playerBullet, Enemy *enemy);

};

#endif // GAME_H
