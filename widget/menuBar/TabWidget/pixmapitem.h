#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QObject>
#include<QDebug>
class pixmapItem: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pixmapItem() = default;
    pixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    void setShowWidget(QWidget *widget);
private:

    //overrride the hover event
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    bool isHoverd = false;
    QGraphicsRectItem* hoverMask;
    QWidget *Widget;
signals:
    void clicked( );
    void showWidget(QWidget* Widget);
};

#endif // PIXMAPITEM_H
