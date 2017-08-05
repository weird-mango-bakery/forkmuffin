#pragma once

#include <QPointF>

class QPainter;

//! Camera for a painter that stores scale and translation.
//! Provides conversions between three coordinate systems:
//!
//! Screen coordinates - floating-point pixel coordinates with (0, 0) at the top-left corner of the screen.
//! Distance between (0, 0) and (1, 0) is always one pixel.
//!
//! World coordinates - floating-point coordinates with (0, 0) possibly anywhere on the screen.
//! Distance between (0, 0) and (1, 0) depends on the current scale.
//!
//! Level coordinates - integer coordinates counting amount of level blocks from the (0, 0) point of the world.
//! Distance between (0, 0) and (1, 0) is equal to distance between (0, 0) and (Level::BLOCK_SIZE, 0)
//! in world coordinates.
class Camera {
private:
    //! Camera scale.
    float scale = 1;
    //! Camera translation.
    QPointF translation;

public:
    //! Returns camera scale.
    float getScale() const;
    //! Sets scale.
    //! \param s new scale.
    void setScale(float s);

    //! Returns camera translation.
    const QPointF& getTranslation() const;
    //! Sets translation.
    //! \param p new translation.
    void setTranslation(const QPointF& p);

    //! Applies camera to the specified painter.
    //! \param p painter.
    void apply(QPainter& p) const;

    //! Transform screen coordinates to world coordinates.
    QPointF screenToWorld(const QPointF& pos) const;
    //! Transform world coordinates to screen coordinates.
    QPointF worldToScreen(const QPointF& pos) const;
    //! Transform world coordinates to level coordinates.
    static QPoint worldToLevel(const QPointF& pos);
    //! Transform level coordinates to world coordinates.
    static QPointF levelToWorld(const QPoint& pos);
    //! Transform screen coordinates to level coordinates.
    QPoint screenToLevel(const QPointF& pos) const;
    //! Transform level coordinates to screen coordinates.
    QPointF levelToScreen(const QPoint& pos) const;
};
