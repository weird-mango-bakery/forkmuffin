#include "editor/EditorMainWindow.h"

#include "common/saveload.h"
#include "editor/commands/EditorCommand.h"
#include "editor/widgets/BlockWidget.h"
#include "editor/widgets/BlockSelectorWidget.h"

#include <QFileDialog>
#include <QMessageBox>

QString EditorMainWindow::getLevelsDir() {
    return QCoreApplication::applicationDirPath() + "/../data/levels";
}

EditorMainWindow::EditorMainWindow(): grid(*this), blockTool(*this), blockSelectorWidget(new BlockSelectorWidget(this)) {
    // create UI elements and autoconnect signals
    blockSelectorWidget->setObjectName("blockSelectorWidget");
    setupUi(this);

    // dock widgets
    addDockWidget(Qt::LeftDockWidgetArea, blockSelectorWidget);
    menuView->addAction(blockSelectorWidget->toggleViewAction());

    // all renderables
    canvas->addRenderable(level);
    canvas->addRenderable(grid);

    // mouse move for grid
    connect(canvas, SIGNAL(mouseMove(const QPointF&)), &grid, SLOT(mouseMoved(const QPointF&)));

    // undo/redo menu items
    QAction* undoAction = undoStack.createUndoAction(this);
    undoAction->setShortcut(QKeySequence("Ctrl+Z"));
    menuEdit->addAction(undoAction);
    QAction* redoAction = undoStack.createRedoAction(this);
    redoAction->setShortcut(QKeySequence("Ctrl+Shift+Z"));
    menuEdit->addAction(redoAction);
    // undo stack connections
    connect(&undoStack, SIGNAL(indexChanged(int)), canvas, SLOT(update()));
    connect(&undoStack, SIGNAL(cleanChanged(bool)), this, SLOT(updateTitle()));

    // selecting random block
    blockSelectorWidget->getLevelBlocks().values()[0]->clicked();
    // initialize editor with new level
    on_actionNew_triggered();

    // finally, show the window
    show();
}

void EditorMainWindow::on_actionNew_triggered() {
    path.clear();
    undoStack.clear();
    level.createNew();
    updateLevelBlocks();
    canvas->update();
    updateTitle();
}

void EditorMainWindow::updateLevelBlocks() {
    QHash<QChar, QString> textures;
    for (BlockWidget* blockWidget : blockSelectorWidget->getLevelBlocks().values()) {
        textures[blockWidget->getSymbol()] = blockWidget->getTextureName();
    }
    level.updateBlocks(textures);
}

void EditorMainWindow::on_actionOpen_triggered() {
    QString openPath = QFileDialog::getOpenFileName(this, "Open level", getLevelsDir(), "JSON files (*.json)");
    if (openPath.isNull()){
        return;
    }

    QString errorMsg;
    if (!loadLevel(level, openPath, &errorMsg)) {
        QMessageBox::critical(this, "Error opening level", errorMsg);
        return;
    }
    updateLevelBlocks();
    path = openPath;
    undoStack.clear();
    updateTitle();
}

void EditorMainWindow::on_actionSave_triggered() {
    if (path.isNull()) {
        on_actionSaveAs_triggered();
    } else {
        doSaveLevel(path);
    }
}

void EditorMainWindow::on_actionSaveAs_triggered() {
    QString savePath = QFileDialog::getSaveFileName(this, "Save level as", getLevelsDir(), "JSON files (*.json)");
    doSaveLevel(savePath);
}

void EditorMainWindow::doSaveLevel(const QString& savePath) {
    if (savePath.isNull()){
        return;
    }

    QString errorMsg;
    if (!saveLevel(level, savePath, &errorMsg)) {
        QMessageBox::critical(this, "Error saving level", errorMsg);
        return;
    }
    path = savePath;
    undoStack.setClean();
    updateTitle();
}

void EditorMainWindow::on_canvas_mouseDrag(const QPointF& delta) {
    canvas->moveCamera(delta);
    canvas->update();
}

void EditorMainWindow::on_canvas_mouseWheel(float delta) {
    canvas->zoomCamera(1 + delta/10.f, canvas->getCurMousePos());
    canvas->update();
}

void EditorMainWindow::on_canvas_mouseClick(const QPointF& pos) {
    blockTool.mouseClick(pos);
}

Level& EditorMainWindow::getLevel() {
    return level;
}

const Level& EditorMainWindow::getLevel() const {
    return level;
}

const Camera& EditorMainWindow::getCamera() const {
    return canvas->getCamera();
}

void EditorMainWindow::pushCommand(EditorCommand& command) {
    undoStack.push(&command);
}

void EditorMainWindow::updateTitle() {
    if (path.isNull()) {
        setWindowTitle("* New");
        return;
    }
    QString title = QDir(getLevelsDir()).relativeFilePath(path);
    if (!undoStack.isClean()) {
        title = "* " + title;
    }
    setWindowTitle(title);
}

void EditorMainWindow::on_blockSelectorWidget_blockSelected(QChar chr) {
    currentBlock = chr;
    blockSelectorWidget->selectBlock(chr);
}

QChar EditorMainWindow::getCurrentBlock() const {
    return currentBlock;
}
