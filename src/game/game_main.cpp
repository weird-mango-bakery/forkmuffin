#include <QApplication>
#include "game/GameMainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    GameMainWindow* window = new GameMainWindow();
    return app.exec();
}
