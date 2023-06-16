#ifndef WIDGET_H
#define WIDGET_H
#include<QStatusBar>

#include<QMainWindow>
//menuBar dependency
#include"menuBar/TabWidget/pixmapitem.h"
#include"menuBar/TabWidget/tabwidget.h"
#include"menuBar/buildmenu.h"

//menuBar this is
#include"menuBar/menubar.h"

//mapViewer
#include"mapViewer/mapviewwidget.h"

#include"contentBar/contentbar.h"

#include"mapViewer/graphicsView/Editor_bar/editor.h"

#include"menuBar/menuCommand/invoker.h"
class Client : public QMainWindow
{
    Q_OBJECT
public:
    Client(QWidget *parent = nullptr);
    ~Client();
public:

    void showWidget(QWidget*);
private:

    void initClientFacade();
public slots:
    void invokeCmd(Command*);
private:
    //这个命名空间导致的问题也可以说一说
    q_menu::menuBar* menu;
    buildMenu *builder_menu;
    mapViewWidget* map;
    contentBar* cont;
    Invoker* invoker;
    QStatusBar* statusBar ;
};
#endif // WIDGET_H21
