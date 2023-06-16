#ifndef COMMAND_H
#define COMMAND_H
#include<QWidget>

class Client;
class mapView2D;
class SelectionState;
class Editor;
class layerManager;

class Command
{
public:
    Command();
    virtual void excute() = 0;
    virtual ~Command()
    {

    }
};

class showWidgetCommand:public Command
{
public:
    showWidgetCommand(Client* receiver,QWidget* showWidget);

    void excute();

    ~showWidgetCommand();


private:
    Client* receiver;
    QWidget* showWidget;
};

class setSelectStateCommand:public Command
{
public:
    setSelectStateCommand(mapView2D* receiver,SelectionState* state);

    void excute();

    ~setSelectStateCommand();
private:
    SelectionState *state;
    mapView2D *receiver;
};

class EditShapeCommand:public Command
{
public:
    EditShapeCommand(mapView2D* receiver,Editor* edi);

    void excute();

    ~EditShapeCommand();
private:
    mapView2D *receiver;
    Editor* edi;
    layerManager* layers;
    bool show = true;
};
#endif // COMMAND_H
