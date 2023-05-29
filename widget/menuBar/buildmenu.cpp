#include "buildmenu.h"

buildMenu::buildMenu(menuBar* menu)
{
    this->ptr_menu = menu;
}
void buildMenu::build()
{
    this->ptr_menu->addTabWidget(makeTabMap(),"MAP");
    this->ptr_menu->addTabWidget(makeTabInsert(),"Insert");
}
tabWidget* buildMenu::makeTabMap()
{
    tabWidget* map = new tabWidget(this->ptr_menu);
    QPixmap    incon_BaseMap(":/pictures/baseMap.png");
    pixmapItem *baseMap= new pixmapItem(incon_BaseMap);
    map->addItem(baseMap);
    //map->addDivider("layers");
    return map;
}
tabWidget* buildMenu::makeTabInsert()
{
    tabWidget* map = new tabWidget(this->ptr_menu);
    QPixmap    incon_BaseMap(":/pictures/baseMap.png");
    pixmapItem *baseMap = new pixmapItem(incon_BaseMap);
    map->addItem(baseMap);
    map->addDivider("layers");
    return map;
}
tabWidget* buildMenu::makeTabAnalysis()
{

}
tabWidget* buildMenu::makeTabEdit()
{

}
