#include "shapes.h"
#include<QDebug>
#include<cmath>
#include<QPainterPath>
s_Point::s_Point(qreal x, qreal y):mapObject()
{
    this->points.push_back(Point(x,y));
}
s_Point::s_Point(QPoint p):mapObject()
{
    Point p_(p);
    this->points.push_back(p_);
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
    Point p = points[0];
    qreal radius = 5;

    painter->drawEllipse( p.getScreenPos(),radius, radius);
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
    int radius = 5;
    Point p = points[0];
    return QRectF(p.getScreenPos().x(),p.getScreenPos().y(),10,10);
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
    foreach (Point item, this->points) {
        qreal radius = 5;
        painter->drawEllipse( item.getScreenPos(),radius, radius);
    }
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
    if (points.isEmpty())
        return QRectF(); // 如果没有点，返回一个空的包围盒

    Point firstPoint = points[0]; // 第一个点的引用
    qreal minX = firstPoint.getScreenX();
    qreal minY = firstPoint.getScreenY();
    qreal maxX = firstPoint.getScreenX();
    qreal maxY = firstPoint.getScreenY();

    foreach (Point point, points) {
        qreal x = point.getScreenX();
        qreal y = point.getScreenY();
        if (x < minX)
            minX = x;
        if (y < minY)
            minY = y;
        if (x > maxX)
            maxX = x;
        if (y > maxY)
            maxY = y;
    }

    // 构造包围盒并返回
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

PolyLine::PolyLine(int numPoints, QVector<Point> Points, int numParts, QVector<int> Parts, QVector<Point> BoundingBox)
{
    this->points = Points;
    this->box = BoundingBox;
    this->numPoints = numPoints;
    this->numParts = numParts;
    this->parts = Parts;
}

PolyLine::PolyLine(QVector<QPoint> Points,  QVector<int> Parts)
{
    this->parts = Parts;
    this->numParts = Parts.size();
    this->numPoints = Points.size();
    for (int i = 0; i < Points.size(); ++i) {
        Point p(Points[i]);
        this->points.push_back(p);
    }
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
        int startIndex = parts[i];  // 当前线段起始点索引
        int endIndex;               // 当前线段结束点索引

        if (i < numParts - 1)
            endIndex = parts[i + 1] - 1;  // 下一个线段起始点索引的前一个索引
        else
            endIndex = numPoints - 1;     // 最后一个线段的结束点索引

        // 计算当前线段的长度
        for (int j = startIndex; j < endIndex; j++)
        {
            Point p1 = points[j];
            Point p2 = points[j + 1];
            double dx = p2.getScreenX() - p1.getScreenX();
            double dy = p2.getScreenY() - p1.getScreenY();
            double segmentLength = std::sqrt(dx * dx + dy * dy);
            totalLength += segmentLength;
        }
    }

    return totalLength;
}

void PolyLine::updateData(QVector<QPoint> Points,  QVector<int> Parts)
{
    this->points.clear();
    this->parts.clear();

    this->numParts = Parts.size();
    //    qDebug()<<"PolyLine::updateData numParts "<<this->numParts;

    this->numPoints = Points.size();
    //    qDebug()<<"PolyLine::updateData numPoints "<<this->numPoints;

    for (int i = 0; i < Points.size(); ++i) {
        Point p(Points[i]);
        this->points.push_back(p);
    }

    this->parts = Parts;



}

void PolyLine::drawShape(QPainter* painter)
{


    for (int i = 0; i < this->parts.size(); ++i) {
       int start = this->parts[i];


       int end;
       if(i+1 == this->parts.size())
       {
           end = this->points.size()-1;
       }
       else
       {
           //the end of next start is this line's end
           end = this->parts[i+1] -1;
       }

       QPainterPath path(this->points[start].getScreenPos());

       for (int var = start+1; var <= end; ++var) {
           path.lineTo(this->points[var].getScreenPos());
       }

       painter->drawPath(path);

    }
}

void PolyLine::initPainter(QPainter *painter)
{

    //    QGraphicsItem::setScale(this->m_scale);
    //    QGraphicsItem::setRotation(this->rotate);
    //    QGraphicsItem::setOpacity(this->opacity);

    if(isSelected)
    {
        borderColor = Qt::blue;
    }

    //    QBrush brush(fillColor);
    //    painter->setBrush(fillColor);
    //    painter->setBrush(fillStyle);

    painter->setPen(QPen(borderColor, borderWidth, borderStyle));
}

void PolyLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    this->initPainter(painter);
    this->drawShape(painter);
}

