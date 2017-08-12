#include "Muffin.h"
#include <QPainter>

Muffin::Muffin(const QPointF& pos): Renderable(Z_MIDDLE), PhysicsObject(pos) {}

void Muffin::paint(QPainter& p) const {
    p.fillRect(QRectF(getPos(), getSize()), QColor(0, 255, 128));
}

QSizeF Muffin::getSize() const {
    return QSizeF(30, 50);
}
