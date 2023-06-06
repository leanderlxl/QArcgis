#ifndef CONTENTBAR_H
#define CONTENTBAR_H

#include<QTreeWidget>
#include<QVBoxLayout>
#include"mytreewidget.h"
class contentBar:public QWidget
{
public:
    contentBar(QWidget*parent = nullptr);
    void addtreewidget();

private:
    mytreewidget* tree ;
};

#endif // CONTENTBAR_H
