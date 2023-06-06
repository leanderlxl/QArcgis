#ifndef SELECTSTATE_H
#define SELECTSTATE_H
#include<QMouseEvent>
#include"../../../core/shapes.h"
#include<memory>
class mapView2D;

class SelectionState
{
public:
    virtual ~SelectionState() {}
    virtual QList<std::unique_ptr<mapObject>> mousePressEvent(mapView2D* view, QMouseEvent* event) = 0;
    virtual QList<std::unique_ptr<mapObject>> mouseMoveEvent(mapView2D* view, QMouseEvent* event) = 0;
    virtual QList<std::unique_ptr<mapObject>> mouseReleaseEvent(mapView2D* view, QMouseEvent* event) = 0;
};

class SelectOne:public SelectionState
{
    QList<std::unique_ptr<mapObject>> mousePressEvent(mapView2D* view, QMouseEvent* event);

    QList<std::unique_ptr<mapObject>> mouseMoveEvent(mapView2D* view, QMouseEvent* event)
    {
        Q_UNUSED(view);
        Q_UNUSED(event);
        QList<std::unique_ptr<mapObject>> tmp;
        return tmp;
    }
    QList<std::unique_ptr<mapObject>> mouseReleaseEvent(mapView2D* view, QMouseEvent* event)
    {
        Q_UNUSED(view);
        Q_UNUSED(event);
        QList<std::unique_ptr<mapObject>> tmp;
        return tmp;
    }
};

#endif // SELECTSTATE_H
