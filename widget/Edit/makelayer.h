#ifndef MAKELAYER_H
#define MAKELAYER_H

#include <QObject>
#include"ui_form.h"

namespace Ui {
   class createLayer;
}
class makeLayer : public QWidget
{
    Q_OBJECT
public:
    ~makeLayer();
    explicit makeLayer(QWidget *parent = nullptr);
private:
    Ui::createLayer *ui;
signals:

private slots:
    void on_pushButton_clicked();
};

#endif // MAKELAYER_H
