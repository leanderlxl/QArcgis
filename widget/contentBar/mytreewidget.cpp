#include "mytreewidget.h"

mytreewidget::mytreewidget(QWidget *parent):QTreeWidget(parent)
{

}

mytreewidget::mytreewidget(QWidget* parent, const QStringList& labels): QTreeWidget(parent){}

void mytreewidget::contextMenuEvent(QContextMenuEvent *event){
    QTreeWidgetItem* item = currentItem();
    if (item) {
        QMenu menu(this);
        QAction* action = menu.addAction("Do Something");
        connect(action, &QAction::triggered, this, [item]() {
            // 在此处执行针对特定项的操作
            qDebug() << "Right-clicked item: " << item->text(0);
        });
        menu.exec(event->globalPos());
    }
    QTreeWidget::contextMenuEvent(event);
}
