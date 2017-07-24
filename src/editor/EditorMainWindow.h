#pragma once

#include "common/Level.h"

#include <QMainWindow>

#include "ui_editor.h"

class EditorMainWindow : public QMainWindow, private Ui::EditorMainWindow {
Q_OBJECT
private:
    Level level;

public:
    EditorMainWindow();
};
