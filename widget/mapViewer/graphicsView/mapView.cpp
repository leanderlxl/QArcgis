#include "mapView.h"
#include<QDebug>
#include<QApplication>
mapView2D::mapView2D(mapScene2D *scene, QWidget *parent):QGraphicsView(scene,parent)
{
    selection = new SelectionStateManager();
//    this->setCursor(Qt::PointingHandCursor); // 设置为手型形态
}

void mapView2D::setRequiredSettings()
{

}
void mapView2D::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);  // 设置缩放锚点为鼠标位置
    double scaleFactor = 1.15;  // 缩放因子，可以根据需要进行调整

    if (event->delta() > 0)
    {
        // 鼠标滚轮向上滚动，进行放大操作
        scale(scaleFactor, scaleFactor);
    }
    else
    {
        // 鼠标滚轮向下滚动，进行缩小操作
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

}

void mapView2D::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void mapView2D::mouseMoveEvent(QMouseEvent *event)
{

    QGraphicsView::mouseMoveEvent(event);
}

void mapView2D::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}
