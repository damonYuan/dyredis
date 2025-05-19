project(dyr VERSION 1.0)
configure_file(config.h.in config.h)

add_subdirectory(common)
add_subdirectory(client)
add_subdirectory(server)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (BUILD_SHARED_LIBS)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")  
endif()

add_executable(dyr main.cpp)
target_link_libraries(dyr PUBLIC dyr_client_lib dyr_server_lib dyredis_compiler_flags)
target_include_directories(dyr PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS dyr DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)

# setup installer
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${dyr_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${dyr_VERSION_MINOR}")
set(CPACK_GENERATOR "TGZ")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)