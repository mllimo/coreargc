find_package(GTest REQUIRED)

file(GLOB CPP_SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB HPP_SOURCES CONFIGURE_DEPENDS "*.hpp")

add_executable(CoreARGCTests ${CPP_SOURCES} ${HPP_SOURCES})

set_target_properties(CoreARGCTests PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CoreARGCTests PRIVATE raylib CoreARGC GTest::GTest GTest::Main)

enable_testing()

add_test(NAME CoreARGCTests COMMAND CoreARGCTests)

install(TARGETS CoreARGCTests
  EXPORT CoreARGCConfig
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static
)
