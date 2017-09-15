#pragma once

#include "editor/commands/AddDeleteImageCommand.h"

//! The command for adding image.
class AddImageCommand : public AddDeleteImageCommand {
public:
    //! Create the command.
    AddImageCommand(EditorMainWindow& editor, const QString& name, const QPoint& pos, const QSize& size, const QString& textureName);

    void undo() override;
    void redo() override;
};
