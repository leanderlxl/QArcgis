#ifndef EDITOR_H
#define EDITOR_H
#include"../../../../core/layer.h"
#include"decorator.h"
#include <QDockWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
class Editor : public QDockWidget
{
    Q_OBJECT
public:
    explicit Editor(coreEnum::layerType,mapView2D *parent = nullptr);
private:
    void initFacade(mapView2D* parent);
private:
    Decorator* dec;
public:
    QGraphicsView *view;
    QGraphicsScene *scene;
signals:

};

#endif // EDITOR_H
