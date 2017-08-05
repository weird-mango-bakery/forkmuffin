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

//! Level of the game.
class Level : public Serializable, public Renderable {
private:
    //! Map that contains level blocks. Each line consists of chars, each char represents a block.
    QList<QString> map;
    //! Map from char to level block.
    QHash<QChar, Block> blocks;

public:
    //! Block side size in pixels, in world coordinates.
    static const int BLOCK_SIZE;
    //! Simply QSize(BLOCK_SIZE, BLOCK_SIZE) for convenience.
    static const QSize BLOCK_BOX;

    //! Creates empty level by calling createNew().
    Level();

    //! Returns level width in blocks.
    int getWidth() const;
    //! Returns level height in blocks.
    int getHeight() const;
    //! Checks if pos is inside level.
    //! \param pos position in level coordinates.
    bool isInside(const QPoint& pos) const;

    void paint(QPainter& painter) const override;
    float getZOrder() const override;

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;

    //! Returns level block char at (x, y) in level coordinates.
    QChar getBlock(int x, int y) const;
    //! Sets level block char at (x, y) in level coordinates.
    void setBlock(int x, int y, QChar block);

    //! Removes all lines on map and all block type on block.
    void clear();
    //! Makes empty level 16 blocks wide and 10 blocks tall.
    void createNew();
};
