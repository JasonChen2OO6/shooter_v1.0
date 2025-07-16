#ifndef GAME_H
#define GAME_H

#include <vector>

#include "enemy.h"
#include "player.h"
#include "enemybullet.h"
#include "playerbullet.h"

class Game
{
public:
    Game();

    void draw();
    void update();

    ~Game();

private:
    Player *player;
    vector<Enemy> enemyArray;
    vector<EnemyBullet> enemyBulletArray;
    vector<PlayerBullet> playerBulletArray;

    bool checkCollision();

};

#endif // GAME_H
