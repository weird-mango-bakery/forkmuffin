#pragma once

#include "common/Renderable.h"
#include <QObject>
#include <QPointF>

class Camera;

class Grid: public QObject, public Renderable {
Q_OBJECT
private:
    const Camera& camera;
    QPointF mousePos;

public:
    explicit Grid(const Camera& camera);

    void paint(QPainter& p) const override;

    float getZOrder() const override;

public slots:
    void mouseMoved(const QPointF& pos);
};
