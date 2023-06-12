#include "layer.h"
#include<qdebug.h>

void Layer::setZvalue(int z)
{
    for(int i = 0;i<this->container.size();++i)
    {
        auto tmp = container[1];
        tmp->acceptDrops();
        tmp->setZValue(z);
    }
}


void Layer::appendData(mapObject * obj)
{
        this->container.push_back(obj);
}
void Layer::removeData(mapObject * m)
{
    foreach (mapObject* item, this->container) {
        if(m == item)
        {
            this->container.removeOne(m);
        }
    }
}
