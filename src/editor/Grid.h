#pragma once

#include "common/Renderable.h"
#include <QObject>
#include <QPointF>

class EditorMainWindow;

//! A grid to display layer coordinates in editor.
class Grid: public QObject, public Renderable {
Q_OBJECT
private:
    //! The editor.
    const EditorMainWindow& editor;
    //! The current mouse position in screen coordinates.
    QPointF mousePos;

public:
    explicit Grid(const EditorMainWindow& editor);

    void paint(QPainter& p) const override;

    float getZOrder() const override;

public slots:
    //! Slot to update the current mouse position.
    //! \param pos mouse position in screen coordinates.
    void mouseMoved(const QPointF& pos);
};
