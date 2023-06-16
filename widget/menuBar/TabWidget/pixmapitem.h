#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QObject>
#include<QDebug>

#include"../menuCommand/command.h"
class pixmapItem: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pixmapItem() = default;
    pixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr,Command* command = nullptr);


private:

    //overrride the hover event
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    bool isHoverd = false;
    QGraphicsRectItem* hoverMask;
    Command* cmd;

signals:
    void clicked();

    void sendCommand(Command*);
};

#endif // PIXMAPITEM_H
