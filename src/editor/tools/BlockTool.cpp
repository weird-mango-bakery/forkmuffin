#include "BlockTool.h"
#include "editor/EditorMainWindow.h"
#include "editor/commands/EraseBlockCommand.h"
#include "editor/commands/PlaceCurrentBlockCommand.h"

BlockTool::BlockTool(EditorMainWindow& editor): Tool(editor) {}

void BlockTool::mouseClick(const QPointF& pos) {
    QPoint levelPos = editor.getCamera().screenToLevel(pos);
    if (!editor.getLevel().isInside(levelPos)) {
        return;
    }
    EditorCommand* command;
    if (editor.getLevel().getBlock(levelPos) != editor.getCurrentBlock()) {
        command = new PlaceCurrentBlockCommand(editor, levelPos);
    } else {
        command = new EraseBlockCommand(editor, levelPos);
    }
    editor.pushCommand(*command);
}
