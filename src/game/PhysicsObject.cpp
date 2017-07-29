#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(const QPointF& pos): pos(pos) {}


void PhysicsObject::setPos(const QPointF& p) {
    pos = p;
}

void PhysicsObject::setSpeed(const QPointF& s) {
    speed = s;
}

void PhysicsObject::setFriction(const QPointF& f) {
    friction = f;
}


const QPointF& PhysicsObject::getSpeed() const {
    return speed;
}

const QPointF& PhysicsObject::getPos() const {
    return pos;
}

const QPointF& PhysicsObject::getFriction() const {
    return friction;
}