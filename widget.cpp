#include "widget.h"
#include "ui_widget.h"

#define WIN_W 1280
#define WIN_H 960

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    title = new Title(this);
    game = new Game(this);
    over = new Over(this);

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
    }
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch (status) {
        case 0:
            title->keyPressEvent(event);
            break;
        case 1:
            game->keyPressEvent(event);
            if (game->getStatus() == 1 && event->key() == Qt::Key_R) init();
            break;
        case 2:
            over->keyPressEvent(event);
            if (event->key() == Qt::Key_R) init();
            break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return;
    switch (status) {
        case 0:
            title->keyReleaseEvent(event);
            break;
        case 1:
            game->keyReleaseEvent(event);
            break;
        case 2:
            over->keyReleaseEvent(event);
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

void Widget::init() {
    delete game;
    game = new Game(this);
}

int Widget::status = 0;
int Widget::levelUp = 0;
int Widget::experience = 0;
