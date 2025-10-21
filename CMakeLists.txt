# root CMakeLists.txt
cmake_minimum_required(VERSION 4.1)

project(
    altlib
    LANGUAGES CXX
    DESCRIPTION "Algorithm Template for Competitive Program."
    VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# output the command_complie.json

add_subdirectory(include/atl)
add_subdirectory(src)

option(ENABLE_UNIT_TESTS "enable unit tests option" ON)

if (ENABLE_UNIT_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
