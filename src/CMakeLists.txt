# /src/CMakeLists.txt
add_executable(sandbox main.cpp)

target_link_libraries(sandbox PRIVATE atl)
# sandbox env for debugger