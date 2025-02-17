cmake_minimum_required (VERSION 3.26)

cmake_policy(SET CMP0091 NEW)

project ("Planefactory")

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

add_subdirectory ("CoreARGC")
add_subdirectory ("planeworld")

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/assets
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)