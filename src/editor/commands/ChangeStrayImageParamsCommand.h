#pragma once

#include <QPoint>
#include <QSize>
#include "editor/commands/EditorCommand.h"

class EditorMainWindow;
class StrayImage;

//! A command for changing stray image params.
class ChangeStrayImageParamsCommand : public EditorCommand {
private:
    //! The reference to stray image that we are changing.
    StrayImage& currentImage;
    //! The next position of the image.
    QPoint pos;
    //! The new size of the image.
    QSize size;
    //! The new texture name of the image.
    QString textureName;
    //! The current position of the image.
    QPoint oldPos;
    //! The current size of the image.
    QSize oldSize;
    //! The current texture name of the image.
    QString oldTextureName;

    //! Creates the command.
    ChangeStrayImageParamsCommand(
        EditorMainWindow& editor, StrayImage& currentImage, const QPoint& pos, const QSize& size, const QString& textureName);
public:
    //! Creates the command that changes only x.
    static EditorCommand* setX(EditorMainWindow& editor, StrayImage& currentImage, int newX);
    //! Creates the command that changes only y.
    static EditorCommand* setY(EditorMainWindow& editor, StrayImage& currentImage, int newY);
    //! Creates the command that changes only width.
    static EditorCommand* setWidth(EditorMainWindow& editor, StrayImage& currentImage, int newWidth);
    //! Creates the command that changes only height.
    static EditorCommand* setHeight(EditorMainWindow& editor, StrayImage& currentImage, int newHeight);
    //! Creates the command that changes only texture name.
    static EditorCommand* setTexture(EditorMainWindow& editor, StrayImage& currentImage, const QString& newTex);

    void undo() override;
    void redo() override;
};
