#pragma once

#include "editor/commands/EditorCommand.h"

class ToggleBlockCommand: public EditorCommand {
private:
    int x;
    int y;

public:
    ToggleBlockCommand(EditorMainWindow& editor, const QPoint& pos);

    void undo() override;
    void redo() override;
};
