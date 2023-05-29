#ifndef BUILDMENU_H
#define BUILDMENU_H

#include"menubar.h"

#include"TabWidget/tabwidget.h"
#include"TabWidget/pixmapitem.h"
//This is my own advanced build pattern which omit the Director making it easier to read and understand

class buildMenu
{
public:
    buildMenu() = default;
    buildMenu(menuBar* menu);
    void build();
//private member function
private:
    tabWidget* makeTabMap();
    tabWidget* makeTabInsert();
    tabWidget* makeTabAnalysis();
    tabWidget* makeTabEdit();
//private members
private:
    menuBar * ptr_menu = nullptr;

};

#endif // BUILDMENU_H
