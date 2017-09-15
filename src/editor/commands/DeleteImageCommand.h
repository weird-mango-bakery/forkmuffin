#pragma once

#include "editor/commands/AddDeleteImageCommand.h"

//! The command for deleting image.
class DeleteImageCommand : public AddDeleteImageCommand {
private:
    //! Create the command. Made private so the command can be created from image only.
    DeleteImageCommand(EditorMainWindow& editor, const QString& name, const QPoint& pos, const QSize& size, const QString& textureName);

public:
    //! Create the command for stray image.
    static DeleteImageCommand& create(EditorMainWindow& editor, const StrayImage& image);

    void undo() override;
    void redo() override;
};
