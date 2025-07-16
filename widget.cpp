#include "widget.h"
#include "ui_widget.h"

#define WIN_W 1280
#define WIN_H 960

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    title = new Title();
    game = new Game();
    over = new Over();
    pause = new Pause();

    startTimer(10);

    setFixedSize(WIN_W, WIN_H);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event) {
    update();
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    switch (status) {
        case 0:
            title->draw(painter);
            break;
//    case 1:
//            game->draw(painter);
    }
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch (status) {
        case 0:
            title->keyPressEvent(event);
            break;
//        case 1:
//            game->draw(painter);
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event) {

}

int Widget::status = 0;
