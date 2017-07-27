#pragma once

#include <QPointF>

class QPainter;

class Camera {
private:
    float scale = 1;
    QPointF translation;

public:
    float getScale() const;
    void setScale(float s);

    const QPointF& getTranslation() const;
    void setTranslation(const QPointF& p);

    void apply(QPainter& p) const;

    QPointF screenToWorld(const QPointF& pos) const;
    QPointF worldToScreen(const QPointF& pos) const;
};
