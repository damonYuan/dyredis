set(MAIN_APP_PROJECT_NAME dyr)

set(${MAIN_APP_PROJECT_NAME}__VERSION_MAJOR 1)
set(${MAIN_APP_PROJECT_NAME}__VERSION_MINOR 0)
project(${MAIN_APP_PROJECT_NAME} VERSION 1.0)
configure_file(Config.h.in Config.h)

add_subdirectory(common)
add_subdirectory(client)
add_subdirectory(server)



add_executable(${MAIN_APP_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${MAIN_APP_PROJECT_NAME} PUBLIC dyr_client_lib dyr_server_lib)
target_include_directories(${MAIN_APP_PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

install(TARGETS ${MAIN_APP_PROJECT_NAME} DESTINATION bin)