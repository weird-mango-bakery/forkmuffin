#include "StraySelectorWidget.h"

#include "editor/EditorMainWindow.h"
#include "common/StrayImage.h"

StraySelectorWidget::StraySelectorWidget(EditorMainWindow& editor): QDockWidget(&editor), editor(editor) {
    setupUi(this);
}

void StraySelectorWidget::updateStrays() {
    clear();
    for (StrayImage* stray : editor.getLevel().getStrays()) {
        QString name = stray->getName();
        strayList->addItem(name);
    }
    setEnabled(strayList->count() > 0);
}

void StraySelectorWidget::on_strayList_currentTextChanged(const QString& strayName) {
    updateInfo(strayName);
}

void StraySelectorWidget::updateInfo(const QString& strayName) {
    for (StrayImage* stray : editor.getLevel().getStrays()) {
        if (stray->getName() == strayName) {
            currentImage = stray;
            
            QPoint pos = stray->getPos();
            QSize size = stray->getSize();

            posX->setValue(pos.x());
            posY->setValue(pos.y());

            sizeWidth->setValue(size.width());
            sizeHeight->setValue(size.height());

            textureName->setText(stray->getTexture());
            return;
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
    if (currentImage) {
        currentImage->setSize(QSize(width, height));
        editor.update();
    }
}

void StraySelectorWidget::updatePosition(int x, int y) {
    if (currentImage) {
        currentImage->setPos(QPoint(x, y));
        editor.update();
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
