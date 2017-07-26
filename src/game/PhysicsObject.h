#pragma once

#include <QPointF>
#include <QSizeF>

class PhysicsObject {
private:
    QPointF pos;

public:
    virtual QSizeF getSize() const = 0;
    const QPointF& getPos() const;
    void setPos(const QPointF& p);

    explicit PhysicsObject(const QPointF& pos);
    virtual ~PhysicsObject() = default;
};
