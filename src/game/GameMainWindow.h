#pragma once

#include "common/Level.h"
#include "common/DebugLines.h"
#include "game/Player.h"
#include "game/PhysicsEngine.h"

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>

#include "ui_game.h"

//! Main window of the game.
class GameMainWindow : public QMainWindow, private Ui::GameMainWindow {
Q_OBJECT
private:
    //! The player instance.
    Player player;
    //! The loaded level.
    Level level;
    //! The game loop timer.
    QTimer timer;
    //! The elapsed timer to measure the actual time between frames.
    QElapsedTimer elapsedCounter;
    //! The debug lines instance.
    DebugLines debugLines;
    //! The physics engine instance.
    PhysicsEngine engine;
    //! The map to store keyboard state.
    QHash<int, bool> keyState;

private slots:
    //! The main loop function that is called every frame.
    void mainLoop();

public:
    //! Creates game window.
    GameMainWindow();

    //! Returns true if specified key pressed, false otherwise.
    bool isKeyPressed(Qt::Key key) const;

protected:
    //! Gets called by Qt when key is pressed.
    void keyPressEvent(QKeyEvent* event) override;
    //! Gets called by Qt when key is released.
    void keyReleaseEvent(QKeyEvent* event) override;
};