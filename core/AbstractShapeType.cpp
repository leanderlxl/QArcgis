#include "AbstractShapeType.h"
#include<QDebug>


mapObject::mapObject()
{

}


void mapObject::setTopLeftPos(QPointF position)
{
    topLeftPos = position;
}

void mapObject::editData(QMap<Point, int> data)
{
    // Edit the data implementation
}

void mapObject::setVisible(bool visibility)
{
    visible = visibility;
}

void mapObject::setSelected(bool selection)
{
    selected = selection;
}

void mapObject::scale(qreal scaleFactor)
{
    scaleValue = scaleFactor;
}

void mapObject::Rotate(qreal angle)
{
    rotationAngle = angle;
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

void mapObject::setBrushStyle(QBrush brush, QBrush style)
{
    fillBrush = brush;
    //fillStyle = style;
}

void mapObject::setFillStyle(QColor color, Qt::BrushStyle style)
{
    fillColor = color;
    fillStyle = style;
}

void mapObject::setBorderStyle(QColor color, Qt::PenStyle style, int width)
{
    penColor = color;
    penStyle = style;
    penWidth = width;
}

