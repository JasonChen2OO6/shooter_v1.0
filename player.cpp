#include "player.h"

#include "widget.h"


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
    invincibleTime = 100;
    restInvincibleTime = 0;
    experience = 0;
    level = 0;

    lastShoot = 100;


    interval = 1;
    velocity = 1;
    attack = 1;
    bulletSize = 1;
}

void Player::draw(QPainter &painter) {
    painter.setPen(Qt::black);
    if (restInvincibleTime / 10 % 2 == 0) {
        painter.drawEllipse(position.x() - PLY_SIZE / 2, position.y() - PLY_SIZE / 2, PLY_SIZE, PLY_SIZE);
        QPointF triangle[3] = {
            QPointF(position.x() + PLY_SIZE * 0.7 * cos(angle + 20 / 180.0 * M_PI), position.y() + PLY_SIZE * 0.7 * sin(angle + 20 / 180.0 * M_PI)),
            QPointF(position.x() + PLY_SIZE * 0.9 * cos(angle                    ), position.y() + PLY_SIZE * 0.9 * sin(angle                    )),
            QPointF(position.x() + PLY_SIZE * 0.7 * cos(angle - 20 / 180.0 * M_PI), position.y() + PLY_SIZE * 0.7 * sin(angle - 20 / 180.0 * M_PI)),

        };
        painter.drawPolygon(triangle, 3);
    }
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

    painter.drawText(0, 120, WIN_W, 40, Qt::AlignLeft, "ITV: " + QString::number(interval));
    painter.drawText(0, 160, WIN_W, 40, Qt::AlignLeft, "VEL: " + QString::number(velocity));
    painter.drawText(0, 200, WIN_W, 40, Qt::AlignLeft, "ATK: " + QString::number(attack));
    painter.drawText(0, 240, WIN_W, 40, Qt::AlignLeft, "BLTSIZE: " + QString::number(bulletSize));

    if (Widget::levelUp > 0) {
        painter.drawText(0, 0, WIN_W, 40, Qt::AlignRight, "LEVEL UP!");
    }
}

void Player::update() {
    if (restInvincibleTime > 0) --restInvincibleTime;

    if (experience >= levelUps[level] && level < 10) {
        level++;
        Widget::levelUp++;
    }

    dx *= 0.95;
    dy *= 0.95;

    float div = sqrt(up + down + left + right);


    if (up) dy -= velocities[velocity] / div;
    if (down) dy += velocities[velocity] / div;
    if (left) dx -= velocities[velocity] / div;
    if (right) dx += velocities[velocity] / div;

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

    if (canShoot && lastShoot >= intervals[interval]) {
        shootBulletArray.push_back(new PlayerBullet(position, angle, BLT_SPEED, attacks[attack], bulletSizes[bulletSize]));
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

int Player::getInterval() {
    return interval;
}

int Player::getVelocity() {
    return velocity;
}

int Player::getAttack() {
    return attack;
}

int Player::getBulletSize() {
    return bulletSize;
}

void Player::addInterval() {
    interval++;
}

void Player::addVelocity() {
    velocity++;
}

void Player::addAttack() {
    attack++;
}

void Player::addBulletSize() {
    bulletSize++;
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

bool Player::isInvincible() {
    return restInvincibleTime > 0;
}

void Player::hurt(int attack) {
    if (restInvincibleTime > 0) return;
    health -= attack;
    restInvincibleTime = invincibleTime;
}

void Player::reset() {
    up = 0;
    down = 0;
    left = 0;
    right = 0;
}

