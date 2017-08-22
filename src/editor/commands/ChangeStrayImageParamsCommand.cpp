#include "ChangeStrayImageParamsCommand.h"
#include "editor/EditorMainWindow.h"
#include "common/StrayImage.h"

void ChangeStrayImageParamsCommand::undo() {
    currentImage.setPos(oldPos);
    currentImage.setSize(oldSize);
    currentImage.setTexture(oldTextureName);
}

void ChangeStrayImageParamsCommand::redo() {
    currentImage.setPos(pos);
    currentImage.setSize(size);
    currentImage.setTexture(textureName);
}

ChangeStrayImageParamsCommand::ChangeStrayImageParamsCommand(
    EditorMainWindow& editor, StrayImage& currentImage, const QPoint& pos, const QSize& size, const QString& textureName)
    : EditorCommand(editor, "Change image params")
    , currentImage(currentImage)
    , pos(pos)
    , size(size)
    , textureName(textureName)
    , oldPos(currentImage.getPos())
    , oldSize(currentImage.getSize())
    , oldTextureName(currentImage.getTexture())
{}
