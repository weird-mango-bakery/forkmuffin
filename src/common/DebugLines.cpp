#include "DebugLines.h"
#include <QPainter>

void DebugLines::paint(QPainter& p) const {
    QRect rect = QRect(10, 10, 200, 60);
    p.setPen(Qt::yellow);
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
