#include "menubar.h"
#include<QDebug>
using namespace q_menu;
menuBar* menuBar::singleton = nullptr ;
menuBar::menuBar(QWidget *parent):QTabWidget(parent)
{
    //qDebug()<<"widget/menubar/ menuBar::menuBar constructed";
}
menuBar::~menuBar()
{
    delete this->singleton;
    singleton = nullptr;
}
menuBar* menuBar::makeMenuBar(QWidget *parent)
{
    if(singleton == nullptr)
    {
        singleton = new menuBar(parent);
        return singleton;
    }
    else{
        qDebug()<<"tabBar created already!dont do this";
        return singleton;
    }
}
void menuBar::addTabWidget(QWidget *w,QString tabName)
{
        this->addTab(w,tabName);
}
