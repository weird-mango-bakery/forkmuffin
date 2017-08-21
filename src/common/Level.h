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
class StrayImage;

//! Level of the game.
class Level : public Serializable, public Renderable {
private:
    //! Map that contains level blocks. Each line consists of chars, each char represents a block.
    QList<QString> map;
    //! Map from char to level block.
    QHash<QChar, Block> blocks;
    //! List of static images.
    QList<StrayImage*> strays;

public:
    //! Block side size in pixels, in world coordinates.
    static const int BLOCK_SIZE;
    //! Simply QSize(BLOCK_SIZE, BLOCK_SIZE) for convenience.
    static const QSize BLOCK_BOX;

    //! Creates empty level with no blocks.
    Level();
    //! Destroys level and all its objects.
    ~Level() override;
    //! Levels cannot be assigned.
    Level& operator=(const Level& other) = delete;
    //! Levels cannot be copy-constructed.
    Level(const Level& other) = delete;

    //! Returns list of stray images on the level.
    const QList<StrayImage*>& getStrays() const;
    //! Returns level width in blocks.
    int getWidth() const;
    //! Returns level height in blocks.
    int getHeight() const;
    //! Checks if pos is inside level.
    //! \param pos position in level coordinates.
    bool isInside(const QPoint& pos) const;

    //! Checks if there are no blocks at the specified coordinates.
    //! \param pos position in level coordinates.
    bool isEmpty(const QPoint& pos) const;

    void paint(QPainter& painter) const override;

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;

    //!  Returns level block char at the specified coordinates.
    //! \param pos position in level coordinates.
    QChar getBlock(const QPoint& pos) const;
    //! Sets level block char at the specified coordinates.
    //! \param pos position in level coordinates.
    void setBlock(const QPoint& pos, QChar block);
    //! Fills level blocks information from the specified map.
    //! \param texturesForBlocks map with char-to-texture binding.
    void updateBlocks(const QHash<QChar, QString>& texturesForBlocks);

    //! Removes all lines on map and all block type on block.
    void clear();
    //! Makes empty level 16 blocks wide and 10 blocks tall.
    void createNew();
};
