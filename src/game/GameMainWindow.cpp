#include "game/GameMainWindow.h"

#include "common/saveload.h"
#include "common/ValuesSelector.h"

#include <QKeyEvent>

static const QPointF GRAVITY(0, 600);

ValuesSelector<double> elapsedMods({0.01, 0.025, 0.05, 0.1, 0.25, 0.5, 0.75, 1, 2, 3, 4, 5, 6, 7, 8});

GameMainWindow::GameMainWindow(): player(QPointF(230, 175)), engine(GRAVITY) {
    setupUi(this);

    loadLevel(level, QCoreApplication::applicationDirPath() + "/../data/levels/test.json");
    canvas->addRenderable(level);
    canvas->addRenderable(player.getMuffin());
    engine.addObject(player.getMuffin());
    connect(&timer, SIGNAL(timeout()), SLOT(mainLoop()));

    elapsedMods.set(1);
    show();
    elapsedCounter.start();
    timer.start(33);
}

void GameMainWindow::mainLoop() {
    QElapsedTimer spentCounter;
    spentCounter.start();

    double elapsedSec = elapsedCounter.restart() * 0.001;
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
    if (isKeyPressed(Qt::Key_Plus)) {
        elapsedMods.next();
    }
    if (isKeyPressed(Qt::Key_Minus)) {
        elapsedMods.prev();
    }
    if (isKeyPressed(Qt::Key_0)) {
        elapsedMods.set(1);
    }
    double elapsedPhys = elapsedSec * elapsedMods.get();

    // process physics
    engine.setBounds(canvas->rect().adjusted(25, 25, -25, -25));
    engine.process(elapsedPhys);

    //render
    canvas->repaint(); // force repaint of the whole canvas

    statusbar->showMessage(
        QString("%1 msec total spent in main loop, elapsed time is %2 sec (%3 sec for physics with time x%4)")
            .arg(spentCounter.elapsed())
            .arg(elapsedSec)
            .arg(elapsedPhys)
            .arg(elapsedMods.get())
    );
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
