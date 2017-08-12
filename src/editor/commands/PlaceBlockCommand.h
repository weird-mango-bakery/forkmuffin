#pragma once

#include "editor/EditorMainWindow.h"
#include "editor/commands/EditorCommand.h"

//! A base class for commands that place or erase block.
class PlaceBlockCommand : public EditorCommand {
private:
    //! Position of the block in level coordinates.
    const QPoint pos;
    //! The new block in level coordinates.
    const QChar block;
    //! The old block in level coordinates.
    const QChar oldBlock;

protected:
    //! Used by children to create command with the specified name and block to place.
    PlaceBlockCommand(EditorMainWindow& editor, const QPoint& pos, QChar block, const QString& commandName);

public:
    void undo() override;
    void redo() override;
};
