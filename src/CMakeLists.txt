set(MAIN_APP_PROJECT_NAME dyr)
set(MAIN_APP_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set(${MAIN_APP_PROJECT_NAME}__VERSION_MAJOR 1)
set(${MAIN_APP_PROJECT_NAME}__VERSION_MINOR 0)
project(${MAIN_APP_PROJECT_NAME} VERSION 1.0)
configure_file(Config.h.in Config.h)

add_subdirectory(common)
add_subdirectory(client)
add_subdirectory(server)

# executable
set(MAIN_APP_SOURCE ${MAIN_APP_SOURCE_DIR}/main.cpp)
add_executable(${MAIN_APP_PROJECT_NAME} ${MAIN_APP_SOURCE})
target_include_directories(${MAIN_APP_PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR})
target_link_libraries(${MAIN_APP_PROJECT_NAME} PRIVATE dyr_client_lib dyr_server_lib)

# install
install(TARGETS ${MAIN_APP_PROJECT_NAME} DESTINATION bin)