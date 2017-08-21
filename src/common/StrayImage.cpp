#include "StrayImage.h"

#include "common/TextureManager.h"
#include <QPainter>
#include <QJsonObject>

StrayImage::StrayImage() : Renderable(Z_BACKGROUND) {}

void StrayImage::paint(QPainter& p) const {
    TextureManager& manager = TextureManager::get();
    p.drawImage(QRect(pos, size), manager.getImage(texture));
}

void StrayImage::read(const QJsonObject& json) {
    name = json["name"].toString();
    pos = QPoint(json["pos_x"].toInt(), json["pos_y"].toInt());
    size = QSize(json["width"].toInt(), json["height"].toInt());
    texture = json["texture"].toString();
    setZOrder(static_cast<float>(json["z_level"].toDouble()));
}

void StrayImage::write(QJsonObject& json) const {
    json["name"] = name;
    json["pos_x"] = pos.x();
    json["pos_y"] = pos.y();
    json["width"] = size.width();
    json["height"] = size.height();
    json["texture"] = texture;
    json["z_level"] = getZOrder();
}

const QString& StrayImage::getName() const {
    return name;
}

const QPoint& StrayImage::getPos() const {
    return pos;
}

const QSize& StrayImage::getSize() const {
    return size;
}

const QString& StrayImage::getTexture() const {
    return texture;
}

void StrayImage::setPos(const QPoint& p) {
    pos = p;
}

void StrayImage::setSize(const QSize& s) {
    size = s;
}
