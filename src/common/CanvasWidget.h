#pragma once

#include "common/Camera.h"

#include <QWidget>

//! Widget that draws renderables according to their Z-order (from higher to lower).
class CanvasWidget : public QWidget {
Q_OBJECT
private:
    //! Camera of the canvas.
    Camera camera;

public slots:
    //! Zoom camera around given pos by multiplying scale by s.
    //! \param s value to multiply by (usually you'd want (1+delta) or 1/(1+delta), where delta is close to 0).
    //! \param pos point that keeps its position on screen when zoom is changed.
    void zoomCamera(float s, const QPointF& pos);
    //! Move camera by specified shift.
    //! \param delta shift that is added to current translation.
    void moveCamera(const QPointF& delta);

public:
    //! Creates widget with given parent.
    //! \param parent parent widget or nullptr for widgets without parent.
    explicit CanvasWidget(QWidget* parent);

    //! Returns camera of the canvas
    const Camera& getCamera() const;

protected:
    //! Gets called by Qt when widget should be painted.
    void paintEvent(QPaintEvent* event) override;
};
