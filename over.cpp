#include "over.h"
#include "widget.h"
#include "game.h"

Over::Over() {

}

void Over::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 100, Qt::AlignCenter, "Game over");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 50, Qt::AlignCenter, "EXP: " + QString::number(Widget::experience));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 50, 800, 50, Qt::AlignCenter, "Press R to restart");
}

void Over::keyPressEvent(QKeyEvent *event) {
    int keyCode = event->key();
    if (keyCode == Qt::Key_R){
          qDebug() << keyCode;
          Widget::status = 0;
          Widget::levelUp = 0;
          Widget::experience = 0;
    }
}

void Over::keyReleaseEvent(QKeyEvent *event) {

}
