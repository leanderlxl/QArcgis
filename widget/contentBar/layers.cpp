#include "layers.h"
#include"../Edit/editmapobjectstyle.h"
#include<QDebug>
mytreewidget::mytreewidget(QWidget *parent):QTreeWidget(parent)
{

}

mytreewidget::mytreewidget( QWidget* parent, const QStringList& labels): QTreeWidget(parent){}

void mytreewidget::contextMenuEvent(QContextMenuEvent *event){
    QTreeWidgetItem* item = currentItem();
    if (item) {
        QMenu menu(this);
        QAction* action = menu.addAction("Edit");
        connect(action, &QAction::triggered, this, [item]() {
            qDebug()<<item->text(0);
                EditMapObjectStyle *restyle = new EditMapObjectStyle(item->text(0));
                restyle->show();
        });
        menu.exec(event->globalPos());
    }
    QTreeWidget::contextMenuEvent(event);
}
