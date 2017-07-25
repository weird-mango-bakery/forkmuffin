#pragma once

#include "common/Camera.h"

#include <QWidget>

class Level;

class CanvasWidget : public QWidget {
Q_OBJECT
private:
    const Level* level = nullptr;
    Camera camera;
    QPointF curMousePos;

public slots:
    //! Zoom camera around current mouse pos by multiplying scale by s.
    //! @param s - value to multiply by (usually you'd want (1+delta) or 1/(1+delta), where delta is close to 0).
    void zoomCamera(float s);
    void moveCamera(const QPointF& p);

public:
    void setLevel(const Level& lvl);

    explicit CanvasWidget(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

signals:
    void mouseDrag(const QPointF& delta);
    void mouseWheel(float delta);
};
