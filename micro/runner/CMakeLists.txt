cmake_minimum_required(VERSION 3.20)

project(micro_exec LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT DEFINED MICRO_REPO_ROOT)
    message(FATAL_ERROR "MICRO_REPO_ROOT must be provided")
endif()

if(NOT DEFINED MICRO_LIBBPF_PREFIX)
    message(FATAL_ERROR "MICRO_LIBBPF_PREFIX must be provided")
endif()

if(NOT DEFINED MICRO_LIBBPF_LIBRARY)
    message(FATAL_ERROR "MICRO_LIBBPF_LIBRARY must be provided")
endif()

set(MICRO_REPO_ROOT "${MICRO_REPO_ROOT}" CACHE PATH "Repository root")
set(MICRO_LIBBPF_PREFIX "${MICRO_LIBBPF_PREFIX}" CACHE PATH "libbpf prefix")
set(MICRO_LIBBPF_LIBRARY "${MICRO_LIBBPF_LIBRARY}" CACHE FILEPATH "libbpf static library")
set(MICRO_LLVMBPF_ROOT "${MICRO_REPO_ROOT}/vendor/llvmbpf")
set(MICRO_SCANNER_ROOT "${MICRO_REPO_ROOT}/scanner")

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBELF REQUIRED IMPORTED_TARGET libelf)
pkg_check_modules(ZLIB REQUIRED IMPORTED_TARGET zlib)
pkg_check_modules(LIBZSTD REQUIRED IMPORTED_TARGET libzstd)

add_subdirectory("${MICRO_LLVMBPF_ROOT}" "${CMAKE_BINARY_DIR}/llvmbpf")

if(NOT EXISTS "${MICRO_SCANNER_ROOT}/CMakeLists.txt")
    message(FATAL_ERROR "scanner/ was not found at ${MICRO_SCANNER_ROOT}")
endif()

set(BPF_JIT_SCANNER_BUILD_CLI OFF CACHE BOOL "Build the bpf-jit-scanner CLI tool" FORCE)
set(BPF_JIT_SCANNER_BUILD_TESTS OFF CACHE BOOL "Build scanner unit tests" FORCE)
add_subdirectory("${MICRO_SCANNER_ROOT}" "${CMAKE_BINARY_DIR}/scanner")

add_library(vendor_libbpf STATIC IMPORTED GLOBAL)
set_target_properties(vendor_libbpf PROPERTIES
    IMPORTED_LOCATION "${MICRO_LIBBPF_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${MICRO_LIBBPF_PREFIX}/include;${MICRO_REPO_ROOT}/vendor/libbpf/include;${MICRO_REPO_ROOT}/vendor/libbpf/include/uapi"
)

add_executable(micro_exec
    src/common.cpp
    src/elf_program_loader.cpp
    src/kernel_runner.cpp
    src/llvmbpf_runner.cpp
    src/main.cpp
    src/perf_counters.cpp
)

target_include_directories(micro_exec
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${MICRO_LIBBPF_PREFIX}/include"
        "${MICRO_REPO_ROOT}/vendor/libbpf/include"
        "${MICRO_REPO_ROOT}/vendor/libbpf/include/uapi"
        "${MICRO_REPO_ROOT}/vendor/llvmbpf/include"
)

target_link_libraries(micro_exec
    PRIVATE
        llvmbpf_vm
        spdlog::spdlog
        bpf_jit_scanner::scanner
        vendor_libbpf
        PkgConfig::LIBELF
        PkgConfig::ZLIB
        PkgConfig::LIBZSTD
)
