#include "Grid.h"

#include "common/Level.h"
#include "common/Camera.h"
#include <QPainter>

Grid::Grid(const Camera& camera): camera(camera) {}

void Grid::paint(QPainter& p) const {
    p.setPen(QPen(Qt::darkBlue, 2));
    int d = Level::BLOCK_SIZE;
    for (int x = 0; x <= 800; x += d) {
        p.drawLine(x, 0, x, 600);
    }
    for (int y = 0; y <= 600; y += d) {
        p.drawLine(0, y, 800, y);
    }
    p.setPen(QPen(Qt::green, 4));
    QPointF pos = camera.levelToWorld(camera.screenToLevel(mousePos));
    p.drawRect(QRectF(pos, Level::BLOCK_BOX));
}

float Grid::getZOrder() const {
    return Z_FOREGROUND;
}

void Grid::mouseMoved(const QPointF& pos) {
    mousePos = pos;
}
