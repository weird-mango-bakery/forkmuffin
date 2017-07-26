#pragma once

#include "common/Serializable.h"
#include "common/Block.h"

#include <QList>
#include <QString>
#include <QHash>

class QPainter;

class Level : public Serializable {
private:
    QList<QString> map;
    QHash<QChar, Block> blocks;

public:
    void paint(QPainter& painter) const;

    void read(const QJsonObject& json) override;

    void write(QJsonObject& json) const override;
};
