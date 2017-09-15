#include "AddDeleteImageCommand.h"
#include "editor/EditorMainWindow.h"
#include "common/StrayImage.h"
#include <QInputDialog>

AddDeleteImageCommand::AddDeleteImageCommand(EditorMainWindow& editor, const QString& text, const QString& name, const QPoint& pos, const QSize& size, const QString& textureName)
    : ImageCommandBase(editor, text, name), pos(pos), size(size), textureName(textureName) {}

void AddDeleteImageCommand::createImage() {
    editor.getLevel().addStrayImage(new StrayImage(name, pos, size,  textureName));
}

void AddDeleteImageCommand::deleteImage() {
    editor.getLevel().deleteStrayImage(name);
}
