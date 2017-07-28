#include "Level.h"

#include <QPainter>
#include <QJsonObject>
#include <QJsonArray>

const int Level::BLOCK_SIZE = 50;
const QSize Level::BLOCK_BOX = QSize(Level::BLOCK_SIZE, Level::BLOCK_SIZE);

Level::Level() {
    createNew();
}

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
    painter.setBrush(Qt::white);
    painter.drawEllipse(0, 0, 100, 80);

    int y = 0;
    for (QString row : map) {
        int x = 0;
        for (QChar chr : row) {
            if (blocks.contains(chr)) {
                painter.fillRect(QRect(QPoint(x, y) * BLOCK_SIZE, BLOCK_BOX), blocks[chr].getColor());
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
    for (QString row : map){
        newMap << row;
    }
    json["map"] = newMap;
}

float Level::getZOrder() const {
    return Z_BACKGROUND;
}

QChar Level::getBlock(int x, int y) const {
    return map[y][x];
}

void Level::setBlock(int x, int y, QChar block) {
    map[y][x] = block;
}

void Level::clear() {
    map.clear();
    blocks.clear();
}

void Level::createNew() {
    // TODO make resizable level instead of hardcoding
    clear();
    for (int i = 0; i < 10; ++i) {
        map << "                ";
    }
    blocks['#'] = Block(QColor(255, 255, 0));
}

