#include "game.h"
#include "widget.h"

Game::Game() {
    status = 0;

    timer = 0;

    player = new Player();

    pause = new Pause(player);

    for (auto enemy : enemyArray) delete enemy;
    enemyArray.clear();

    for (auto bullet : playerBulletArray) delete bullet;
    playerBulletArray.clear();

    for (auto bullet : enemyBulletArray) delete bullet;
    enemyBulletArray.clear();
}

void Game::draw(QPainter &painter) {
    if (status == 0) {
        player->draw(painter);

        for (auto bullet : playerBulletArray) {
            bullet->draw(painter);
        }

        for (auto enemy : enemyArray) {
            enemy->draw(painter);
        }

        for (auto bullet : enemyBulletArray) {
            bullet->draw(painter);
        }
    } else {
        pause->draw(painter);
    }
}

void Game::update() {
    if (status == 0) {
        ++timer;

        playerShoot();

        generateEnemy();
        enemyRepulse();
        enemyShoot();

        checkCollision();
        deleteDeadEnemy();

        updateEverything();

        deleteOutScreenBullet();

        Widget::experience = getExperience();

        if (!player->isAlive()) {
            Widget::status = 2;
        }
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    player->keyPressEvent(event);

    if (event->isAutoRepeat()) return;

    int keyCode = event->key();
    if (status == 0 && keyCode == Qt::Key_Escape) {
          qDebug() << keyCode;
          status = 1;
          player->reset();
    } else if (status == 1) {
        pause->keyPressEvent(event);
        if (keyCode == Qt::Key_Escape) {
              qDebug() << keyCode;
              status = 0;
        }
        if (keyCode == Qt::Key_R) {
              qDebug() << keyCode;
              Widget::status = 0;
              Widget::levelUp = 0;
              Widget::experience = 0;
        }
    }
}

void Game::keyReleaseEvent(QKeyEvent *event) {
    player->keyReleaseEvent(event);

    if (status == 1) {
        pause->keyReleaseEvent(event);
    }
}

void Game::mousePressEvent(QMouseEvent *event) {
    player->mousePressEvent(event);
}

void Game::mouseReleaseEvent(QMouseEvent *event) {
    player->mouseReleaseEvent(event);
}

void Game::mouseMoveEvent(QMouseEvent *event) {
    player->mouseMoveEvent(event);
}

int Game::getStatus() {
    return status;
}

int Game::getExperience() {
    return player->getExperience();
}

Game::~Game() {
    delete player;

    delete pause;

    for (auto enemy : enemyArray) delete enemy;
    enemyArray.clear();

    for (auto bullet : playerBulletArray) delete bullet;
    playerBulletArray.clear();

    for (auto bullet : enemyBulletArray) delete bullet;
    enemyBulletArray.clear();
}

void Game::playerShoot()
{
    auto newBulletArray = player->shoot();
    playerBulletArray.insert(playerBulletArray.end(), newBulletArray.begin(), newBulletArray.end());
}

void Game::generateEnemy() {
    if (timer % 100 == 0) {
        float angle = (rand() % 360) / 180.0 * M_PI;
        enemyArray.push_back(new Enemy01(QPointF(player->getPosition().x() + WIN_W * cos(angle), player->getPosition().y() + WIN_W * sin(angle))));
    }

    if (timer > 1000 && timer % 300 == 0) {
        float angle = (rand() % 360) / 180 * M_PI;
        enemyArray.push_back(new Enemy02(QPointF(player->getPosition().x() + WIN_W * cos(angle), player->getPosition().y() + WIN_W * sin(angle))));
    }

    if (timer > 2000 && timer % 800 == 0) {
        float angle = (rand() % 360) / 180.0 * M_PI;
        enemyArray.push_back(new Enemy03(QPointF(player->getPosition().x() + WIN_W * cos(angle), player->getPosition().y() + WIN_W * sin(angle))));

    }
    if (timer % 1000 == 0) {
        float angle = (rand() % 360) / 180.0 * M_PI;
        enemyArray.push_back(new EliteEnemy01(QPointF(player->getPosition().x() + WIN_W * cos(angle), player->getPosition().y() + WIN_W * sin(angle))));

    }
}

void Game::enemyRepulse() {
    for (auto enemy : enemyArray) {
        for (auto _enemy : enemyArray) {
            if (enemy == _enemy) continue;
            enemy->repulse(_enemy->getPosition());
        }
    }

}

void Game::enemyShoot() {
    for (auto enemy : enemyArray) {
        auto newBulletArray = enemy->shoot(player->getPosition());
        enemyBulletArray.insert(enemyBulletArray.end(), newBulletArray.begin(), newBulletArray.end());
    }

}

void Game::checkCollision() {
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

    bool flag = false;
    for (auto enemy : enemyArray) {
        if (enemy->isAlive() && checkCollision(player, enemy)) {
            flag = true;
            player->hurt(enemy->getAttack());
            if (!player->isInvincible()) {
                enemy->hurt(player->getAttack());
            }
        }
    }

    for (auto it = enemyBulletArray.begin(); it != enemyBulletArray.end();) {
        if (checkCollision(player, *it)) {
            flag = true;
            player->hurt((*it)->getAttack());
            delete *it;
            it = enemyBulletArray.erase(it);
        }
        else ++it;
    }


    if (flag) {
        for (auto enemy : enemyArray) {
            enemy->repel(player->getPosition());
        }
        for (auto it = enemyBulletArray.begin(); it != enemyBulletArray.end();) {
            if (dist(player, *it) < ENMB_CLR_RG) {
                delete *it;
                it = enemyBulletArray.erase(it);
            }
            else ++it;
        }
    }
}

void Game::deleteDeadEnemy() {
    for (auto it = enemyArray.begin(); it != enemyArray.end();) {
        if (!(*it)->isAlive()) {
            player->addExperience((*it)->getExperience());
            delete *it;
            it = enemyArray.erase(it);
        }
        else ++it;
    }
}

void Game::updateEverything() {
    player->update();
    for (auto bullet : playerBulletArray) bullet->update();
    for (auto bullet : enemyBulletArray) bullet->update();
    for (auto enemy : enemyArray) enemy->update(player->getPosition());
}

void Game::deleteOutScreenBullet() {
    for (auto it = playerBulletArray.begin(); it != playerBulletArray.end();) {
        if (!(*it)->isInScreen()) {
            delete *it;
            it = playerBulletArray.erase(it);
        } else {
            ++it;
        }
    }
    for (auto it = enemyBulletArray.begin(); it != enemyBulletArray.end();) {
        if (!(*it)->isInScreen()) {
            delete *it;
            it = enemyBulletArray.erase(it);
        } else {
            ++it;
        }
    }

}


bool Game::checkCollision(Player *player, Enemy *enemy) {
    return dist(player, enemy) < PLY_SIZE / 2 + ENM_SIZE / 2;
}


bool Game::checkCollision(PlayerBullet *playerBullet, Enemy *enemy) {
    return dist(playerBullet, enemy) < bulletSizes[player->getBulletSize()] / 2 + ENM_SIZE / 2;
}

bool Game::checkCollision(Player *player, EnemyBullet *enemyBullet) {
    return dist(player, enemyBullet) < PLY_SIZE / 2 + BLT_SIZE / 2;
}

template<typename T1, typename T2>
float Game::dist(T1 a, T2 b) {
    QPointF vec = a->getPosition() - b->getPosition();
    return sqrt(vec.x() * vec.x() + vec.y() * vec.y());
}
