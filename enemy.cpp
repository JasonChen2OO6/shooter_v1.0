#include "enemy.h"

Enemy::Enemy(int _size, QPointF _position, float _angle, float _mass, float _velocity,
             int _health, int _interval, int _attack, int _experience) {
    size        = _size;
    position    = _position;
    angle       = _angle;
    mass        = _mass;
    dx          = 0;
    dy          = 0;
    velocity    = _velocity;
    health      = _health;
    interval    = _interval;
    lastShoot   = 0;
    attack      = _attack;
    experience  = _experience;
    life        = 0;
    restRetardTime = 0;
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

void Enemy::repel(QPointF playerPosition, int repelForce) {
    QPointF vec = position - playerPosition;
    float r2 = (vec.x() * vec.x() + vec.y() * vec.y());
    dx += ENM_RPL * vec.x() / r2 / mass;
    dy += ENM_RPL * vec.y() / r2 / mass;
    dx += repelForce * vec.x() / r2 / mass;
    dy += repelForce * vec.y() / r2 / mass;
}
int Enemy::getSize() {
    return size;
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

void Enemy::hurt(int attack, bool isRetard) {
    health -= attack;
    if (isRetard) restRetardTime = MAX_RTD_TIME;
}

Enemy::~Enemy() {

}

Enemy01::Enemy01(QPointF _position) :
    Enemy(ENM01_S, _position, 0, ENM01_M, ENM01_V, ENM01_H, 0, ENM01_A, ENM01_E) {
}

void Enemy01::draw(QPainter &painter) {
    painter.setPen(Qt::red);
    painter.drawEllipse(position.x() - size / 2, position.y() - size / 2, size, size);
}

void Enemy01::update(QPointF playerPosition) {
    ++life;

    dx *= 0.9;
    dy *= 0.9;

    dx += (playerPosition.x() - position.x()) / velocity;
    dy += (playerPosition.y() - position.y()) / velocity;

    if (restRetardTime > 0) {
        --restRetardTime;
        position.rx() += dx * RTD_RATE;
        position.ry() += dy * RTD_RATE;
    } else {
        position.rx() += dx;
        position.ry() += dy;
    }
}

std::vector<EnemyBullet*> Enemy01::shoot(QPointF playerPosition) {
    return std::vector<EnemyBullet*>();
}

Enemy01::~Enemy01() {

}

Enemy02::Enemy02(QPointF _position) :
    Enemy(ENM02_S, _position, 0, ENM02_M, ENM02_V, ENM02_H, 0, ENM02_A, ENM02_E) {

}

void Enemy02::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.drawEllipse(position.x() - size / 2, position.y() - size / 2, size, size);
}

void Enemy02::update(QPointF playerPosition) {
    ++life;

    dx *= 0.9;
    dy *= 0.9;
    dx += (playerPosition.x() - position.x()) / velocity * (sin(life / 30.0) + 1);
    dy += (playerPosition.y() - position.y()) / velocity * (sin(life / 30.0) + 1);

    position.rx() += dx;
    position.ry() += dy;
}

std::vector<EnemyBullet*> Enemy02::shoot(QPointF playerPosition) {
    return std::vector<EnemyBullet*>();
}

Enemy02::~Enemy02() {

}

Enemy03::Enemy03(QPointF _position) :
    Enemy(ENM03_S, _position, 0, ENM03_M, ENM03_V, ENM03_H, 0, ENM03_A, ENM03_E) , interval(ENM03_I){

}

void Enemy03::draw(QPainter &painter) {
    painter.setPen(Qt::darkGreen);
    painter.drawEllipse(position.x() - size / 2, position.y() - size / 2, size, size);
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
    Enemy(EENM01_S, _position, 0, EENM01_M, EENM01_V, EENM01_H, 0, EENM01_A, EENM01_E), interval(EENM01_I) {

}

void EliteEnemy01::draw(QPainter &painter) {
    painter.setPen(Qt::darkYellow);
    painter.drawEllipse(position.x() - size / 2, position.y() - size / 2, size, size);
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

EliteEnemy01::~EliteEnemy01() {

}

Boss01::Boss01(QPointF _position):
    Enemy(BOSS01_S, _position, 0, BOSS01_M, BOSS01_V, BOSS01_H, 0, BOSS01_A, BOSS01_E), interval(BOSS01_I), moveInterval(BOSS01_MI) {

}

void Boss01::draw(QPainter &painter) {
    painter.setPen(Qt::darkRed);
    float angle = life / 50.0;
//    painter.drawEllipse(position.x() - size / 2, position.y() - size / 2, size, size);
    QPointF points1[3] = {
        QPointF(position.x() + size * cos(angle)               , position.y() + size * sin(angle)               ),
        QPointF(position.x() + size * cos(angle + M_PI * 2 / 3), position.y() + size * sin(angle + M_PI * 2 / 3)),
        QPointF(position.x() + size * cos(angle + M_PI * 4 / 3), position.y() + size * sin(angle + M_PI * 4 / 3))
    };
    QPointF points2[3] = {
        QPointF(position.x() + size * cos(-angle)               , position.y() + size * sin(-angle)               ),
        QPointF(position.x() + size * cos(-angle + M_PI * 2 / 3), position.y() + size * sin(-angle + M_PI * 2 / 3)),
        QPointF(position.x() + size * cos(-angle + M_PI * 4 / 3), position.y() + size * sin(-angle + M_PI * 4 / 3))
    };
    painter.drawPolygon(points1, 3);
    painter.drawPolygon(points2, 3);
    QPen pen = QPen(Qt::darkRed);
    pen.setWidth(5);
    painter.setPen(pen);
//    painter.drawArc(position.x() - size * 1.4, position.y() - size * 1.4, size * 2.8, size * 2.8, 90 * 16, (90 + 360.0 * health / BOSS01_H) * 16);
    painter.drawLine(50, WIN_H - 50, (WIN_W - 100) * (1.0 * health / BOSS01_H), WIN_H - 50);
}

void Boss01::update(QPointF playerPosition) {
    ++life;
    if (life % moveInterval == 0) {
        dx = (playerPosition.x() - position.x()) * velocity;
        dy = (playerPosition.y() - position.y()) * velocity;
    }

    dx *= 0.98;
    dy *= 0.98;

    position.rx() += dx;
    position.ry() += dy;
}



std::vector<EnemyBullet*> Boss01::shoot(QPointF playerPosition) {
    std::vector<EnemyBullet*> newEnemyBullet;
    if (life % interval == 0) newEnemyBullet.push_back(new EnemyBullet(position, life * life / 50000.0, BOSS01_BV, attack));
    return newEnemyBullet;
}

Boss01::~Boss01() {

}

SubEnemy::SubEnemy(QPointF _position, float angle):
    Enemy(SENM_S, _position, angle, SENM_M, SENM_V, SENM_H, 0, SENM_A, SENM_E), startPosition(_position), interval(SENM_I), moveInterval(SENM_MI) {
//    qDebug() << "Yes";
}

void SubEnemy::update(QPointF playerPosition) {
    ++life;
    float angle0 = (1.0 * life / moveInterval) * M_PI;
    position = startPosition + QPointF(0.5 * WIN_W * sin(angle0) * cos(angle + angle0), 0.5 * WIN_W * sin(angle0) * sin(angle + angle0));
}

void SubEnemy::draw(QPainter &painter) {
    painter.setPen(Qt::darkCyan);
    float angle0 = (1.0 * life / moveInterval) * M_PI * 2;
    QPointF points[3] = {
        position + QPointF(size / 2 * cos(angle + angle0)               , size / 2 * sin(angle + angle0)               ),
        position + QPointF(size / 2 * cos(angle + angle0 + M_PI * 2 / 3), size / 2 * sin(angle + angle0 + M_PI * 2 / 3)),
        position + QPointF(size / 2 * cos(angle + angle0 + M_PI * 4 / 3), size / 2 * sin(angle + angle0 + M_PI * 4 / 3)),
    };
    painter.drawPolygon(points, 3);
}

std::vector<EnemyBullet *> SubEnemy::shoot(QPointF playerPosition) {
    std::vector<EnemyBullet*> newEnemyBullet;
    if (life % interval == 0) newEnemyBullet.push_back(new EnemyBullet(position, atan2(playerPosition.y() - position.y(), playerPosition.x() - position.x()), SENM_BV, attack));
    return newEnemyBullet;
}

bool SubEnemy::isAlive() {
    return health > 0 && life <= moveInterval;
}

SubEnemy::~SubEnemy() {

}

Boss02::Boss02(QPointF _position, QPointF playerPosition):
    Enemy(BOSS02_S, _position, 0, BOSS02_M, BOSS02_V, BOSS02_H, 0, BOSS02_A, BOSS02_E), nextPosition(playerPosition), interval(BOSS02_I), moveInterval(BOSS02_MI) {

}

void Boss02::update(QPointF playerPosition) {
    ++life;
    if (life % moveInterval == 0) {
        position = nextPosition;
        nextPosition = playerPosition;
    }
}

void Boss02::draw(QPainter &painter) {
    painter.setPen(Qt::darkCyan);
    float angle = (life / 50.0);
    float sizeAngle = (life / 100.0);
    painter.drawEllipse(position + QPointF(size * 0.4 * cos(angle               ), size * 0.4 * sin(angle               )) * sin(sizeAngle), size * 0.7, size * 0.7);
    painter.drawEllipse(position + QPointF(size * 0.4 * cos(angle + M_PI * 2 / 3), size * 0.4 * sin(angle + M_PI * 2 / 3)) * sin(sizeAngle), size * 0.7, size * 0.7);
    painter.drawEllipse(position + QPointF(size * 0.4 * cos(angle + M_PI * 4 / 3), size * 0.4 * sin(angle + M_PI * 4 / 3)) * sin(sizeAngle), size * 0.7, size * 0.7);

    QPen pen = QPen(Qt::darkCyan);
    pen.setWidth(3);
    painter.setPen(pen);

    float scale = (2 + sin(1.0 * life / 30.0) / 2);
    painter.drawLine(nextPosition + QPointF(10, 0) * scale, nextPosition + QPointF(20, 0) * scale);
    painter.drawLine(nextPosition + QPointF(-10, 0) * scale, nextPosition + QPointF(-20, 0) * scale);
    painter.drawLine(nextPosition + QPointF(0, 10) * scale, nextPosition + QPointF(0, 20) * scale);
    painter.drawLine(nextPosition + QPointF(0, -10) * scale, nextPosition + QPointF(0, -20) * scale);

    QColor color = Qt::darkCyan;
    color.setAlphaF(pow(1.0 * (life % moveInterval) / moveInterval, 3));
    pen = QPen(color);
    pen.setWidth(3);
    painter.setPen(pen);
    scale = (1 - pow(1.0 * (life % moveInterval)/ moveInterval, 3));
    painter.drawEllipse(nextPosition, 100 * scale, 100 * scale);
    painter.drawEllipse(nextPosition, 150 * scale, 150 * scale);
}

std::vector<EnemyBullet *> Boss02::shoot(QPointF playerPosition) {
    std::vector<EnemyBullet*> newBulletArray;
    if (life % interval) return newBulletArray;
    int count = 3 + life / moveInterval;
    float angle0 = life / 1000.0;
    for (int i = 0; i < count; i++) {
        newBulletArray.push_back(new EnemyBullet(position, angle0 + M_PI * 2 / count * i, BOSS02_BV, attack));
    }
    return newBulletArray;
}

Boss02::~Boss02() {

}
