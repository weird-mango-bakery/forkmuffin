#include <QApplication>
#include "editor/EditorMainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    EditorMainWindow* window = new EditorMainWindow();
    return app.exec();
}
