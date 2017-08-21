#pragma once

#include <QDockWidget>

#include "ui_stray_images.h"

class EditorMainWindow;
class StrayImage;

//! A widget for selecting stray images and modifying it.
class StraySelectorWidget : public QDockWidget, private Ui::StraySelectorWidget {
Q_OBJECT
private:
    //! The editor.
    EditorMainWindow& editor;
    //! The selected stray image.
    StrayImage* currentImage = nullptr;

    //! Sets selected stray image from the new name and updates image info on the widget.
    //! \param strayName The new name.
    void updateInfo(const QString& strayName);
    //! Resizes selected stray image with the new width and the new height.
    //! \param width The new width.
    //! \param height The new height.
    void updateSize(int width, int height);
    //! Sets selected stray image pos to the new x and the new y.
    //! \param x The new x.
    //! \param y The new y.
    void updatePosition(int x, int y);
    //! Clear list of stray images and params on the widget.
    void clear();

public:
    //! Create widget.
    explicit StraySelectorWidget(EditorMainWindow& editor);

    //! Load stray images from editor.
    void updateStrays();

private slots:
    void on_strayList_currentTextChanged(const QString& strayName);
    void on_sizeWidth_valueChanged(int width);
    void on_sizeHeight_valueChanged(int height);
    void on_posX_valueChanged(int x);
    void on_posY_valueChanged(int y);
};
