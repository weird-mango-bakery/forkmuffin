#include "ToggleBlockCommand.h"

#include "editor/EditorMainWindow.h"

ToggleBlockCommand::ToggleBlockCommand(EditorMainWindow& editor, const QPoint& pos)
    : EditorCommand(editor, "Toggle block"), pos(pos) {}

void ToggleBlockCommand::undo() {
    redo();
}

void ToggleBlockCommand::redo() {
    if (editor.getLevel().getBlock(pos.x(), pos.y()) == ' ') {
        editor.getLevel().setBlock(pos.x(), pos.y(), '#');
    } else {
        editor.getLevel().setBlock(pos.x(), pos.y(), ' ');
    }
}
