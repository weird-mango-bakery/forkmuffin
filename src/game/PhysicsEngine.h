#pragma once

#include "PhysicsObject.h"
#include <QList>
#include <QPointF>
#include <QRectF>

//! The class to handle physics interaction between objects.
class PhysicsEngine {
private:
    //! The list of interacting objects.
    QList<PhysicsObject*> objects;
    //! The screen bounds.
    QRectF bounds;
    //! The global gravity acceleration.
    QPointF gravity;

public:
    //! Creates engine with specified gravity acceleration.
    explicit PhysicsEngine(const QPointF& gravity);

    //! Process physics for the elapsed period of the time.
    //! \param elapsed passed period of time (in seconds).
    void process(double elapsed);

    //! Sets the screen bounds.
    void setBounds(const QRectF& r);
    //! Adds the object for interaction.
    void addObject(PhysicsObject& obj);
};
