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
    camera.setScale(camera.getScale() * s);
}

void CanvasWidget::moveCamera(const QPoint& p) {
    camera.setTranslation(camera.getTranslation() + p);
}

void CanvasWidget::wheelEvent(QWheelEvent* event) {
    emit mouseWheel(event->delta()/120.f);
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    QPoint delta = event->pos() - curMousePos;
    curMousePos = event->pos();
    if (event->buttons() & Qt::MouseButton::RightButton) {
        emit mouseDrag(delta);
    }
}
