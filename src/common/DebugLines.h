#pragma once

#include <QString>
#include "common/Renderable.h"

//! Displays lines of text at the top-left corner of the screen, above everything else.
class DebugLines: public Renderable{
private:
    //! Concatenated lines of text to display.
    QString lines;

public:
    void paint(QPainter& p) const override;
    DebugLines();

    //! Remove all lines.
    void reset();
    //! Add a line to display.
    //! \param s line of text.
    void addLine(const QString& s);
};
