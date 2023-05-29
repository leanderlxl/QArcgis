#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QString>
#include"pixmapitem.h"
class tabWidget:public QWidget
{
    Q_OBJECT
public:
    tabWidget() = default;
    tabWidget(QWidget* parent = nullptr);
    void addItem(pixmapItem*);
    // str is the summarization of last conten;
    void addDivider(QString str);
private:
    QGraphicsView view;
    QGraphicsScene scene;
    int rear = 5;
    int lastRear = 0;
};

#endif // TABWIDGET_H
