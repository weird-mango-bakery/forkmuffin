# QTDIR must point to c:/Qt/5.7/mingw53_32/ or similar
message("qtdir is set to '$ENV{QTDIR}' (must be 'c:/Qt/5.7/mingw53_32/' or similar)")
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(GAME_NAME "muffin")
set(EDITOR_NAME "muffin_editor")

set(GAME_SOURCES
        game/game_main.cpp
        game/game.ui
        game/GameMainWindow.cpp
        game/GameMainWindow.h
        game/Player.cpp
        game/Player.h
        game/PhysicsObject.cpp
        game/PhysicsObject.h
        game/PhysicsEngine.cpp
        game/PhysicsEngine.h
        game/Muffin.cpp
        game/Muffin.h
        )

set(EDITOR_SOURCES
        editor/editor_main.cpp
        editor/editor.ui
        editor/EditorMainWindow.cpp
        editor/EditorMainWindow.h
        editor/EditorCanvasWidget.cpp
        editor/EditorCanvasWidget.h
        editor/Grid.cpp
        editor/Grid.h
        editor/tools/Tool.cpp
        editor/tools/Tool.h
        editor/tools/BlockTool.cpp
        editor/tools/BlockTool.h
        editor/commands/EditorCommand.cpp
        editor/commands/EditorCommand.h
        editor/widgets/BlockSelectorWidget.cpp
        editor/widgets/BlockSelectorWidget.h
        editor/widgets/BlockWidget.cpp
        editor/widgets/BlockWidget.h
        editor/widgets/block_selector.ui
        editor/widgets/block.ui
        editor/commands/EraseBlockCommand.cpp
        editor/commands/EraseBlockCommand.h
        editor/commands/PlaceBlockCommand.cpp
        editor/commands/PlaceBlockCommand.h
        editor/commands/PlaceCurrentBlockCommand.cpp
        editor/commands/PlaceCurrentBlockCommand.h
        )

set(COMMON_SOURCES
        common/Level.cpp
        common/Level.h
        common/CanvasWidget.cpp
        common/CanvasWidget.h
        common/Serializable.h
        common/Camera.cpp
        common/Camera.h
        common/Block.cpp
        common/Block.h
        common/utils.cpp
        common/utils.h
        common/saveload.cpp
        common/saveload.h
        common/Renderable.cpp
        common/Renderable.h
        common/ValuesSelector.h
        common/DebugLines.cpp
        common/DebugLines.h
        common/TextureManager.cpp
        common/TextureManager.h
        common/RenderManager.cpp
        common/RenderManager.h
        common/StrayImage.cpp
        common/StrayImage.h
        )
add_library(muffin_common ${COMMON_SOURCES})
target_link_libraries(muffin_common Qt5::Core Qt5::Widgets)

add_executable(${GAME_NAME} ${GAME_SOURCES})
target_link_libraries(${GAME_NAME} muffin_common Qt5::Widgets Qt5::Core)

add_executable(${EDITOR_NAME} ${EDITOR_SOURCES})
target_link_libraries(${EDITOR_NAME} muffin_common Qt5::Widgets Qt5::Core)
