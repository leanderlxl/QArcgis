#ifndef MENUBAR_H
#define MENUBAR_H

#include<QTabWidget>
#include<QString>
namespace q_menu {
class menuBar:public QTabWidget
{
    Q_OBJECT
public:
    static menuBar* makeMenuBar(QWidget * parent);
    void addTabWidget(QWidget *,QString tabName);
private:
    menuBar() = default;
    menuBar(QWidget *parent = nullptr);
    ~menuBar();
    static menuBar *singleton;
};
}

#endif // MENUBAR_H
