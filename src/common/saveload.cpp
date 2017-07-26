#include "saveload.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "common/Level.h"

bool loadLevel(Level& level, const QString& path, QString* errorMsg) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)){
        if (errorMsg) {
            *errorMsg = QString("Couldn't open file \"%1\" for reading.").arg(path);
        }
        return false;
    }

    level.read(QJsonDocument::fromJson(file.readAll()).object());
    return true;
}

bool saveLevel(const Level& level, const QString& path, QString* errorMsg) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)){
        if (errorMsg) {
            *errorMsg = QString("Couldn't open file \"%1\" for writing.").arg(path);
        }
        return false;
    }

    // root object to be filled.
    QJsonObject root;
    level.write(root);
    file.write(QJsonDocument(root).toJson());
    return true;
}
