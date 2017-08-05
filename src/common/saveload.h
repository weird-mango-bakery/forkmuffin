#pragma once

class Level;
class QString;

//! Load level from json file.
//! \param level level to load to.
//! \param path path to json file.
//! \param errorMsg if is not nullptr, when an error happens, error message will be written to it.
//! \return true if loaded successfully, false otherwise.
bool loadLevel(Level& level, const QString& path, QString* errorMsg = nullptr);

//! Save level to json file.
//! \param level to save.
//! \param path path to json file.
//! \param errorMsg if is not nullptr, when an error happens, error message will be written to it.
//! \return true if saved successfully, false otherwise.
bool saveLevel(const Level& level, const QString& path, QString* errorMsg = nullptr);
