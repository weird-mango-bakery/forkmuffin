#pragma once

#include "common/Level.h"
#include "editor/tools/BlockTool.h"
#include "editor/Grid.h"

#include <QMainWindow>
#include <QUndoStack>

#include "ui_editor.h"

class EditorCommand;
class BlockSelectorWidget;

//! Main window of the editor.
class EditorMainWindow : public QMainWindow, private Ui::EditorMainWindow {
Q_OBJECT
private:
    //! The edited level.
    Level level;
    //! Grid of the editor.
    Grid grid;

    //! Undo stack for editor commands.
    QUndoStack undoStack;

    //! The block tool instance.
    BlockTool blockTool;
    //! The path to current opened file, null string if no file is open.
    QString path;
    //! The dockable widget with list of available blocks to select.
    BlockSelectorWidget* blockSelectorWidget;

    //! The current block symbol.
    QChar currentBlock;

private:
    //! Returns the path to levels directory ("data/levels").
    static QString getLevelsDir();
    //! Saves level to specified path and sets path as current if there were no errors.
    //! \param savePath specified path.
    void doSaveLevel(const QString& savePath);
    //! Fills current level with all known blocks.
    void updateLevelBlocks();

private slots:
    // Auto-connected slots for gui elements
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_canvas_mouseDrag(const QPointF& delta);
    void on_canvas_mouseWheel(float delta);
    void on_canvas_mouseClick(const QPointF& pos);
    void on_blockSelectorWidget_blockSelected(QChar chr);

    //! Slot to update title with current file name and unsaved marker.
    void updateTitle();

public:
    //! Creates editor window.
    EditorMainWindow();

    //! Returns the level reference.
    Level& getLevel();
    //! Returns the const level reference.
    const Level& getLevel() const;
    //! Returns the const camera reference.
    const Camera& getCamera() const;

    //! Push the command to the undo stack.
    void pushCommand(EditorCommand& command);
    //! Returns current block symbol.
    QChar getCurrentBlock() const;
};
