#include "layer.h"
#include<qdebug.h>
layerManager* layerManager::singleton = nullptr;

layerManager* layerManager::makeLayerManager()
{
    if( singleton == nullptr)
    {
        singleton = new layerManager();
        return singleton;
    }
    else
    {
        qDebug()<<"don't fucking do this";
        return singleton;
    }
}

QVector<mapObject*> layerManager::getData()
{
    QVector<mapObject*> data;
    for (int i = 0; i < this->layers.size(); ++i) {
        auto layer = layers[i];
        auto tmp = layer.getData();
        data.append(tmp);
    }
    return data;
}

void Layer::setZvalue(int z)
{
    for(int i = 0;i<this->container.size();++i)
    {
        auto tmp = container[1];
        tmp->acceptDrops();
        tmp->setZValue(z);
    }
}
