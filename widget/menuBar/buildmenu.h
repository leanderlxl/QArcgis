#ifndef BUILDMENU_H
#define BUILDMENU_H
#include<QObject>

#include"menubar.h"

#include"TabWidget/tabwidget.h"
#include"TabWidget/pixmapitem.h"

#include"../mapViewer/mapviewwidget.h"
//This is my own advanced build pattern which omit the Director making it easier to read and understand
class Client;

class buildMenu
{
public:
    buildMenu() = default;
    buildMenu(q_menu::menuBar* menu);
//private member function
public:
    void makeTabMap();
    void makeTabInsert(mapViewWidget*,Client* c);
    void makeTabAnalysis();
    void makeTabEdit(mapView2D*,Client* c);
//private members
private:
    q_menu::menuBar * ptr_menu = nullptr;
};

#endif // BUILDMENU_H
