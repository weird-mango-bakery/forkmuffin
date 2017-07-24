#pragma once

#include "common/Level.h"

#include <QMainWindow>

#include "ui_game.h"

class GameMainWindow : public QMainWindow, private Ui::GameMainWindow {
Q_OBJECT
private:
    Level level;

public:
    GameMainWindow();
};
