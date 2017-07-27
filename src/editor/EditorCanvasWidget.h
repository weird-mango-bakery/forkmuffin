#pragma once

#include "common/CanvasWidget.h"

class EditorCanvasWidget: public CanvasWidget {
Q_OBJECT
private:
    QPointF curMousePos;

public:
    explicit EditorCanvasWidget(QWidget* parent);

    const QPointF& getCurMousePos() const;

protected:
    void wheelEvent(QWheelEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

signals:
    void mouseDrag(const QPointF& delta);
    void mouseWheel(float delta);
    void mouseMove(const QPointF& pos);
};
