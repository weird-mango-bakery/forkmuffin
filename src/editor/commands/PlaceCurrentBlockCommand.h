#pragma once

#include "editor/commands/PlaceBlockCommand.h"

//! Places a block of type that is currently selected.
class PlaceCurrentBlockCommand: public PlaceBlockCommand {
public:
    //! Creates Place Current Block command for specified point in level coordinates.
    PlaceCurrentBlockCommand(EditorMainWindow& editor, const QPoint& pos);
};
