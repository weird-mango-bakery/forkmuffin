#pragma once

#include "Serializable.h"
#include <QColor>

class Block : public Serializable{
private:
    QColor color;

public:
    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
    const QColor& getColor() const;

    explicit Block(const QColor& color);

    Block() = default;
};
