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
    Point() = default;
    Point(qreal x,qreal y);
public:
    double length(){ return 0;}
    double area(){ return 0;}
private:
    qreal x;
    qreal y;
};
//abstract type of all shapes
class mapObject:public QGraphicsItem
{
public:
    mapObject();
public:
    // interface for change of mapobjects
    virtual double area() = 0;

    virtual double length() = 0;

    void setTopLeftPos(QPointF);

    //when index is -1 pushBack ,when index outof range do nothing please avoid
    //inserting data in the middle of the container
    void editData(QMap<Point,int>);

    void setVisible(bool);

    void setSelected(bool);

    void scale(qreal);

    void Rotate(qreal);

    QVector<double> getZ();

    //when a new z is inserted ,there mush be a new point
    QVector<QMap<double,int>> setZ();

    QVector<double> getM();

    //when a new  M is inserted ,there mush be a new point
    QVector<QMap<double,int>> setM();

    void setBrushStyle(QBrush,QBrush);

    void setFillStyle(QColor,Qt::BrushStyle);

    void setBorderStyle(QColor,Qt::PenStyle,int);

    //QgraphicsItem has declare these functions to abstract virtual function
    //please override it in subClass

    //QRectF boundingRect();

    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


protected:
    QVector<Point> points;
    int objectId;
    QColor fillColor;
    Qt::BrushStyle fillStyle;
    qreal opacity;
    int penWidth;
    Qt::PenStyle penStyle;
    QColor penColor;
    QBrush penBrush;
    QBrush fillBrush;
    bool selected;
    bool visible;
    qreal  scaleValue;
    qreal rotationAngle;
    QPointF   topLeftPos;
    bool isZ;
    bool isM;
    QVector<double>    ZRange;
    QRectF box;
    QVector<double>  Zarray;
    QVector<double>  MRange;
    QVector<double>  Marray;
};


#endif // MAPOBJECT_H
