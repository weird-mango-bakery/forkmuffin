#pragma once

#include <QPointF>
#include <QSizeF>

class PhysicsObject {
private:
    QPointF pos;
    QPointF speed;
    QPointF friction;

public:
    virtual QSizeF getSize() const = 0;

    const QPointF& getPos() const;
    const QPointF& getSpeed() const;
    const QPointF& getFriction() const;

    void setPos(const QPointF& p);
    void setSpeed(const QPointF& s);
    void setFriction(const QPointF& f);

    explicit PhysicsObject(const QPointF& pos);
    virtual ~PhysicsObject() = default;
};
