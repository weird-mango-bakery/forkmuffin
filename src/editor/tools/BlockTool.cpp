#include "BlockTool.h"
#include "editor/EditorMainWindow.h"
#include "editor/commands/ToggleBlockCommand.h"

BlockTool::BlockTool(EditorMainWindow& editor): Tool(editor) {}

void BlockTool::mouseClick(const QPointF& pos) {
    QPoint levelPos = editor.getCamera().screenToLevel(pos);
    if (!editor.getLevel().isInside(levelPos)) {
        return;
    }
    ToggleBlockCommand* command = new ToggleBlockCommand(editor, levelPos);
    editor.pushCommand(*command);
}