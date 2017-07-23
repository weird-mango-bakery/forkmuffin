#pragma once

#include <QMainWindow>

#include "ui_editor.h"

class EditorMainWindow : public QMainWindow, private Ui::EditorMainWindow {
Q_OBJECT
public:
    EditorMainWindow();
};
