#include "game/GameMainWindow.h"

#include "common/saveload.h"

#include <QElapsedTimer>

GameMainWindow::GameMainWindow(){
    setupUi(this);

    loadLevel(level, QCoreApplication::applicationDirPath() + "/../data/levels/test.json");
    canvas->addRenderable(level);
    connect(&timer, SIGNAL(timeout()), SLOT(mainLoop()));

    show();
    timer.start(33);
}

void GameMainWindow::mainLoop() {
    QElapsedTimer spentCounter;
    spentCounter.start();

    // handle input
    // TODO

    // process physics
    // TODO

    //render
    canvas->repaint(); // force repaint of the whole canvas

    statusbar->showMessage(QString("%1 msec total spent in main loop").arg(spentCounter.elapsed()));
}
