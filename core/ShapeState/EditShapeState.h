#ifndef EDITSTATE_H
#define EDITSTATE_H
#include<QMouseEvent>
#include<QGraphicsScene>
#include"../shapes.h"
#include"../layer.h"
class EditState
{
public:
    EditState();
    virtual void mousePressevent(QMouseEvent*) = 0;
    virtual void mouseMoveEvent(QMouseEvent*) =0;
    virtual void mouseReleaseEvent(QMouseEvent*) =0;
    virtual void mouseDoubleClickedEvent(QMouseEvent*) =0;
    void setEditLayer(Layer*);
    void setEditItem(mapObject*);
    void setScene(QGraphicsScene*);
protected:
    mapObject* item;
    Layer* layer;
    QGraphicsScene* scene;
};
class CreatePointState:public EditState
{
public:
    CreatePointState() {}

    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*){}
};

class CreatePolyLineState:public EditState
{
public:
    CreatePolyLineState() {
        this->line = nullptr;
    }

    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*);

private:
    int start  =  0;
    QVector<QPoint> points;
    QVector<int> Parts;
    PolyLine *line;
};

class CreatePolygonState:public EditState
{
public:
    CreatePolygonState() {}

    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*);

private:
    int start  =  0;
    QVector<QPoint> points;
    QVector<int> Parts;
    Polygon *rect;

};

class CreateRectangleState:public EditState
{
public:
    CreateRectangleState() {}
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*);
private:
    bool shouldPress = true;
    int start  =  0;
    QVector<QPoint> points;
    QVector<int> Parts;
    Polygon *rect;
};

class CreateCircleState:public EditState
{
public:
    CreateCircleState() {}
};

class EditMapObjectMoveState
{
public:
    EditMapObjectMoveState() {}
};
class EditMapObjectRotateState
{
public:
    EditMapObjectRotateState() {}
};

class EditMapObjectScaleState
{
public:
    EditMapObjectScaleState() {}
};

class EditMapObjectDelState
{

};

class reStyleMapObjectState
{

};

#endif // EDITSTATE_H
