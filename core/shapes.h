#ifndef SHAPES_H
#define SHAPES_H
#include"AbstractShapeType.h"
class s_Point:public mapObject
{
public:
    s_Point(qreal x, qreal y);

    double area()override;
    double length()override;

    void drawShape(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;


private:
    double x,y;
};

//definition of multi point
class m_Point:public mapObject
{
public:
    m_Point(int numPoints,QVector<Point> Points,QVector<Point> BoundingBox);

    double area()override;
    double length()override;

    void drawShape(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

};

class PolyLine:public mapObject
{
public:
    PolyLine(int numPoints,QVector<Point> Points,int numParts,QVector<int> Parts,QVector<Point> BoundingBox);

    double area()override;
    double length()override;

    void drawShape(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
private:
        int numParts;
        QVector<int> Parts;
};

class Polygon:public mapObject
{
public:
    Polygon(int numPoints,QVector<Point> Points,int numParts,QVector<int> Parts,QVector<Point> BoundingBox);

    double area()override;
    double length()override;

    void drawShape(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
private:
        int numParts;
        QVector<int> Parts;
};
#endif // SHAPES_H
