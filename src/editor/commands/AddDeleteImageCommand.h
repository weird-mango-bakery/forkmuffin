#pragma once

#include "editor/commands/ImageCommandBase.h"

#include <QPoint>
#include <QSize>
#include <QString>

//! The base command for adding and deleting images.
class AddDeleteImageCommand : public ImageCommandBase {
private:
    //! The position of the image.
    QPoint pos;
    //! The size of the image.
    QSize size;
    //! The texture name of the image.
    QString textureName;

protected:
    //! Create the command.
    AddDeleteImageCommand(EditorMainWindow& editor, const QString& text, const QString& name, const QPoint& pos,
                          const QSize& size, const QString& textureName);
    //! A protected method for creating image from the params given in constructor when the command was created.
    void createImage();
    //! A protected method for deleting image with the name given in constructor when the command was created.
    void deleteImage();
};
