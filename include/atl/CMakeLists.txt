# include/atl/CMakeLists.txt

add_library(atl INTERFACE)
# static interface

file(GLOB_RECURSE atl_headers CONFIGURE_DEPENDS "*.hpp")

list(FILTER atl_headers EXCLUDE REGEX ".*/atl\\.hpp\\.in$")
list(FILTER atl_headers EXCLUDE REGEX ".*/atl\\.hpp$")
list(FILTER atl_headers EXCLUDE REGEX ".*Def\\.hpp$")
# get all files name under dir atl

set(ATL_INCLUDE_STRINGS "")
foreach(HEADER_FILE ${atl_headers})
    # now CMAKE_CURRENT_SOURCE_DIR is include/atl/
    file(RELATIVE_PATH REL_HEADER "${CMAKE_CURRENT_SOURCE_DIR}" ${HEADER_FILE})
    string(APPEND ATL_INCLUDE_STRINGS "#include \"${REL_HEADER}\"\n")
endforeach()

# this atl.hpp will be automatic generated at location : include/atl/
configure_file(
    "atl.hpp.in"
    "${CMAKE_SOURCE_DIR}/include/atl/atl.hpp"
)

target_include_directories(atl INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> 
    # cmake_souce_dir : root dir    
)

target_compile_features(atl INTERFACE cxx_std_20)