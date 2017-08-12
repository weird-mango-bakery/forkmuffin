#include "Block.h"

#include "common/utils.h"

#include <QJsonObject>

void Block::read(const QJsonObject& json) {
    textureName = json["texture"].toString();
}

void Block::write(QJsonObject& json) const {
    json["texture"] = textureName;
}

const QString& Block::getTexture() const {
    return textureName;
}

Block::Block(const QString& texture): textureName(texture) {}
