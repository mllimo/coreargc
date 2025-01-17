find_package(raylib REQUIRED)

file(GLOB CPP_SOURCES CONFIGURE_DEPENDS "src/**/*.cpp" "src/*.cpp")
file(GLOB HPP_SOURCES CONFIGURE_DEPENDS "include/Sandbox/*.hpp" "include/Sandbox/**/*.hpp")

add_executable (Sandbox ${CPP_SOURCES} ${HPP_SOURCES})

target_link_libraries(Sandbox raylib CoreARGC)

target_include_directories(Sandbox
  PUBLIC
    include
)

install(TARGETS Sandbox
  EXPORT SandboxConfig
  LIBRARY DESTINATION .        # .dll
  ARCHIVE DESTINATION lib      # .lib
  RUNTIME DESTINATION .        # .exe
)
