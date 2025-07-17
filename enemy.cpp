#include "enemy.h"

Enemy::Enemy(QPointF _position, float _angle, float _velocity,
             int _health, int _interval, int _attack, int _experience) {
    position = _position;
    angle = _angle;
    dx = 0;
    dy = 0;
    velocity = _velocity;
    health = _health;
    interval = _interval;
    lastShoot = 0;
    attack = _attack;
    experience = _experience;
    life = 0;
}

//std::vector<EnemyBullet> Enemy::shoot() {
//    std::vector<EnemyBullet> shootBulletArray;
//    shootBulletArray.clear();

//    if (lastShoot >= interval) {
//        shootBulletArray.push_back(EnemyBullet(position, angle, BLT_SPEED, attack));
//        lastShoot = 0;
//    }

//    return shootBulletArray;
//}

QPointF Enemy::getPosition() {
    return position;
}

int Enemy::getExperience() {
    return experience;
}

bool Enemy::isAlive() {
    return health > 0;
}

void Enemy::hurt(int attack) {
    health -= attack;
}

Enemy::~Enemy() {

}

Enemy01::Enemy01(QPointF _position) :
    Enemy(_position, 0, ENM01_V, ENM01_H, 0, ENM01_A, ENM01_E) {

}

void Enemy01::draw(QPainter &painter) {
    painter.setPen(Qt::red);
    painter.drawEllipse(position.x() - ENM_SIZE / 2, position.y() - ENM_SIZE / 2, ENM_SIZE, ENM_SIZE);
}

void Enemy01::update(QPointF playerPosition) {
    ++life;

    dx *= 0.9;
    dy *= 0.9;

    dx += (playerPosition.x() - position.x()) / velocity;
    dy += (playerPosition.y() - position.y()) / velocity;

    position.rx() += dx;
    position.ry() += dy;
}

std::vector<EnemyBullet> Enemy01::shoot() {

}

void Enemy01::repel(QPointF enemyPosition) {
    QPointF vec = position - enemyPosition;
    float r2 = (vec.x() * vec.x() + vec.y() * vec.y());
    dx += ENM_RPS * vec.x() / r2;
    dy += ENM_RPS * vec.y() / r2;
}

Enemy01::~Enemy01() {

}
