#include "game/GameMainWindow.h"

GameMainWindow::GameMainWindow(){
    setupUi(this);

    canvas->setLevel(level);

    show();
}
