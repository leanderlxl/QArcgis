#include "selectstate.h"
#include"../mapView.h"
#include<QDebug>
QList<std::unique_ptr<mapObject>> SelectOne::mousePressEvent(mapView2D *view, QMouseEvent *event)
{
    QList<std::unique_ptr<mapObject>> list;
    QGraphicsItem *item = view->itemAt(event->pos());
    qDebug()<<"triggered";
    if (item) {
        qDebug()<<"has one";
        mapObject *mapObj = dynamic_cast<mapObject*>(item);
        if (mapObj) {
            //list.append(std::unique_ptr<mapObject>(new mapObject(*mapObj)));
            qDebug()<<"set one";
            mapObj->setPos(100,100);
        }
    }
    return list;
}

