#include "enemy.h"

Enemy::Enemy(QPointF _position, float _angle, float _mass, float _velocity,
             int _health, int _interval, int _attack, int _experience) {
    position = _position;
    angle = _angle;
    mass = _mass;
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

int Enemy::getAttack() {
    return attack;
}

void Enemy::repel(QPointF playerPosition) {
    QPointF vec = position - playerPosition;
    float r2 = (vec.x() * vec.x() + vec.y() * vec.y());
    dx += ENM_RPL * vec.x() / r2 / mass;
    dy += ENM_RPL * vec.y() / r2 / mass;
}

void Enemy::repulse(QPointF enemyPosition) {
    QPointF vec = position - enemyPosition;
    float r2 = (vec.x() * vec.x() + vec.y() * vec.y());
    dx += ENM_RPS * vec.x() / r2 / mass;
    dy += ENM_RPS * vec.y() / r2 / mass;
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
    Enemy(_position, 0, ENM01_M, ENM01_V, ENM01_H, 0, ENM01_A, ENM01_E) {
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

std::vector<EnemyBullet*> Enemy01::shoot(QPointF playerPosition) {
    return std::vector<EnemyBullet*>();
}

Enemy01::~Enemy01() {

}

Enemy02::Enemy02(QPointF _position) :
    Enemy(_position, 0, ENM02_M, ENM02_V, ENM02_H, 0, ENM02_A, ENM02_E) {

}

void Enemy02::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.drawEllipse(position.x() - ENM_SIZE / 2, position.y() - ENM_SIZE / 2, ENM_SIZE, ENM_SIZE);
}

void Enemy02::update(QPointF playerPosition) {
    ++life;

    dx *= 0.9;
    dy *= 0.9;

    position.rx() += dx;
    position.ry() += dy;
}

std::vector<EnemyBullet*> Enemy02::shoot(QPointF playerPosition) {
    return std::vector<EnemyBullet*>();
}

Enemy02::~Enemy02() {

}

Enemy03::Enemy03(QPointF _position) :
    Enemy(_position, 0, ENM03_M, ENM03_V, ENM03_H, 0, ENM03_A, ENM03_E) , interval(ENM03_I){

}

void Enemy03::draw(QPainter &painter) {
    painter.setPen(Qt::darkGreen);
    painter.drawEllipse(position.x() - ENM_SIZE / 2, position.y() - ENM_SIZE / 2, ENM_SIZE, ENM_SIZE);
}

void Enemy03::update(QPointF playerPosition) {
    ++life;

    dx *= 0.85;
    dy *= 0.85;

    dx += (playerPosition.x() - position.x() - 100) / velocity;
    dy += (playerPosition.y() - position.y() - 100) / velocity;

    QPointF vec = position - playerPosition;
    float r2 = (vec.x() * vec.x() + vec.y() * vec.y());
    dx += ENM_PRPS * vec.x() / r2 / mass;
    dy += ENM_PRPS * vec.y() / r2 / mass;

    position.rx() += dx;
    position.ry() += dy;
}

std::vector<EnemyBullet*> Enemy03::shoot(QPointF playerPosition) {
    std::vector<EnemyBullet*> newEnemyBullet;
    if (life % interval == 0) {
        newEnemyBullet.push_back(new EnemyBullet(position, atan2(playerPosition.y() - position.y(), playerPosition.x() - position.x()), ENM03_BV, attack));
        return newEnemyBullet;
    }
    else return newEnemyBullet;
}

Enemy03::~Enemy03() {

}

EliteEnemy01::EliteEnemy01(QPointF _position):
    Enemy(_position, 0, EENM01_M, EENM01_V, EENM01_H, 0, EENM01_A, EENM01_E), interval(EENM01_I) {

}

void EliteEnemy01::draw(QPainter &painter) {
    painter.setPen(Qt::darkYellow);
    painter.drawEllipse(position.x() - EENM_SIZE / 2, position.y() - EENM_SIZE / 2, EENM_SIZE, EENM_SIZE);
}

void EliteEnemy01::update(QPointF playerPosition) {
    ++life;

    dx *= 0.8;
    dy *= 0.8;

    dx += (playerPosition.x() - position.x()) / velocity;
    dy += (playerPosition.y() - position.y()) / velocity;

    QPointF vec = position - playerPosition;
    float r2 = (vec.x() * vec.x() + vec.y() * vec.y());
    dx += EENM_PRPS * vec.x() / r2 / mass;
    dy += EENM_PRPS * vec.y() / r2 / mass;

    position.rx() += dx;
    position.ry() += dy;
}

std::vector<EnemyBullet*> EliteEnemy01::shoot(QPointF playerPosition) {
    std::vector<EnemyBullet*> newEnemyBullet;
    if (life % interval == 0) {
        float angle0 = (rand() % 360) / 180.0 * M_PI;
        for (int i = 0; i < 16; i++)
            newEnemyBullet.push_back(new EnemyBullet(position, angle0 + M_PI * 2 / 16 * i, EENM01_BV, attack));
        return newEnemyBullet;
    }
    else return newEnemyBullet;
}

EliteEnemy01::~EliteEnemy01()
{

}

