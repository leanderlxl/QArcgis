#include "createfeatures.h"
#include"../../core/layermanager.h"
#include<QDebug>
createFeatures::createFeatures(QWidget *parent) : QWidget(parent),ui(new Ui::Form)
{

    ui->setupUi(this);
    initCombobox();
}
createFeatures::~createFeatures()
{

    delete ui;
}
void createFeatures::initCombobox()
{
    ui->layerBox->clear();
    layerManager* tmp = layerManager::makeLayerManager();
    QVector<Layer*> layers = tmp->getLayer();
    foreach (Layer* layer, layers) {
            QString layerName = layer->getLayerName();
            ui->layerBox->addItem(layerName);
    }
}

void createFeatures::on_pushButton_clicked()
{
    layerManager* tmp = layerManager::makeLayerManager();
    QVector<Layer*> layers = tmp->getLayer();
    try
    {
        if(ui->layerBox->currentIndex() == -1) return;
        tmp->setActiveLayer(layers[ui->layerBox->currentIndex()]);
    }
    catch(_exception e)
    {

    }

    this->close();

}

void createFeatures::on_pushButton_2_clicked()
{
    initCombobox();
}
