#ifndef MAPSCENE2D_H
#define MAPSCENE2D_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include<QWheelEvent>
#include"mapscene.h"
#include"ViewState/statemanager.h"
class mapView2D:public QGraphicsView
{
public:
    mapView2D(mapScene2D * scene,QWidget *parent = nullptr);
protected:
    void wheelEvent(QWheelEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event) ;
private:
    void setRequiredSettings();
private:
    bool isPanning;  // 是否正在平移
    QPoint lastPos;  // 上次鼠标位置
    SelectionStateManager* selection;
};
#endif // MAPSCENE2D_H
