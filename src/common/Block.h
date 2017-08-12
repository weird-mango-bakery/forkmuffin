#pragma once

#include "Serializable.h"
#include <QString>

//! Textured block of the level.
class Block : public Serializable {
private:
    //! Texture name of the block.
    QString textureName;

public:
    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
    //! Returns texture name of the block.
    const QString& getTexture() const;

    //! Creates block with specified texture name.
    //! \param texture texture name of the created block.
    explicit Block(const QString& texture);

    Block() = default;
};
