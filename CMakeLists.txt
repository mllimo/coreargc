cmake_minimum_required (VERSION 3.26)

cmake_policy(SET CMP0091 NEW)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Planefactory")

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

add_subdirectory ("CoreARGC")
add_subdirectory ("planefactory")

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/assets
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)