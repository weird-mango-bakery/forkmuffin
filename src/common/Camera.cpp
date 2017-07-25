#include "Camera.h"

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
