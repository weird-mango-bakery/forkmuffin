#pragma once

#include "common/Renderable.h"
#include <QObject>
#include <QPointF>

class EditorMainWindow;

class Grid: public QObject, public Renderable {
Q_OBJECT
private:
    const EditorMainWindow& editor;
    QPointF mousePos;

public:
    explicit Grid(const EditorMainWindow& editor);

    void paint(QPainter& p) const override;

    float getZOrder() const override;

public slots:
    void mouseMoved(const QPointF& pos);
};
