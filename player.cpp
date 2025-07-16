#include "player.h"

Player::Player() {
    position = *new QPointF(WIN_W / 2, WIN_H / 2);
    angle = 0;
    velocity = 1;
    health = 10;
    experience = 0;
    level = 0;
    interval = 200;
    lastShoot = 0;
    attack = 1;
}

void Player::draw();

void Player::update();

vector<PlayerBullet> Player::shoot();

QPointF Player::getPosition();
