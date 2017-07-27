#pragma once

#include "common/Level.h"

#include <QMainWindow>

#include "ui_editor.h"

class Grid;

class EditorMainWindow : public QMainWindow, private Ui::EditorMainWindow {
Q_OBJECT
private:
    Level level;
    Grid* grid;

    QString getLevelsDir() const;

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_canvas_mouseDrag(const QPointF& delta);
    void on_canvas_mouseWheel(float delta);

public:
    EditorMainWindow();
    ~EditorMainWindow() override;
};
