#ifndef SELECTSTATE_H
#define SELECTSTATE_H
#include<QMouseEvent>
#include"../../../../core/shapes.h"
#include<memory>
class mapView2D;

class SelectionState
{
public:
    virtual ~SelectionState() {}
    virtual QList<mapObject*> mousePressEvent(mapView2D* view, QMouseEvent* event) = 0;
    virtual QList<mapObject*> mouseMoveEvent(mapView2D* view, QMouseEvent* event) = 0;
    virtual QList<mapObject*> mouseReleaseEvent(mapView2D* view, QMouseEvent* event) = 0;
};

class SelectOne:public SelectionState
{
    ~SelectOne()
    {

    }
    QList<mapObject*> mousePressEvent(mapView2D* view, QMouseEvent* event);

    QList<mapObject*> mouseMoveEvent(mapView2D* view, QMouseEvent* event)
    {
        Q_UNUSED(view);
        Q_UNUSED(event);
        QList<mapObject*> tmp;
        return tmp;
    }

    QList<mapObject*> mouseReleaseEvent(mapView2D* view, QMouseEvent* event)
    {
        Q_UNUSED(view);
        Q_UNUSED(event);
        QList<mapObject*> tmp;
        return tmp;
    }
};

#endif // SELECTSTATE_H
