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

void buildMenu::makeTabInsert(mapViewWidget* map,Client* mainwindow)
{
    tabWidget* Insert = new tabWidget(this->ptr_menu);

    QPixmap    AddpicPixmap(":/pictures/AddPic.png");
    pixmapItem *AddPic = new pixmapItem(AddpicPixmap);
//    pixmapItem* AddText = new pixmapItem(AddpicPixmap);

    Insert->addItem(AddPic);
    AddPic->setPos(2,2);
    QObject::connect(AddPic,&pixmapItem::clicked,map,&mapViewWidget::addPixmap);

    pixmapItem *AddText = new pixmapItem(AddpicPixmap);
    Insert->addItem(AddText);
    AddText->setPos(50,2);

    QObject::connect(AddText,&pixmapItem::clicked,map,&mapViewWidget::addText);

    this->ptr_menu->addTabWidget(Insert,"Insert");
}

void buildMenu::makeTabAnalysis()
{

}
#include"../Edit/makelayer.h"
#include"../Edit/createfeatures.h"
void buildMenu::makeTabEdit(mapView2D* map,Client* mainwindow)
{
    tabWidget* Edit = new tabWidget(this->ptr_menu);

    //for layOut use
    int rear = 0;

    QWidget* makelayer = new makeLayer();
    makelayer->hide();
    pixmapItem* createLayers = new pixmapItem(QPixmap(":/pictures/toolbox.png")
                                              ,nullptr,new showWidgetCommand(mainwindow,makelayer));
    QObject::connect(createLayers,&pixmapItem::sendCommand,mainwindow,&Client::invokeCmd);


    pixmapItem* select = new pixmapItem(QPixmap(":/pictures/select.png")
                                        ,nullptr,new setSelectStateCommand(map,new SelectOne()));
    QObject::connect(select,&pixmapItem::sendCommand,map,&mapView2D::invokeCmd);

    Editor *edi = new Editor(coreEnum::null,map);
    edi->hide();
    pixmapItem* edit_ = new pixmapItem(QPixmap(":/pictures/edit.png")
                                       ,nullptr,new EditShapeCommand(map,edi));
    QObject::connect(edit_,&pixmapItem::sendCommand,map,&mapView2D::invokeCmd);

    QWidget* features = new createFeatures();
    features->hide();
    pixmapItem* makeFeatures = new pixmapItem(QPixmap(":/pictures/createFeatures.png")
                                              ,nullptr,new showWidgetCommand(mainwindow,features));
    QObject::connect(makeFeatures,&pixmapItem::sendCommand,mainwindow,&Client::invokeCmd);


    Edit->addItem(createLayers);
    createLayers->setPos(2,0);
    rear = createLayers->pixmap().width()+2;





    Edit->addItem(select);
    select->setPos(rear+2,0);
    rear += select->pixmap().width()+2;



    Edit->addItem(edit_);
    edit_->setPos(rear+2,0);
    rear += edit_->pixmap().width()+2;

    Edit->addItem(makeFeatures);
    makeFeatures->setPos(rear+2,0);
    rear += makeFeatures->pixmap().width()+2;




    this->ptr_menu->addTabWidget(Edit,"Edit");

}
