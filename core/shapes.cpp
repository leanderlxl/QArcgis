#include "shapes.h"

rectangle::rectangle(qreal x, qreal y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    // Insert the points into the points vector
    points.push_back(Point(x, y));
    points.push_back(Point(x + width, y));
    points.push_back(Point(x + width, y + height));
    points.push_back(Point(x, y + height));
}
double rectangle::area()
{
    // Calculate and return the area of the rectangle
}

double rectangle::length()
{
    // Calculate and return the length of the rectangle
}

QRectF rectangle::boundingRect() const
{
    // Implement the bounding rectangle of the rectangle object
    return QRectF(x, y, width, height);
}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Implement the painting of the rectangle object
    QRectF rect(x, y, width, height);

//    // Set the pen and brush for the rectangle
//    QPen pen(penColor, penWidth, penStyle);
//    QBrush brush(fillColor, fillStyle);

//    // Apply the pen and brush to the painter
//    painter->setPen(pen);
//    painter->setBrush(brush);

    // Draw the rectangle
    painter->drawRect(rect);
}

Point::Point(qreal x, qreal y)
{
    this->x = x;
    this->y = y;

    // Insert the point into the points vector
//    points.push_back(QPointF(x, y));
}
