#include "Client.h"
Client::Client(QWidget *parent)
    : QWidget(parent)
{
    initClientFacade();
}
void Client::initClientFacade()
{

    //set the size of the window
    this->setMinimumSize(500,500);
    this->resize(1350,725);

    //the map view
    map = new mapViewWidget(this);


    //set menuBar
    menu = menu->makeMenuBar(this);
    if(menu != nullptr)menu->setGeometry(0,0,1350,150);

    builder_menu = new buildMenu(menu);

    builder_menu->makeTabMap();

    builder_menu->makeTabEdit(map);

    delete builder_menu;
    builder_menu = nullptr;

}
Client::~Client()
{

}

