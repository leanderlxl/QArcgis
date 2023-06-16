#include "selectstate.h"
#include"../mapView.h"
#include<QDebug>
QList<mapObject*> SelectOne::mousePressEvent(mapView2D *view, QMouseEvent *event)
{
    QList<mapObject*> list;
    QGraphicsItem *item = view->itemAt(event->pos());
//    qDebug()<<"triggered";
    if (item) {
//        qDebug()<<"has one";
        mapObject *mapObj = dynamic_cast<mapObject*>(item);
        if (mapObj) {
            qDebug()<<mapObj->pos();
            list.append(mapObj);
        }
    }
    return list;
}

