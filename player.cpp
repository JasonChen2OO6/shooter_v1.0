#include "player.h"

#include "widget.h"

const int levelUps[11] = {10, 20, 50, 100, 150, 200, 300, 500, 700, 1000, 1000};

Player::Player() {
    position = *new QPointF(WIN_W / 2, WIN_H / 2);
    angle = 0;

    dx = 0;
    dy = 0;
    up = 0;
    down = 0;
    left = 0;
    right = 0;

    canShoot = false;

    health = 10;
    experience = 0;
    level = 0;

    interval = 100;
    lastShoot = 100;

    velocity = 0.2;
    attack = 1;
    bulletSize = 1;
}

void Player::draw(QPainter &painter) {
    painter.setPen(Qt::black);
    painter.drawEllipse(position.x() - PLY_SIZE / 2, position.y() - PLY_SIZE / 2, PLY_SIZE, PLY_SIZE);
    drawData(painter);
}

void Player::drawData(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 10));

    painter.drawText(0, 0, WIN_W, 40, Qt::AlignLeft, "HP: ");
    for (int i = 0; i < health; i++) {
        painter.drawText(90 + i * 30, 0, WIN_W - (90 + i * 30), 40, Qt::AlignLeft, "♥");
    }
    painter.drawText(0, 40, WIN_W, 40, Qt::AlignLeft, "EXP: " + QString::number(experience) + " / " + QString::number(levelUps[level]));
    painter.drawText(0, 80, WIN_W, 40, Qt::AlignLeft, "LV: " + QString::number(level));
    painter.drawText(0, 120, WIN_W, 40, Qt::AlignLeft, "VEL: " + QString::number(velocity));
    painter.drawText(0, 160, WIN_W, 40, Qt::AlignLeft, "ATK: " + QString::number(attack));
    painter.drawText(0, 200, WIN_W, 40, Qt::AlignLeft, "BLTSIZE: " + QString::number(bulletSize));

    if (Widget::levelUp > 0) {
        painter.drawText(0, 0, WIN_W, 40, Qt::AlignRight, "LEVEL UP!");
    }
}

void Player::update() {
    if (experience >= levelUps[level] && level < 10) {
        level++;
        Widget::levelUp++;
    }

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

    lastShoot++;
}

std::vector<PlayerBullet*> Player::shoot() {
    std::vector<PlayerBullet*> shootBulletArray;
    shootBulletArray.clear();

    if (canShoot && lastShoot >= interval) {
        shootBulletArray.push_back(new PlayerBullet(position, angle, BLT_SPEED, attack, bulletSize));
        lastShoot = 0;
    }

    return shootBulletArray;
}

void Player::addExperience(int _experience) {
    experience += _experience;
}

int Player::getExperience() {
    return experience;
}

QPointF Player::getPosition() {
    return position;
}

int Player::getBulletSize() {
    return bulletSize;
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

void Player::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canShoot = true;
        qDebug() << "shoot";
    }
}

void Player::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canShoot = false;
    }
}

void Player::mouseMoveEvent(QMouseEvent *event) {
    angle = atan2(float(event->y() - position.y()), float(event->x() - position.x()));
}

bool Player::isAlive() {
    return health > 0;
}

void Player::hurt(int attack) {
    health -= attack;
}

void Player::reset() {
    up = 0;
    down = 0;
    left = 0;
    right = 0;
}

