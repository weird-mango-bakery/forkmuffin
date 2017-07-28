#pragma once

#include <QUndoCommand>

class EditorMainWindow;

class EditorCommand: public QUndoCommand {
protected:
    EditorMainWindow& editor;

    EditorCommand(EditorMainWindow& editor, const QString& text);
};
