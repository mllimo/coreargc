find_package(raylib REQUIRED)

file(GLOB CPP_SOURCES CONFIGURE_DEPENDS "src/**/*.cpp" "src/*.cpp")
file(GLOB HPP_SOURCES CONFIGURE_DEPENDS "include/Planeworld/*.hpp" "include/Planeworld/**/*.hpp")

add_executable (Planeworld ${CPP_SOURCES} ${HPP_SOURCES})

target_link_libraries(Planeworld raylib CoreARGC)

target_include_directories(Planeworld
  PUBLIC
    include
)

install(TARGETS Planeworld
  EXPORT PlaneworldConfig
  LIBRARY DESTINATION .        # .dll
  ARCHIVE DESTINATION lib      # .lib
  RUNTIME DESTINATION .        # .exe
)
