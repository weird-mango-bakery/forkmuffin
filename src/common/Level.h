#pragma once

#include "common/Serializable.h"
#include "common/Block.h"
#include "common/Renderable.h"

#include <QList>
#include <QString>
#include <QHash>
#include <QSize>

class QPainter;
class QPoint;

class Level : public Serializable, public Renderable {
private:
    QList<QString> map;
    QHash<QChar, Block> blocks;

public:
    static const int BLOCK_SIZE;
    static const QSize BLOCK_BOX;

    Level();

    int getWidth() const;
    int getHeight() const;
    bool isInside(const QPoint& pos) const;

    void paint(QPainter& painter) const override;
    float getZOrder() const override;

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;

    QChar getBlock(int x, int y) const;
    void setBlock(int x, int y, QChar block);

    void clear();
    void createNew();
};
