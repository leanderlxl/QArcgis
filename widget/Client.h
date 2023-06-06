#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

//menuBar dependency
#include"menuBar/TabWidget/pixmapitem.h"
#include"menuBar/TabWidget/tabwidget.h"
#include"menuBar/buildmenu.h"

//menuBar this is
#include"menuBar/menubar.h"

//mapViewer
#include"mapViewer/mapviewwidget.h"
class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
    void initClientFacade();

private:
    menuBar* menu;
    buildMenu *builder_menu;
    mapViewWidget* map;
};
#endif // WIDGET_H21
