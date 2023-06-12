#include "buildmenu.h"
#include"../Client.h"
#include<QDebug>
using namespace q_menu;
buildMenu::buildMenu(menuBar* menu)
{
    this->ptr_menu = menu;
//    menu->setStyleSheet("background-color: gray;");

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
    tabWidget* Insert = new tabWidget(this->ptr_menu);

    QPixmap    AddpicPixmap(":/pictures/AddPic.png");
    pixmapItem *AddPic = new pixmapItem(AddpicPixmap);
    Insert->addItem(AddPic);
    AddPic->setPos(2,2);


    this->ptr_menu->addTabWidget(Insert,"Insert");
}

void buildMenu::makeTabAnalysis()
{

}
#include"../Edit/makelayer.h"
#include"../Edit/createfeatures.h"
void buildMenu::makeTabEdit(mapViewWidget* map,Client* mainwindow)
{
    tabWidget* Edit = new tabWidget(this->ptr_menu);

    //for layOut use
    int rear = 0;

    pixmapItem* createLayers = new pixmapItem(QPixmap(":/pictures/toolbox.png"));
    pixmapItem* select = new pixmapItem(QPixmap(":/pictures/select.png"));
    pixmapItem* edit_ = new pixmapItem(QPixmap(":/pictures/edit.png"));
    pixmapItem* makeFeatures = new pixmapItem(QPixmap(":/pictures/createFeatures.png"));


    Edit->addItem(createLayers);
    createLayers->setPos(2,0);
    rear = createLayers->pixmap().width()+2;

    QWidget* tmp = new makeLayer();
    tmp->hide();
    createLayers->setShowWidget(tmp);
    QObject::connect(createLayers,&pixmapItem::showWidget,mainwindow,&Client::showWindow);

    Edit->addItem(select);
    select->setPos(rear+2,0);
    rear += select->pixmap().width()+2;
    QObject::connect(select,&pixmapItem::clicked,map,&mapViewWidget::select);

    Edit->addItem(edit_);
    edit_->setPos(rear+2,0);
    rear += edit_->pixmap().width()+2;

    Edit->addItem(makeFeatures);
    makeFeatures->setPos(rear+2,0);
    rear += makeFeatures->pixmap().width()+2;

    QWidget* features = new createFeatures();
    makeFeatures->setShowWidget(features);
    QObject::connect(makeFeatures,&pixmapItem::showWidget,mainwindow,&Client::showWindow);

    this->ptr_menu->addTabWidget(Edit,"Edit");

}
