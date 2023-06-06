#ifndef STATEMANAGER_H
#define STATEMANAGER_H
class mapView2D;
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
        if (currentState)
        {
            delete currentState;
        }
        currentState = state;
    }

    void mousePressEvent(mapView2D* view, QMouseEvent* event)
    {
        if (currentState)
        {
            currentState->mousePressEvent(view, event);
        }
    }

    void mouseMoveEvent(mapView2D* view, QMouseEvent* event)
    {

        if (currentState)
        {
            currentState->mouseMoveEvent(view, event);
        }
    }

    void mouseReleaseEvent(mapView2D* view, QMouseEvent* event)
    {
        if (currentState)
        {
            currentState->mouseReleaseEvent(view, event);
        }
    }
};


#endif // STATEMANAGER_H
