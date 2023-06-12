#include "mapView.h"
#include<QDebug>
#include<QApplication>
mapView2D::mapView2D(mapScene2D *scene, QWidget *parent):QGraphicsView(scene,parent)
{
    selection = new SelectionStateManager();
    layers = layerManager::makeLayerManager();

    connect(layers,&layerManager::LayerActivtate,this,&mapView2D::layerActive);
    activingLayer = nullptr;
    shapeEditor = new ShapeEditor();
}

void mapView2D::setRequiredSettings()
{

}
void mapView2D::setSelectingMode(SelectionState* select)
{
   this->isSelecting = true;
   this->setCursor(Qt::PointingHandCursor); // 设置为手型形态
   selection->setState(select);
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
    this->scene()->setSceneRect(this->rect());
}

void mapView2D::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if(isSelecting)
    {
        QList<mapObject*> list = selection->mousePressEvent(this,event);

    }

    if(activingLayer)
    {
        shapeEditor->mousePressEvent(event);
    }
}

void mapView2D::mouseMoveEvent(QMouseEvent *event)
{

    QGraphicsView::mouseMoveEvent(event);
    if(isSelecting)
    {
        selection->mouseMoveEvent(this,event);
    }
    if(activingLayer)
    {
        shapeEditor->mouseMoveEvent(event);
    }
}

void mapView2D::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    //if release , all events stop
    if(isSelecting)
    {
        isSelecting = false;
        selection->mouseReleaseEvent(this,event);
    }
    if(activingLayer)
    {
        shapeEditor->mouseReleaseEvent(event);
    }
    this->setCursor(Qt::ArrowCursor);
}
void mapView2D::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(activingLayer)
    {
        shapeEditor->mouseDoubleClickedEvent(event);
    }
}
void mapView2D::layerActive()
{
    this->activingLayer = layers->getActiveLayer();
    editor = new Editor(this->activingLayer->getType(),this);
    editor->show();
}
void mapView2D::updateShapeEditorState(EditState * s)
{
//    qDebug()<<"signale recv";
    s->setScene(this->scene());
    s->setEditLayer(this->activingLayer);
    this->shapeEditor->setState(s);
}
void mapView2D::finishShapeEdit()
{
    qDebug()<<"recv";
    this->layers->restoreActiveLayer();
    this->activingLayer = nullptr;
    this->editor->close();
}
