#pragma once

#include "common/Level.h"

#include <QMainWindow>

#include "ui_editor.h"

class EditorMainWindow : public QMainWindow, private Ui::EditorMainWindow {
Q_OBJECT
private:
    Level level;

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();

public:
    EditorMainWindow();
};
