#include "layermanager.h"
#include<QDebug>
layerManager* layerManager::singleton = nullptr;
layerManager::layerManager(QObject *parent):QObject(parent)
{
    this->activingObject = nullptr;
}
layerManager* layerManager::makeLayerManager()
{
    if( singleton == nullptr)
    {
        singleton = new layerManager();
        return singleton;
    }
    else
    {
        return singleton;
    }
}

QVector<mapObject*> layerManager::getData()
{
    QVector<mapObject*> data;
    for (int i = 0; i < this->layers.size(); ++i) {
        auto layer = layers[i];
        auto tmp = layer->getData();
        data.append(tmp);
    }
    return data;
}
bool layerManager::addLayer(Layer *layer)
{
    if(layer == nullptr ) return false;
    else
    {
        this->layers.append(layer);
        emit LayerUpdate();
        return true;
    }
}
QVector<Layer*> layerManager::getLayer()
{
    return this->layers;
}
void layerManager::setActiveLayer(Layer *layer)
{
    this->activingLayer = layer;
    emit LayerActivtate();
}
void layerManager::restoreActiveLayer()
{
    this->activingLayer = nullptr;
}
Layer* layerManager::getActiveLayer()
{
    if(activingLayer != nullptr)
    {
        return activingLayer;
    }
    qDebug()<<"nullptr";
    return nullptr;
}

void layerManager::setActivingObject(mapObject * m)
{
    if(m != nullptr)
    {
        this->activingObject = m;
        m->setActive(true);
    }
}

mapObject* layerManager::getActivingObject()
{
    return this->activingObject;
}

void layerManager::restoreActivingObject()
{
    this->activingObject->setActive(false);
    this->activingObject = nullptr;
}
