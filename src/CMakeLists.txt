set(MAIN_APP_PROJECT_NAME dyr)
set(MAIN_APP_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_library(${MAIN_APP_PROJECT_NAME}_lib INTERFACE)

project(${MAIN_APP_PROJECT_NAME} VERSION 1.0)
configure_file(Config.h.in Config.h)
add_subdirectory(client)
list(APPEND EXTRA_INCLUDES "${MAIN_APP_SOURCE_DIR}/client")
add_subdirectory(server)
list(APPEND EXTRA_INCLUDES "${MAIN_APP_SOURCE_DIR}/server")
target_include_directories(${MAIN_APP_PROJECT_NAME}_lib INTERFACE ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})
target_link_libraries(${MAIN_APP_PROJECT_NAME}_lib INTERFACE dyr_client dyr_server)

# executable
set(MAIN_APP_SOURCE ${MAIN_APP_SOURCE_DIR}/main.cpp)
add_executable(${MAIN_APP_PROJECT_NAME} ${MAIN_APP_SOURCE})
target_link_libraries(${MAIN_APP_PROJECT_NAME} PRIVATE ${MAIN_APP_PROJECT_NAME}_lib)

# install
install(TARGETS ${MAIN_APP_PROJECT_NAME} DESTINATION bin)