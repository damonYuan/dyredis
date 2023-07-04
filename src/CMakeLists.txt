set(MAIN_APP_PROJECT_NAME dyredis)
set(MAIN_APP_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(MAIN_APP_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/libs)
set(MAIN_APP_SOURCE
        ${MAIN_APP_SOURCE_DIR}/main.cpp
        ${MAIN_APP_SOURCE_DIR}/server.cpp
        ${MAIN_APP_SOURCE_DIR}/client.cpp
        )

# build
project(${MAIN_APP_PROJECT_NAME})
add_executable(${MAIN_APP_PROJECT_NAME} ${MAIN_APP_SOURCE})

# install
install(TARGETS ${MAIN_APP_PROJECT_NAME} DESTINATION bin)