#pragma once

class EditorMainWindow;
class QPointF;

class Tool {
protected:
    EditorMainWindow& editor;

public:
    explicit Tool(EditorMainWindow& editor);
    virtual ~Tool() = default;

    virtual void mouseClick(const QPointF& pos) = 0;
};
