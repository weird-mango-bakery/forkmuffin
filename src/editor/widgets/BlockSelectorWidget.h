#pragma once

#include <QDockWidget>
#include <QVBoxLayout>

#include "ui_block_selector.h"

class BlockWidget;

//! A list of buttons to select a current block type in editor.
class BlockSelectorWidget : public QDockWidget, private Ui::BlockSelectorWidget {
Q_OBJECT
private:
    //! A map from symbols to buttons, that you can press to select block type.
    QHash<QChar, BlockWidget*> levelBlocks;

    //! Get layout. It is set in the ui file, that this widget has VBox layout.
    //! \return Layout to add buttons to.
    QVBoxLayout* getButtonsLayout();
    //! Adds button to the widget to represent block type.
    //! \param textureName Texture file name.
    //! \param symbol Block symbol.
    void appendBlock(const QString& textureName, QChar symbol);

public:
    //! Selects a button that correspond to specified symbol.
    //! \param symbol Block symbol.
    void selectBlock(QChar symbol);
    //! Returns the map from symbols to buttons.
    const QHash<QChar, BlockWidget*>& getLevelBlocks() const;
    //! Create widget.
    //! \param parent parent widget.
    explicit BlockSelectorWidget(QWidget* parent);

signals:
    //! Informs the editor that a button is selected.
    //! \param symbol symbol of the selected button.
    void blockSelected(QChar symbol);
};
