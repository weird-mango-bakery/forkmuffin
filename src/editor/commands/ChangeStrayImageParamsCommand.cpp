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

EditorCommand* ChangeStrayImageParamsCommand::setX(EditorMainWindow& editor, StrayImage& currentImage, int newX) {
    return new ChangeStrayImageParamsCommand(editor, currentImage, QPoint(newX, currentImage.getPos().y()), currentImage.getSize(), currentImage.getTexture());
}

EditorCommand* ChangeStrayImageParamsCommand::setY(EditorMainWindow& editor, StrayImage& currentImage, int newY) {
    return new ChangeStrayImageParamsCommand(editor, currentImage, QPoint(currentImage.getPos().x(), newY), currentImage.getSize(), currentImage.getTexture());
}

EditorCommand* ChangeStrayImageParamsCommand::setWidth(EditorMainWindow& editor, StrayImage& currentImage, int newWidth) {
    return new ChangeStrayImageParamsCommand(editor, currentImage, currentImage.getPos(), QSize(newWidth, currentImage.getSize().height()), currentImage.getTexture());
}

EditorCommand* ChangeStrayImageParamsCommand::setHeight(EditorMainWindow& editor, StrayImage& currentImage, int newHeight) {
    return new ChangeStrayImageParamsCommand(editor, currentImage, currentImage.getPos(), QSize(currentImage.getSize().width(), newHeight), currentImage.getTexture());
}

EditorCommand* ChangeStrayImageParamsCommand::setTexture(EditorMainWindow& editor, StrayImage& currentImage, const QString& newTex) {
    return new ChangeStrayImageParamsCommand(editor, currentImage, currentImage.getPos(), currentImage.getSize(), newTex);
}
