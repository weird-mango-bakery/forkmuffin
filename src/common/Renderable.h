#pragma once

class QPainter;

class Renderable{
public:
    virtual void paint(QPainter& p) const = 0;
    virtual float getZOrder() const = 0;

    static constexpr float Z_DEBUG = -2;
    static constexpr float Z_HUD = -1;
    static constexpr float Z_FOREGROUND = 0;
    static constexpr float Z_MIDDLE = .5f;
    static constexpr float Z_BACKGROUND = 1;

    virtual ~Renderable() = default;
};
