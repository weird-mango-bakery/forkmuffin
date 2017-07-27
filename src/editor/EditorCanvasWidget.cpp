#include "EditorCanvasWidget.h"

#include <QWheelEvent>
#include <QMouseEvent>

EditorCanvasWidget::EditorCanvasWidget(QWidget* parent): CanvasWidget(parent) {
    setMouseTracking(true);
}

void EditorCanvasWidget::wheelEvent(QWheelEvent* event) {
    emit mouseWheel(event->delta()/120.f);
}

void EditorCanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    QPointF delta = event->pos() - curMousePos;
    curMousePos = event->localPos();
    emit mouseMove(curMousePos);
    mouseMoved = true;
    if (event->buttons() & Qt::MouseButton::RightButton) {
        emit mouseDrag(delta);
    }
    update();
}

const QPointF& EditorCanvasWidget::getCurMousePos() const {
    return curMousePos;
}

void EditorCanvasWidget::mousePressEvent(QMouseEvent* event) {
    mouseMoved = false;
}

void EditorCanvasWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (!mouseMoved) {
        emit mouseClick(curMousePos);
    }
}
