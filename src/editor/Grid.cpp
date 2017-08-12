#include "Grid.h"

#include "common/Level.h"
#include "common/Camera.h"
#include "editor/EditorMainWindow.h"
#include <QPainter>

Grid::Grid(const EditorMainWindow& editor): Renderable(Z_FOREGROUND), editor(editor) {}

void Grid::paint(QPainter& p) const {
    p.setPen(QPen(Qt::darkBlue, 2));
    int d = Level::BLOCK_SIZE;
    int w = editor.getLevel().getWidth() * d;
    int h = editor.getLevel().getHeight() * d;
    for (int x = 0; x <= w; x += d) {
        p.drawLine(x, 0, x, h);
    }
    for (int y = 0; y <= h; y += d) {
        p.drawLine(0, y, w, y);
    }
    p.setPen(QPen(Qt::green, 4));
    QPointF pos = editor.getCamera().levelToWorld(editor.getCamera().screenToLevel(mousePos));
    p.drawRect(QRectF(pos, Level::BLOCK_BOX));
}

void Grid::mouseMoved(const QPointF& pos) {
    mousePos = pos;
}
