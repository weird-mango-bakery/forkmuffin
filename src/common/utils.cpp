#include "utils.h"

QColor stringToColor(const QString& s) {
    return QColor(QRgb(s.toUInt(nullptr, 16)));
}

QString colorToString(const QColor& c) {
    return QString("%1").arg(c.rgb() & 0xffffff, 6, 16, QLatin1Char('0'));
}
