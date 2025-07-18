#include "enemybullet.h"

EnemyBullet::EnemyBullet(QPointF _position, float _angle, float _velocity, int _attack) {
    position = _position;
    angle = _angle;
    velocity = _velocity;
    attack = _attack;
}

void EnemyBullet::draw(QPainter &painter) {
    painter.setPen(Qt::red);
    painter.drawEllipse(position.x() - 3, position.y() - 3, 6, 6);
}

void EnemyBullet::update() {
    position.rx() += velocity * cos(angle);
    position.ry() += velocity * sin(angle);
}

bool EnemyBullet::isInScreen() {
    return position.x() >= -WIN_W && position.x() <= WIN_W * 2 && position.y() >= -WIN_H && position.y() <= WIN_H * 2;
}

int EnemyBullet::getAttack() {
    return attack;
}

QPointF EnemyBullet::getPosition() {
    return position;
}
