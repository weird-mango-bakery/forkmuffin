#pragma once

#include "game/Muffin.h"

class Player {
private:
    Muffin muffin;

public:
    explicit Player(const QPointF& pos);

    Muffin& getMuffin();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};


