#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
};
#endif // WIDGET_H
