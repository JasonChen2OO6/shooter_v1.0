#include "title.h"
#include "widget.h"

Title::Title(QObject *obj) {
    button = new QSoundEffect(obj);
    button->setSource(QUrl::fromLocalFile(QDir::current().absoluteFilePath(":/res/button.wav")));
}

void Title::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 100, Qt::AlignCenter, "SHOOTER!");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 50, Qt::AlignCenter, "Press SPACE to start");
}

void Title::keyPressEvent(QKeyEvent *event) {
    int keyCode = event->key();
    if (keyCode == Qt::Key_Space){
          qDebug() << keyCode;
          button->play();
          Widget::status = 1;
    }
}

void Title::keyReleaseEvent(QKeyEvent *event) {

}
