#include "editor/EditorMainWindow.h"

#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

EditorMainWindow::EditorMainWindow(){
    setupUi(this);

    canvas->setLevel(level);

    show();
}

void EditorMainWindow::on_actionOpen_triggered() {
    QString path = QFileDialog::getOpenFileName(this, "Open level", QString(), "JSON files (*.json)");
    if (path.isNull()){
        return;
    }

    QFile loadLevel(path);
    if (!loadLevel.open(QIODevice::ReadOnly)){
        QString message = QString("Couldn't open file \"%1\" for reading.").arg(path);
        QMessageBox::critical(this, "Error opening level", message);
        return;
    }

    level.read(QJsonDocument::fromJson(loadLevel.readAll()).object());
}

void EditorMainWindow::on_actionSaveAs_triggered() {
    QString path = QFileDialog::getSaveFileName(this, "Save level as", QString(), "JSON files (*.json)");
    if (path.isNull()){
        return;
    }

    QFile saveLevel(path);
    if (!saveLevel.open(QIODevice::WriteOnly)){
        QString message = QString("Couldn't open file \"%1\" for writing.").arg(path);
        QMessageBox::critical(this, "Error saving level", message);
        return;
    }

    // root object to be filled.
    QJsonObject root;

    level.write(root);
    saveLevel.write(QJsonDocument(root).toJson());
}
