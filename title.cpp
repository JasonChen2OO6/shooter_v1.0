#include "title.h"
#include "widget.h"

Title::Title()
{

}

void Title::draw(QPainter &painter)
{
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));

    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 200, Qt::AlignCenter, "SHOOTER!");

}

void Title::keyPressEvent(QKeyEvent *event)
{
    int keyCode = event->key();
    if (keyCode == Qt::Key_Space){
          qDebug() << keyCode;
          Widget::status = 1;
    }
}

void Title::keyReleaseEvent(QKeyEvent *event)
{

}
