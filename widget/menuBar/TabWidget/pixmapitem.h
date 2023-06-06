#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QObject>

class pixmapItem: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
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
    void clicked( );
};

#endif // PIXMAPITEM_H
