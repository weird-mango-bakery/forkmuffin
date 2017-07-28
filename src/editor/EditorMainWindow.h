#pragma once

#include "common/Level.h"
#include "editor/tools/BlockTool.h"
#include "editor/Grid.h"

#include <QMainWindow>
#include <QUndoStack>

#include "ui_editor.h"

class EditorCommand;

class EditorMainWindow : public QMainWindow, private Ui::EditorMainWindow {
Q_OBJECT
private:
    Level level;
    Grid grid;

    QUndoStack undoStack;

    BlockTool blockTool;

    QString getLevelsDir() const;

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_canvas_mouseDrag(const QPointF& delta);
    void on_canvas_mouseWheel(float delta);
    void on_canvas_mouseClick(const QPointF& pos);

public:
    EditorMainWindow();

    Level& getLevel();
    const Camera& getCamera() const;

    void pushCommand(EditorCommand& command);
};
