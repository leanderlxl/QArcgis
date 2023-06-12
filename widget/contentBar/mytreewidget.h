#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include<QTreeWidget>
#include<QMenu>
#include<QDebug>
#include<QContextMenuEvent>
#include<QWidget>
class mytreewidget:public QTreeWidget
{
public:

    mytreewidget(QWidget* parent);

    mytreewidget(QWidget* parent, const QStringList& labels);


    void contextMenuEvent(QContextMenuEvent* event) override ;

    void addTopLevelItem(QTreeWidgetItem* ite) {
      QTreeWidget::addTopLevelItem(ite);
    }
};

#endif // MYTREEWIDGET_H
