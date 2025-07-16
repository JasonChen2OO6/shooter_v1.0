#include "game.h"
#include "widget.h"

Game::Game() {
    player = new Player();
    enemyArray.clear();
    playerBulletArray.clear();
    enemyBulletArray.clear();
}

void Game::draw(QPainter &painter) {
    player->draw(painter);
}

void Game::update() {
    player->update();
}

void Game::keyPressEvent(QKeyEvent *event) {
    player->keyPressEvent(event);

    int keyCode = event->key();
    if (keyCode == Qt::Key_P){
          qDebug() << keyCode;
          Widget::status = 3;
    }
    if (keyCode == Qt::Key_Escape){
          qDebug() << keyCode;
          Widget::status = 2;
    }
}

void Game::keyReleaseEvent(QKeyEvent *event) {
    player->keyReleaseEvent(event);
}
