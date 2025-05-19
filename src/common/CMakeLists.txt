add_library(dyr_common_lib STATIC common.cpp)
target_link_libraries(dyr_common_lib PUBLIC dyredis_compiler_flags)
target_include_directories(dyr_common_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(dyr_common_lib PRIVATE "EXPORTING_DYREDIS")

# install libs
set(installable_libs dyr_common_lib dyredis_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
# install include headers
install(FILES common.h DESTINATION include)
