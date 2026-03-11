cmake_minimum_required(VERSION 3.16)
project(bpf_jit_scanner VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

# --------------------------------------------------------------------
# Options
# --------------------------------------------------------------------

option(BPF_JIT_SCANNER_BUILD_CLI   "Build the bpf-jit-scanner CLI tool"  ON)
option(BPF_JIT_SCANNER_BUILD_TESTS "Build unit tests"                     ON)

# --------------------------------------------------------------------
# Library: bpf_jit_scanner
# --------------------------------------------------------------------

add_library(bpf_jit_scanner STATIC
    src/pattern_v5.cpp
    src/policy_config.cpp
)
add_library(bpf_jit_scanner::scanner ALIAS bpf_jit_scanner)

set_target_properties(bpf_jit_scanner PROPERTIES
    OUTPUT_NAME scanner
    EXPORT_NAME scanner
)

target_compile_features(bpf_jit_scanner PUBLIC cxx_std_20)

target_include_directories(bpf_jit_scanner
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(bpf_jit_scanner PUBLIC yaml-cpp)

target_compile_options(bpf_jit_scanner PRIVATE
    -Wall -Wextra -Wpedantic
    -Wno-unused-parameter
)

# --------------------------------------------------------------------
# CLI tool: bpf-jit-scanner
# --------------------------------------------------------------------

if(BPF_JIT_SCANNER_BUILD_CLI)
    pkg_check_modules(LIBBPF REQUIRED IMPORTED_TARGET libbpf)
    add_executable(bpf-jit-scanner src/cli.cpp)
    target_link_libraries(bpf-jit-scanner PRIVATE bpf_jit_scanner PkgConfig::LIBBPF)
    target_compile_options(bpf-jit-scanner PRIVATE
        -Wall -Wextra
        -Wno-unused-parameter
    )
endif()

# --------------------------------------------------------------------
# Tests
# --------------------------------------------------------------------

if(BPF_JIT_SCANNER_BUILD_TESTS)
    enable_testing()

    add_executable(test_scanner tests/test_scanner.cpp)
    target_link_libraries(test_scanner PRIVATE bpf_jit_scanner)
    target_compile_options(test_scanner PRIVATE -Wall -Wextra -Wno-unused-parameter)

    add_test(NAME unit_tests COMMAND test_scanner)
endif()

# --------------------------------------------------------------------
# Install rules (optional)
# --------------------------------------------------------------------

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS bpf_jit_scanner
    EXPORT bpf_jit_scannerTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES
    include/bpf_jit_scanner/pattern_v5.hpp
    include/bpf_jit_scanner/policy_config.hpp
    include/bpf_jit_scanner/types.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/bpf_jit_scanner
)

if(BPF_JIT_SCANNER_BUILD_CLI)
    install(TARGETS bpf-jit-scanner
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endif()

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/bpf_jit_scannerConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/bpf_jit_scannerConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/bpf_jit_scannerConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/bpf_jit_scanner"
)

install(EXPORT bpf_jit_scannerTargets
    FILE bpf_jit_scannerTargets.cmake
    NAMESPACE bpf_jit_scanner::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/bpf_jit_scanner"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/bpf_jit_scannerConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/bpf_jit_scannerConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/bpf_jit_scanner"
)
