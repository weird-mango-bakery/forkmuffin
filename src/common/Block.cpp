#include "Block.h"

#include "common/utils.h"

#include <QJsonObject>

void Block::read(const QJsonObject& json) {
    color = stringToColor(json["color"].toString());
}

void Block::write(QJsonObject& json) const {
    json["color"] = colorToString(color);
}

const QColor& Block::getColor() const {
    return color;
}

Block::Block(const QColor& color): color(color) {}
