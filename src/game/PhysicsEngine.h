#pragma once

#include "PhysicsObject.h"
#include <QList>
#include <QRectF>

class PhysicsEngine {
private:
    QList<PhysicsObject*> objects;
    QRectF bounds;

public:
    void process();

    void setBounds(const QRectF& r);
    void addObject(PhysicsObject& obj);
};
