#pragma once

#include "Serializable.h"
#include <QColor>

//! Colored block of the level.
class Block : public Serializable {
private:
    //! Color of the block.
    QColor color;

public:
    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
    //! Returns color of the block.
    const QColor& getColor() const;

    //! Creates block with specified color.
    //! \param color color of the created block.
    explicit Block(const QColor& color);

    Block() = default;
};
