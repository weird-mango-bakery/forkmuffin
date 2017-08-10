#pragma once

#include <QList>
#include <QPointF>
#include <QRectF>

class PhysicsObject;
class Level;

//! The class to handle physics interaction between objects.
class PhysicsEngine {
private:
    //! The list of interacting objects.
    QList<PhysicsObject*> objects;
    //! The screen bounds.
    QRectF bounds;
    //! The global gravity acceleration.
    QPointF gravity;
    //! The level for objects to collide with.
    const Level& level;

public:
    //! Creates engine with specified gravity acceleration.
    PhysicsEngine(const QPointF& gravity, const Level& level);

    //! Process physics for the elapsed period of the time.
    //! \param elapsed passed period of time (in seconds).
    void process(double elapsed);

    //! Sets the screen bounds.
    void setBounds(const QRectF& r);
    //! Adds the object for interaction.
    void addObject(PhysicsObject& obj);
};
