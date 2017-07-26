#pragma once

class Level;
class QString;

bool loadLevel(Level& level, const QString& path, QString* errorMsg = nullptr);
bool saveLevel(const Level& level, const QString& path, QString* errorMsg = nullptr);
