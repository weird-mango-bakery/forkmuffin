#pragma once

#include "PhysicsObject.h"
#include <QList>
#include <QPointF>
#include <QRectF>

class PhysicsEngine {
private:
    QList<PhysicsObject*> objects;
    QRectF bounds;
    QPointF gravity;

public:
    explicit PhysicsEngine(const QPointF& gravity);

    void process();

    void setBounds(const QRectF& r);
    void addObject(PhysicsObject& obj);
};
