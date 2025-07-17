#include "enemy.h"

Enemy::Enemy() {

}

void Enemy::draw(QPainter &painter) {
    painter.setPen(Qt::red);
    painter.drawEllipse(position.x() - PLY_SIZE / 2, position.y() - PLY_SIZE / 2, PLY_SIZE, PLY_SIZE);
}

void Enemy::update() {
    position.rx() += cos(angle) * velocity;
    position.ry() += sin(angle) * velocity;

    lastShoot++;
}

std::vector<EnemyBullet> Enemy::shoot() {
    std::vector<EnemyBullet> shootBulletArray;
    shootBulletArray.clear();

    if (lastShoot >= interval) {
        shootBulletArray.push_back(EnemyBullet(position, angle, BLT_SPEED, attack));
        lastShoot = 0;
    }

    return shootBulletArray;
}

QPointF Enemy::getPosition() {
    return position;
}

