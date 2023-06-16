#include "EditShapeState.h"
#include<QDebug>
#include<qmath.h>
#include"../layermanager.h"
EditState::EditState()
{
}

void EditState::setEditItem(mapObject * item)
{
    this->item = item;
}

void EditState::setEditLayer(Layer * layer)
{
    this->layer = layer;
}

void EditState::setScene(QGraphicsScene * scene)
{
    this->scene = scene;
}

void CreatePointState::mousePressevent(QMouseEvent *e)
{
    mapObject* tmp = new s_Point(e->pos());

    tmp->setObjectId(this->layer->getData().size());
    this->layer->appendData(tmp);
    this->scene->addItem(tmp);
    this->scene->update();
}

void CreatePolyLineState::mousePressevent(QMouseEvent * e)
{
    //if first clicked dont pop back
    if(firstClickProcess)
    {
        this->points.push_back(e->pos());
    }
    else
    {
        this->points.pop_back();
        this->points.push_back(e->pos());
    }
    shouldInsertVirtualPoint = true;
    clicked = true;


    //    qDebug()<<"CreatePolyLineState::mousePressevent "<<"pressed";
}

void CreatePolyLineState::mouseMoveEvent(QMouseEvent * e)
{
    //    qDebug()<<e->pos().x()<<" "<<e->pos().y();
    // update the rear of line
    if(clicked)
    {
        //        qDebug()<<"moving...";
        if(shouldInsertVirtualPoint)
        {
            this->points.push_back(e->pos());
            shouldInsertVirtualPoint = false;
        }
        else
        {
            this->points.pop_back();
            //            qDebug()<<"push new point";
            this->points.push_back(e->pos());
        }


        this->line->updateData(this->points,this->Parts);

        if(!added)
        {
            this->scene->addItem(line);
            added = true;
        }

        this->scene->update();
    }
}

void CreatePolyLineState::mouseDoubleClickedEvent(QMouseEvent * e)
{
    //hanlde the must triggered press event
    this->points.pop_back();
    shouldInsertVirtualPoint = false;


    //    qDebug()<<"CreatePolyLineState::mouseDoubleClickedEvent "<<"mouseDoubleClicke";

    //pop the virtual point
    this->points.pop_back();
    this->points.push_back(e->pos());


    this->line->updateData(this->points,this->Parts);

    this->scene->update();

    clicked = false;
    firstClickProcess = true;

    this->Parts.push_back(this->points.size());

}

void CreatePolygonState::mousePressevent(QMouseEvent * e)
{
    if(firstClickProcess)
    {
        this->points.push_back(e->pos());
        firstClickProcess = false;
        doubleClickProcess = true;
    }
    else if(doubleClickProcess)
    {
        this->points.push_back(e->pos());
        clickedTwice = true;
        doubleClickProcess = false;
        shouldInsertVirtualPoint = true;
    }
    else
    {
        this->points.pop_back();
        this->points.push_back(e->pos());
        shouldInsertVirtualPoint = true;
    }


}

void CreatePolygonState::mouseMoveEvent(QMouseEvent * e)
{
    if(clickedTwice)
    {
        if(shouldInsertVirtualPoint)
        {
            this->points.push_back(e->pos());
            shouldInsertVirtualPoint = false;
        }
        else
        {
            this->points.pop_back();
            //            qDebug()<<"push new point";
            this->points.push_back(e->pos());
        }


        this->polygon->updateData(this->points,this->Parts);

        if(!added)
        {
            this->scene->addItem(polygon);
            added = true;
        }

        this->scene->update();
    }


}

void CreatePolygonState::mouseDoubleClickedEvent(QMouseEvent * e)
{
    //hanlde the must triggered press event
    shouldInsertVirtualPoint = false;

    this->points.pop_back();
    this->points.push_back(e->pos());


    this->polygon->updateData(this->points,this->Parts);

    this->scene->update();

    clickedTwice = false;
    firstClickProcess = true;

    this->Parts.push_back(this->points.size());
}

void CreateRectangleState::mousePressevent(QMouseEvent* e)
{
    if(firstClickProcess)
    {
        this->points.push_back(e->pos());
        clicked = true;
        firstClickProcess = false;
    }
    else
    {
        this->points.pop_back();this->points.pop_back();this->points.pop_back();
        QPoint start = this->points[0];
        int width = e->pos().x() - start.x();
        int height = e->pos().y() - start.y();
        this->points.push_back(QPoint(start.x()+width,start.y()));
        this->points.push_back(e->pos());
        this->points.push_back(QPoint(start.x(),start.y()+height));

        this->polygon->updateData(this->points,this->parts);
        this->scene->update();

        firstClickProcess = true;
        clicked = false;
        shouldRemoveVirtualPoint = false;

        this->parts.push_back(this->points.size());
    }

}

void CreateRectangleState::mouseMoveEvent(QMouseEvent * e)
{
    if(clicked)
    {
        QPoint start = this->points[0];

        int width = e->pos().x() - start.x();
        int height = e->pos().y() - start.y();
        if(shouldRemoveVirtualPoint)
        {
            this->points.pop_back();this->points.pop_back();this->points.pop_back();
        }

        this->points.push_back(QPoint(start.x()+width,start.y()));
        this->points.push_back(e->pos());
        this->points.push_back(QPoint(start.x(),start.y()+height));
        shouldRemoveVirtualPoint = true;

        this->polygon->updateData(this->points,this->parts);

        if(!added)
        {
            this->scene->addItem(polygon);
            added = true;
        }

        this->scene->update();


    }

}

