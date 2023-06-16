#ifndef EDITSTATE_H
#define EDITSTATE_H
#include<QMouseEvent>
#include<QWheelEvent>
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
    virtual void mouseWheelEvent(QWheelEvent*) =0;
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
    void mouseWheelEvent(QWheelEvent*){}
};

class CreatePolyLineState:public EditState
{
public:
    CreatePolyLineState() {
        line = new PolyLine();
        this->Parts.push_back(0);


    }

    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*){

    }
    void mouseDoubleClickedEvent(QMouseEvent*);
    void mouseWheelEvent(QWheelEvent*){}

private:
    bool added = false;

    bool shouldInsertVirtualPoint = true;
    bool firstClickProcess = true;

    bool clicked = false;

    QVector<QPoint> points;
    QVector<int> Parts;
    PolyLine *line;
};

class CreatePolygonState:public EditState
{
public:
    CreatePolygonState()
    {
        this->polygon = new Polygon();
        this->Parts.push_back(0);
    }

    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*);
    void mouseWheelEvent(QWheelEvent*){}

private:
    bool added = false;

    bool shouldInsertVirtualPoint = true;

    bool firstClickProcess = true;
    bool doubleClickProcess = false;

    bool clickedTwice = false;


    QVector<QPoint> points;
    QVector<int> Parts;
    Polygon *polygon;

};

class CreateRectangleState:public EditState
{
public:
    CreateRectangleState()
    {
        this->polygon = new Polygon();
        this->parts.push_back(0);
    }
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*){
    }
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*){}
private:
    bool added = false;

    bool firstClickProcess = true;
    bool clicked = false;
    bool shouldRemoveVirtualPoint = false;

    QVector<QPoint> points;
    QVector<int> parts;
    Polygon *polygon;
};

class CreateCircleState:public EditState
{
public:
    CreateCircleState()
    {
        this->polygon = new Polygon();
        this->parts.push_back(0);
    }

    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*){
    }
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*){}

private:
    bool added = false;

    bool firstClickProcess = true;
    bool clicked = false;
    bool shouldRemoveVirtualPoint = false;

    QPoint center;
    double radius;

    QVector<QPoint> points;
    QVector<int> parts;
    Polygon *polygon;
};
class CreateSectorState:public EditState
{
public:
    CreateSectorState()
    {

        this->polygon = new Polygon();
        this->parts.push_back(0);
    }
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*){
    }
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*){}
private:
    void calculateArc(QMouseEvent*);
private:
    bool added = false;

    bool firstClickProcess = true;
    bool secondClickProcess = false;

    bool clicked = false;
    bool shouldRemoveVirtualPoint = false;

    QPoint center;
    QPoint start;
    double radius;

    QVector<QPoint> points;
    QVector<int> parts;
    Polygon *polygon;
};

class EditMapObjectMoveState:public EditState
{
public:
    EditMapObjectMoveState() {}
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*){}
private:
    bool enableMove = false;
};

class EditMapObjectRotateState:public EditState
{
public:
    EditMapObjectRotateState() {}
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*);
private:
    bool enable = false;
};

class EditMapObjectScaleState:public EditState
{
public:
    EditMapObjectScaleState() {}
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*);
private:
    bool enable = false;
};

class EditMapObjectDelState:public EditState
{
public:
    EditMapObjectDelState() {}
    void mousePressevent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*){}
    void mouseReleaseEvent(QMouseEvent*){}
    void mouseDoubleClickedEvent(QMouseEvent*){}
    void mouseWheelEvent(QWheelEvent*){}
};

class reStyleMapObjectState
{

};



#endif // EDITSTATE_H
