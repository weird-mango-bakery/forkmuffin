#include "AddImageCommand.h"

void AddImageCommand::undo() {
    deleteImage();
}

void AddImageCommand::redo() {
    createImage();
}

AddImageCommand::AddImageCommand(EditorMainWindow& editor, const QString& name, const QPoint& pos, const QSize& size, const QString& textureName)
    : AddDeleteImageCommand(editor, "Add image", name, pos, size, textureName) {}
