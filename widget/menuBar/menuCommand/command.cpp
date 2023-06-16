#include "command.h"
#include"../../Client.h"
#include"../../../core/layermanager.h"
Command::Command()
{

}
showWidgetCommand::showWidgetCommand(Client *receiver, QWidget *showWidget)
    :receiver(receiver),showWidget(showWidget)
{

}

void showWidgetCommand::excute()
{
    this->receiver->showWidget(this->showWidget);
}

showWidgetCommand::~showWidgetCommand()
{
    if(receiver) delete receiver;
    if(showWidget) delete showWidget;
}

setSelectStateCommand::setSelectStateCommand(mapView2D *receiver, SelectionState *state)
    :receiver(receiver),state(state)
{

}
void setSelectStateCommand::excute()
{
    this->receiver->setSelectingMode(state);
}

setSelectStateCommand::~setSelectStateCommand()
{
    if(receiver) delete receiver;
    if(state) delete state;
}

EditShapeCommand::EditShapeCommand(mapView2D *receiver, Editor *edi)
    :receiver(receiver),edi(edi)
{

}
EditShapeCommand::~EditShapeCommand()
{
    if(receiver) delete receiver;
    if(edi) delete edi;
}

void EditShapeCommand::excute()
{
    layers = layerManager::makeLayerManager();
    if(layers->getActivingObject() == nullptr)return;
    if(show)
    {
        edi->show();
        show = false;
    }
    else
    {
        show = true;
        edi->close();
    }
}

