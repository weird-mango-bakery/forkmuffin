#include "StraySelectorWidget.h"

#include "editor/EditorMainWindow.h"
#include "editor/commands/ChangeStrayImageParamsCommand.h"
#include "editor/commands/AddImageCommand.h"
#include "editor/commands/DeleteImageCommand.h"
#include "editor/commands/ChangeStrayImageNameCommand.h"
#include "common/StrayImage.h"
#include "common/TextureManager.h"

#include <QInputDialog>
#include <QFileInfo>

StraySelectorWidget::StraySelectorWidget(EditorMainWindow& editor): QDockWidget(&editor), editor(editor) {
    setupUi(this);
}

void StraySelectorWidget::updateStrays() {
    bool currentDeleted = true;
    bool currentRenamed = true;
    for (StrayImage* stray : editor.getLevel().getStrays()) {
        if (currentImage == stray) {
            currentDeleted = false;
            if (stray->getName() == currentName) {
                currentRenamed = false;
            }
            break;
        }
    }
    if (currentDeleted) {
        clearData();
    }

    // Remove stray images.
    for (int i = 0; i < strayList->count(); ++i) {
        QListWidgetItem* item = strayList->item(i);
        if (currentRenamed && item->text() == currentName) {
            currentName = currentImage->getName();
            item->setText(currentName);
            continue;
        }
        bool needDel = true;
        for (StrayImage* stray : editor.getLevel().getStrays()) {
            if (stray->getName() == item->text()) {
                needDel = false;
                break;
            }
        }
        if (needDel) {
            strayList->removeItemWidget(item);
            delete item;
            break; //TODO multiple deletions at once are not supported yet.
        }
    }
    // Add stray images.
    for (StrayImage* stray : editor.getLevel().getStrays()) {
        const QString& name = stray->getName();
        bool needAdd = true;
        for (int i = 0; i < strayList->count(); ++i) {
            QListWidgetItem* item = strayList->item(i);
            if (item->text() == name) {
                needAdd = false;
                break;
            }
        }
        if (needAdd) {
            strayList->addItem(name);
        }
    }
    frame->setEnabled(currentImage);
}

void StraySelectorWidget::on_strayList_currentTextChanged(const QString& strayName) {
    updateInfo(strayName);
}

void StraySelectorWidget::updateInfo(const QString& strayName) {
    isInsideUpdate = true;
    updateTextureNames();
    // cleaning text so textChanged will be called.
    imageName->setText("");
    StrayImage* stray = editor.getLevel().getStrayFromName(strayName);
    clearData();
    currentImage = stray;
    if (stray) {
        QPoint pos = stray->getPos();
        QSize size = stray->getSize();

        posX->setValue(pos.x());
        posY->setValue(pos.y());

        sizeWidth->setValue(size.width());
        sizeHeight->setValue(size.height());

        currentName = strayName;
        zOrder->setValue(stray->getZOrder());
        imageName->setText(strayName);
        textureName->setCurrentText(stray->getTexture());
        frame->setEnabled(true);
    } else {
        currentName.clear();
    }
    isInsideUpdate = false;
}

void StraySelectorWidget::updateTextureNames() {
    textureName->clear();
    textureName->addItems(TextureManager::getTextureNames());
}

void StraySelectorWidget::on_sizeWidth_valueChanged(int width) {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    editor.pushCommand(*ChangeStrayImageParamsCommand::setWidth(editor, *currentImage, width));
}

void StraySelectorWidget::on_sizeHeight_valueChanged(int height) {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    editor.pushCommand(*ChangeStrayImageParamsCommand::setHeight(editor, *currentImage, height));
}

void StraySelectorWidget::on_posX_valueChanged(int x) {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    editor.pushCommand(*ChangeStrayImageParamsCommand::setX(editor, *currentImage, x));
}

void StraySelectorWidget::on_posY_valueChanged(int y) {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    editor.pushCommand(*ChangeStrayImageParamsCommand::setY(editor, *currentImage, y));
}

void StraySelectorWidget::on_zOrder_valueChanged(double z) {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    zToHud->setDisabled(z == Renderable::Z_HUD);
    zToFront->setDisabled(z == Renderable::Z_FOREGROUND);
    zToBack->setDisabled(z == Renderable::Z_BACKGROUND);
    editor.pushCommand(*ChangeStrayImageParamsCommand::setZOrder(editor, *currentImage, z));
}

