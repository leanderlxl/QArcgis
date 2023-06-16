#include "Client.h"
#include<QPushButton>
Client::Client(QWidget *parent)
    : QMainWindow(parent)
{
    initClientFacade();
   this->invoker = new Invoker();
    statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);
    statusBar->addWidget(new QPushButton("复位", statusBar));
}
void Client::initClientFacade()
{

    //set the size of the window
    this->setMinimumSize(500,500);
    this->resize(1350,725);
    using namespace q_menu;
    //set menuBar
    menu = menu->makeMenuBar(this);
    if(menu != nullptr)menu->setGeometry(0,0,1350,150);

    builder_menu = new buildMenu(menu);

    //the map view
    map = new mapViewWidget(this);

    builder_menu->makeTabMap();

    builder_menu->makeTabEdit(map->getMap(),this);

    builder_menu->makeTabInsert(map,this);

//    builder_menu->makeTabAnalysis();
    delete builder_menu;
    builder_menu = nullptr;

    cont = new contentBar(this);
    cont->setGeometry(0,151,228,574);
}
void Client::invokeCmd(Command * cmd)
{
    this->invoker->setCommad(cmd);
    this->invoker->invoke();
}

void Client::showWidget(QWidget * w)
{
    w->show();
}
Client::~Client()
{

}

