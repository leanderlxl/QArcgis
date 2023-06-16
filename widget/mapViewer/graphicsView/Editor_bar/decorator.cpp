#include"decorator.h"

#include"editor.h"
#include<QObject>
#include"../mapView.h"

//模板与装饰器模式
Decorator* Decorator::makeDecorator(coreEnum::layerType type,Editor* edit)
{
    switch (type) {
    case coreEnum::point:
        return editPoint::factory(edit);
        break;
    case coreEnum::polyLine:
        return editLine::factory(edit);
        break;
    case coreEnum::polyGon:
        return editPolygon::factory(edit);
        break;
    case coreEnum::null:
        return editShape::factory(edit);
        break;
    default:
        break;
    }
}

void Decorator::initFacade(QVector<EditorPixmapItem *> tmp)
{
    int width = 0;
    int height = 0;
    int rear = 0;
    int distance = 2;
    for (int i = 0; i < tmp.size(); ++i) {
        if(i == tmp.size()-1) break;
        EditorPixmapItem* p1 = tmp[i];
        EditorPixmapItem* p2 = tmp[i+1];

        if(p1->pixmap().size().height() > p2->pixmap().size().height()) height = p1->pixmap().size().height();
        else height = p2->pixmap().size().height();

        width += p1->pixmap().size().width();
    }
    width += tmp[tmp.size()-1]->pixmap().size().width();



    height += 10;
    width += 4*2;

    this->edit->resize(width,height);
    this->edit->view->setGeometry(0,0,width,height);

    for (int i = 0; i < tmp.size(); ++i) {
        EditorPixmapItem* p1 = tmp[i];

        p1->setPos(rear+distance,5);
        rear += p1->pixmap().size().width();
        this->edit->scene->addItem(p1);
    }
}
Decorator* editPoint::factory(Editor *edi)
{
    return new editPoint(edi);
}
void editPoint::loadDecorator(mapView2D* mapView)
{
    EditorPixmapItem* Cancel = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Cancel.png"));
    EditorPixmapItem* Finish = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Finish.png"));
    EditorPixmapItem* NewPoint = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/NewPoint.png"),nullptr,new CreatePointState());
    EditorPixmapItem* EditPoint = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/EditPoint.png"));

    QObject::connect(NewPoint,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);
    QObject::connect(Finish,&EditorPixmapItem::clicked,mapView,&mapView2D::finishShapeEdit);

    QVector<EditorPixmapItem*> tmp;

    tmp.push_back(NewPoint);
    tmp.push_back(EditPoint);
    tmp.push_back(Finish);
    tmp.push_back(Cancel);

    this->initFacade(tmp);


}
Decorator* editLine::factory(Editor *edi)
{
    return new editLine(edi);
}
void editLine::loadDecorator(mapView2D* mapView)
{

    EditorPixmapItem* Finish = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Finish.png"));
    EditorPixmapItem* DrawLine = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/DrawLine.png"),nullptr,new CreatePolyLineState());
    EditorPixmapItem* EditPoint = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/EditPoint.png"));
    EditorPixmapItem* Extent = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Extent.png"));

    QObject::connect(DrawLine,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);
    QObject::connect(Finish,&EditorPixmapItem::clicked,mapView,&mapView2D::finishShapeEdit);

    QVector<EditorPixmapItem*> tmp;


    tmp.push_back(DrawLine);
    tmp.push_back(EditPoint);
    tmp.push_back(Extent);
    tmp.push_back(Finish);



    this->initFacade(tmp);
}
Decorator* editPolygon::factory(Editor *edi)
{
    return new editPolygon(edi);
}
void editPolygon::loadDecorator(mapView2D* mapView)
{



    EditorPixmapItem* Finish = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Finish.png"));

    EditorPixmapItem* DrawLine = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/DrawLine.png")
                                                      ,nullptr,new CreatePolygonState());

    EditorPixmapItem* EditPoint = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/EditPoint.png"));

    EditorPixmapItem* Extent = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Extent.png"));

    EditorPixmapItem* Circle = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Circle.png")
                                                    ,nullptr,new CreateCircleState());

    EditorPixmapItem* Rectangle = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Rectangle.png")
                                                       ,nullptr,new CreateRectangleState());
    EditorPixmapItem* Sector = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Sector.png")
                                                    ,nullptr,new CreateSectorState());

    QObject::connect(DrawLine,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);
    QObject::connect(Finish,&EditorPixmapItem::clicked,mapView,&mapView2D::finishShapeEdit);
    QObject::connect(Rectangle,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);
    QObject::connect(Circle,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);
    QObject::connect(Sector,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);


    QVector<EditorPixmapItem*> tmp;


    tmp.push_back(DrawLine);
    tmp.push_back(Circle);
    tmp.push_back(Rectangle);
    tmp.push_back(Sector);
    tmp.push_back(Extent);
    tmp.push_back(Finish);


    this->initFacade(tmp);
}

Decorator* editShape::factory(Editor *edi)
{
    return new editShape(edi);
}

void editShape::loadDecorator(mapView2D * mapView)
{
    EditorPixmapItem* Cancel = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Cancel.png"),
                                                    nullptr,new EditMapObjectDelState());
    QObject::connect(Cancel,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);

    EditorPixmapItem* Finish = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/Finish.png"));
//    QObject::connect(Finish,&EditorPixmapItem::clicked,mapView,&mapView2D::finishShapeEdit);

    EditorPixmapItem*  Rotate = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/rotate.png")
                                                     ,nullptr,new EditMapObjectRotateState ());
    QObject::connect(Rotate,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);

    EditorPixmapItem*  Move = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/move.png"),
                                                   nullptr,new EditMapObjectMoveState());
    QObject::connect(Move,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);

    EditorPixmapItem*  Scale = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/scale.png")
                                                    ,nullptr,new EditMapObjectScaleState());

    QObject::connect(Scale,&EditorPixmapItem::sendState,mapView,&mapView2D::updateShapeEditorState);

    EditorPixmapItem*  edit_point = new EditorPixmapItem(QPixmap(":/pic/graphicsView/pictures/EditPoint.png"));



    QVector<EditorPixmapItem*> tmp;

    tmp.push_back(edit_point);
    tmp.push_back(Move);
    tmp.push_back(Rotate);
    tmp.push_back(Scale);
    tmp.push_back(Cancel);
    tmp.push_back(Finish);

    this->initFacade(tmp);
}
