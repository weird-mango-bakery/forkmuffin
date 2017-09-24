#pragma once

#include "editor/commands/EditorCommand.h"

//! The command for changing stray image name.
class ChangeStrayImageNameCommand : public EditorCommand {
private:
    //! New image name.
    QString newName;
    //! Old image name.
    QString oldName;

public:
    void undo() override;
    void redo() override;

    //! Create the command.
    ChangeStrayImageNameCommand(EditorMainWindow& editor, const QString& newName, const QString& oldName);
};
