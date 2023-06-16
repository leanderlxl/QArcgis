#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include<QString>
#include<QVector>
#include<QGraphicsItem>
#include<QBrush>
#include<QMap>
#include<QPainter>

//avoid polution to the outter namespace
//the namespace of core including needed enumeration for this part
namespace coreEnum {
enum layerType
{
    point,
    multiPoint,
    polyLine,
    polyGon,
    baseMap,
    null
};
}

class Point
{
public:
    //delete the default constructor would cause error
    //but i dont know why
    Point() = default;
    Point(QPoint);
    Point(qreal x,qreal y)
    {
        this->x = x;
        this->y = y;
    }
    QVector<double> getPos()
    {
        QVector<double> pos;
        pos.push_back(x);
        pos.push_back(y);
        return pos;
    }
    void setPos(qreal x,qreal y)
    {
            this->x = x;
            this->y = y;
    }
    void setScreenPos(QPointF pos)
    {
        this->pos = pos;
    }
    void setScreenX(int X)
    {
        this->pos.setX(X);
    }
    int getScreenX()
    {
        return this->pos.x();
    }
    void setScreenY(int Y)
    {
        this->pos.setY(Y);
    }
    int getScreenY()
    {
        return this->pos.y();
    }

    QPointF getScreenPos()
    {
        return pos;
    }

private:
    qreal x;
    qreal y;
    QPointF pos;
};
//abstract type of all shapes
class mapObject:public QGraphicsItem
{
public:
    mapObject();
public:
    // interface
    virtual double area() = 0;

    virtual double length() = 0;


    //when index is -1 pushBack ,when index outof range
    //do nothing please
    //avoid inserting data in the middle of the container
    void editData(QMap<Point,int>);


    QVector<double> getZ();

    //when a new z is inserted ,there mush be a new point
    QVector<QMap<double,int>> setZ();

    QVector<double> getM();

    //when a new  M is inserted ,there mush be a new point
    QVector<QMap<double,int>> setM();

    void appendData();

    void updatePoints(QVector<QPoint>);

    //pure virtual function that should be overrideed

    //QRectF boundingRect();

    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    //style releated

    void scale(qreal);

    qreal getScale();

    void Rotate(qreal);

    qreal getRotate();

    void Visible(bool);

    void Selected(bool);

    void Opacity(qreal);

    qreal getOpacity();

    void FillStyle(QColor,Qt::BrushStyle);

    void BorderStyle(QColor,Qt::PenStyle,int);

    void setActive(bool active);

    //templates for draw shapes
    virtual void initPainter(QPainter *painter);
    virtual void drawShape(QPainter *painter) = 0;

    void setObjectId(int);
protected:
    int objectId;
    int numPoints;

    QVector<Point> box;
    QVector<Point> points;



    bool isZ;
    QVector<double>  ZRange;
    QVector<double>  Zarray;

    bool isM;
    QVector<double>  MRange;
    QVector<double>  Marray;


    //    style
    //the first is scale the second is rotate the third is opacity
    qreal m_scale,rotate,opacity;

    bool isVisible,isSelected;

    //fillcolor for fill, borderColor for setting pen color
    QColor fillColor,borderColor;

    Qt::BrushStyle fillStyle;
    Qt::PenStyle borderStyle;

    int borderWidth;
};


#endif // MAPOBJECT_H
