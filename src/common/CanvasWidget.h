#pragma once

#include <QWidget>

class Level;

class CanvasWidget : public QWidget {
Q_OBJECT
private:
    const Level* level = nullptr;

public:
    void setLevel(const Level& lvl);

    explicit CanvasWidget(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* event) override;
};
