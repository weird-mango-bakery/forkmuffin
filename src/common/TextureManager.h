#pragma once

#include <QImage>
#include <QString>
#include <QHash>

class TextureManager {
private:
    QHash<QString, QImage> imgs;
    QImage emptyImage;
    TextureManager();

public:
    const QImage& getImage(const QString& s);
    static TextureManager& get();
};
