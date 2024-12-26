include(GenerateExportHeader)

find_package(raylib REQUIRED)

file(GLOB CPP_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB HPP_SOURCES CONFIGURE_DEPENDS "include/CoreARGC/*.hpp")

add_library(CoreARGC ${CPP_SOURCES} ${HPP_SOURCES})

set_target_properties(CoreARGC PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CoreARGC raylib)

generate_export_header(CoreARGC EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/CoreARGC_api.h)

target_include_directories(CoreARGC
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/exports>
    include
)

install(TARGETS CoreARGC
  EXPORT CoreARGCConfig
  LIBRARY DESTINATION .        # .dll
  ARCHIVE DESTINATION lib      # .lib
  RUNTIME DESTINATION .        # .exe
)

install(DIRECTORY include/ DESTINATION include/)

add_subdirectory(tests)
