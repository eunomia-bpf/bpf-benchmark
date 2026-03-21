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
option(MICRO_EXEC_ENABLE_LLVMBPF "Build llvmbpf support into micro_exec" ON)

# llvmbpf is built as a static library, so the LLVM package's imported targets
# must remain visible when the top-level micro_exec target resolves its full
# link closure.
set(CMAKE_FIND_PACKAGE_TARGETS_GLOBAL TRUE)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBELF REQUIRED IMPORTED_TARGET libelf)
pkg_check_modules(ZLIB REQUIRED IMPORTED_TARGET zlib)
pkg_check_modules(LIBZSTD REQUIRED IMPORTED_TARGET libzstd)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    find_package(LLVM REQUIRED CONFIG)

    if(NOT TARGET ZLIB::ZLIB)
        add_library(ZLIB::ZLIB INTERFACE IMPORTED GLOBAL)
        target_link_libraries(ZLIB::ZLIB INTERFACE PkgConfig::ZLIB)
    endif()

    find_library(MICRO_TERMINFO_LIBRARY
        NAMES tinfo terminfo ncurses ncursesw curses
        PATH_SUFFIXES lib64 lib
        REQUIRED
    )
    mark_as_advanced(MICRO_TERMINFO_LIBRARY)

    if(NOT TARGET Terminfo::terminfo)
        add_library(Terminfo::terminfo UNKNOWN IMPORTED GLOBAL)
        set_target_properties(Terminfo::terminfo PROPERTIES
            IMPORTED_LOCATION "${MICRO_TERMINFO_LIBRARY}"
        )
    endif()

    add_subdirectory("${MICRO_LLVMBPF_ROOT}" "${CMAKE_BINARY_DIR}/llvmbpf")
endif()

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

set(MICRO_EXEC_SOURCES
    src/common.cpp
    src/elf_program_loader.cpp
    src/kernel_runner.cpp
    src/main.cpp
    src/perf_counters.cpp
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    list(APPEND MICRO_EXEC_SOURCES src/llvmbpf_runner.cpp)
endif()

add_executable(micro_exec ${MICRO_EXEC_SOURCES})

target_include_directories(micro_exec
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${MICRO_LIBBPF_PREFIX}/include"
        "${MICRO_REPO_ROOT}/vendor/libbpf/include"
        "${MICRO_REPO_ROOT}/vendor/libbpf/include/uapi"
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    target_include_directories(micro_exec
        PRIVATE
            "${MICRO_REPO_ROOT}/vendor/llvmbpf/include"
    )
endif()

target_link_libraries(micro_exec
    PRIVATE
        bpf_jit_scanner::scanner
        vendor_libbpf
        PkgConfig::LIBELF
        PkgConfig::ZLIB
        PkgConfig::LIBZSTD
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    target_link_libraries(micro_exec PRIVATE llvmbpf_vm spdlog::spdlog)
endif()

target_compile_definitions(micro_exec
    PRIVATE
        MICRO_EXEC_ENABLE_LLVMBPF=$<BOOL:${MICRO_EXEC_ENABLE_LLVMBPF}>
)
