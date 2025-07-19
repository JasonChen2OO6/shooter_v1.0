#ifndef PAUSE_H
#define PAUSE_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QPixmap>
#include <QSoundEffect>
#include <QUrl>

#include "config.h"

#include "player.h"

class Pause {
public:
    Pause(Player *_player, QObject *obj);

    void draw(QPainter &painter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Player *player;

    int id1, id2, id3;
    void getId();
    void printData(int x, int y, int w, int h, QPainter &painter, int id);
    void printData2(int x, int y, int w, int h, QPainter &painter, int id);
    void drawImage(int x, int y, int w, int h, QPainter &painter, int id);

    QPixmap *image1;
    QPixmap *image2;
    QPixmap *image3;
    QPixmap *image4;
    QPixmap *image5;
    QPixmap *image6;
    QPixmap *image7;
    QPixmap *image8;
    QPixmap *image9;
    QPixmap *image10;
    QPixmap *image11;
    QPixmap *image12;

    QSoundEffect *upgrade;

    int pressCode;
};

#endif // PAUSE_H
