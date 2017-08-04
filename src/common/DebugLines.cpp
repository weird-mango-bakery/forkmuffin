#include "DebugLines.h"
#include <QPainter>

void DebugLines::paint(QPainter& p) const {
    QRect rect = QRect(10, 10, 200, 50);
    p.setPen(Qt::darkGreen);
    p.drawText(rect, lines);
}

float DebugLines::getZOrder() const {
    return Z_DEBUG;
}

void DebugLines::reset() {
    lines.clear();
}

void DebugLines::addLine(const QString& s) {
    lines += s + "\n";
}