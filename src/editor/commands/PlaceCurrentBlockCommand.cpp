#include "PlaceCurrentBlockCommand.h"

PlaceCurrentBlockCommand::PlaceCurrentBlockCommand(EditorMainWindow& editor, const QPoint& pos)
    : PlaceBlockCommand(editor, pos, editor.getCurrentBlock(), "Place block") {}
