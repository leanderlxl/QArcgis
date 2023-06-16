#include "AbstractShapeType.h"
#include<QDebug>
Point::Point(QPoint p)
{
    this->pos = p;
}

mapObject::mapObject()
{
    rotate = 0;
    opacity = 1.0;
    m_scale = 1;
    isVisible = true;
    isSelected  = false;


    fillColor = Qt::red;
    fillStyle = Qt::HorPattern;

    borderStyle = Qt::SolidLine;
    borderColor = Qt::black;
    borderWidth = 2;
}


void mapObject::editData(QMap<Point, int> data)
{
    // Edit the data implementation
}

QVector<double> mapObject::getZ()
{
    return ZRange;
}

QVector<QMap<double, int>> mapObject::setZ()
{
    QVector<QMap<double, int>> zData;
    // Set Z data implementation
    return zData;
}

QVector<double> mapObject::getM()
{
    return MRange;
}

QVector<QMap<double, int>> mapObject::setM()
{
    QVector<QMap<double, int>> mData;
    // Set M data implementation
    return mData;
}


void mapObject::Rotate(qreal angle)
{
    this->rotate = angle;
    update();
}


void mapObject::scale(qreal scaleFactor)
{
    this->m_scale = scaleFactor;
    update();
}


void mapObject::Visible(bool visibility)
{
    this->isVisible = visibility;
    update();
}


void mapObject::Selected(bool selection)
{
    this->isSelected = selection;
    update();
}


void mapObject::Opacity(qreal opacity)
{
    this->opacity = opacity;
    update();
}


void mapObject::FillStyle(QColor color, Qt::BrushStyle style)
{
    fillColor = color;
    fillStyle = style;
    update();
}



void mapObject::BorderStyle(QColor color, Qt::PenStyle style, int width)
{
    this->borderColor = color;
    this->borderStyle = style;
    this->borderWidth = width;
    update();
}
void mapObject::initPainter(QPainter *painter)
{

    QGraphicsItem::setScale(this->m_scale);
    QGraphicsItem::setRotation(this->rotate);
    QGraphicsItem::setOpacity(this->opacity);

    if(isSelected)
    {
        borderColor = Qt::blue;
    }

    QBrush brush(fillColor,fillStyle);
    painter->setBrush(brush);


    painter->setPen(QPen(borderColor, borderWidth, borderStyle));
}
void mapObject::setObjectId(int i)
{
    this->objectId = i;
}

//this method will update all the points in the container
void mapObject::updatePoints(QVector<QPoint> p)
{
    foreach (auto item, p) {
        this->points.clear();
        Point p(item);
        this->points.push_back(p);
    }
}

void mapObject::setActive(bool active)
{
    isSelected = active;
    QGraphicsItem::setActive(active);
    this->update();
}

qreal mapObject::getScale()
{
    return this->m_scale;
}

qreal mapObject::getRotate()
{
    return this->rotate;
}

qreal mapObject::getOpacity()
{
    return this->opacity;
}
