#include "PhysicsEngine.h"

void PhysicsEngine::process() {
    for (PhysicsObject* object : objects) {
        double x = qBound(bounds.left(), object->getPos().x(), bounds.right() - object->getSize().width());
        double y = qBound(bounds.top(), object->getPos().y(), bounds.bottom() - object->getSize().height());
        object->setPos(QPointF(x, y));
    }
}

void PhysicsEngine::addObject(PhysicsObject& obj) {
    objects << &obj;
}

void PhysicsEngine::setBounds(const QRectF& r) {
    bounds = r;
}
