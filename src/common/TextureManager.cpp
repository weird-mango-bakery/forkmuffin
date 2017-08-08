#include "TextureManager.h"

#include <QCoreApplication>

const QImage& TextureManager::getImage(const QString& name) {
    QString path = QString("%1/../data/textures/%2").arg(QCoreApplication::applicationDirPath()).arg(name);
    if (imgs.contains(path)) {
        return imgs[path];
    }
    QImage img(path);
    if (img.isNull()) {
        return emptyImage;
    }
    imgs[path] = img;
    return imgs[path];
}

TextureManager::TextureManager() {
    emptyImage = QImage(2, 2, QImage::Format_RGB32);
    emptyImage.setPixel(0, 0, 0xff00ff);
    emptyImage.setPixel(1, 0, 0xffff00);
    emptyImage.setPixel(0, 1, 0x00ff00);
    emptyImage.setPixel(1, 1, 0x0080ff);
}

TextureManager& TextureManager::get() {
    static TextureManager manager;
    return manager;
}
