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
        )

set(EDITOR_SOURCES
        editor/editor_main.cpp
        editor/editor.ui
        editor/EditorMainWindow.cpp
        editor/EditorMainWindow.h
        )

add_executable(${GAME_NAME} ${GAME_SOURCES})
target_link_libraries(${GAME_NAME} Qt5::Widgets Qt5::Core)

add_executable(${EDITOR_NAME} ${EDITOR_SOURCES})
target_link_libraries(${EDITOR_NAME} Qt5::Widgets Qt5::Core)
