#pragma once

#include <QMainWindow>

#include "ui_game.h"

class GameMainWindow : public QMainWindow, private Ui::GameMainWindow {
Q_OBJECT
public:
    GameMainWindow();
};
