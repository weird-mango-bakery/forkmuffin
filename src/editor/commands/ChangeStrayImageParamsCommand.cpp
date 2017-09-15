#include "ChangeStrayImageParamsCommand.h"
#include "editor/EditorMainWindow.h"
#include "common/StrayImage.h"

ChangeStrayImageParamsCommand::CommandType ChangeStrayImageParamsCommand::lastCommandType = CommandType::SET_TEXTURE;
int ChangeStrayImageParamsCommand::lastCommandId = 1;

void ChangeStrayImageParamsCommand::undo() {
    currentImage().setPos(oldPos);
    currentImage().setSize(oldSize);
    currentImage().setTexture(oldTextureName);
}

void ChangeStrayImageParamsCommand::redo() {
    currentImage().setPos(pos);
    currentImage().setSize(size);
    currentImage().setTexture(textureName);
}

ChangeStrayImageParamsCommand::ChangeStrayImageParamsCommand(
    EditorMainWindow& editor,
    const QString& text,
    StrayImage& currentImage,
    const QPoint& pos,
    const QSize& size,
    const QString& textureName,
    CommandType type
)
    : ImageCommandBase(editor, text, currentImage.getName())
    , pos(pos)
    , size(size)
    , textureName(textureName)
    , oldPos(currentImage.getPos())
    , oldSize(currentImage.getSize())
    , oldTextureName(currentImage.getTexture())
    , commandType(type)
    , commandId(type == lastCommandType ? lastCommandId : ++lastCommandId)
{
    lastCommandType = type;
}

EditorCommand* ChangeStrayImageParamsCommand::setX(EditorMainWindow& editor, StrayImage& currentImage, int newX) {
    return new ChangeStrayImageParamsCommand(
        editor,
        "Change x",
        currentImage,
        QPoint(newX, currentImage.getPos().y()),
        currentImage.getSize(),
        currentImage.getTexture(),
        CommandType::SET_X
    );
}

EditorCommand* ChangeStrayImageParamsCommand::setY(EditorMainWindow& editor, StrayImage& currentImage, int newY) {
    return new ChangeStrayImageParamsCommand(
        editor,
        "Change y",
        currentImage,
        QPoint(currentImage.getPos().x(), newY),
        currentImage.getSize(),
        currentImage.getTexture(),
        CommandType::SET_Y
    );
}

EditorCommand* ChangeStrayImageParamsCommand::setWidth(EditorMainWindow& editor, StrayImage& currentImage, int newWidth) {
    return new ChangeStrayImageParamsCommand(
        editor,
        "Change width",
        currentImage,
        currentImage.getPos(),
        QSize(newWidth, currentImage.getSize().height()),
        currentImage.getTexture(),
        CommandType::SET_WIDTH
    );
}

EditorCommand* ChangeStrayImageParamsCommand::setHeight(EditorMainWindow& editor, StrayImage& currentImage, int newHeight) {
    return new ChangeStrayImageParamsCommand(
        editor,
        "Change height",
        currentImage,
        currentImage.getPos(),
        QSize(currentImage.getSize().width(), newHeight),
        currentImage.getTexture(),
        CommandType::SET_HEIGHT
    );
}

EditorCommand* ChangeStrayImageParamsCommand::setTexture(EditorMainWindow& editor, StrayImage& currentImage, const QString& newTex) {
    return new ChangeStrayImageParamsCommand(
        editor,
        "Change texture",
        currentImage,
        currentImage.getPos(),
        currentImage.getSize(),
        newTex,
        CommandType::SET_TEXTURE
    );
}

int ChangeStrayImageParamsCommand::id() const {
    return commandId;
}
//! The macro generates a case block that checks if the difference between new and old properties are the same
//! for two commands. If they are, the current command gets new value from the other command, and true is returned.
//! \param name all-lowercase name of the getter of the property.
//! \param Name capitalised name for setter of the property.
//! \param NAME all-uppercase name for command type enum value.
//! \param var field in the command that contains the new values.
//! \param oldVar field in the command that contains the old values.
#define MERGE(name, Name, NAME, var, oldVar)                                                        \
case CommandType::SET_##NAME:                                                                       \
    if ((var.name() - oldVar.name() < 0) != (command->var.name() - command->oldVar.name() < 0)) {   \
        return false;                                                                               \
    }                                                                                               \
    var.set##Name(command->var.name());                                                             \
    break;

//! The macro checks if the difference between new and old coordinates are the same for two commands, see MERGE().
//! Since coordinate name consists only of one letter, its capitalized and all-uppercase names are the same.
#define MERGE_POS(name, NAME) MERGE(name, NAME, NAME, pos, oldPos)

//! The macro checks if the difference between new and old width or height are the same for two commands, see MERGE().
#define MERGE_SIZE(name, Name, NAME) MERGE(name, Name, NAME, size, oldSize)

bool ChangeStrayImageParamsCommand::mergeWith(const QUndoCommand* other) {
    auto command = static_cast<const ChangeStrayImageParamsCommand*>(other);
    switch(commandType) {
        MERGE_POS(x, X)
        MERGE_POS(y, Y)
        MERGE_SIZE(width, Width, WIDTH)
        MERGE_SIZE(height, Height, HEIGHT)
        default:
            return false;
    }
    return true;
}
