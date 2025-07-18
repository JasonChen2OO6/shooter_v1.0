#include "playerbullet.h"

PlayerBullet::PlayerBullet(QPointF _position, float _angle, float _velocity, int _attack, int _bulletSize, int _bounceTime) {
    position = _position;
    angle = _angle;
    velocity = _velocity;

    dx = velocity * cos(angle);
    dy = velocity * sin(angle);

    attack = _attack;
    bulletSize = _bulletSize;

    bounceTime = _bounceTime;

    for (auto enemy : lastCollidEnemyArray) delete enemy;
    lastCollidEnemyArray.clear();
}

void PlayerBullet::draw(QPainter &painter) {
    painter.setPen(Qt::black);
    painter.drawEllipse(position.x() - bulletSize / 2, position.y() - bulletSize / 2, bulletSize, bulletSize);
}

void PlayerBullet::update() {
    if (bounceTime > 0) {
        if (position.x() <= bulletSize / 2 || position.x() >= WIN_W - bulletSize / 2) {
            dx = -dx;
            bounceTime--;
        }
        if (position.y() <= bulletSize / 2 || position.y() >= WIN_H - bulletSize / 2) {
            dy = -dy;
            bounceTime--;
        }

        position.rx() += dx;
        position.ry() += dy;

        position.rx() = std::min(position.x(), qreal(WIN_W - bulletSize / 2));
        position.rx() = std::max(position.x(), qreal(bulletSize / 2));
        position.ry() = std::min(position.y(), qreal(WIN_H - bulletSize / 2));
        position.ry() = std::max(position.y(), qreal(bulletSize / 2));
    } else {
        position.rx() += dx;
        position.ry() += dy;
    }
}

bool PlayerBullet::isInScreen() {
    return position.x() >= 0 && position.x() <= WIN_W && position.y() >= 0 && position.y() <= WIN_H;
}

QPointF PlayerBullet::getPosition() {
    return position;
}

int PlayerBullet::getAttack() {
    return attack;
}

bool PlayerBullet::checkEnemy(Enemy *enemy) {
    if (std::count(lastCollidEnemyArray.begin(), lastCollidEnemyArray.end(), enemy) > 0) return true;
    else return false;
}

void PlayerBullet::updateEnemyArray(std::vector<Enemy *> array) {
    lastCollidEnemyArray = array;
}
