#include "CanvasWidget.h"

#include "common/Level.h"
#include "common/RenderManager.h"

#include <QPainter>

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    camera.apply(p);

    p.fillRect(rect(), Qt::lightGray);

    RenderManager::get().paint(p);
}

CanvasWidget::CanvasWidget(QWidget* parent): QWidget(parent) {
}

const Camera& CanvasWidget::getCamera() const {
    return camera;
}

void CanvasWidget::zoomCamera(float s, const QPointF& pos) {
    // first, move (0, 0) of the level to specified pos
    QPointF delta = pos - camera.getTranslation();
    // then move (0, 0) of the level back with respect to scale change
    delta -= delta * s;
    moveCamera(delta);
    camera.setScale(camera.getScale() * s);
}

void CanvasWidget::moveCamera(const QPointF& delta) {
    camera.setTranslation(camera.getTranslation() + delta);
}
