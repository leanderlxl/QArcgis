#ifndef SHAPES_H
#define SHAPES_H
#include"AbstractShapeType.h"



class rectangle : public mapObject
{
private:
    qreal x;
    qreal y;
    int width;
    int height;
public:
    // Implement the virtual functions from mapObject
    rectangle(qreal x,qreal y,int width,int height);
    double area() override;
    double length() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SHAPES_H
