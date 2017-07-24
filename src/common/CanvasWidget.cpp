#include "CanvasWidget.h"

#include "Level.h"

#include <QPainter>

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter p(this);

    p.fillRect(rect(), Qt::magenta);

    if (level) {
        level->paint(p);
    }
}

CanvasWidget::CanvasWidget(QWidget* parent): QWidget(parent) {}

void CanvasWidget::setLevel(const Level& lvl) {
    level = &lvl;
}
