#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include<QString>
#include<QVector>
#include<QGraphicsItem>
#include<QQueue>
//avoid polution to the outter namespace
//the namespace of core including needed enumeration for this part
namespace coreEnum {
    enum layerType
    {
        point,
        multiPoint,
        polyLine,
        polyGon,
        null
    };
}
class Layer;
class layerManager
{
    static layerManager* makeLayerManager();
    QQueue<mapObject*> getData();
    void setLayerOrder(QQueue<QString> layerOrder);

private:
    QVector<Layer> layers;
    static layerManager* singleton;
};

//forward declration
class mapObject;
class Layer
{
public:
    Layer(coreEnum::layerType type,QString layerName,QVector<mapObject*> data)
    {
        this->type = type;
        this->layerName = layerName;
        this->container = data;
    }
public:
    //set every zValue of layerItem
    void setZvalue(int z);
    int getZvalue(){return zValue;}

    //setter for layername
    void setLayerName(QString name){layerName = name;}
    QString getLayerName(){return   layerName;}

    QQueue<mapObject*> getData();

private:
    int zValue = 0;
    QString layerName = "undefined";
    coreEnum::layerType type = coreEnum::null;
    QVector<mapObject*> container;

};

class mapObject:public QGraphicsItem
{
public:
    mapObject();
public:
    double area();
    double length();
};

class point:public mapObject
{
public:
    point() {}
};

#endif // MAPOBJECT_H
