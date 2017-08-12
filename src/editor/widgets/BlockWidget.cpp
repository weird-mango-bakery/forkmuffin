#include "BlockWidget.h"
#include "common/TextureManager.h"
#include <QMouseEvent>

void BlockWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton){
        emit clicked();
    }
}

BlockWidget::BlockWidget(QWidget* parent, const QString& textureName, QChar symbol): QFrame(parent), textureName(textureName), symbol(symbol) {
    setupUi(this);
    blockText->setText(QString("Block %1").arg(symbol));
    blockPreview->setPixmap(QPixmap::fromImage(TextureManager::get().getImage(textureName)));
}

void BlockWidget::setSelected(bool selected) {
    setFrameShape(selected ? Panel : NoFrame);
}

const QString& BlockWidget::getTextureName() const {
    return textureName;
}

QChar BlockWidget::getSymbol() const {
    return symbol;
}
