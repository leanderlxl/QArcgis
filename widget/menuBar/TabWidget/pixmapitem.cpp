#include "pixmapitem.h"
#include<QDebug>
pixmapItem::pixmapItem(const QPixmap &pixmap, QGraphicsItem *parent):QGraphicsPixmapItem(pixmap)
{
    Q_UNUSED(parent);
}
void pixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHoverd = true;
    qDebug()<<"mouse hovered";
}
void pixmapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHoverd = false;
    qDebug()<<"mouse hovered cancel mouse leave";
}
