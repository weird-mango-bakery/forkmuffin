#pragma once

#include "common/Level.h"
#include "game/Player.h"
#include "game/PhysicsEngine.h"

#include <QMainWindow>
#include <QTimer>

#include "ui_game.h"

class GameMainWindow : public QMainWindow, private Ui::GameMainWindow {
Q_OBJECT
private:
    Player player;
    Level level;
    QTimer timer;
    PhysicsEngine engine;

private slots:
    void mainLoop();

public:
    GameMainWindow();
};
