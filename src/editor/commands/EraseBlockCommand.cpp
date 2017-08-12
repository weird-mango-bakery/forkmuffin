#include "EraseBlockCommand.h"

EraseBlockCommand::EraseBlockCommand(EditorMainWindow& editor, const QPoint& pos)
    : PlaceBlockCommand(editor, pos, ' ', "Erase block") {}
