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

    for (auto it = playerBulletArray.begin(); it != playerBulletArray.end(); ++it) {
        it->draw(painter);
    }
}

void Game::update() {
    player->update();

    std::vector<PlayerBullet> newBulletArray = player->shoot();
    for (auto it = newBulletArray.begin(); it != newBulletArray.end(); ++it) {
        playerBulletArray.push_back(*it);
    }

    for (auto it = playerBulletArray.begin(); it != playerBulletArray.end();) {
        it->update();
        if (!it->isInScreen()) {
            it = playerBulletArray.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    player->keyPressEvent(event);

    int keyCode = event->key();
    if (keyCode == Qt::Key_P){
          qDebug() << keyCode;
          Widget::status = 3;
          player->reset();
    }
    if (keyCode == Qt::Key_Escape){
          qDebug() << keyCode;
          Widget::status = 2;
    }
}

void Game::keyReleaseEvent(QKeyEvent *event) {
    player->keyReleaseEvent(event);
}

void Game::mousePressEvent(QMouseEvent *event) {
    player->mousePressEvent(event);
}

void Game::mouseReleaseEvent(QMouseEvent *event) {
    player->mouseReleaseEvent(event);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    player->mouseMoveEvent(event);
}
