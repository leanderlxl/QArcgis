#ifndef EDITMAPOBJECTSTYLE_H
#define EDITMAPOBJECTSTYLE_H

#include <QWidget>
#include<QString>
#include"ui_EditMapObjectStyle.h"
#include"../../core/layermanager.h"
class EditMapObjectStyle : public QWidget
{
    Q_OBJECT
public:
    explicit EditMapObjectStyle(QString layerName,QWidget *parent = nullptr);
private:

    void getFillStyle();
    void getBorderStyle();
    void getLayer();


    Ui::EditMapObjectStyle *ui;
    Layer* layer;
    Qt::PenStyle penStyle;
    Qt::BrushStyle brushStyle;
    QColor penColor,brushColor;
    int width;

signals:

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // EDITMAPOBJECTSTYLE_H