void StraySelectorWidget::on_zToHud_clicked() {
    zOrder->setValue(Renderable::Z_HUD);
}

void StraySelectorWidget::on_zToFront_clicked() {
    zOrder->setValue(Renderable::Z_FOREGROUND);
}

void StraySelectorWidget::on_zToBack_clicked() {
    zOrder->setValue(Renderable::Z_BACKGROUND);
}

void StraySelectorWidget::clearData() {
    currentName.clear();
    currentImage = nullptr;
    posX->setValue(0);
    posY->setValue(0);
    sizeWidth->setValue(0);
    sizeHeight->setValue(0);
    zOrder->setValue(0);
}

void StraySelectorWidget::on_imageName_textChanged(const QString& strayName) {
    if (!strayList->currentItem()) {
        return;
    }
    QPalette p;
    if (strayList->currentItem()->text() == strayName || isUniqueName(strayName)) {
        p.setColor(imageName->backgroundRole(), Qt::white);
    } else {
        p.setColor(imageName->backgroundRole(), Qt::red);
    }
    imageName->setPalette(p);
}

void StraySelectorWidget::on_imageName_editingFinished() {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    QString strayName = imageName->text();
    if (isUniqueName(strayName)) {
        ChangeStrayImageNameCommand* cmd = new ChangeStrayImageNameCommand(editor, strayName, currentName);
        editor.pushCommand(*cmd);
    }
}

bool StraySelectorWidget::isUniqueName(const QString& strayName) const {
    for (int i = 0; i < strayList->count(); ++i) {
        QListWidgetItem* pItem = strayList->item(i);
        if (pItem->text() == strayName.trimmed()) {
            return false;
        }
    }
    return true;
}

void StraySelectorWidget::updateCurrentInfo() {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    updateInfo(currentImage->getName());
}

void StraySelectorWidget::on_textureName_activated(const QString& textureName) {
    if (!currentImage || isInsideUpdate) {
        return;
    }
    editor.pushCommand(*ChangeStrayImageParamsCommand::setTexture(editor, *currentImage, textureName));
}

QString StraySelectorWidget::getUniqueNameFromTexture(const QString& textureName) const {
    QString namePart =  QFileInfo(textureName).baseName();
    QString prefix = QString("%1_%2").arg(namePart);
    for (int i = 0; i < 100000; ++i) {
        QString name = prefix.arg(i);
        if (isUniqueName(name)) {
            return name;
        }
    }
    return "exhausted 100K names? seriously???";
}

void StraySelectorWidget::on_addButton_clicked() {
    QString textureName = QInputDialog::getItem(this, "Add", "Choose the texture", TextureManager::getTextureNames(), 0, false);
    QString name = getUniqueNameFromTexture(textureName);
    QSize imageSize = TextureManager::get().getImage(textureName).size();
    QPoint pos = editor.getCamera().screenToWorld(editor.getScreenCenter()).toPoint() - QPoint(imageSize.width() / 2, imageSize.height() / 2);
    AddImageCommand* cmd = new AddImageCommand(editor, name, pos, imageSize, textureName);
    editor.pushCommand(*cmd);
}

void StraySelectorWidget::on_cloneButton_clicked() {
    if (!strayList->currentItem()) {
        return;
    }
    StrayImage* stray = editor.getLevel().getStrayFromName(strayList->currentItem()->text());
    if (stray) {
        QPoint pos = editor.getCamera().screenToWorld(editor.getScreenCenter()).toPoint() - QPoint(stray->getSize().width() / 2, stray->getSize().height() / 2);
        AddImageCommand* cmd = new AddImageCommand(editor, getUniqueNameFromTexture(stray->getTexture()), pos, stray->getSize(), stray->getTexture());
        editor.pushCommand(*cmd);
    }
}

void StraySelectorWidget::on_deleteButton_clicked() {
    if (!strayList->currentItem()) {
        return;
    }
    StrayImage* stray = editor.getLevel().getStrayFromName(strayList->currentItem()->text());
    if (stray) {
        editor.pushCommand(DeleteImageCommand::create(editor, *stray));
    }
}
