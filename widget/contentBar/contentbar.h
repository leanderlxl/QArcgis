#ifndef CONTENTBAR_H
#define CONTENTBAR_H
#include<QObject>
#include<QTreeWidget>
#include<QVBoxLayout>
#include"layers.h"
class contentBar:public QWidget
{
public:
    contentBar(QWidget*parent = nullptr);
private:
    void initContentBar();
public slots:
    void updateContent();
private:
    mytreewidget* tree;
};

#endif // CONTENTBAR_H
