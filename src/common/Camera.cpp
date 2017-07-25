#include "Camera.h"

#include <QPainter>

void Camera::setScale(float s) {
    scale = s;
}

void Camera::setTranslation(const QPoint& p) {
    translation = p;
}

void Camera::apply(QPainter& p) const {
    p.translate(translation);
    p.scale(scale, scale);
}

float Camera::getScale() const {
    return scale;
}

const QPoint& Camera::getTranslation() const {
    return translation;
}
