file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})

add_library(dyr_server_lib STATIC ${SOURCES})

target_link_libraries(dyr_server_lib PUBLIC dyr_common_lib)
target_include_directories(dyr_server_lib PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src/common)

