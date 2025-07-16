#ifndef TITLE_H
#define TITLE_H

#include <QDebug>
#include <QPainter>
#include <QKeyEvent>

#include "config.h"


class Title
{
public:
    Title();

    // 处理画笔的函数
    void draw(QPainter &painter);

    // 处理键盘事件的函数
    void keyPressEvent(QKeyEvent *event);
};

#endif // TITLE_H
