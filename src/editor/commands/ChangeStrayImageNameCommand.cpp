#include "ChangeStrayImageNameCommand.h"

#include "editor/EditorMainWindow.h"
#include "common/StrayImage.h"

ChangeStrayImageNameCommand::ChangeStrayImageNameCommand(
    EditorMainWindow& editor, const QString& newName, const QString& oldName
)
    : EditorCommand(editor, "Change image name")
    , newName(newName)
    , oldName(oldName)
{}

void ChangeStrayImageNameCommand::undo() {
    editor.getLevel().getStrayFromName(newName)->setName(oldName);
}

void ChangeStrayImageNameCommand::redo() {
    editor.getLevel().getStrayFromName(oldName)->setName(newName);
}
