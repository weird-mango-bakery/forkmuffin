#include "EditorCanvasWidget.h"

#include <QWheelEvent>
#include <QMouseEvent>

EditorCanvasWidget::EditorCanvasWidget(QWidget* parent): CanvasWidget(parent) {}

void EditorCanvasWidget::wheelEvent(QWheelEvent* event) {
    emit mouseWheel(event->delta()/120.f);
}

void EditorCanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    QPointF delta = event->pos() - curMousePos;
    curMousePos = event->localPos();
    if (event->buttons() & Qt::MouseButton::RightButton) {
        emit mouseDrag(delta);
    }
}

const QPointF& EditorCanvasWidget::getCurMousePos() const {
    return curMousePos;
}
