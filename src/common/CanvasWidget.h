#pragma once

#include "common/Camera.h"

#include <QWidget>
#include <QMultiMap>

class Renderable;

class CanvasWidget : public QWidget {
Q_OBJECT
private:
    QMultiMap<float, const Renderable*> renderables;
    Camera camera;

public slots:
    //! Zoom camera around given pos by multiplying scale by s.
    //! @param s - value to multiply by (usually you'd want (1+delta) or 1/(1+delta), where delta is close to 0).
    //! @param pos - point that keeps its position on screen when zoom is changed.
    void zoomCamera(float s, const QPointF& pos);
    void moveCamera(const QPointF& p);

public:
    void addRenderable(const Renderable& item);

    explicit CanvasWidget(QWidget* parent);

    const Camera& getCamera() const;

protected:
    void paintEvent(QPaintEvent* event) override;
};
