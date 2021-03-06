#include "Level.h"

#include "common/TextureManager.h"
#include "common/StrayImage.h"
#include <QPainter>
#include <QJsonObject>
#include <QJsonArray>

const int Level::BLOCK_SIZE = 50;
const QSize Level::BLOCK_BOX = QSize(Level::BLOCK_SIZE, Level::BLOCK_SIZE);

int Level::getWidth() const {
    if (map.isEmpty()) {
        return 0;
    }
    return map.first().size();
}

int Level::getHeight() const {
    return map.size();
}

bool Level::isInside(const QPoint& pos) const {
    QRect bounds = QRect(QPoint(), QSize(getWidth(), getHeight()));
    return bounds.contains(pos);
}

void Level::paint(QPainter& painter) const {
    TextureManager& manager = TextureManager::get();
    int y = 0;
    for (QString row : map) {
        int x = 0;
        for (QChar chr : row) {
            if (blocks.contains(chr)) {
                // Maybe problem with applicationDirPath(). If u can't see textures
                // when u r placing block - it is problem with dirPath
                painter.drawImage(QRect(QPoint(x, y) * BLOCK_SIZE, BLOCK_BOX), manager.getImage(blocks[chr].getTexture()));
            }
            x++;
        }
        y++;
    }
}

void Level::read(const QJsonObject& json) {
    clear();
    int version = json["version"].toInt(-1);
    if (version == -1) {
        printf("File with invalid version!\n");
    } else {
        printf("Reading from version %d\n", version);
    }

    QJsonObject jsonBlocks = json["blocks"].toObject();
    for (QString key : jsonBlocks.keys()) {
        blocks[key[0]].read(jsonBlocks[key].toObject());
    }

    for (QJsonValue row : json["map"].toArray()) {
        map << row.toString();
    }
    for (QJsonValue stray : json["stray_images"].toArray()) {
        addStrayImage(new StrayImage());
        strays.last()->read(stray.toObject());
    }
}

void Level::write(QJsonObject& json) const {
    json["version"] = 1;

    QJsonObject newBlocks;
    for (QChar chr : blocks.keys()) {
        QJsonObject blockObject;
        blocks[chr].write(blockObject);
        newBlocks[chr] = blockObject;
    }

    json["blocks"] = newBlocks;

    QJsonArray newMap;
    for (const QString& row : map){
        newMap << row;
    }
    json["map"] = newMap;

    QJsonArray newStrays;
    for (const StrayImage* stray : strays) {
        QJsonObject object;
        stray->write(object);
        newStrays << object;
    }
    json["stray_images"] = newStrays;
}

Level::Level(): Renderable(Z_BACKGROUND) {}

Level::~Level() {
    clear();
}

QChar Level::getBlock(const QPoint& pos) const {
    return map[pos.y()][pos.x()];
}

void Level::setBlock(const QPoint& pos, QChar block) {
    map[pos.y()][pos.x()] = block;
}

void Level::clear() {
    map.clear();
    blocks.clear();
    for (StrayImage* stray : strays) {
        delete stray;
    }
    strays.clear();
}

void Level::createNew() {
    // TODO make resizable level instead of hardcoding
    clear();
    for (int i = 0; i < 10; ++i) {
        map << "                ";
    }
}

bool Level::isEmpty(const QPoint& pos) const {
    return getBlock(pos) == ' ';
}

void Level::updateBlocks(const QHash<QChar, QString>& texturesForBlocks) {
    blocks.clear();
    for (QChar blockSymbol : texturesForBlocks.keys()) {
        blocks[blockSymbol] = Block(texturesForBlocks[blockSymbol]);
    }
}

const QList<StrayImage*>& Level::getStrays() const {
    return strays;
}

void Level::addStrayImage(StrayImage* img) {
    strays << img;
}

void Level::deleteStrayImage(const QString& name) {
    StrayImage* stray = getStrayFromName(name);
    if (stray) {
        strays.removeOne(stray);
        delete stray;
    }
}

StrayImage* Level::getStrayFromName(const QString& name) const {
    for (StrayImage* stray : strays) {
        if (stray->getName() == name) {
            return stray;
        }
    }
    return nullptr;
}
