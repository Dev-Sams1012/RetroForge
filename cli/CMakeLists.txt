add_executable(retroforge_cli main.cpp)
target_link_libraries(retroforge_cli PRIVATE rf_core)
target_include_directories(retroforge_cli PRIVATE ${CMAKE_SOURCE_DIR}/external/CLI11/include)