#include "explosion.h"

Particle::Particle(QPointF _position, QColor _color, int maxTransparency, int maxForce) {
    position = _position;
//    color = _color;
    color = Qt::darkBlue;
    float angle = (rand() % 360 / 180.0) * M_PI;
    transparency = (rand() % maxTransparency);
    int force = rand() % maxForce;
    dx = force * cos(angle);
    dy = force * sin(angle);
}

void Particle::update() {
    transparency *= 0.9;
    dx *= 0.9;
    dy *= 0.9;
    position.rx() += dx;
    position.ry() += dy;
}

void Particle::draw(QPainter &painter)
{
    color.setAlpha(transparency);
    painter.setPen(color);
    painter.drawEllipse(position.x() - PTC_SIZE / 2, position.y() - PTC_SIZE / 2, PTC_SIZE, PTC_SIZE);
}

bool Particle::isAlive(){
    return transparency > 0;
}

Explosion::Explosion(QPointF position, int count, int maxForce) {
    while (count--) {
        particleArray.push_back(new Particle(position, QColor(0, 0, 0, 0), 150, maxForce));
    }
}

void Explosion::update() {
    for (auto particle : particleArray) particle->update();
    for (auto it = particleArray.begin(); it != particleArray.end();) {
        if (!(*it)->isAlive()) {
            delete *it;
            it = particleArray.erase(it);
        }
        else ++it;
    }
}

void Explosion::draw(QPainter &painter) {
    for (auto particle : particleArray) particle->draw(painter);
}

bool Explosion::isAlive() {
    return particleArray.size() > 0;
}

Explosion::~Explosion()
{
    for (auto particle : particleArray) delete particle;
    particleArray.clear();
}
