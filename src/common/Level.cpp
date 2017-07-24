#include "Level.h"

#include <QPainter>

void Level::paint(QPainter& painter) const {
    painter.setBrush(Qt::white);
    painter.drawEllipse(0, 0, 100, 80);
}
