#pragma once
#include <ostream>

class QString;
class QByteArray;
class QColor;
class QJsonObject;
class QPointF;
class QPoint;

void PrintTo(const QString& o, std::ostream* stream);
void PrintTo(const QByteArray& o, std::ostream* stream);
void PrintTo(const QColor& o, std::ostream* stream);
void PrintTo(const QJsonObject& o, std::ostream* stream);
void PrintTo(const QPointF& o, std::ostream* stream);
void PrintTo(const QPoint& o, std::ostream* stream);
