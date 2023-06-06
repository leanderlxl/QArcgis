#include "buildmenu.h"
#include<QDebug>
buildMenu::buildMenu(menuBar* menu)
{
    this->ptr_menu = menu;
}
void buildMenu::makeTabMap()
{
    tabWidget* map = new tabWidget(this->ptr_menu);

    QPixmap    incon_BaseMap(":/pictures/baseMap.png");
    pixmapItem *baseMap= new pixmapItem(incon_BaseMap);

    map->addItem(baseMap);
    baseMap->setPos(10,10);
    //map->addDivider("layers");

    this->ptr_menu->addTabWidget(map,"MAP");
}

void buildMenu::makeTabInsert()
{
    tabWidget* map = new tabWidget(this->ptr_menu);

    QPixmap    incon_BaseMap(":/pictures/baseMap.png");
    pixmapItem *baseMap = new pixmapItem(incon_BaseMap);
    map->addItem(baseMap);
}

void buildMenu::makeTabAnalysis()
{

}

void buildMenu::makeTabEdit(mapViewWidget* map)
{
    tabWidget* Edit = new tabWidget(this->ptr_menu);

    //for layOut use
    int rear = 0;

    pixmapItem* createLayers = new pixmapItem(QPixmap(":/pictures/toolbox.png"));
    pixmapItem* select = new pixmapItem(QPixmap(":/pictures/select.png"));
    pixmapItem* edit_ = new pixmapItem(QPixmap(":/pictures/edit.png"));
    pixmapItem* createFeatures = new pixmapItem(QPixmap(":/pictures/createFeatures.png"));


    Edit->addItem(createLayers);
    createLayers->setPos(2,0);
    rear = createLayers->pixmap().width()+2;


    qDebug()<<"rear "<<rear;

    Edit->addItem(select);
    select->setPos(rear+2,0);
    rear += select->pixmap().width()+2;
    //QObject::connect(select,&pixmapItem::clicked,map,&mapViewWidget::select);

    Edit->addItem(edit_);
    edit_->setPos(rear+2,0);
    rear += edit_->pixmap().width()+2;Edit->addItem(edit_);
    qDebug()<<"rear "<<rear;

    Edit->addItem(createFeatures);
    createFeatures->setPos(rear+2,0);
    rear += createFeatures->pixmap().width()+2;
    qDebug()<<"rear "<<rear;

    this->ptr_menu->addTabWidget(Edit,"Edit");

}
