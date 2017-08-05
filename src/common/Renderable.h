#pragma once

class QPainter;

//! A base class for object that can be drawn.
class Renderable {
public:
    //! Abstract method that is called when renderable should be painted.
    //! \param p  painter to paint renderable with.
    virtual void paint(QPainter& p) const = 0;
    //! Returns Z-order of the renderable.
    virtual float getZOrder() const = 0;

    //! Z-level above everything, should be used for debug.
    static constexpr float Z_DEBUG = -2;
    //! Z-level above entire level, should be used for user interface, menus, etc.
    static constexpr float Z_HUD = -1;
    //! Z-level of the foreground of the level.
    static constexpr float Z_FOREGROUND = 0;
    //! Z-level of the middle part of the level, player and most of objects should be here.
    static constexpr float Z_MIDDLE = .5f;
    //! Z-level for level background.
    static constexpr float Z_BACKGROUND = 1;

    virtual ~Renderable() = default;
};
