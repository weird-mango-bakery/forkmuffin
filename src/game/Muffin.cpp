#include "Muffin.h"
#include <QPainter>

Muffin::Muffin(const QPointF& pos): PhysicsObject(pos) {}

void Muffin::paint(QPainter& p) const {
    p.fillRect(QRectF(getPos(), getSize()), QColor(0, 255, 128));
}

float Muffin::getZOrder() const {
    return Z_MIDDLE;
}

QSizeF Muffin::getSize() const {
    return QSizeF(30, 50);
}
