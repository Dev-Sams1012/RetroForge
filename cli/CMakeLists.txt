file(GLOB_RECURSE CLI_SOURCES 
    CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(retroforge_cli
    ${CLI_SOURCES}
)

target_link_libraries(retroforge_cli PRIVATE 
    retroforge_core
)

target_include_directories(retroforge_cli PRIVATE 
    ${CMAKE_SOURCE_DIR}/external/CLI11/include
)