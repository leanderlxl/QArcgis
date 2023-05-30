#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QWidget>
#include<QGraphicsPixmapItem>
class pixmapItem:public QGraphicsPixmapItem
{
public:
    pixmapItem() = default;
    pixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    //overrride the hover event
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    bool isHoverd = false;
    QGraphicsRectItem* hoverMask;
signals:

};

#endif // PIXMAPITEM_H
