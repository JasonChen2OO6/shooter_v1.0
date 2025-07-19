#include "over.h"
#include "widget.h"
#include "game.h"

Over::Over(QObject *obj) {
    button = new QSoundEffect(obj);
    button->setSource(QUrl::fromLocalFile(QDir::current().absoluteFilePath(":/res/button.wav")));
}

void Over::draw(QPainter &painter) {
    painter.setPen(Qt::darkBlue);
    painter.setFont(QFont("Arial", 60));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 100, Qt::AlignCenter, "Game over");

    painter.setFont(QFont("Arial", 30));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 50, Qt::AlignCenter, "EXP: " + QString::number(Widget::experience));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 50, 800, 50, Qt::AlignCenter, "Press R to restart");
}

void Over::keyPressEvent(QKeyEvent *event) {
    int keyCode = event->key();
    if (keyCode == Qt::Key_R){
          qDebug() << keyCode;
          button->play();
          Widget::status = 0;
          Widget::levelUp = 0;
          Widget::experience = 0;
    }
}

void Over::keyReleaseEvent(QKeyEvent *event) {

}
