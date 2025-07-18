#include "pause.h"
#include "widget.h"

Pause::Pause(Player *_player) {
    player = _player;
    id1 = 0;
    id2 = 0;
    id3 = 0;
    pressCode = 0;
}

#define get(id) (id == 1 ? player->getInterval() :\
                id == 2 ? player->getVelocity() :\
                id == 3 ? player->getAttack() :\
                id == 4 ? player->getBulletSize() : player->getRepelForce())

#define set(id) (id == 1 ? player->addInterval() :\
                id == 2 ? player->addVelocity() :\
                id == 3 ? player->addAttack() :\
                id == 4 ? player->addBulletSize() : player->addRepelForce())

#define get2(id) (id == 1 ? player->getCanSplash() :\
                id == 2 ? player->getCanBounce() :\
                id == 3 ? player->getCanRetard() :\
                id == 4 ? player->getCanPenetrate() :\
                id == 5 ? player->getLongerInvincible() :\
                id == 6 ? player->getHurtInvincible() :\
                id == 7 ? player->getAddHealthByDefeat() :\
                id == 8 ? player->getAddHealthByTime() :\
                id == 9 ? player->getAddShieldByHurt() :\
                id == 10 ? player->getAddShieldByTime() :\
                id == 11 ? player->getCanPassWall() : false)

#define set2(id) (id == 1 ? player->setCanSplash() :\
                id == 2 ? player->setCanBounce() :\
                id == 3 ? player->setCanRetard() :\
                id == 4 ? player->setCanPenetrate() :\
                id == 5 ? player->setLongerInvincible() :\
                id == 6 ? player->setHurtInvincible() :\
                id == 7 ? player->setAddHealthByDefeat() :\
                id == 8 ? player->setAddHealthByTime() :\
                id == 9 ? player->setAddShieldByHurt() :\
                id == 10 ? player->setAddShieldByTime() :\
                id == 11 ? player->setCanPassWall() : player->addHealth(10))

void Pause::draw(QPainter &painter) {
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 400, 800, 100, Qt::AlignCenter, "Pause");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 300, 800, 50, Qt::AlignCenter, "Press ESC to continue");
    painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 250, 800, 50, Qt::AlignCenter, "Press R to restart");

    player->drawData(painter);

    if (Widget::levelUp > 0) {
        if (id1 == 0) {
            getId();
        }
        painter.setFont(QFont("Arial", 10));
        painter.drawText(WIN_W / 2 - 400, WIN_H / 2 - 200, 800, 50, Qt::AlignCenter, "Select the stat you wish to boost:");

        if (pressCode == 1) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawRect(WIN_W / 2 - 550, WIN_H / 2 - 100, 300, 300);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(WIN_W / 2 - 500, WIN_H / 2 + 250, 200, 50, Qt::AlignCenter, "[1]");
        if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) {
            painter.setFont(QFont("Arial", 6));
            printData2(WIN_W / 2 - 600, WIN_H / 2 + 350, 400, 50, painter, id1);
        } else {
            painter.setFont(QFont("Arial", 10));
            printData(WIN_W / 2 - 550, WIN_H / 2, 300, 100, painter, id1);
        }


        if (pressCode == 2) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawRect(WIN_W / 2 - 150, WIN_H / 2 - 100, 300, 300);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(WIN_W / 2 - 100, WIN_H / 2 + 250, 200, 50, Qt::AlignCenter, "[2]");
        if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) {
            painter.setFont(QFont("Arial", 6));
            printData2(WIN_W / 2 - 200, WIN_H / 2 + 350, 400, 50, painter, id2);
        } else {
            painter.setFont(QFont("Arial", 10));
            printData(WIN_W / 2 - 150, WIN_H / 2, 300, 100, painter, id2);
        }

        if (pressCode == 3) painter.setPen(Qt::red);
        else painter.setPen(Qt::blue);
        painter.drawRect(WIN_W / 2 + 250, WIN_H / 2 - 100, 300, 300);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(WIN_W / 2 + 300, WIN_H / 2 + 250, 200, 50, Qt::AlignCenter, "[3]");
        if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) {
            painter.setFont(QFont("Arial", 6));
            printData2(WIN_W / 2 + 200, WIN_H / 2 + 350, 400, 50, painter, id3);
        } else {
            painter.setFont(QFont("Arial", 10));
            printData(WIN_W / 2 + 250, WIN_H / 2, 300, 100, painter, id3);
        }
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
        }
    }
}

void Pause::keyReleaseEvent(QKeyEvent *event) {
    if (Widget::levelUp > 0) {
        switch (event->key()) {
            case Qt::Key_1:
                pressCode = 0;
                if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) set2(id1);
                else set(id1);
                Widget::levelUp--;
                id1 = 0;
                id2 = 0;
                id3 = 0;
                break;
            case Qt::Key_2:
                pressCode = 0;
                if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) set2(id2);
                else set(id2);
                Widget::levelUp--;
                id1 = 0;
                id2 = 0;
                id3 = 0;
                break;
            case Qt::Key_3:
                pressCode = 0;
                if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) set2(id3);
                else set(id3);
                Widget::levelUp--;
                id1 = 0;
                id2 = 0;
                id3 = 0;
                break;
        }
    }
}

void Pause::getId()
{
    if ((player->getLevel() - Widget::levelUp + 1) % 5 == 0) {
        id1 = rand() % 12 + 1;
        id2 = rand() % 12 + 1;
        id3 = rand() % 12 + 1;

        while (id1 == id2 || id1 == id3 || id2 == id3 ||
               get2(id1) == true || get2(id2) == true || get2(id3) == true) {
                id1 = rand() % 12 + 1;
                id2 = rand() % 12 + 1;
                id3 = rand() % 12 + 1;
        }
    } else {
        id1 = rand() % 5 + 1;
        id2 = rand() % 5 + 1;
        id3 = rand() % 5 + 1;

        while (id1 == id2 || id1 == id3 || id2 == id3 ||
               get(id1) >= 5 || get(id2) >= 5 || get(id3) >= 5) {
                id1 = rand() % 5 + 1;
                id2 = rand() % 5 + 1;
                id3 = rand() % 5 + 1;
        }
    }
}

void Pause::printData(int x, int y, int w, int h, QPainter &painter, int id) {
    switch (id) {
        case 1:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "ITV++");
            break;
        case 2:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "VEL++");
            break;
        case 3:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "ATK++");
            break;
        case 4:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "BLT_SIZE++");
            break;
        case 5:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "RPL_FRC++");
            break;
    }
}

void Pause::printData2(int x, int y, int w, int h, QPainter &painter, int id)
{
    switch (id) {
        case 1:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Splash hurts to others");
            break;
        case 2:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Bullets can bounce against walls");
            break;
        case 3:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Enemies become slower when hurt");
            break;
        case 4:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Bullets can go through enemies");
            break;
        case 5:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Longer invincible time");
            break;
        case 6:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Hurt enemies when invincible");
            break;
        case 7:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Add 1 HP when defeat 50 enemies");
            break;
        case 8:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Add 1 HP every 30 sec");
            break;
        case 9:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Obtain a shield when hurt");
            break;
        case 10:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Obtain a shield every 20 sec");
            break;
        case 11:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Bullets can go through walls");
            break;
        case 12:
            painter.drawText(x, y, w, h, Qt::AlignCenter, "Add 10 HP");
            break;
    }
}

#undef get
#undef set
#undef get2
#undef set2
