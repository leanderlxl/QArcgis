#include "shapeeditor.h"
#include<QDebug>
ShapeEditor::ShapeEditor(EditState* e):currentState(e)
{

}
void ShapeEditor::setState(EditState * state)
{
//    qDebug()<<"set state";
    if(currentState) delete currentState;
    currentState = nullptr;
    currentState = state;
}
void ShapeEditor::mousePressEvent(QMouseEvent *e)
{
    if(currentState)currentState->mousePressevent(e);
}
void ShapeEditor::mouseMoveEvent(QMouseEvent *e)
{
    if(currentState)currentState->mouseMoveEvent(e);
}
void ShapeEditor::mouseReleaseEvent(QMouseEvent *e)
{
    if(currentState)currentState->mouseReleaseEvent(e);
}
void ShapeEditor::mouseDoubleClickedEvent(QMouseEvent* e)
{
    if(currentState)currentState->mouseDoubleClickedEvent(e);
}
void ShapeEditor::mouseWheelEvent(QWheelEvent * e)
{
    if(currentState)currentState->mouseWheelEvent(e);
}
