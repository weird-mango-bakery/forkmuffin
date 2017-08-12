#include "TextureManager.h"

#include <QCoreApplication>

const QImage& TextureManager::getImage(const QString& name) {
    QString path = QString("%1/%2").arg(getTextureDir()).arg(name);
    if (imgs.contains(path)) {
        return imgs[path];
    }
    QImage img(path);
    if (img.isNull()) {
        return getInvalid();
    }
    imgs[path] = img;
    return imgs[path];
}

TextureManager::TextureManager() {
    invalidImage = QImage(2, 2, QImage::Format_RGB32);
    invalidImage.setPixel(0, 0, 0xff00ff);
    invalidImage.setPixel(1, 0, 0xffff00);
    invalidImage.setPixel(0, 1, 0x00ff00);
    invalidImage.setPixel(1, 1, 0x0080ff);
}

TextureManager& TextureManager::get() {
    static TextureManager manager;
    return manager;
}

const QImage& TextureManager::getInvalid() const {
    return invalidImage;
}

QString TextureManager::getTextureDir() {
    return QString("%1/../data/textures").arg(QCoreApplication::applicationDirPath());
}
