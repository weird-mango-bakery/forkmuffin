#pragma once

#include "common/Serializable.h"

class QPainter;

class Level : public Serializable {
public:
    void paint(QPainter& painter) const;

    void read(const QJsonObject& json) override;

    void write(QJsonObject& json) const override;
};
