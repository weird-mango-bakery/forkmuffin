#include "BlockTool.h"
#include "editor/EditorMainWindow.h"

BlockTool::BlockTool(EditorMainWindow& editor): Tool(editor) {}

void BlockTool::mouseClick(const QPointF& pos) {
    QPoint levelPos = editor.getCamera().screenToLevel(pos);
    if (!editor.getLevel().isInside(levelPos)) {
        return;
    }
    editor.getLevel().toggleBlock(levelPos.x(), levelPos.y());
}
