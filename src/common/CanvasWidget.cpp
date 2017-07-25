#include "CanvasWidget.h"

#include "common/Level.h"

#include <QPainter>
#include <QWheelEvent>
#include <QMouseEvent>

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    camera.apply(p);

    p.fillRect(rect(), Qt::magenta);

    if (level) {
        level->paint(p);
    }
}

CanvasWidget::CanvasWidget(QWidget* parent): QWidget(parent) {}

void CanvasWidget::setLevel(const Level& lvl) {
    level = &lvl;
}

void CanvasWidget::zoomCamera(float s) {
    // first, move (0, 0) of the level to current mouse pos
    QPointF delta = curMousePos - camera.getTranslation();
    // then move (0, 0) of the level back with respect to scale change
    delta -= delta * s;
    moveCamera(delta);
    camera.setScale(camera.getScale() * s);
}

void CanvasWidget::moveCamera(const QPointF& p) {
    camera.setTranslation(camera.getTranslation() + p);
}

void CanvasWidget::wheelEvent(QWheelEvent* event) {
    emit mouseWheel(event->delta()/120.f);
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    QPointF delta = event->pos() - curMousePos;
    curMousePos = event->localPos();
    if (event->buttons() & Qt::MouseButton::RightButton) {
        emit mouseDrag(delta);
    }
}
