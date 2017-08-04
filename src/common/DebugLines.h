#pragma once

#include <QString>
#include "common/Renderable.h"

class DebugLines: public Renderable{
private:
    QString lines;

public:
    void paint(QPainter& p) const override;
    float getZOrder() const override;

    void reset();
    void addLine(const QString& s);
};
