#ifndef GAME_H
#define GAME_H

#include <vector>
#include <QKeyEvent>
#include <QMouseEvent>

#include "pause.h"
#include "enemy.h"
#include "player.h"
#include "enemybullet.h"
#include "playerbullet.h"
#include "explosion.h"

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
    int getStatus();

    int getExperience();

    ~Game();

private:
    Pause *pause;

    int status; // 0 game 1 pause

    int timer;

    Player *player;
    std::vector<Enemy*> enemyArray;
    std::vector<PlayerBullet*> playerBulletArray;
    std::vector<EnemyBullet*> enemyBulletArray;
    std::vector<Explosion*> explosionArray;


    void playerShoot();
    void generateEnemy();
    void enemyRepulse();
    void enemyShoot();
    void checkCollision();
    void deleteDeadEnemy();
    void updateEverything();
    void deleteOutScreenBullet();

    template<typename T1, typename T2>
    float dist(T1 a, T2 b);

    bool checkCollision(Player *player, Enemy *enemy);
    bool checkCollision(PlayerBullet *playerBullet, Enemy *enemy);
    bool checkCollision(Player *player, EnemyBullet *enemyBullet);

};

#endif // GAME_H
