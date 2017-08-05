#pragma once

class EditorMainWindow;
class QPointF;

//! A base class for all editor tools.
class Tool {
protected:
    //! The editor for tool to manipulate.
    EditorMainWindow& editor;

public:
    explicit Tool(EditorMainWindow& editor);
    virtual ~Tool() = default;

    //! Called by editor when mouse is clicked on canvas.
    //! \param pos mouse position in screen coordinates.
    virtual void mouseClick(const QPointF& pos) = 0;
};
