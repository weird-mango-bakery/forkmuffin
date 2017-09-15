#pragma once

#include "editor/commands/ImageCommandBase.h"
#include <QPoint>
#include <QSize>

class EditorMainWindow;
class StrayImage;

//! A command for changing stray image params. Each command can change only one of the following params:
//! x, y, width, height or texture name.
class ChangeStrayImageParamsCommand : public ImageCommandBase {
private:
    //! The next position of the image.
    QPoint pos;
    //! The new size of the image.
    QSize size;
    //! The new texture name of the image.
    QString textureName;
    //! The current position of the image.
    QPoint oldPos;
    //! The current size of the image.
    QSize oldSize;
    //! The current texture name of the image.
    QString oldTextureName;

    //! The enum class that describes which one of the params the command changes.
    enum class CommandType {
        //! The command changes x coordinates.
        SET_X,
        //! The command changes y coordinates.
        SET_Y,
        //! The command changes width.
        SET_WIDTH,
        //! The command changes height.
        SET_HEIGHT,
        //! The command changes texture name.
        SET_TEXTURE,
    };
    //! The type of the command.
    CommandType commandType;
    //! The type of the last created command.
    static CommandType lastCommandType;
    //! The unique id for merge, see mergeWith().
    int commandId;
    //! The id that was used when the last command had been created.
    static int lastCommandId;

    //! Creates the command.
    ChangeStrayImageParamsCommand(
        EditorMainWindow& editor,
        const QString& text,
        StrayImage& currentImage,
        const QPoint& pos,
        const QSize& size,
        const QString& textureName,
        CommandType type
    );
    //! Returns the command id. Qt tries to merge commands with the same id by calling mergeWith().
    //! Commands with the same type, that are created one after another, have the same id.
    //! When a command with a different type is created it gets a new unique id.
    int id() const override;
    //! Returns true if the command successfully merges with the specified command.
    //! For command that changes position (either x or y), only changes in the same direction are merged.
    //! For command that changes size (either width or height), value increments are merged only
    //! with another increments, same for decrements.
    //! \param other the new command to try merging with.
    bool mergeWith(const QUndoCommand* other) override;

public:
    //! Creates the command that changes only x.
    static EditorCommand* setX(EditorMainWindow& editor, StrayImage& currentImage, int newX);
    //! Creates the command that changes only y.
    static EditorCommand* setY(EditorMainWindow& editor, StrayImage& currentImage, int newY);
    //! Creates the command that changes only width.
    static EditorCommand* setWidth(EditorMainWindow& editor, StrayImage& currentImage, int newWidth);
    //! Creates the command that changes only height.
    static EditorCommand* setHeight(EditorMainWindow& editor, StrayImage& currentImage, int newHeight);
    //! Creates the command that changes only texture name.
    static EditorCommand* setTexture(EditorMainWindow& editor, StrayImage& currentImage, const QString& newTex);

    void undo() override;
    void redo() override;
};
