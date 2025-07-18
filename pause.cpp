#include "pause.h"
#include "widget.h"

Pause::Pause(Player *_player) {
    player = _player;
}

void Pause::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 200, Qt::AlignCenter, "Pause");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 200, Qt::AlignCenter, "Press SPACE to continue");
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 50, 800, 200, Qt::AlignCenter, "Press R to restart");

    player->drawData(painter);

    if (Widget::levelUp > 0) {
        painter.setFont(QFont("Arial", 10));
        painter.drawText(WIN_W / 2 - 400, WIN_H / 2, 800, 200, Qt::AlignCenter, "LEVEL UP!");
    }
}
