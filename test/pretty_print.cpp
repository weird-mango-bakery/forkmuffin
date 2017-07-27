#include "pretty_print.h"

#include <QString>
#include <QColor>
#include <QJsonDocument>
#include <QPointF>
#include <QPoint>

void PrintTo(const QString& o, std::ostream* stream) {
    if (o.isNull()) {
        *stream << "QString{null}";
    } else {
        *stream << "QString{\"" << o.toUtf8().data() << "\"}";
    }
}

void PrintTo(const QByteArray& o, std::ostream* stream) {
    if (o.isNull()) {
        *stream << "QByteArray{null}";
    } else {
        *stream << "QByteArray{\"" << o.data() << "\"}";
    }
}

void PrintTo(const QColor& o, std::ostream* stream) {
    switch (o.spec()) {
        case QColor::Invalid:
            *stream << "QColor(invalid){}";
            break;
        case QColor::Rgb:
            *stream << "QColor(RGB){" << o.red() << ", " << o.green() << ", " << o.blue() << ", a=" << o.alpha() << "}";
            break;
        case QColor::Hsv:
            *stream << "QColor(HSV){" << o.hue() << ", " << o.saturation() << ", " << o.value() << ", a=" << o.alpha() << "}";
            break;
        case QColor::Cmyk:
            *stream << "QColor(CMYK){" << o.cyan() << ", " << o.magenta() << ", " << o.yellow() << ", " << o.black() << ", a=" << o.alpha() << "}";
            break;
        case QColor::Hsl:
            *stream << "QColor(HSL){" << o.hslHue() << ", " << o.hslSaturation() << ", " << o.lightness() << ", a=" << o.alpha() << "}";
            break;
    }
}

void PrintTo(const QJsonObject& o, std::ostream* stream) {
    *stream << "QJsonObject" << QJsonDocument(o).toJson().data();
}

void PrintTo(const QPointF& o, std::ostream* stream) {
    *stream << "QPointF{" << o.x() << ", " << o.y() << "}";
}

void PrintTo(const QPoint& o, std::ostream* stream) {
    *stream << "QPoint{" << o.x() << ", " << o.y() << "}";
}
