#pragma once

#include "common/CanvasWidget.h"

//! Canvas widget with additional functionality for editor.
class EditorCanvasWidget: public CanvasWidget {
Q_OBJECT
private:
    //! Current mouse position in screen coordinates.
    QPointF curMousePos;
    //! Gets set to false on each mouse press.
    //! Gets set to true if mouse has moved after the mouse press.
    bool mouseMoved = false;

public:
    //! Creates widget with given parent.
    //! \param parent parent widget or nullptr for widgets without parent.
    explicit EditorCanvasWidget(QWidget* parent);

    //! Returns current mouse position in screen coordinates.
    const QPointF& getCurMousePos() const;

protected:
    //! Gets called by Qt when mouse wheel is scrolled.
    void wheelEvent(QWheelEvent* event) override;
    //! Gets called by Qt when mouse is moved.
    void mouseMoveEvent(QMouseEvent* event) override;
    //! Gets called by Qt when mouse is pressed.
    void mousePressEvent(QMouseEvent* event) override;
    //! Gets called by Qt when mouse is released.
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    //! A signal that is emitted when mouse is dragged with right button.
    //! \param delta distance the mouse was dragged since previous emit, in screen coordinates.
    void mouseDrag(const QPointF& delta);
    //! A signal that is emitted when mouse wheel is rotated.
    //! \param delta value of corresponds to rotation by 15 degrees, which for most mice is one "tick" of rotation.
    void mouseWheel(float delta);
    //! A signal that is emitted when mouse is moved.
    //! \param pos new mouse position in screen coordinates.
    void mouseMove(const QPointF& pos);
    //! A signal that is emitted when any mouse button is clicked.
    //! \param pos click position in screen coordinates.
    void mouseClick(const QPointF& pos);
};
