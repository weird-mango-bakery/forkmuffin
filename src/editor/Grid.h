#pragma once

#include "common/Renderable.h"

class Grid: public Renderable {
public:
    void paint(QPainter& p) const override;

    float getZOrder() const override;
};
