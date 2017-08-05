#pragma once

#include <QUndoCommand>

class EditorMainWindow;

//! A base class for all editor commands.
class EditorCommand: public QUndoCommand {
protected:
    //! The editor for command to manipulate.
    EditorMainWindow& editor;

    //! Creates the editor command.
    //! \param editor editor for the command.
    //! \param text name of the command in "Undo ..." or "Redo ..." menus.
    EditorCommand(EditorMainWindow& editor, const QString& text);
};
