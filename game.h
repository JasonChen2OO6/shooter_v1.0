#ifndef GAME_H
#define GAME_H

#include <vector>
#include <QKeyEvent>

#include "enemy.h"
#include "player.h"
#include "enemybullet.h"
#include "playerbullet.h"

class Game
{
public:
    Game();

    void draw(QPainter &painter);
    void update();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    ~Game();

private:
    Player *player;
    std::vector<Enemy> enemyArray;
    std::vector<PlayerBullet> playerBulletArray;
    std::vector<EnemyBullet> enemyBulletArray;

    bool checkCollision();

};

#endif // GAME_H
