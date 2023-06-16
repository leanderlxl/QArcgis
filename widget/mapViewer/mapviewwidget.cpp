#include "mapviewwidget.h"
#include<QDebug>
#include<QFileDialog>
#include <QInputDialog>
mapViewWidget::mapViewWidget(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(230,155,1120,570);
    this->initMapView();
}

void mapViewWidget::initMapView()
{

    //binding view and scnene
    scene = new mapScene2D();
    view = new mapView2D(scene,this);

    view->setRenderHint(QPainter::Antialiasing);

    view->setGeometry(0,0,this->width()-5,this->height()-5);
    scene->setSceneRect(view->rect());

}


void mapViewWidget::addPixmap()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "选择图片", "", "Images (*.png *.jpg)");
    QPixmap pixmap(filePath);
    pixmap.scaled(50,50);
    // 创建一个QGraphicsPixmapItem，并将图片设置为其图像
    QGraphicsPixmapItem *pixmapItem= new QGraphicsPixmapItem(pixmap);

    // 将QGraphicsPixmapItem添加到场景中
    scene->addItem(pixmapItem);

    pixmapItem->setPos(0,0);
}
void mapViewWidget::addText()
{
    QString userInput = QInputDialog::getText(nullptr, "输入文本", "请输入文本内容:");

        // 创建文本项
        QGraphicsTextItem *textItem = new QGraphicsTextItem();
        textItem->setPlainText(userInput);
        textItem->setFont(QFont("Arial", 16));
        textItem->setDefaultTextColor(Qt::red);
        scene->addItem(textItem);
}
