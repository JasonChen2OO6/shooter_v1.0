#include "pause.h"
#include "widget.h"

Pause::Pause(Player *_player) {
    player = _player;
    pressCode = 0;
}

void Pause::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 100, Qt::AlignCenter, "Pause");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 100, 800, 50, Qt::AlignCenter, "Press ESC to continue");
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 50, 800, 50, Qt::AlignCenter, "Press R to restart");

    player->drawData(painter);

    if (Widget::levelUp > 0) {
        painter.setFont(QFont("Arial", 10));
        painter.drawText(WIN_W / 2 - 400, WIN_H / 2, 800, 50, Qt::AlignCenter, "Select the stat you wish to boost:");

        if (player->getInterval() >= 5) painter.setPen(Qt::gray);
        else if (pressCode == 1) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawText(WIN_W / 2 - 400, WIN_H / 2 + 50, 400, 50, Qt::AlignCenter, "1.ITV++");

        if (player->getVelocity() >= 5) painter.setPen(Qt::gray);
        else if (pressCode == 2) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawText(WIN_W / 2, WIN_H / 2 + 50, 400, 50, Qt::AlignCenter, "2.VEL++");

        if (player->getAttack() >= 5) painter.setPen(Qt::gray);
        else if (pressCode == 3) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawText(WIN_W / 2 - 400, WIN_H / 2 + 100, 400, 50, Qt::AlignCenter, "3.ATK++");

        if (player->getBulletSize() >= 5) painter.setPen(Qt::gray);
        else if (pressCode == 4) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawText(WIN_W / 2, WIN_H / 2 + 100, 400, 50, Qt::AlignCenter, "4.BLTSIZE++");
    }
}

void Pause::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return;
    if (Widget::levelUp > 0) {
        switch (event->key()) {
            case Qt::Key_1:
                pressCode = 1;
                break;
            case Qt::Key_2:
                pressCode = 2;
                break;
            case Qt::Key_3:
                pressCode = 3;
                break;
            case Qt::Key_4:
                pressCode = 4;
                break;
        }
    }
}

void Pause::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:
            pressCode = 0;
            if (player->getInterval() < 5) {
                player->addInterval();
                Widget::levelUp--;
            }
            break;
        case Qt::Key_2:
            pressCode = 0;
            if (player->getVelocity() < 5) {
                player->addVelocity();
                Widget::levelUp--;
            }
            break;
        case Qt::Key_3:
            pressCode = 0;
            if (player->getAttack() < 5) {
                player->addAttack();
                Widget::levelUp--;
            }
            break;
        case Qt::Key_4:
            pressCode = 0;
            if (player->getBulletSize() < 5) {
                player->addBulletSize();
                Widget::levelUp--;
            }
            break;
    }
}
