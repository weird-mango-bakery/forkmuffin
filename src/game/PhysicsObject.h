#pragma once

#include <QPointF>
#include <QSizeF>

class PhysicsObject {
private:
    QPointF pos;
    QPointF speed;

public:
    virtual QSizeF getSize() const = 0;
    const QPointF& getPos() const;
    void setPos(const QPointF& p);
    const QPointF& getSpeed() const;
    void setSpeed(const QPointF& s);

    explicit PhysicsObject(const QPointF& pos);
    virtual ~PhysicsObject() = default;
};
