#include "PhysicsEngine.h"

#include "common/Camera.h"
#include "common/Level.h"
#include "game/PhysicsObject.h"

const int FRICTION_Y = 50;
const int FRICTION_X = 1;

void PhysicsEngine::process(double elapsed) {
    for (PhysicsObject* object : objects) {
        QPointF speed = object->getSpeed();
        QPointF pos = object->getPos();
        QPointF friction = object->getFriction();

        double xFric = -friction.rx() * speed.rx();
        double yFric = -friction.ry() * speed.ry();
        QPointF acceleration = gravity + QPointF(xFric, yFric);

        // special magic so speed won't infinitely grow
        // equivalent to x = x0 + v0*t + a*t*t/2; v = v0 + a*t
        speed += acceleration * 0.5 * elapsed;
        pos   += speed * elapsed;
        speed += acceleration * 0.5 * elapsed;

        QList<QPoint> collidedBlocks;
        QRectF objectRect(pos, object->getSize());
        for (int levelY = 0; levelY < level.getHeight(); ++levelY) {
            for (int levelX = 0; levelX < level.getWidth(); ++levelX) {
                if (!level.isEmpty(QPoint(levelX, levelY))) {
                    const QPointF& levelPoint = Camera::levelToWorld(QPoint(levelX, levelY));
                    QRectF levelBlock(levelPoint, Level::BLOCK_BOX);
                    QRectF intersect = levelBlock.intersected(objectRect);
                    if (!intersect.isEmpty()) {
                        collidedBlocks << QPoint(levelX, levelY);
                    }
                }
            }
        }

        friction = QPointF();
        for (QPoint collidedBlock : collidedBlocks) {
            const QPointF& levelPoint = Camera::levelToWorld(collidedBlock);
            QRectF levelBlock(levelPoint, Level::BLOCK_BOX);
            QRectF intersect = levelBlock.intersected(objectRect);

            bool collideX = false;
            bool collideY = false;
            if (collidedBlocks.size() == 1) {
                if (intersect.width() > intersect.height()) {
                    collideY = true;
                } else {
                    collideX = true;
                }
            } else {
                // The specified value for case when the object collides with several blocks on the level at the same time.
                // If the intersection rectangle's width or height is less than this value, we will not collide the object.
                const int submersion = Level::BLOCK_SIZE / 4;

                if (intersect.width() > intersect.height() && intersect.width() >= submersion) {
                    collideY = true;
                } else if (intersect.height() >= submersion) {
                    collideX = true;
                } else {
                    // Both intersect.height() and intersect.width() are less than submersion.
                    // We don't collide the object, at least for now...
                }
            }

            if (collideY) {
                if (pos.y() < levelPoint.y()) {
                    if (speed.y() >= 0) {
                        pos.setY(levelBlock.top() - object->getSize().height());
                    }
                } else {
                    pos.setY(levelBlock.bottom());
                }
                speed.setY(0);
                friction.setX(FRICTION_X);
            }
            if (collideX) {
                if (pos.x() < levelPoint.x()) {
                    if (speed.x() >= 0) {
                        pos.setX(levelBlock.left() - object->getSize().width());
                    }
                } else {
                    pos.setX(levelBlock.right());
                }
                speed.setX(0);
                friction.setY(FRICTION_Y);
            }
        }

        object->setPos(pos);
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

PhysicsEngine::PhysicsEngine(const QPointF& gravity, const Level& level): gravity(gravity), level(level) {}
