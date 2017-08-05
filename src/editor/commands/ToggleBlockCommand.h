#pragma once

#include <QPoint>
#include "editor/commands/EditorCommand.h"

//! Toggles block on the level (hardcoded to replace ' ' with '#', and '#' with ' ').
class ToggleBlockCommand: public EditorCommand {
private:
    //! Position of the block in level coordinates.
    QPoint pos;

public:
    //! Creates Toggle Block command for specified point in level coordinates.
    ToggleBlockCommand(EditorMainWindow& editor, const QPoint& pos);

    void undo() override;
    void redo() override;
};
