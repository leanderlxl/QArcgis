#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H
#include<QObject>
#include"layer.h"
class layerManager:public QObject
{
    Q_OBJECT
public:
    static layerManager* makeLayerManager();

    QVector<mapObject*> getData();

    QVector<Layer*> getLayer();

    void removeLayer(Layer *layer);

    bool addLayer(Layer *layer);

    void setLayerOrder(QQueue<QString> layerOrder);

    void setLyrVisibility(Layer*,bool);

    void setActiveLayer(Layer* layer);

    void restoreActiveLayer();

    void setActivingObject(mapObject*);

    void restoreActivingObject();

    mapObject* getActivingObject();

    Layer* getActiveLayer();

    ~layerManager()
    {
    }
signals:
    void LayerUpdate();

    void LayerActivtate();
private:
    explicit layerManager(QObject *parent = nullptr);
    QVector<Layer*> layers;
    static layerManager* singleton;
    Layer* activingLayer;
    mapObject* activingObject;
};

#endif // LAYERMANAGER_H
