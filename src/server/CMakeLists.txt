set(SERVER_LIB_NAME dyr_server)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
add_library(${SERVER_LIB_NAME}_lib STATIC ${SOURCES})

# Add the include directory for the common library
target_include_directories(${SERVER_LIB_NAME}_lib PRIVATE ${CMAKE_SOURCE_DIR}/src/common)

# Link the common library
target_link_libraries(${SERVER_LIB_NAME}_lib PRIVATE dyr_common_lib)