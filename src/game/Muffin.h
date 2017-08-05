#pragma once

#include "common/Renderable.h"
#include "game/PhysicsObject.h"

//! The object that represents the main hero.
class Muffin: public Renderable, public PhysicsObject {
public:
    //! Creates muffin at the specified position.
    explicit Muffin(const QPointF& pos);

    void paint(QPainter& p) const override;
    float getZOrder() const override;
    QSizeF getSize() const override;
};


