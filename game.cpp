#include "game.h"
#include "widget.h"

Game::Game() {
    timer = 0;
    player = new Player();
    for (auto enemy : enemyArray) delete enemy;
    enemyArray.clear();
    for (auto bullet : playerBulletArray) delete bullet;
    playerBulletArray.clear();
    for (auto bullet : enemyBulletArray) delete bullet;
    enemyBulletArray.clear();
}

void Game::draw(QPainter &painter) {
    player->draw(painter);

    for (auto bullet : playerBulletArray) {
        bullet->draw(painter);
    }

    for (auto enemy : enemyArray) {
        enemy->draw(painter);
    }
}

void Game::update() {
    ++timer;

    player->update();

    std::vector<PlayerBullet*> newBulletArray = player->shoot();
    for (auto bullet : newBulletArray) {
        playerBulletArray.push_back(bullet);
    }

    for (auto it = playerBulletArray.begin(); it != playerBulletArray.end();) {
        (*it)->update();
        if (!(*it)->isInScreen()) {
            delete *it;
            it = playerBulletArray.erase(it);
        } else {
            ++it;
        }
    }

    if (timer % 100 == 0) {
        float angle = (rand() % 360) / 180.0 * M_PI;
        enemyArray.push_back(new Enemy01(QPointF(player->getPosition().x() + WIN_W * cos(angle), player->getPosition().y() + WIN_W* sin(angle))));
    }

    for (auto enemy : enemyArray) {
        for (auto _enemy : enemyArray) {
            if (enemy == _enemy) continue;
            enemy->repel(_enemy->getPosition());
        }
    }

    for (auto enemy : enemyArray) {
        enemy->update(player->getPosition());
    }

    for (auto it = playerBulletArray.begin(); it != playerBulletArray.end();) {
        bool flag = false;
        for (auto enemy : enemyArray) {
            if (enemy->isAlive() && checkCollision(*it, enemy)) {
                flag = true;
                enemy->hurt((*it)->getAttack());
            }
        }
        if (flag) {
            delete *it;
            it = playerBulletArray.erase(it);
        }
        else ++it;
    }

    for (auto it = enemyArray.begin(); it != enemyArray.end();) {
        if (!(*it)->isAlive()) {
            player->getExperience((*it)->getExperience());
            delete *it;
            it = enemyArray.erase(it);
        }
        else ++it;
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

bool Game::checkCollision(PlayerBullet *playerBullet, Enemy *enemy)
{
    QPointF vec = playerBullet->getPosition() - enemy->getPosition();
    float r = sqrt(vec.x() * vec.x() + vec.y() * vec.y());
    return r < BLT_SIZE / 2 + ENM_SIZE / 2;
}
