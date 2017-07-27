#include "Grid.h"

#include "common/Level.h"
#include <QPainter>

void Grid::paint(QPainter& p) const {
    p.setPen(QPen(Qt::darkBlue, 2));
    int w = Level::BLOCK_SIZE.width();
    int h = Level::BLOCK_SIZE.height();
    for (int x = 0; x <= 800; x += w) {
        p.drawLine(x, 0, x, 600);
    }
    for (int y = 0; y <= 600; y += h) {
        p.drawLine(0, y, 800, y);
    }
}

float Grid::getZOrder() const {
    return Z_FOREGROUND;
}
