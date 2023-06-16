#ifndef DECORATOR_H
#define DECORATOR_H
#include<QVector>
#include"../../../../core/layer.h"
#include"editorpixmapitem.h"
class mapView2D;
class Editor;
class Decorator
{
public:
    Decorator(Editor* edi)
    {
        edit = edi;
    }
    virtual void loadDecorator(mapView2D*) =0;
    static Decorator* makeDecorator(coreEnum::layerType,Editor*);

protected:
    Editor* edit;
    void initFacade(QVector<EditorPixmapItem*>);

};
class editPoint:public Decorator
{
public:
    editPoint(Editor* edi):Decorator(edi)
    {

    }
    static Decorator* factory(Editor* edi);
    void loadDecorator(mapView2D*);

};
class editLine:public Decorator
{
public:
    editLine(Editor* edi):Decorator(edi)
    {}
    static Decorator* factory(Editor* edi);
    void loadDecorator(mapView2D*);
};
class editPolygon:public Decorator
{
public:
    editPolygon(Editor* edi):Decorator(edi)
    {}
    static Decorator* factory(Editor* edi);
    void loadDecorator(mapView2D*);
};

class editShape:public Decorator
{
public:
    editShape(Editor* edi):Decorator(edi)
    {}
    static Decorator* factory(Editor* edi);
    void loadDecorator(mapView2D*);
};
#endif // DECORATOR_H
