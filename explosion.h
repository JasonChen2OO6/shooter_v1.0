#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QPointF>
#include <QColor>
#include <vector>
#include <QPainter>

#include "config.h"

class Particle {
public:
    Particle(QPointF _position, QColor _color, int maxTransparency, int maxForce);

    void update();
    void draw(QPainter &painter);

    bool isAlive();

private:
    float dx, dy;
    QPointF position;
    QColor color;
    int transparency;
};

class Explosion
{
public:
    Explosion(QPointF position, int count, int maxForce);

    void update();
    void draw(QPainter &painter);

    bool isAlive();

    ~Explosion();

private:
    std::vector<Particle*> particleArray;
};

#endif // EXPLOSION_H
