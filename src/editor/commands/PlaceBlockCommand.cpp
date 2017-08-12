#include "PlaceBlockCommand.h"

PlaceBlockCommand::PlaceBlockCommand(EditorMainWindow& editor, const QPoint& pos, QChar block, const QString& commandName)
    : EditorCommand(editor, commandName)
    , pos(pos)
    , block(block)
    , oldBlock(editor.getLevel().getBlock(pos)) {}

void PlaceBlockCommand::undo() {
    editor.getLevel().setBlock(pos, oldBlock);
}

void PlaceBlockCommand::redo() {
    editor.getLevel().setBlock(pos, block);
}
