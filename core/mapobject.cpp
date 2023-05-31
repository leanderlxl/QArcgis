#include "mapobject.h"
#include<QDebug>
layerManager* layerManager::singleton = nullptr;

layerManager* layerManager::makeLayerManager()
{
    if(this->singleton == nullptr)
    {
        this->singleton = new layerManager();
        return this->singleton;
    }
    else
    {
        qDebug()<<"don't fucking do this";
        return this->singleton;
    }
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

mapObject::mapObject()
{

}
