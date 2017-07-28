#include "EditorCommand.h"

EditorCommand::EditorCommand(EditorMainWindow& editor, const QString& text)
        : QUndoCommand(text), editor(editor) {}
