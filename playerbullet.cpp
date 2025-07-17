#include "playerbullet.h"

PlayerBullet::PlayerBullet(QPointF _position, float _angle, float _velocity, int _attack) {
    position = _position;
    angle = _angle;
    velocity = _velocity;
    attack = _attack;
}

void PlayerBullet::draw(QPainter &painter) {
    painter.setPen(Qt::black);
    painter.drawEllipse(position.x() - BLT_SIZE / 2, position.y() - BLT_SIZE / 2, BLT_SIZE, BLT_SIZE);
}

void PlayerBullet::update() {
    position.rx() += velocity * cos(angle);
    position.ry() += velocity * sin(angle);   
}

bool PlayerBullet::isInScreen() {
    return position.x() >= 0 && position.x() <= WIN_W && position.y() >= 0 && position.y() <= WIN_H;
}
