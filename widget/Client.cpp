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

    //set menuBar
    menu = menu->makeMenuBar(this);
    if(menu != nullptr)menu->setGeometry(0,0,1350,150);

    builder_menu = new buildMenu(menu);

    //the map view
    map = new mapViewWidget(this);

    builder_menu->makeTabMap();

    builder_menu->makeTabEdit(map);

    delete builder_menu;
    builder_menu = nullptr;

    cont = new contentBar(this);
    cont->setGeometry(0,151,228,574);

}
Client::~Client()
{

}

