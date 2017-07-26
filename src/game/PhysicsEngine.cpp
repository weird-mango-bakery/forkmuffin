#include "PhysicsEngine.h"

void PhysicsEngine::process() {
    for (PhysicsObject* object : objects) {
        QPointF speed = object->getSpeed();
        QPointF pos = object->getPos();

        // special magic so speed won't infinitely grow
        // equivalent to x = x0 + v0*t + a*t*t/2; v = v0 + a*t
        speed += gravity*0.5;
        pos += speed;
        speed += gravity*0.5;

        double x = qBound(bounds.left(), pos.x(), bounds.right() - object->getSize().width());
        double y = qBound(bounds.top(), pos.y(), bounds.bottom() - object->getSize().height());
        if (x != pos.x()) {
            speed.setX(0);
        }
        if (y != pos.y()) {
            speed.setY(0);
        }
        object->setPos(QPointF(x, y));
        object->setSpeed(speed);
    }
}

void PhysicsEngine::addObject(PhysicsObject& obj) {
    objects << &obj;
}

void PhysicsEngine::setBounds(const QRectF& r) {
    bounds = r;
}

PhysicsEngine::PhysicsEngine(const QPointF& gravity): gravity(gravity) {}
