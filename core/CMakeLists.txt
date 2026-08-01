if(UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBZIP REQUIRED IMPORTED_TARGET libzip)

    if(TARGET PkgConfig::LIBZIP AND NOT TARGET libzip::zip)
        add_library(libzip::zip ALIAS PkgConfig::LIBZIP)
    endif()
else()
    find_package(libzip CONFIG REQUIRED)
endif()

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

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/BuildInfo.hpp.in
    ${CMAKE_BINARY_DIR}/generated/BuildInfo.hpp
    @ONLY
)

target_include_directories(retroforge_core PUBLIC
    ${CMAKE_BINARY_DIR}/generated
)

target_compile_features(retroforge_core PUBLIC cxx_std_20)

target_link_libraries(retroforge_core PRIVATE
    libzip::zip
)