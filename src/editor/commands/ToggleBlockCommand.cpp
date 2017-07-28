#include "ToggleBlockCommand.h"

#include "editor/EditorMainWindow.h"

ToggleBlockCommand::ToggleBlockCommand(EditorMainWindow& editor, const QPoint& pos)
        : EditorCommand(editor, "Toggle block"), x(pos.x()), y(pos.y()) {}

void ToggleBlockCommand::undo() {
    redo();
}

void ToggleBlockCommand::redo() {
    if (editor.getLevel().getBlock(x, y) == ' ') {
        editor.getLevel().setBlock(x, y, '#');
    } else {
        editor.getLevel().setBlock(x, y, ' ');
    }
}
