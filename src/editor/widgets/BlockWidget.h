#pragma once

#include <QFrame>

#include "ui_block.h"

//! A button to select block type. You can select it with click.
class BlockWidget: public QFrame, private Ui::BlockWidget {
Q_OBJECT
private:
    //! Texture file name.
    QString textureName;
    //! Block symbol.
    QChar symbol;

public:
    //!Create widget.
    //! \param parent parent widget.
    //! \param textureName Texture file name.
    //! \param symbol Block symbol.
    BlockWidget(QWidget* parent, const QString& textureName, QChar symbol);

    //! Changes "selected" state of the button.
    //! \param selected true makes the widget look sunken.
    void setSelected(bool selected);
    //! Returns texture file name.
    const QString& getTextureName() const;
    //! Returns block symbol.
    QChar getSymbol() const;

protected:
    //! Gets called by Qt when mouse is pressed.
    void mousePressEvent(QMouseEvent* event) override;

signals:
    //! The signal that is emitted when you click on the widget.
    void clicked();
};
