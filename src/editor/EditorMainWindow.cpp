#include "editor/EditorMainWindow.h"

EditorMainWindow::EditorMainWindow(){
    setupUi(this);

    canvas->setLevel(level);

    show();
}
