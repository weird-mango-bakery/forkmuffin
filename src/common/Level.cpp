#include "Level.h"

#include <QPainter>
#include <QJsonObject>
#include <QJsonArray>

const QSize Level::BLOCK_SIZE = QSize(50, 50);

void Level::paint(QPainter& painter) const {
    painter.setBrush(Qt::white);
    painter.drawEllipse(0, 0, 100, 80);

    int y = 0;
    for (QString row : map) {
        int x = 0;
        for (QChar chr : row) {
            if (blocks.contains(chr)) {
                painter.fillRect(QRect(QPoint(x, y) * BLOCK_SIZE.width(), BLOCK_SIZE), blocks[chr].getColor());
            }
            x++;
        }
        y++;
    }
}

void Level::read(const QJsonObject& json) {
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
