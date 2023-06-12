#include "editorpixmapitem.h"
#include<QDebug>
#include <QGraphicsSceneMouseEvent>
EditorPixmapItem::EditorPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent,EditState* s):QGraphicsPixmapItem(pixmap),state(s)
{
    Q_UNUSED(parent);
    setAcceptHoverEvents(true);
    hoverMask = new QGraphicsRectItem(this);
    hoverMask->setBrush(QColor(0, 0, 255, 30));
    hoverMask->setRect(this->boundingRect());
    hoverMask->hide();
    Widget = nullptr;
}
void EditorPixmapItem::setShowWidget(QWidget *widget)
{
    this->Widget = widget;
}
void EditorPixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    Q_UNUSED(event);
    isHoverd = true;
    hoverMask->show();
    //qDebug()<<"mouse hovered";
}
void EditorPixmapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    isHoverd = false;
    hoverMask->hide();
    //qDebug()<<"mouse hovered cancel mouse leave";
}
void EditorPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
//        qDebug()<<"state emitted";
        if(state)emit sendState(this->state);;
        if(Widget != nullptr)
        {
            emit showWidget(Widget);
        }
        emit clicked();
    }
}

