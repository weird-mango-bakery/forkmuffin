#include "ImageCommandBase.h"
#include "editor/EditorMainWindow.h"

ImageCommandBase::ImageCommandBase(EditorMainWindow& editor, const QString& text, const QString& name)
    : EditorCommand(editor, text), name(name) {}

StrayImage& ImageCommandBase::currentImage() {
    return *editor.getLevel().getStrayFromName(name);
}
