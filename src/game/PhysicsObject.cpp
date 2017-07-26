#include "PhysicsObject.h"

const QPointF& PhysicsObject::getPos() const {
    return pos;
}

void PhysicsObject::setPos(const QPointF& p) {
    pos = p;
}

PhysicsObject::PhysicsObject(const QPointF& pos): pos(pos) {}
