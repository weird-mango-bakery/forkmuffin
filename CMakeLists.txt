cmake_minimum_required(VERSION 3.5)
project(muffin)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(
        NAME muffin_tests
        COMMAND muffin_tests
)
