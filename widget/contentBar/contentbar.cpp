#include "contentbar.h"
#include<QDebug>
#include"../../core/layermanager.h"
contentBar::contentBar(QWidget*parent):QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    tree = new mytreewidget(parent);
    // 将QTreeWidget添加到布局中
    layout->addWidget(tree);

    // 设置布局管理器
    setLayout(layout);

    connect(layerManager::makeLayerManager(),&layerManager::LayerUpdate,this,&contentBar::updateContent);
}

void contentBar::initContentBar()
{
    this->tree->clear();
    layerManager* tmp = layerManager::makeLayerManager();
    QVector<Layer*> layers = tmp->getLayer();
    foreach (Layer* layer, layers) {
       if(layer)
       {
           QTreeWidgetItem* layer_item = new QTreeWidgetItem(tree, QStringList(layer->getLayerName()));
           tree->addTopLevelItem(layer_item);
       }
    }
}

void contentBar::updateContent()
{
     initContentBar();
}
