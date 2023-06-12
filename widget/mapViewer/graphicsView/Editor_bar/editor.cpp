#include "editor.h"
#include<QDebug>
#include<QStyleOption>
#include"../mapView.h"
Editor::Editor(coreEnum::layerType type,mapView2D *parent) : QDockWidget(parent)
{

    view = new QGraphicsView(this);

    scene = new QGraphicsScene();
    view->setScene(scene);
    dec = Decorator::makeDecorator(type,this);
    dec->loadDecorator(parent);
    initFacade(parent);


}
void Editor::initFacade(mapView2D* parent)
{
        this->move(parent->width()/2-this->size().width()/2,parent->height()-this->height()-10);
}
