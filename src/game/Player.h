#pragma once

#include "game/Muffin.h"

//! The player that controls the muffin.
class Player {
private:
    //! The muffin to control.
    Muffin muffin;

public:
    //! Creates player with muffin at the specified position.
    explicit Player(const QPointF& pos);

    //! Returns controlled muffin reference.
    Muffin& getMuffin();

    //! Moves muffin up.
    void moveUp();
    //! Moves muffin down.
    void moveDown();
    //! Moves muffin left.
    void moveLeft();
    //! Moves muffin right.
    void moveRight();
};


