#ifndef WIDGET_H
#define WIDGET_H

#include "title.h"
#include "game.h"
#include "over.h"
#include "pause.h"

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    Title *title = nullptr;
    Game *game = nullptr;
    Over *over = nullptr;
    Pause *pause = nullptr;
    static int status;


private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
