#ifndef BUILDMENU_H
#define BUILDMENU_H
#include<QObject>

#include"menubar.h"

#include"TabWidget/tabwidget.h"
#include"TabWidget/pixmapitem.h"

#include"../mapViewer/mapviewwidget.h"
//This is my own advanced build pattern which omit the Director making it easier to read and understand

class buildMenu
{
public:
    buildMenu() = default;
    buildMenu(menuBar* menu);
//private member function
public:
    void makeTabMap();
    void makeTabInsert();
    void makeTabAnalysis();
    void makeTabEdit(mapViewWidget*);
//private members
private:
    menuBar * ptr_menu = nullptr;
};

#endif // BUILDMENU_H
