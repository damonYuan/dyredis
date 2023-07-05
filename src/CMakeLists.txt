set(MAIN_APP_PROJECT_NAME dyredis)
set(MAIN_APP_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(MAIN_APP_SOURCE
        ${MAIN_APP_SOURCE_DIR}/main.cpp
        )
set(MAIN_APP_COMPILER_FLAGS ${MAIN_APP_PROJECT_NAME}_compiler_flags)

add_library(${MAIN_APP_COMPILER_FLAGS} INTERFACE)
target_compile_features(${MAIN_APP_COMPILER_FLAGS} INTERFACE cxx_std_11)

project(${MAIN_APP_PROJECT_NAME} VERSION 1.0)
configure_file(Config.h.in Config.h)
add_subdirectory(client)
list(APPEND EXTRA_INCLUDES "${MAIN_APP_SOURCE_DIR}/client")
add_subdirectory(server)
list(APPEND EXTRA_INCLUDES "${MAIN_APP_SOURCE_DIR}/server")

add_executable(${MAIN_APP_PROJECT_NAME} ${MAIN_APP_SOURCE})
target_link_libraries(${MAIN_APP_PROJECT_NAME} PUBLIC
        ${MAIN_APP_COMPILER_FLAGS}
        dyr_client
        dyr_server
        )
target_include_directories(${MAIN_APP_PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        ${EXTRA_INCLUDES}
        )

# install
install(TARGETS ${MAIN_APP_PROJECT_NAME} DESTINATION bin)