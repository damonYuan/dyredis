set(CLIENT_LIB_NAME dyr_client)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
add_library(${CLIENT_LIB_NAME}_lib STATIC ${SOURCES})

# Link the common library
target_link_libraries(${CLIENT_LIB_NAME}_lib PRIVATE ${COMMON_LIB_NAME})