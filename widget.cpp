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

    setWindowTitle("SHOOTER!");
    setFixedSize(WIN_W, WIN_H);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event) {
    update();
    if (status == 1) {
        game->update();
    }
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    switch (status) {
        case 0:
            title->draw(painter);
            break;
        case 1:
            game->draw(painter);
            break;
        case 2:
            over->draw(painter);
            break;
        case 3:
            pause->draw(painter);
            break;
    }
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch (status) {
        case 0:
            title->keyPressEvent(event);
            break;
        case 1:
            game->keyPressEvent(event);
            break;
        case 2:
            over->keyPressEvent(event);
            break;
        case 3:
            pause->keyPressEvent(event);
            break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event) {
    switch (status) {
        case 0:
            title->keyReleaseEvent(event);
            break;
        case 1:
            game->keyReleaseEvent(event);
            break;
        case 2:
            over->keyPressEvent(event);
            break;
        case 3:
            pause->keyPressEvent(event);
            break;
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (status == 1) {
        game->mousePressEvent(event);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (status == 1) {
        game->mouseReleaseEvent(event);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (status == 1) {
        game->mouseMoveEvent(event);
    }
}

int Widget::status = 0;
int Widget::levelUp = 0;
