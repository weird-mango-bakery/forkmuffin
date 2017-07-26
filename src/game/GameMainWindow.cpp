#include "game/GameMainWindow.h"

#include "common/saveload.h"

#include <QElapsedTimer>

GameMainWindow::GameMainWindow(){
    setupUi(this);

    loadLevel(level, QCoreApplication::applicationDirPath() + "/../data/levels/test.json");
    canvas->addRenderable(level);
    canvas->addRenderable(player);
    connect(&timer, SIGNAL(timeout()), SLOT(mainLoop()));

    show();
    timer.start(33);
}

void GameMainWindow::mainLoop() {
    QElapsedTimer spentCounter;
    spentCounter.start();

    // handle input
    if (canvas->isKeyPressed(Qt::Key_Up) || canvas->isKeyPressed(Qt::Key_W)) {
        player.moveUp();
    }
    if (canvas->isKeyPressed(Qt::Key_Down) || canvas->isKeyPressed(Qt::Key_S)) {
        player.moveDown();
    }
    if (canvas->isKeyPressed(Qt::Key_Left) || canvas->isKeyPressed(Qt::Key_A)) {
        player.moveLeft();
    }
    if (canvas->isKeyPressed(Qt::Key_Right) || canvas->isKeyPressed(Qt::Key_D)) {
        player.moveRight();
    }

    // process physics
    QSize size = canvas->size();
    int x = qBound(0, player.getPos().x(), size.width() - player.getSize().width());
    int y = qBound(0, player.getPos().y(), size.height() - player.getSize().height());
    player.setPos(QPoint(x, y));

    //render
    canvas->repaint(); // force repaint of the whole canvas

    statusbar->showMessage(QString("%1 msec total spent in main loop").arg(spentCounter.elapsed()));
}
