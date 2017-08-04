#include "PhysicsEngine.h"

void PhysicsEngine::process(double elapsed) {
    for (PhysicsObject* object : objects) {
        QPointF speed = object->getSpeed();
        QPointF pos = object->getPos();
        QPointF friction = object->getFriction();

        double xFric = -friction.rx() * speed.rx();
        double yFric = -friction.ry() * speed.ry();
        speed += QPointF(xFric, yFric);

        // special magic so speed won't infinitely grow
        // equivalent to x = x0 + v0*t + a*t*t/2; v = v0 + a*t
        speed += gravity*0.5*elapsed;
        pos += speed*elapsed;
        speed += gravity*0.5*elapsed;

        double x = qBound(bounds.left(), pos.x(), bounds.right()  - object->getSize().width());
        double y = qBound(bounds.top(),  pos.y(), bounds.bottom() - object->getSize().height());

        if (x != pos.x()) {
            speed.setX(0);
            // Freezing at fall with the touch of the wall
            friction.setY(0.4);
        }else{
            friction.setY(0);
        }

        if (y != pos.y()) {
            speed.setY(0);
            friction.setX(0.1); // temp const
        }else{
            // Muffin can glide in air without friction
            friction.setX(0);
        }
        object->setPos(QPointF(x, y));
        object->setSpeed(speed);
        object->setFriction(friction);
    }
}

void PhysicsEngine::addObject(PhysicsObject& obj) {
    objects << &obj;
}

void PhysicsEngine::setBounds(const QRectF& r) {
    bounds = r;
}

PhysicsEngine::PhysicsEngine(const QPointF& gravity): gravity(gravity) {}
