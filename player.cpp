#include "player.h"

Player::Player() {
    position = *new QPointF(WIN_W / 2, WIN_H / 2);
    angle = 0;
    velocity = 0.2;
    health = 10;
    experience = 0;
    level = 0;
    interval = 200;
    lastShoot = 0;
    attack = 1;
}

void Player::draw(QPainter &painter) {
    painter.setPen(Qt::black);
    painter.drawEllipse(position.x() - PLY_SIZE / 2, position.y() - PLY_SIZE / 2, PLY_SIZE, PLY_SIZE);
}

void Player::update() {
    dx *= 0.95;
    dy *= 0.95;

    float div = sqrt(up + down + left + right);

    if (up) dy -= velocity / div;
    if (down) dy += velocity / div;
    if (left) dx -= velocity / div;
    if (right) dx += velocity / div;

    if (position.x() <= PLY_SIZE / 2 || position.x() >= WIN_W - PLY_SIZE / 2) dx = -dx;
    if (position.y() <= PLY_SIZE / 2 || position.y() >= WIN_H - PLY_SIZE / 2) dy = -dy;

    position.rx() += dx;
    position.ry() += dy;

    position.rx() = std::min(position.x(), qreal(WIN_W - PLY_SIZE / 2));
    position.rx() = std::max(position.x(), qreal(PLY_SIZE / 2));
    position.ry() = std::min(position.y(), qreal(WIN_H - PLY_SIZE / 2));
    position.ry() = std::max(position.y(), qreal(PLY_SIZE / 2));
}

std::vector<PlayerBullet> Player::shoot() {

}

QPointF Player::getPosition() {
    return position;
}

void Player::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_W:
            up = true;
            break;
        case Qt::Key_S:
            down = true;
            break;
        case Qt::Key_A:
            left = true;
            break;
        case Qt::Key_D:
            right = true;
            break;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_W:
            up = false;
            break;
        case Qt::Key_S:
            down = false;
            break;
        case Qt::Key_A:
            left = false;
            break;
        case Qt::Key_D:
            right = false;
            break;
    }
}

