#ifndef LAYER_H
#define LAYER_H

#include"AbstractShapeType.h"

class Layer
{
public:
    Layer() = default;
    Layer(coreEnum::layerType type,QString layerName)
    {
        this->type = type;
        this->layerName = layerName;
    }
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

    QVector<mapObject*> getData(){return container;}

    coreEnum::layerType getType()
    {
        return this->type;
    }
    void appendData(mapObject*);

    void removeData(mapObject*);
private:
    int zValue = 0;
    QString layerName = "undefined";
    coreEnum::layerType type = coreEnum::null;
    QVector<mapObject*> container;
};




#endif // LAYER_H