void CreateCircleState::mousePressevent(QMouseEvent * e)
{
    if(firstClickProcess)
    {
        center = e->pos();
        clicked = true;
        firstClickProcess = false;
    }
    else
    {
        this->points.clear();
        int width = e->pos().x() - center.x();
        int height = e->pos().y() - center.y();

        radius = std::sqrt(width*width+height*height);
        for (double angle = 0; angle < 360; angle += 2)
        {
            int x = center.x() + radius * qCos(qDegreesToRadians(angle));
            int y = center.y() + radius * qSin(qDegreesToRadians(angle));

            this->points.push_back(QPoint(x,y));
        }
        this->polygon->updateData(this->points,this->parts);
        this->scene->update();

        firstClickProcess = true;
        clicked = false;
        shouldRemoveVirtualPoint = false;

        this->parts.push_back(this->points.size());
    }
}

void CreateCircleState::mouseMoveEvent(QMouseEvent * e)
{

    if(clicked)
    {


        int width = e->pos().x() - center.x();
        int height = e->pos().y() - center.y();

        radius = std::sqrt(width*width+height*height);

        if(shouldRemoveVirtualPoint)
        {
            this->points.clear();
        }
        for (double angle = 0; angle < 360; angle += 2)
        {
            int x = center.x() + radius * qCos(qDegreesToRadians(angle));
            int y = center.y() + radius * qSin(qDegreesToRadians(angle));

            this->points.push_back(QPoint(x,y));
        }
        shouldRemoveVirtualPoint = true;

        this->polygon->updateData(this->points,this->parts);

        if(!added)
        {
            this->scene->addItem(polygon);
            added = true;
        }

        this->scene->update();
    }
}

void CreateSectorState::mousePressevent(QMouseEvent * e)
{
    if(firstClickProcess)
    {
        center = e->pos();
        firstClickProcess = false;
        secondClickProcess = true;
    }
    else if(secondClickProcess)
    {
        start = e->pos();
        secondClickProcess = false;
        clicked = true;
    }
    else
    {
        this->points.clear();
        this->calculateArc(e);
        this->polygon->updateData(this->points,this->parts);
        this->scene->update();

        firstClickProcess = true;
        clicked = false;
        shouldRemoveVirtualPoint = false;

        this->parts.push_back(this->points.size());
    }
}

void CreateSectorState::calculateArc(QMouseEvent * e)
{
    QLineF startLine(center,start);
    this->points.push_back(center);
    this->points.push_back(start);

    // 构造连接圆心和终点的直线
    double dx = e->pos().x() - center.x();
    double dy = e->pos().y() - center.y();
    double lineLength = std::sqrt(dx * dx + dy * dy);
    double unitX = dx / lineLength;
    double unitY = dy / lineLength;

    double endPointX = center.x() + radius * unitX;
    double endPointY = center.y() + radius * unitY;

    QPoint end(endPointX,endPointY);
    QLineF endLine(center,end);

    //    this->points.push_back(end);

    // 计算圆弧的起始角度和结束角度
    double startAngle = startLine.angle();
    double endAngle = endLine.angle();


    this->radius =  startLine.length();



    if (startAngle < endAngle)
    {
        for (double angle = startAngle; angle <= endAngle; ++angle)
        {
            double x = center.x() + radius * qCos(qDegreesToRadians(angle));
            double y = center.y() + radius * qSin(qDegreesToRadians(angle));
            this->points.push_back(QPoint(x,y));
        }
    }
    else
    {
        for (double angle = startAngle; angle >= endAngle; --angle)
        {
            double x = center.x() + radius * qCos(qDegreesToRadians(angle));
            double y = center.y() + radius * qSin(qDegreesToRadians(angle));
            this->points.push_back(QPoint(x,y));
        }
    }
}

void CreateSectorState::mouseMoveEvent(QMouseEvent * e)
{
    if(clicked)
    {
        if(shouldRemoveVirtualPoint)this->points.clear();
        this->calculateArc(e);
        shouldRemoveVirtualPoint = true;

        this->polygon->updateData(this->points,this->parts);

        if(!added)
        {
            this->scene->addItem(polygon);
            added = true;
        }

        this->scene->update();


    }
}


void EditMapObjectMoveState::mousePressevent(QMouseEvent * e)
{
    if(this->item->contains(e->pos()))
    {
        enableMove = true;
    }
}

void EditMapObjectMoveState::mouseMoveEvent(QMouseEvent * e)
{
    if(enableMove)
    {
        this->item->setPos(e->pos());
    }
}

void EditMapObjectMoveState::mouseReleaseEvent(QMouseEvent *)
{
    enableMove = false;
}

void EditMapObjectRotateState::mousePressevent(QMouseEvent * e)
{
    if(!enable)
    {
        enable = true;
    }
    else
    {
        enable = false;
    }
}

void EditMapObjectRotateState::mouseWheelEvent(QWheelEvent * e)
{
    const qreal rotateFactor = 10;
    if (e->delta() > 0) {
        // 放大
        this->item->Rotate(item->getRotate() + rotateFactor);
    } else {
        // 缩小
        this->item->Rotate(item->getRotate() -rotateFactor);
    }
}

void EditMapObjectScaleState::mousePressevent(QMouseEvent * e)
{
    if(!enable)
    {
        enable = true;
    }
    else
    {
        enable = false;
    }
}

void EditMapObjectScaleState::mouseWheelEvent(QWheelEvent * e)
{
    const qreal scaleFactor = 1.15;
    if (e->delta() > 0) {
        // 放大
        this->item->scale(item->getScale() *scaleFactor);
    } else {
        // 缩小
        this->item->scale(item->getScale() /scaleFactor);
    }
}

void EditMapObjectDelState::mousePressevent(QMouseEvent *e)
{
    if(this->item)
    {
        if(this->item->contains(e->pos()))
        {
            delete this->item;
            layerManager* layers = layerManager::makeLayerManager();
            layers->restoreActivingObject();
        }
    }
}



