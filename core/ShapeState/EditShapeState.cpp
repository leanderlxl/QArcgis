#include "EditShapeState.h"
#include<QDebug>
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
}

void CreatePolyLineState::mousePressevent(QMouseEvent * e)
{
    if (!points.contains(e->pos())) {
        points.push_back(e->pos());
    }
}

void CreatePolyLineState::mouseDoubleClickedEvent(QMouseEvent * e)
{

    Q_UNUSED(e);

    this->Parts.push_back(start);
    this->Parts.push_back(this->points.size()-1);

    start = this->points.size();
    if(line)
    {
        this->scene->removeItem(line);
        this->layer->removeData(line);
    }
    line = nullptr;
    line = new PolyLine(this->points,this->Parts);

    this->scene->addItem(line);
    this->layer->appendData(line);
}

void CreatePolygonState::mousePressevent(QMouseEvent * e)
{
    if (!points.contains(e->pos())) {
        points.push_back(e->pos());
    }
}

void CreatePolygonState::mouseDoubleClickedEvent(QMouseEvent * e)
{
    qDebug()<<this->points.size();
    this->points.pop_back();
    qDebug()<<this->points.size();

    Q_UNUSED(e);
    this->Parts.push_back(start);



    this->points.push_back(points[start]);
    this->Parts.push_back(this->points.size()-1);
    start = this->points.size();
    if(rect)
    {
        this->scene->removeItem(rect);
        this->layer->removeData(rect);
    }
    rect = nullptr;
    rect = new Polygon(this->points,this->Parts);

    this->scene->addItem(rect);
    this->layer->appendData(rect);
}

void CreateRectangleState::mousePressevent(QMouseEvent* e)
{
    if (shouldPress)
    {
        points.push_back(e->pos());
    }
}

void CreateRectangleState::mouseDoubleClickedEvent(QMouseEvent *e)
{
    Q_UNUSED(e);

    if (points.size() < 2)
    {
        // 至少需要两个点才能绘制矩形
        return;
    }

    QPoint startPoint = points[0];
    QPoint endPoint = points[1];

    // 确保起始点和结束点的 x 坐标和 y 坐标都是矩形的左上角和右下角
    int x = std::min(startPoint.x(), endPoint.x());
    int y = std::min(startPoint.y(), endPoint.y());
    int width = std::abs(startPoint.x() - endPoint.x());
    int height = std::abs(startPoint.y() - endPoint.y());

    // 清除之前的绘制数据
    points.clear();
    Parts.clear();

    // 添加矩形的四个顶点
    points.push_back(QPoint(x, y));
    points.push_back(QPoint(x + width, y));
    points.push_back(QPoint(x + width, y + height));
    points.push_back(QPoint(x, y + height));
    points.push_back(QPoint(x, y));  // 重复添加起始点，以闭合矩形

    // 设置 Parts
    Parts.push_back(0);
    Parts.push_back(points.size() - 1);

    // 移除之前的矩形对象
    if (rect)
    {

        scene->removeItem(rect);
        layer->removeData(rect);
        delete rect;
    }

    // 创建新的矩形对象
    rect = new Polygon(points, Parts);

    // 添加矩形对象到场景和图层
    scene->addItem(rect);
    layer->appendData(rect);
}

//void CreateCircleState::mousePressevent(QMouseEvent * e)
//{

//}

//void CreateCircleState::mouseDoubleClickedEvent(QMouseEvent * e)
//{
//    Q_UNUSED(e);

//    this->Parts.push_back(start);
//    int width = e->pos().x() - points[start].x();

//    int height = e->y() - points[start].y();

//    this->points.push_back(QPoint(points[start].x()+width,points[start].y()));
//    this->points.push_back(QPoint(points[start].x()+width,points[start].y()+height));
//    this->points.push_back(QPoint(points[start].x(),points[start].y()+height));
//    this->points.push_back(points[start]);

//    this->Parts.push_back(this->points.size()-1);
//    start = this->points.size();
//    if(rect)
//    {
//        this->scene->removeItem(rect);
//        this->layer->removeData(rect);
//    }
//    rect = nullptr;
//    rect = new Polygon(this->points,this->Parts);

//    this->scene->addItem(rect);
//    this->layer->appendData(rect);
//}

