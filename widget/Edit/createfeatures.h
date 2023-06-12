#ifndef CREATEFEATURES_H
#define CREATEFEATURES_H

#include <QObject>
#include"ui_createFeatures.h"
class createFeatures : public QWidget
{
    Q_OBJECT
public:
    explicit createFeatures(QWidget *parent = nullptr);
    ~createFeatures();
private:
    void initCombobox();
private:
    Ui::Form *ui;
signals:

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // CREATEFEATURES_H
