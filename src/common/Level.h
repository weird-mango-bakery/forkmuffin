#pragma once

#include "common/Serializable.h"
#include "common/Block.h"
#include "common/Renderable.h"

#include <QList>
#include <QString>
#include <QHash>
#include <QSize>

class QPainter;

class Level : public Serializable, public Renderable {
private:
    QList<QString> map;
    QHash<QChar, Block> blocks;

public:
    static const QSize BLOCK_SIZE;

    void paint(QPainter& painter) const override;
    float getZOrder() const override;

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
};
