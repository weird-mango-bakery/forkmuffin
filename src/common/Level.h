#pragma once

#include "common/Serializable.h"
#include "common/Block.h"
#include "common/Renderable.h"

#include <QList>
#include <QString>
#include <QHash>

class QPainter;

class Level : public Serializable, public Renderable {
private:
    QList<QString> map;
    QHash<QChar, Block> blocks;

public:
    void paint(QPainter& painter) const override;
    float getZOrder() const override;

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
};
