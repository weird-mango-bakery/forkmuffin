#pragma once

#include "editor/EditorMainWindow.h"
#include "editor/commands/PlaceBlockCommand.h"

//! Erases block.
class EraseBlockCommand : public PlaceBlockCommand {
public:
    //! Creates Erase Block command for specified point in level coordinates.
    EraseBlockCommand(EditorMainWindow& editor, const QPoint& pos);
};
