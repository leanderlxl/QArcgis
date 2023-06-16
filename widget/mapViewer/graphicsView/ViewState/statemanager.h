#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include"selectstate.h"
class SelectionStateManager
{
private:
    SelectionState* currentState;

public:
    SelectionStateManager(SelectionState *state = nullptr)
        : currentState(state)
    {
    }

    ~SelectionStateManager()
    {
        if (currentState)
        {
            delete currentState;
        }
    }

    void setState(SelectionState* state)
    {
        currentState = state;
    }

    QList<mapObject*> mousePressEvent(mapView2D* view, QMouseEvent* event)
    {
        if (currentState)
        {
            QList<mapObject*> list = currentState->mousePressEvent(view, event);
            return list;
        }
    }

    QList<mapObject*> mouseMoveEvent(mapView2D* view, QMouseEvent* event)
    {

        if (currentState)
        {
            currentState->mouseMoveEvent(view, event);
            QList<mapObject*> tmp;
            return tmp;
        }
    }

    QList<mapObject*> mouseReleaseEvent(mapView2D* view, QMouseEvent* event)
    {
        if (currentState)
        {
            currentState->mouseReleaseEvent(view, event);
            QList<mapObject*> tmp;
            return tmp;
        }
    }
};


#endif // STATEMANAGER_H
