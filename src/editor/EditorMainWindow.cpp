#include "editor/EditorMainWindow.h"

#include "common/saveload.h"
#include "editor/Grid.h"

#include <QFileDialog>
#include <QMessageBox>

QString EditorMainWindow::getLevelsDir() const {
    return QCoreApplication::applicationDirPath() + "/../data/levels";
}

EditorMainWindow::EditorMainWindow() {
    setupUi(this);
    grid = new Grid(canvas->getCamera());

    canvas->setMouseTracking(true);
    canvas->addRenderable(level);
    canvas->addRenderable(*grid);

    connect(canvas, SIGNAL(mouseMove(const QPointF&)), grid, SLOT(mouseMoved(const QPointF&)));

    show();
}

void EditorMainWindow::on_actionOpen_triggered() {
    QString path = QFileDialog::getOpenFileName(this, "Open level", getLevelsDir(), "JSON files (*.json)");
    if (path.isNull()){
        return;
    }

    QString errorMsg;
    if (!loadLevel(level, path, &errorMsg)) {
        QMessageBox::critical(this, "Error opening level", errorMsg);
    }
}

void EditorMainWindow::on_actionSaveAs_triggered() {
    QString path = QFileDialog::getSaveFileName(this, "Save level as", getLevelsDir(), "JSON files (*.json)");
    if (path.isNull()){
        return;
    }

    QString errorMsg;
    if (!saveLevel(level, path, &errorMsg)) {
        QMessageBox::critical(this, "Error saving level", errorMsg);
    }
}

void EditorMainWindow::on_canvas_mouseDrag(const QPointF& delta) {
    canvas->moveCamera(delta);
    canvas->update();
}

void EditorMainWindow::on_canvas_mouseWheel(float delta) {
    canvas->zoomCamera(1 + delta/10.f, canvas->getCurMousePos());
    canvas->update();
}

EditorMainWindow::~EditorMainWindow() {
    delete grid;
}
