#pragma once

#include "common/Renderable.h"
#include "game/PhysicsObject.h"

class Player: public Renderable, public PhysicsObject {
public:
    explicit Player(const QPointF& pos);

    void paint(QPainter& p) const override;
    float getZOrder() const override;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    QSizeF getSize() const override;
};


