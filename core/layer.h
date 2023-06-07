#ifndef LAYER_H
#define LAYER_H

#include"AbstractShapeType.h"
class baseMapLayer
{
public:
    baseMapLayer()
    {
    }
    ~baseMapLayer()
    {
    }
public:
    int getZvalue(){return zValue;}
    QString getLayerName(){return   layerName;}

    void addData(QVector<QGraphicsPixmapItem*> container,int z = -1)
    {
        Q_UNUSED(z);
        this->container = container;
    }
    void addItem(QGraphicsPixmapItem* pix)
    {
        pix->setZValue(1000000);
        container.push_back(pix);
    }
    QVector<QGraphicsPixmapItem*> getData()
    {
        return container;
    }
    void removeAll()
    {
        container.clear();
    }
    void setBaseMapVisible(bool t)
    {
        for(int i = 0;i<container.size();++i)
        {
            QGraphicsPixmapItem* tmp = container[i];
            tmp->setVisible(t);
        }
    }

private:
    int zValue = -1;
    QString layerName = "baseMap";
    coreEnum::layerType type = coreEnum::baseMap;
    QVector<QGraphicsPixmapItem*> container;

};

class Layer
{
public:
    Layer() = default;
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

private:
    int zValue = 0;
    QString layerName = "undefined";
    coreEnum::layerType type = coreEnum::null;
    QVector<mapObject*> container;
};

class layerManager
{
public:
    static layerManager* makeLayerManager();
    QVector<mapObject*> getData();
    void setLayerOrder(QQueue<QString> layerOrder);
    void removeLayer(Layer *layer);
    void addLayer(Layer *layer);
    void setLyrVisibility(Layer*,bool);

    void addBaseMap(QVector<QGraphicsPixmapItem*> container,int z = -1)
    {
        Q_UNUSED(z);
        this->basemap->removeAll();
        this->basemap->addData(container,-1);
    }
    void setBaseMapVisibility(bool t)
    {
        this->basemap->setBaseMapVisible(t);
    }

private:
    layerManager()
    {
        basemap = new baseMapLayer();
    }
    ~layerManager()
    {
        delete basemap;
        basemap = nullptr;
    }
    QVector<Layer> layers;
    baseMapLayer *basemap;
    static layerManager* singleton;
};


#endif // LAYER_H
