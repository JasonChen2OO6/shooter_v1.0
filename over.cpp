#include "over.h"
#include "widget.h"

Over::Over() {

}

void Over::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 200, Qt::AlignCenter, "Game over");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 200, Qt::AlignCenter, "Press R to restart");
}

void Over::keyPressEvent(QKeyEvent *event) {

}

void Over::keyReleaseEvent(QKeyEvent *event) {

}
