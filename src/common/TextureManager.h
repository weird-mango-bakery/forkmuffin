#pragma once

#include <QImage>
#include <QString>
#include <QHash>

//! Class that contains and caches textures.
class TextureManager {
private:
    //! Map of texture name to texture image.
    QHash<QString, QImage> imgs;
    //! Invalid image to return if the texture was not loaded.
    QImage invalidImage;
    //! Private constructor so the texture manager can be created inside get() only.
    TextureManager();

public:
    //! Returns the invalid image.
    const QImage& getInvalid() const;
    //! Returns texture from cache or load it from texture name.
    //! \param s texture name.
    const QImage& getImage(const QString& s);
    //! The static function to get or create the texture manager.
    static TextureManager& get();
    //! Returns path to directory with textures.
    static QString getTextureDir();
};
