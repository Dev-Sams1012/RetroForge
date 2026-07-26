file(GLOB_RECURSE CORE_SOURCES 
    CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(retroforge_core STATIC
    ${CORE_SOURCES}
)

target_include_directories(retroforge_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(retroforge_core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(retroforge_core PUBLIC cxx_std_20)