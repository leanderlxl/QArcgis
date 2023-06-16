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
void Layer::setBorderStyle(QColor borderColor,Qt::PenStyle boderStyle,int borderWidth)
{

    for(int i = 0;i<this->container.size();i++)
    {
        this->container[i]->BorderStyle(borderColor,boderStyle,borderWidth);
    }
}

void Layer::setfillStyle(QColor fillColor,Qt::BrushStyle fillStyle)
{
    for(int i = 0;i<this->container.size();i++)
    {
        this->container[i]->FillStyle(fillColor,fillStyle);
    }
}

void Layer::setScale(qreal s)
{
    for(int i = 0;i<this->container.size();i++)
    {
        this->container[i]->scale(s);
    }
}

void Layer::setRotate(qreal s)
{
    for(int i = 0;i<this->container.size();i++)
    {
        this->container[i]->Rotate(s);
    }
}

void Layer::setOpacity(qreal s)
{
    for(int i = 0;i<this->container.size();i++)
    {
        this->container[i]->Opacity(s);
    }
}
