#pragma once

#include "editor/tools/Tool.h"

//! Toggles block on the level using ToggleBlockCommand.
class BlockTool: public Tool {
public:
    explicit BlockTool(EditorMainWindow& editor);

    void mouseClick(const QPointF& pos) override;
};
