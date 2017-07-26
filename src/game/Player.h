#pragma once

#include <common/Renderable.h>
#include <QPoint>

class Player: public Renderable {
private:
    QPoint pos = QPoint(230, 175);

public:
    void paint(QPainter& p) const override;
    float getZOrder() const override;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};


