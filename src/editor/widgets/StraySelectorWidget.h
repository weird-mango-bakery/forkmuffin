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
    //! Set to true when we are changing displayed params inside updateInfo to prevent adding commands to undo stack.
    bool isInsideUpdate = false;

    //! Sets selected stray image from the new name and updates image info on the widget.
    //! \param strayName The new name.
    void updateInfo(const QString& strayName);
    //! Clear displayed params on the widget.
    void clearData();
    //! Fills the combobox with textures from texture folder.
    void updateTextureNames();
    //! Returns true if no other images have the specified name (except the current image).
    //! \param strayName The specified name.
    bool isUniqueName(const QString& strayName) const;

public:
    //! Create widget.
    explicit StraySelectorWidget(EditorMainWindow& editor);

private slots:
    void on_strayList_currentTextChanged(const QString& strayName);
    void on_sizeWidth_valueChanged(int width);
    void on_sizeHeight_valueChanged(int height);
    void on_posX_valueChanged(int x);
    void on_posY_valueChanged(int y);
    void on_imageName_textChanged(const QString& strayName);
    void on_textureName_activated(const QString& textureName);
    void on_addButton_clicked();
    void on_cloneButton_clicked();
    void on_deleteButton_clicked();

public slots:
    //! Calls updateInfo and passes the current stray image name to it.
    void updateCurrentInfo();

    //! Load stray images from editor.
    void updateStrays();

    //! Returns unique name for image from the given texture.
    QString getUniqueNameFromTexture(const QString& textureName) const;
};
