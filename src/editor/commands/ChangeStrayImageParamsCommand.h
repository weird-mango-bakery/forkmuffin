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

public:
    //! Creates the command.
    ChangeStrayImageParamsCommand(
        EditorMainWindow& editor, StrayImage& currentImage, const QPoint& pos, const QSize& size, const QString& textureName);

    void undo() override;
    void redo() override;
};
