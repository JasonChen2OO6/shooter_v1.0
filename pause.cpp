#include "pause.h"
#include "widget.h"

Pause::Pause() {

}

void Pause::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 200, Qt::AlignCenter, "Pause");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 200, Qt::AlignCenter, "Press SPACE to continue");
}

void Pause::keyPressEvent(QKeyEvent *event) {
    int keyCode = event->key();
    if (keyCode == Qt::Key_Space){
          qDebug() << keyCode;
          Widget::status = 1;
    }
    if (keyCode == Qt::Key_Escape){
          qDebug() << keyCode;
          Widget::status = 2;
    }
}

void Pause::keyReleaseEvent(QKeyEvent *event) {

}
