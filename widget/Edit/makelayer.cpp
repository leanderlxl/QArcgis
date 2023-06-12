#include "makelayer.h"
#include<QDebug>
#include<QString>
#include"../../core/layermanager.h"

makeLayer::makeLayer(QWidget *parent) : QWidget(parent),ui(new Ui::createLayer)
{
    ui->setupUi(this);
}
makeLayer::~makeLayer()
{

    delete ui;
}


void makeLayer::on_pushButton_clicked()
{
//    qDebug()<<"clicked";
    layerManager* tmp_layerManager = layerManager::makeLayerManager();

    QString layerName = ui->featureName->text();
    if(layerName.isEmpty())
    {
        return;
    }
//    qDebug()<<layerName;

    QString layerType = ui->comboBox->currentText();
//    qDebug()<<layerType;
    Layer* layer = nullptr;
    if(layerType == "single point")
    {
         layer = new Layer(coreEnum::point,layerName);
    }
    else if(layerType == "multi Point")
    {
         layer = new Layer(coreEnum::multiPoint,layerName);
    }
    else if(layerType == "Poly Line")
    {
         layer = new Layer(coreEnum::polyLine,layerName);
    }
    else if(layerType == "Polygon")
    {
          layer= new Layer(coreEnum::polyGon,layerName);
    }
    if(tmp_layerManager->addLayer(layer))
    {
//        qDebug()<<"add";
    }
    else
    {
        qDebug()<<"error";
    }
    layer = nullptr;
    qDebug()<<tmp_layerManager->getLayer().size();
    ui->featureName->clear();
    this->close();
}
