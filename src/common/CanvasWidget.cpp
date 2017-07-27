#include "CanvasWidget.h"

#include "common/Level.h"

#include <QPainter>

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    camera.apply(p);

    p.fillRect(rect(), Qt::magenta);

    QMapIterator<float, const Renderable*> it(renderables);
    it.toBack();
    while(it.hasPrevious()) {
        it.previous();
        p.save();
        it.value()->paint(p);
        p.restore();
    }
}

CanvasWidget::CanvasWidget(QWidget* parent): QWidget(parent) {
}

const Camera& CanvasWidget::getCamera() const {
    return camera;
}

void CanvasWidget::addRenderable(const Renderable& item) {
    renderables.insert(item.getZOrder(), &item);
}

void CanvasWidget::zoomCamera(float s, const QPointF& pos) {
    // first, move (0, 0) of the level to specified pos
    QPointF delta = pos - camera.getTranslation();
    // then move (0, 0) of the level back with respect to scale change
    delta -= delta * s;
    moveCamera(delta);
    camera.setScale(camera.getScale() * s);
}

void CanvasWidget::moveCamera(const QPointF& p) {
    camera.setTranslation(camera.getTranslation() + p);
}
