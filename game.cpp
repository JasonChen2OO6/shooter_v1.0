#include "game.h"

Game::Game() {
    player = new Player();
    enemyArray.clear();
    playerBulletArray.clear();
    enemyBulletArray.clear();
}

void Game::draw(QPainter &painter)
{
    player->draw(painter);
}

void Game::update()
{
    player->update();
}

void Game::keyPressEvent(QKeyEvent *event) {
    player->keyPressEvent(event);
}

void Game::keyReleaseEvent(QKeyEvent *event) {
    player->keyReleaseEvent(event);
}
