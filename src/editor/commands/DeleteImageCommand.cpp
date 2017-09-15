#include "DeleteImageCommand.h"
#include "common/StrayImage.h"

DeleteImageCommand::DeleteImageCommand(EditorMainWindow& editor, const QString& name, const QPoint& pos, const QSize& size, const QString& textureName)
    : AddDeleteImageCommand(editor, "Delete image", name, pos, size, textureName) {}

void DeleteImageCommand::undo() {
    createImage();
}

void DeleteImageCommand::redo() {
    deleteImage();
}

DeleteImageCommand& DeleteImageCommand::create(EditorMainWindow& editor, const StrayImage& image) {
    return *new DeleteImageCommand(editor, image.getName(), image.getPos(), image.getSize(), image.getTexture());
}
