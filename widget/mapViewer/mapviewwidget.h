#ifndef MAPVIEWWIDGET_H
#define MAPVIEWWIDGET_H

#include <QWidget>


#include"graphicsView/mapView.h"
#include"graphicsView/mapscene.h"
#include"graphicsView/ViewState/selectstate.h"

#include"../../core/AbstractShapeType.h"



class mapViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mapViewWidget(QWidget *parent = nullptr);

signals:

private:
    void initMapView();
private:
    mapScene2D* scene = nullptr;
    mapView2D* view = nullptr;
    QVector<mapObject*> mapObjectBuffer;

public slots:
    void select();
//    void createLayer();
};

#endif // MAPVIEWWIDGET_H