QRectF PolyLine::boundingRect() const
{
    if (points.isEmpty())
        return QRectF(); // 如果没有点，返回一个空的包围盒

    Point firstPoint = points[0]; // 第一个点的引用
    qreal minX = firstPoint.getScreenX();
    qreal minY = firstPoint.getScreenY();
    qreal maxX = firstPoint.getScreenX();
    qreal maxY = firstPoint.getScreenY();

    foreach (Point point, points) {
        qreal x = point.getScreenX();
        qreal y = point.getScreenY();
        if (x < minX)
            minX = x;
        if (y < minY)
            minY = y;
        if (x > maxX)
            maxX = x;
        if (y > maxY)
            maxY = y;
    }

    // 构造包围盒并返回
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}


Polygon::Polygon(int numPoints, QVector<Point> Points, int numParts, QVector< int> Parts, QVector<Point> BoundingBox):mapObject()
{
    this->points = Points;
    this->box = BoundingBox;
    this->numPoints = numPoints;
    this->numParts = numParts;
    this->Parts = Parts;
}

Polygon::Polygon(QVector<QPoint> Points, QVector<int> Parts)
{
    this->Parts = Parts;
    this->numParts = Parts.size();
    this->numPoints = Points.size();
    for (int i = 0; i < Points.size(); ++i) {
        Point p(Points[i]);
        this->points.push_back(p);
    }
}

double Polygon::area()
{
    // 计算多边形的面积
    double totalArea = 0.0;
    for (int i = 0; i < numParts; i++) {
        int startIndex = Parts[i];  // 当前部分起始点索引
        int endIndex;               // 当前部分结束点索引

        if (i < numParts - 1)
            endIndex = Parts[i + 1] - 1;  // 下一个部分起始点索引的前一个索引
        else
            endIndex = numPoints - 1;     // 最后一个部分的结束点索引

        // 计算当前部分的面积
        double partArea = 0.0;
        for (int j = startIndex; j < endIndex; j++) {
            Point p1 = points[j];
            Point p2 = points[j + 1];

            partArea += (p1.getScreenX() * p2.getScreenY() - p2.getScreenX() * p1.getScreenY());
        }

        totalArea += partArea;
    }

    return std::abs(totalArea / 2.0);
}

double Polygon::length()
{
    // 计算多边形的周长
    double totalLength = 0.0;
    for (int i = 0; i < numParts; i++) {
        int startIndex = Parts[i];  // 当前部分起始点索引
        int endIndex = Parts[i+1];               // 当前部分结束点索引
        ++i;


        // 计算当前部分的周长
        double partLength = 0.0;
        for (int j = startIndex; j < endIndex; j++) {
            Point p1 = points[j];
            Point p2 = points[j + 1];

            double dx = p2.getScreenX() - p1.getScreenX();
            double dy = p2.getScreenY() - p1.getScreenY();
            double segmentLength = std::sqrt(dx * dx + dy * dy);
            partLength += segmentLength;
        }

        totalLength += partLength;
    }

    return totalLength;
}

void Polygon::updateData(QVector<QPoint> Points, QVector<int> Parts)
{
    this->points.clear();
    this->Parts.clear();

    this->numParts = Parts.size();
    //    qDebug()<<"PolyLine::updateData numParts "<<this->numParts;

    this->numPoints = Points.size();
    //    qDebug()<<"PolyLine::updateData numPoints "<<this->numPoints;

    for (int i = 0; i < Points.size(); ++i) {
        Point p(Points[i]);
        this->points.push_back(p);
    }

    this->Parts = Parts;



}

void Polygon::drawShape(QPainter *painter)
{

    for (int i = 0; i < this->Parts.size(); ++i) {
       int start = this->Parts[i];


       int end;
       if(i+1 == this->Parts.size())
       {
           end = this->points.size()-1;
       }
       else
       {
           end = this->Parts[i+1]-1;
       }

       QPolygonF polygon;
       for (; start <=end; ++start) {
            polygon<<this->points[start].getScreenPos();
       }

       painter->drawPolygon(polygon);



    }




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
    if (points.isEmpty())
        return QRectF(); // 如果没有点，返回一个空的包围盒

    Point firstPoint = points[0]; // 第一个点的引用
    qreal minX = firstPoint.getScreenX();
    qreal minY = firstPoint.getScreenY();
    qreal maxX = firstPoint.getScreenX();
    qreal maxY = firstPoint.getScreenY();

    foreach (Point point, points) {
        qreal x = point.getScreenX();
        qreal y = point.getScreenY();
        if (x < minX)
            minX = x;
        if (y < minY)
            minY = y;
        if (x > maxX)
            maxX = x;
        if (y > maxY)
            maxY = y;
    }

    // 构造包围盒并返回
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

