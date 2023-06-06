#include "contentbar.h"

contentBar::contentBar(QWidget*parent):QWidget(parent)
{
    // 创建一个布局管理器
    QVBoxLayout *layout = new QVBoxLayout(this);

    tree = new mytreewidget(parent);
    // 将QTreeWidget添加到布局中
    layout->addWidget(tree);

    addtreewidget();

    // 设置布局管理器
    setLayout(layout);
}
void contentBar::addtreewidget(){

    QTreeWidgetItem* parentItem = new QTreeWidgetItem(tree, QStringList("Parent Item"));

    QTreeWidgetItem* childItem1 = new QTreeWidgetItem(parentItem, QStringList("Child Item 1"));
    childItem1->setFlags(childItem1->flags() | Qt::ItemIsUserCheckable);
    childItem1->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* childItem2 = new QTreeWidgetItem(parentItem, QStringList("Child Item 2"));
    childItem2->setFlags(childItem2->flags() | Qt::ItemIsUserCheckable);
    childItem2->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* childItem3 = new QTreeWidgetItem(parentItem, QStringList("Child Item 3"));
    childItem3->setFlags(childItem3->flags() | Qt::ItemIsUserCheckable);
    childItem3->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* childItem4 = new QTreeWidgetItem(parentItem, QStringList("Child Item 4"));
    childItem4->setFlags(childItem4->flags() | Qt::ItemIsUserCheckable);
    childItem4->setCheckState(0, Qt::Unchecked);


    QTreeWidgetItem* childItem5 = new QTreeWidgetItem(parentItem, QStringList("Child Item 5"));
    childItem5->setFlags(childItem5->flags() | Qt::ItemIsUserCheckable);
    childItem5->setCheckState(0, Qt::Unchecked);

    tree->addTopLevelItem(parentItem);
}
