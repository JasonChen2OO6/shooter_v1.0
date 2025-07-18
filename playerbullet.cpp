#include "playerbullet.h"

PlayerBullet::PlayerBullet(QPointF _position, float _angle, float _velocity, int _attack, int _bulletSize) {
    position = _position;
    angle = _angle;
    velocity = _velocity;

    attack = _attack;
    bulletSize = _bulletSize;
}

void PlayerBullet::draw(QPainter &painter) {
    painter.setPen(Qt::black);
    painter.drawEllipse(position.x() - BLT_SIZE * bulletSize / 2, position.y() - BLT_SIZE * bulletSize / 2,
                        BLT_SIZE * bulletSize, BLT_SIZE * bulletSize);
}

void PlayerBullet::update() {
    position.rx() += velocity * cos(angle);
    position.ry() += velocity * sin(angle);   
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
