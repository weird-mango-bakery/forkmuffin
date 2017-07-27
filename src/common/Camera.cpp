#include "Camera.h"

#include "common/Level.h"
#include <QPainter>

float Camera::getScale() const {
    return scale;
}

void Camera::setScale(float s) {
    scale = s;
}

const QPointF& Camera::getTranslation() const {
    return translation;
}

void Camera::setTranslation(const QPointF& p) {
    translation = p;
}

void Camera::apply(QPainter& p) const {
    p.translate(translation);
    p.scale(scale, scale);
}

QPointF Camera::screenToWorld(const QPointF& pos) const {
    return (pos - translation)/scale;
}

QPointF Camera::worldToScreen(const QPointF& pos) const {
    return pos*scale + translation;
}

QPoint Camera::worldToLevel(const QPointF& pos) {
    QPointF result = pos / Level::BLOCK_SIZE;
    return QPoint(static_cast<int>(floor(result.x())), static_cast<int>(floor(result.y())));
}

QPointF Camera::levelToWorld(const QPoint& pos) {
    return pos * Level::BLOCK_SIZE;
}

QPoint Camera::screenToLevel(const QPointF& pos) const {
    return worldToLevel(screenToWorld(pos));
}

QPointF Camera::levelToScreen(const QPoint& pos) const {
    return worldToScreen(levelToWorld(pos));
}
