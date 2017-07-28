#include "BlockTool.h"
#include "editor/EditorMainWindow.h"

BlockTool::BlockTool(EditorMainWindow& editor): Tool(editor) {}

void BlockTool::mouseClick(const QPointF& pos) {
    QPoint levelPos = editor.getCamera().screenToLevel(pos);
    if (!editor.getLevel().isInside(levelPos)) {
        return;
    }
    int x = levelPos.x();
    int y = levelPos.y();
    if (editor.getLevel().getBlock(x, y) == ' ') {
        editor.getLevel().setBlock(x, y, '#');
    } else {
        editor.getLevel().setBlock(x, y, ' ');
    }
}
