#pragma once

#include <QString>
#include <QColor>

//! Convert hexadecimal string to QColor: "ff7f00" becomes QColor(255, 127, 0).
QColor stringToColor(const QString& s);

//! Convert QColor to hexadecimal string: QColor(255, 127, 0) becomes "ff7f00".
QString colorToString(const QColor& c);
