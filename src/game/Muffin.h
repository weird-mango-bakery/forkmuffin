#pragma once

#include "common/Renderable.h"
#include "game/PhysicsObject.h"

class Muffin: public Renderable, public PhysicsObject {
public:
    Muffin(const QPointF& pos);

    void paint(QPainter& p) const override;
    float getZOrder() const override;
    QSizeF getSize() const override;
};


