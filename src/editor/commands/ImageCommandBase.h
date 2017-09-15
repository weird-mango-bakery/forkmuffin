#pragma once

#include "editor/commands/EditorCommand.h"

#include <QString>

class StrayImage;

//! The base class for all image commands.
class ImageCommandBase : public EditorCommand {
protected:
    //! The name of the image.
    const QString name;

    //! Create command.
    ImageCommandBase(EditorMainWindow& editor, const QString& text, const QString& name);

    //! Returns the stray image from name.
    StrayImage& currentImage();
};
