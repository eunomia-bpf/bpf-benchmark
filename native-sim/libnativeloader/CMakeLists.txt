cmake_minimum_required(VERSION 3.20)

project(nativeloader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED NATIVE_LOADER_REPO_ROOT)
    get_filename_component(NATIVE_LOADER_REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
endif()

if(NOT DEFINED NATIVE_LOADER_LIBBPF_PREFIX)
    message(FATAL_ERROR "NATIVE_LOADER_LIBBPF_PREFIX must be provided")
endif()

if(NOT DEFINED NATIVE_LOADER_LIBBPF_LIBRARY)
    message(FATAL_ERROR "NATIVE_LOADER_LIBBPF_LIBRARY must be provided")
endif()

set(NATIVE_LOADER_KERNEL_OFFSETS_INCLUDE
    "${NATIVE_LOADER_REPO_ROOT}/micro/programs/build-x86"
    CACHE PATH "kernel_offsets.h include directory")

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBELF REQUIRED IMPORTED_TARGET libelf)
pkg_check_modules(ZLIB REQUIRED IMPORTED_TARGET zlib)

add_library(native_loader STATIC
    src/native_loader.cpp
)

add_library(native_loader_shared SHARED
    src/native_loader.cpp
)
set_target_properties(native_loader_shared PROPERTIES OUTPUT_NAME native_loader)

add_library(native_loader_libbpf STATIC IMPORTED GLOBAL)
set_target_properties(native_loader_libbpf PROPERTIES
    IMPORTED_LOCATION "${NATIVE_LOADER_LIBBPF_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${NATIVE_LOADER_LIBBPF_PREFIX}/include;${NATIVE_LOADER_REPO_ROOT}/vendor/libbpf/include;${NATIVE_LOADER_REPO_ROOT}/vendor/libbpf/include/uapi"
)

target_include_directories(native_loader
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${NATIVE_LOADER_LIBBPF_PREFIX}/include"
        "${NATIVE_LOADER_REPO_ROOT}/vendor/libbpf/include"
        "${NATIVE_LOADER_REPO_ROOT}/vendor/libbpf/include/uapi"
        "${NATIVE_LOADER_KERNEL_OFFSETS_INCLUDE}"
        "/artifacts/kernel"
)

target_include_directories(native_loader_shared
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${NATIVE_LOADER_LIBBPF_PREFIX}/include"
        "${NATIVE_LOADER_REPO_ROOT}/vendor/libbpf/include"
        "${NATIVE_LOADER_REPO_ROOT}/vendor/libbpf/include/uapi"
        "${NATIVE_LOADER_KERNEL_OFFSETS_INCLUDE}"
        "/artifacts/kernel"
)

target_link_libraries(native_loader
    PUBLIC
        native_loader_libbpf
        PkgConfig::LIBELF
        PkgConfig::ZLIB
        ${CMAKE_DL_LIBS}
)

target_link_libraries(native_loader_shared
    PUBLIC
        native_loader_libbpf
        PkgConfig::LIBELF
        PkgConfig::ZLIB
        ${CMAKE_DL_LIBS}
)
