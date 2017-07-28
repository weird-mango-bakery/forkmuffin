#pragma once

#include "editor/tools/Tool.h"

class BlockTool: public Tool {
public:
    explicit BlockTool(EditorMainWindow& editor);

    void mouseClick(const QPointF& pos) override;

};
