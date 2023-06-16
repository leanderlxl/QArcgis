#ifndef EditorPixmapItem_H
#define EditorPixmapItem_H


#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QObject>
#include<QDebug>
#include"../../../../core/ShapeState/shapeeditor.h"
class EditorPixmapItem: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    EditorPixmapItem() = default;
    EditorPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr,EditState* state = nullptr);

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
    EditState* state;
signals:
    void sendState(EditState*);
    void clicked();
    void showWidget(QWidget* Widget);
};

#endif // EditorPixmapItem_H

