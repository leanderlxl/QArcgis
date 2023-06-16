#include "editmapobjectstyle.h"
#include <QColorDialog>
EditMapObjectStyle::EditMapObjectStyle(QString layerName,QWidget *parent) : QWidget(parent),ui(new Ui::EditMapObjectStyle)
{
    ui->setupUi(this);
    layerManager* layers = layerManager::makeLayerManager();
    QVector<Layer*> layerList = layers->getLayer();

    for (int i = 0; i < layerList.size(); ++i) {
       if(layerList[i]->getLayerName() == layerName)
       {
           this->layer = layerList[i];
           break;
       }
    }
    ui->roate->setRange(0,360);
    ui->scale->setRange(0,3);
    ui->opacity->setRange(0,1);
    this->width = 2;

    penColor = Qt::black;
    brushColor = Qt::red;
    penStyle = Qt::SolidLine;
    brushStyle = Qt::SolidPattern;
}

void EditMapObjectStyle::on_pushButton_3_clicked()
{
   if(ui->roate->value() != 0)
   {
       layer->setRotate(ui->roate->value());
   }

   if(ui->scale->value() != 0)
   {
       layer->setScale(ui->roate->value());
   }

   if(ui->opacity->value() != 0)
   {
       layer->setOpacity(ui->roate->value());
   }

   QString borderStyle = ui->BroderStyle->currentText();

   if(borderStyle == "DashLine")
   {
       this->penStyle = Qt::DashLine;
   }
   if(borderStyle == "DotLine")
   {
       this->penStyle = Qt::DotLine;
   }

   QString width = ui->width->text();
   if(!width.isEmpty())
   {
       this->width = width.toInt();
   }

   layer->setBorderStyle(penColor,penStyle,this->width);

   QString fillStyle = ui->BroderStyle->currentText();

   if(fillStyle == "HorPattern")
   {
       this->brushStyle = Qt::HorPattern;
   }

   this->layer->setfillStyle(brushColor,brushStyle);

}

void EditMapObjectStyle::on_pushButton_2_clicked()
{
    QColorDialog dialog;
    // 设置对话框的标题
    dialog.setWindowTitle("选择颜色");
    // 打开对话框并等待用户选择颜色
    if (dialog.exec() == QDialog::Accepted) {
        brushColor = dialog.selectedColor();
    }
}

void EditMapObjectStyle::on_pushButton_clicked()
{
    QColorDialog dialog;
    // 设置对话框的标题
    dialog.setWindowTitle("选择颜色");
    // 打开对话框并等待用户选择颜色
    if (dialog.exec() == QDialog::Accepted) {
        penColor = dialog.selectedColor();
    }
}
