find_package(raylib REQUIRED)

file(GLOB CPP_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB HPP_SOURCES CONFIGURE_DEPENDS "include/Planefactory/*.hpp")

add_executable (Planefactory ${CPP_SOURCES} ${HPP_SOURCES})

target_link_libraries(Planefactory raylib CoreARGC)

target_include_directories(Planefactory
  PUBLIC
    include
)

install(TARGETS Planefactory
  EXPORT PlanefactoryConfig
  LIBRARY DESTINATION .        # .dll
  ARCHIVE DESTINATION lib      # .lib
  RUNTIME DESTINATION .        # .exe
)
