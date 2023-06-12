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

    view->setGeometry(0,0,this->width()-5,this->height()-5);
    scene->setSceneRect(view->rect());


}

void mapViewWidget::select()
{
    //    qDebug()<<"select one";
    view->setSelectingMode(new SelectOne());
}
