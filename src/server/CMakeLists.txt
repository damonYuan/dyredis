set(SERVER_LIB_NAME dyr_server)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
add_library(${SERVER_LIB_NAME}_lib STATIC ${SOURCES})

# Link the common library
target_link_libraries(${SERVER_LIB_NAME}_lib PRIVATE ${COMMON_LIB_NAME})