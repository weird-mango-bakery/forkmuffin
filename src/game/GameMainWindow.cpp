#include "game/GameMainWindow.h"

#include "common/saveload.h"

#include <QElapsedTimer>
#include <QKeyEvent>

GameMainWindow::GameMainWindow(): player(QPointF(230, 175)), engine(QPointF(0, .1)) {
    setupUi(this);

    loadLevel(level, QCoreApplication::applicationDirPath() + "/../data/levels/test.json");
    canvas->addRenderable(level);
    canvas->addRenderable(player);
    engine.addObject(player);
    connect(&timer, SIGNAL(timeout()), SLOT(mainLoop()));

    show();
    timer.start(33);
}

void GameMainWindow::mainLoop() {
    QElapsedTimer spentCounter;
    spentCounter.start();

    // handle input
    if (isKeyPressed(Qt::Key_Up) || isKeyPressed(Qt::Key_W)) {
        player.moveUp();
    }
    if (isKeyPressed(Qt::Key_Down) || isKeyPressed(Qt::Key_S)) {
        player.moveDown();
    }
    if (isKeyPressed(Qt::Key_Left) || isKeyPressed(Qt::Key_A)) {
        player.moveLeft();
    }
    if (isKeyPressed(Qt::Key_Right) || isKeyPressed(Qt::Key_D)) {
        player.moveRight();
    }

    // process physics
    engine.setBounds(canvas->rect().adjusted(25, 25, -25, -25));
    engine.process();

    //render
    canvas->repaint(); // force repaint of the whole canvas

    statusbar->showMessage(QString("%1 msec total spent in main loop").arg(spentCounter.elapsed()));
}

void GameMainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) {
        return;
    }
    keyState.insert(event->key(), true);
}

void GameMainWindow::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) {
        return;
    }
    keyState.insert(event->key(), false);
}

bool GameMainWindow::isKeyPressed(Qt::Key key) const {
    return keyState.value(key, false);
}
