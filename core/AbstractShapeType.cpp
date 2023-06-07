#include "AbstractShapeType.h"
#include<QDebug>


mapObject::mapObject()
{
    rotate = 0;
    opacity = 0;
    isVisible = 1;
    isSelected  = 0;

    fillColor = Qt::black;

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

    QBrush brush(fillColor);
    painter->setBrush(brush);
//    painter->setBrush(fillStyle);

    painter->setPen(QPen(borderColor, borderWidth, borderStyle));
}
