#include "Level.h"

#include <QPainter>
#include <QJsonObject>

void Level::paint(QPainter& painter) const {
    painter.setBrush(Qt::white);
    painter.drawEllipse(0, 0, 100, 80);
}

void Level::read(const QJsonObject& json) {
    int version = json["version"].toInt(-1);
    if (version == -1) {
        printf("File with invalid version!");
    } else {
        printf("Reading from version %d\n", version);
    }
}

void Level::write(QJsonObject& json) const {
    json["version"] = 1;
}
