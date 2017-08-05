#pragma once

#include <QPointF>
#include <QSizeF>

//! A base class for objects that interact with each other by physics laws.
//! Only rectangle objects are supported.
class PhysicsObject {
private:
    //! The object position in world coordinates.
    QPointF pos;
    //! The object speed.
    QPointF speed;
    //! The object viscous friction.
    QPointF friction;

public:
    //! Returns the object size.
    virtual QSizeF getSize() const = 0;

    //! Returns the object position
    const QPointF& getPos() const;
    //! Returns the object speed.
    const QPointF& getSpeed() const;
    //! Returns the object viscous friction.
    const QPointF& getFriction() const;

    //! Sets the object position.
    void setPos(const QPointF& p);
    //! Sets the object speed.
    void setSpeed(const QPointF& s);
    //! Sets the object viscous friction.
    void setFriction(const QPointF& f);

    //! Creates object at the specified position.
    explicit PhysicsObject(const QPointF& pos);
    virtual ~PhysicsObject() = default;
};
