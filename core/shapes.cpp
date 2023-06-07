#include "shapes.h"
#include<QDebug>
s_Point::s_Point(qreal x, qreal y):mapObject()
{
    this->points.push_back(Point(x,y));
}

double s_Point::area()
{
    return 0;
}

double s_Point::length()
{
    return 0;
}

void s_Point::drawShape(QPainter *painter)
{
//    Point p = points[1];
    painter->setBrush(Qt::black);
//    qDebug()<<"draw circle";
    painter->drawEllipse(100,100, 20,20);
}

void s_Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    mapObject::initPainter(painter);
    this->drawShape(painter);
}

QRectF s_Point::boundingRect() const
{
    int radius = 2;
    int diameter = radius * 2;
    return QRectF(-radius, -radius, diameter, diameter);
}

m_Point::m_Point(int numPoints,QVector<Point> Points,QVector<Point> BoundingBox):mapObject()
{
        this->points = Points;
        this->box = BoundingBox;
        this->numPoints = numPoints;
}
double m_Point::area()
{
    return 0;
}

double m_Point::length()
{
    return 0;
}

void m_Point::drawShape(QPainter *painter)
{

}

void m_Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    mapObject::initPainter(painter);
    this->drawShape(painter);
}

QRectF m_Point::boundingRect() const
{
    int radius = 2;
    int diameter = radius * 2;
    return QRectF(-radius, -radius, diameter, diameter);
}

PolyLine::PolyLine(int numPoints, QVector<Point> Points, int numParts, QVector<int> Parts, QVector<Point> BoundingBox):mapObject()
{
        this->points = Points;
        this->box = BoundingBox;
        this->numPoints = numPoints;
        this->numParts = numParts;
        this->Parts = Parts;
}

double PolyLine::area()
{
    return 0;
}

double PolyLine::length()
{
    // 计算多段直线的总长度
    double totalLength = 0.0;
    for (int i = 0; i < numParts; i++)
    {
        int startIndex = Parts[i];  // 当前线段起始点索引
        int endIndex;               // 当前线段结束点索引

        if (i < numParts - 1)
            endIndex = Parts[i + 1] - 1;  // 下一个线段起始点索引的前一个索引
        else
            endIndex = numPoints - 1;     // 最后一个线段的结束点索引

        // 计算当前线段的长度
        for (int j = startIndex; j < endIndex; j++)
        {
            const Point& p1 = points[j];
            const Point& p2 = points[j + 1];
            totalLength += calculateDistance(p1, p2);
        }
    }

    return totalLength;
}

void PolyLine::drawShape(QPainter* painter)
{
//    // 绘制多段直线
//    for (int i = 0; i < numParts; i++)
//    {
//        int startIndex = Parts[i];  // 当前线段起始点索引
//        int endIndex;               // 当前线段结束点索引

//        if (i < numParts - 1)
//            endIndex = Parts[i + 1] - 1;  // 下一个线段起始点索引的前一个索引
//        else
//            endIndex = numPoints - 1;     // 最后一个线段的结束点索引

//        // 绘制当前线段
//        for (int j = startIndex; j < endIndex; j++)
//        {
//            const Point& p1 = points[j];
//            const Point& p2 = points[j + 1];
//            painter->drawLine(p1.x, p1.y, p2.x, p2.y);
//        }
//    }
}

void PolyLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    mapObject::initPainter(painter);
    this->drawShape(painter);
}

QRectF PolyLine::boundingRect() const
{
    int radius = 2;
    int diameter = radius * 2;
    return QRectF(-radius, -radius, diameter, diameter);
}

Polygon::Polygon(int numPoints, QVector<Point> Points, int numParts, QVector<int> Parts, QVector<Point> BoundingBox):mapObject()
{
        this->points = Points;
        this->box = BoundingBox;
        this->numPoints = numPoints;
        this->numParts = numParts;
        this->Parts = Parts;
}

double Polygon::area()
{
    return 0;
}

double Polygon::length()
{
    return 0;
}

void Polygon::drawShape(QPainter *painter)
{
    int radius = 2;
    int diameter = radius * 2;
    QRectF boundingRect = QRectF(-radius, -radius, diameter, diameter);
    painter->drawEllipse(boundingRect);
}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    mapObject::initPainter(painter);
    this->drawShape(painter);
}

QRectF Polygon::boundingRect() const
{
    int radius = 2;
    int diameter = radius * 2;
    return QRectF(-radius, -radius, diameter, diameter);
}
