#ifndef SHAPEEDITOR_H
#define SHAPEEDITOR_H

#include"EditShapeState.h"

class ShapeEditor
{
public:
    ShapeEditor(EditState*e = nullptr);
    ~ShapeEditor()
    {
        if(currentState)delete currentState;
    }
    void setState(EditState*);

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickedEvent(QMouseEvent*);

    void mouseWheelEvent(QWheelEvent*);
private:
    EditState* currentState;
};

#endif // SHAPEEDITOR_H
