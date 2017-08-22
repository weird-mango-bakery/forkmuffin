#include "StraySelectorWidget.h"

#include "editor/EditorMainWindow.h"
#include "editor/commands/ChangeStrayImageParamsCommand.h"
#include "common/StrayImage.h"
#include "common/TextureManager.h"
#include <QDir>

StraySelectorWidget::StraySelectorWidget(EditorMainWindow& editor): QDockWidget(&editor), editor(editor) {
    setupUi(this);
}

void StraySelectorWidget::updateStrays() {
    clear();
    for (StrayImage* stray : editor.getLevel().getStrays()) {
        QString name = stray->getName();
        strayList->addItem(name);
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
    for (StrayImage* stray : editor.getLevel().getStrays()) {
        if (stray->getName() == strayName) {
            currentImage = stray;
            
            QPoint pos = stray->getPos();
            QSize size = stray->getSize();

            posX->setValue(pos.x());
            posY->setValue(pos.y());

            sizeWidth->setValue(size.width());
            sizeHeight->setValue(size.height());

            imageName->setText(strayName);
            textureName->setCurrentText(stray->getTexture());
            frame->setEnabled(true);
            break;
        }
    }
    isInsideUpdate = false;
}

void StraySelectorWidget::updateTextureNames() {
    textureName->clear();
    QStringList textureNameList = QDir(TextureManager::getTextureDir()).entryList();
    for (const QString& texture : textureNameList) {
        if (texture.endsWith(".png")) {
            textureName->addItem(texture);
        }
    }
}

void StraySelectorWidget::on_sizeWidth_valueChanged(int width) {
    updateSize(width, sizeHeight->value());
}

void StraySelectorWidget::on_sizeHeight_valueChanged(int height) {
    updateSize(sizeWidth->value(), height);
}

void StraySelectorWidget::on_posX_valueChanged(int x) {
    updatePosition(x, posY->value());
}

void StraySelectorWidget::on_posY_valueChanged(int y) {
    updatePosition(posX->value(), y);
}

void StraySelectorWidget::updateSize(int width, int height) {
    if (currentImage && !isInsideUpdate) {
        EditorCommand* command = new ChangeStrayImageParamsCommand(
            editor, *currentImage, QPoint(posX->value(), posY->value()), QSize(width, height), currentImage->getTexture());
        editor.pushCommand(*command);
    }
}

void StraySelectorWidget::updatePosition(int x, int y) {
    if (currentImage&& !isInsideUpdate) {
        EditorCommand* command = new ChangeStrayImageParamsCommand(
            editor, *currentImage, QPoint(x, y), QSize(sizeWidth->value(), sizeHeight->value()), currentImage->getTexture());
        editor.pushCommand(*command);
    }
}

void StraySelectorWidget::clear() {
    strayList->clear();
    currentImage = nullptr;
    posX->setValue(0);
    posY->setValue(0);
    sizeWidth->setValue(0);
    sizeHeight->setValue(0);
    textureName->clear();
}

void StraySelectorWidget::on_imageName_textChanged(const QString& strayName) {
    QPalette p;
    if (isUniqueName(strayName)) {
        p.setColor(imageName->backgroundRole(), Qt::white);
    } else {
        p.setColor(imageName->backgroundRole(), Qt::red);
    }
    imageName->setPalette(p);
}

bool StraySelectorWidget::isUniqueName(const QString& strayName) const {
    for (int i = 0; i < strayList->count(); ++i) {
        QListWidgetItem* pItem = strayList->item(i);
        if (pItem->text() == strayName.trimmed() && pItem != strayList->currentItem()) {
            return false;
        }
    }
    return true;
}

void StraySelectorWidget::updateCurrentInfo() {
    if (currentImage) {
        updateInfo(currentImage->getName());
    }
}

void StraySelectorWidget::on_textureName_activated(const QString& textureName) {
    if (currentImage) {
        EditorCommand* command = new ChangeStrayImageParamsCommand(
            editor, *currentImage, QPoint(posX->value(), posY->value()), QSize(sizeWidth->value(), sizeHeight->value()), textureName);
        editor.pushCommand(*command);
    }
}
