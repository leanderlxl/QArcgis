#ifndef MAPSCENE2D_H
#define MAPSCENE2D_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include<QWheelEvent>

#include"mapscene.h"
#include"ViewState/statemanager.h"
#include"../../../core/layer.h"
#include"../../../core/layermanager.h"
#include"../../../core/ShapeState/shapeeditor.h"
#include"Editor_bar/editor.h"

#include"../../menuBar/menuCommand/invoker.h"
class mapView2D:public QGraphicsView
{
    Q_OBJECT
public:
    mapView2D(mapScene2D * scene,QWidget *parent = nullptr);

    void setSelectingMode(SelectionState* select);

protected:
    void wheelEvent(QWheelEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    void setRequiredSettings();

public slots:
    void layerActive();

    void updateShapeEditorState(EditState*);

    void finishShapeEdit();

    void invokeCmd(Command * cmd);
private:
    bool isPanning;  // 是否正在平移
    QPoint lastPos;  // 上次鼠标位置
    SelectionStateManager* selection;
    bool isSelecting;
    layerManager* layers;
    Layer* activingLayer;
    Editor* editor;
    Invoker *invoker;
    ShapeEditor* shapeEditor;

};


#endif // MAPSCENE2D_H
