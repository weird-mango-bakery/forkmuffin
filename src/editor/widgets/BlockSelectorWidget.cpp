#include "BlockSelectorWidget.h"
#include "editor/widgets/BlockWidget.h"
#include "common/TextureManager.h"

#include <QDir>

void BlockSelectorWidget::selectBlock(QChar selectedChar) {
    for (QChar chr : levelBlocks.keys()) {
        levelBlocks[chr]->setSelected(chr == selectedChar);
    }
}

QVBoxLayout* BlockSelectorWidget::getButtonsLayout() {
    return reinterpret_cast<QVBoxLayout*>(blocks->layout());
}

void BlockSelectorWidget::appendBlock(const QString& textureName, QChar symbol) {
    BlockWidget* block = new BlockWidget(this, textureName, symbol);
    levelBlocks[symbol] = block;

    QVBoxLayout* boxLayout = getButtonsLayout();
    boxLayout->insertWidget(boxLayout->count() - 1, block);

    connect(block, &BlockWidget::clicked, [this, symbol]() {
        emit blockSelected(symbol);
    });
}

BlockSelectorWidget::BlockSelectorWidget(QWidget* parent): QDockWidget(parent) {
    setupUi(this);

    QStringList textureNameList = QDir(TextureManager::getTextureDir()).entryList();
    for (const QString& textureName : textureNameList) {
        if (textureName.startsWith("block_") && textureName[7] == '_') {
            QChar symbol = textureName[6];
            appendBlock(textureName, symbol);
        }
    }
}

const QHash<QChar, BlockWidget*>& BlockSelectorWidget::getLevelBlocks() const {
    return levelBlocks;
}
