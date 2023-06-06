#include "mapviewwidget.h"
#include<QDebug>
mapViewWidget::mapViewWidget(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(230,155,1120,570);
    this->initMapView();
}
void mapViewWidget::initMapView()
{

    //binding view and scnene
    scene = new mapScene2D();
    view = new mapView2D(scene,this);
    view->setRenderHint(QPainter::Antialiasing);
//    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setGeometry(0,0,this->width(),this->height()-5);

    // Create a rectangle
    QGraphicsItem* rectItem2 = new rectangle(0, 0, 100, 100);
    rectItem2->setPos(0,0); // Set the position of the rectangle

    // Add the rectangle to the scene
    scene->addItem(rectItem2);
    //add baseMap layers
    layers = layerManager::makeLayerManager();
}
void mapViewWidget::select()
{

}
