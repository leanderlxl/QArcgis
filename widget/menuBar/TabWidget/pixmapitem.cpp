#include "pixmapitem.h"
#include<QDebug>
#include <QGraphicsSceneMouseEvent>
pixmapItem::pixmapItem(const QPixmap &pixmap, QGraphicsItem *parent):QGraphicsPixmapItem(pixmap)
{
    Q_UNUSED(parent);
    setAcceptHoverEvents(true);
    hoverMask = new QGraphicsRectItem(this);
    hoverMask->setBrush(QColor(0, 0, 255, 30));
    hoverMask->setRect(this->boundingRect());
    hoverMask->hide();
}
void pixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    Q_UNUSED(event);
    isHoverd = true;
    hoverMask->show();
    //qDebug()<<"mouse hovered";
}
void pixmapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHoverd = false;
    hoverMask->hide();
    //qDebug()<<"mouse hovered cancel mouse leave";
}
void pixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //qDebug()<<"left btn triggered";
    }

}
