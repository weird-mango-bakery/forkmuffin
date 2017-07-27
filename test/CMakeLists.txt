set(gtest_disable_pthreads on) # needed in MinGW?
add_subdirectory(googletest-release-1.8.0)

find_package(Qt5Core REQUIRED)

add_executable(muffin_tests level_saveload.cpp block_saveload.cpp utils.cpp pretty_print.cpp pretty_print.h camera.cpp)

target_link_libraries(muffin_tests gtest gtest_main muffin_common Qt5::Core)
