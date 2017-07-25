#pragma once

#include <QPoint>

class QPainter;

class Camera {
private:
    float scale = 1;
    QPoint translation;
public:
    float getScale() const;

    const QPoint& getTranslation() const;

public:
    void setScale(float s);
    void setTranslation(const QPoint& p);

    void apply(QPainter& p) const;
};
