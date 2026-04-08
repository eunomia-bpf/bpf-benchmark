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

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBELF REQUIRED IMPORTED_TARGET libelf)
pkg_check_modules(ZLIB REQUIRED IMPORTED_TARGET zlib)
pkg_check_modules(YAMLCPP REQUIRED IMPORTED_TARGET yaml-cpp)

add_library(vendor_libbpf STATIC IMPORTED GLOBAL)
set_target_properties(vendor_libbpf PROPERTIES
    IMPORTED_LOCATION "${MICRO_LIBBPF_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${MICRO_LIBBPF_PREFIX}/include;${MICRO_REPO_ROOT}/vendor/libbpf/include;${MICRO_REPO_ROOT}/vendor/libbpf/include/uapi"
)

set(MICRO_EXEC_SOURCES
    src/bpf_helpers.cpp
    src/common.cpp
    src/elf_program_loader.cpp
    src/kernel_runner.cpp
    src/main.cpp
    src/perf_counters.cpp
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    if(NOT DEFINED MICRO_LLVMBPF_LIBRARY OR "${MICRO_LLVMBPF_LIBRARY}" STREQUAL "")
        message(FATAL_ERROR "MICRO_EXEC_ENABLE_LLVMBPF=ON requires explicit MICRO_LLVMBPF_LIBRARY")
    endif()
    if(NOT EXISTS "${MICRO_LLVMBPF_LIBRARY}")
        message(FATAL_ERROR "MICRO_EXEC_ENABLE_LLVMBPF=ON requires ${MICRO_LLVMBPF_LIBRARY}")
    endif()
    if(NOT DEFINED LLVM_DIR OR "${LLVM_DIR}" STREQUAL "")
        message(FATAL_ERROR "MICRO_EXEC_ENABLE_LLVMBPF=ON requires explicit LLVM_DIR")
    endif()

    add_library(vendor_llvmbpf STATIC IMPORTED GLOBAL)
    set_target_properties(vendor_llvmbpf PROPERTIES
        IMPORTED_LOCATION "${MICRO_LLVMBPF_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${MICRO_REPO_ROOT}/vendor/llvmbpf/include;${MICRO_REPO_ROOT}/vendor/llvmbpf/src"
    )
    find_package(LLVM REQUIRED CONFIG PATHS "${LLVM_DIR}" NO_DEFAULT_PATH)

    # Keep this list aligned with vendor/llvmbpf/CMakeLists.txt so host-cross
    # builds can link against target LLVM libraries without executing a target
    # llvm-config binary on the host.
    set(MICRO_EXEC_LLVM_COMPONENTS
        ${LLVM_TARGETS_TO_BUILD}
        Core
        Support
        Target
        Analysis
        ipo
        TransformUtils
        BitReader
        AsmParser
        Linker
        MC
        MCParser
        MCDisassembler
        Object
        ExecutionEngine
        RuntimeDyld
        OrcJIT
        MCJIT
        X86CodeGen
        X86Desc
        X86Info
        X86AsmParser
        NVPTXCodeGen
        NVPTXDesc
        NVPTXInfo
        AArch64CodeGen
        AArch64Desc
        AArch64Info
        AArch64AsmParser
    )
    llvm_map_components_to_libnames(MICRO_EXEC_LLVM_LIBS ${MICRO_EXEC_LLVM_COMPONENTS})

    set(MICRO_LLVMBPF_SPDLOG_LIBRARY "")
    if(DEFINED MICRO_LLVMBPF_SPDLOG_LIBRARY AND NOT "${MICRO_LLVMBPF_SPDLOG_LIBRARY}" STREQUAL "")
        if(NOT EXISTS "${MICRO_LLVMBPF_SPDLOG_LIBRARY}")
            message(FATAL_ERROR "MICRO_LLVMBPF_SPDLOG_LIBRARY is missing: ${MICRO_LLVMBPF_SPDLOG_LIBRARY}")
        endif()
    elseif(DEFINED MICRO_LLVMBPF_BUILD_CACHE AND NOT "${MICRO_LLVMBPF_BUILD_CACHE}" STREQUAL "")
        get_filename_component(MICRO_LLVMBPF_BUILD_DIR "${MICRO_LLVMBPF_BUILD_CACHE}" DIRECTORY)
        foreach(
            SPDLOG_CANDIDATE
            "${MICRO_LLVMBPF_BUILD_DIR}/_deps/spdlog-build/libspdlogd.a"
            "${MICRO_LLVMBPF_BUILD_DIR}/_deps/spdlog-build/libspdlog.a"
        )
            if(EXISTS "${SPDLOG_CANDIDATE}")
                set(MICRO_LLVMBPF_SPDLOG_LIBRARY "${SPDLOG_CANDIDATE}")
                break()
            endif()
        endforeach()
    endif()
    if(MICRO_LLVMBPF_SPDLOG_LIBRARY)
        add_library(vendor_llvmbpf_spdlog STATIC IMPORTED GLOBAL)
        set_target_properties(vendor_llvmbpf_spdlog PROPERTIES
            IMPORTED_LOCATION "${MICRO_LLVMBPF_SPDLOG_LIBRARY}"
        )
    else()
        pkg_check_modules(SPDLOG REQUIRED IMPORTED_TARGET spdlog)
    endif()

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
    target_compile_definitions(micro_exec PRIVATE MICRO_EXEC_ENABLE_LLVMBPF=1)
    target_include_directories(
        micro_exec
        PRIVATE
            "${MICRO_REPO_ROOT}/vendor/llvmbpf/include"
            "${MICRO_REPO_ROOT}/vendor/llvmbpf/src"
    )
endif()

target_link_libraries(micro_exec
    PRIVATE
        vendor_libbpf
        PkgConfig::LIBELF
        PkgConfig::ZLIB
        PkgConfig::YAMLCPP
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    target_link_libraries(micro_exec
        PRIVATE
            vendor_llvmbpf
            ${MICRO_EXEC_LLVM_LIBS}
    )
    if(TARGET vendor_llvmbpf_spdlog)
        target_link_libraries(micro_exec PRIVATE vendor_llvmbpf_spdlog)
    else()
        target_link_libraries(micro_exec PRIVATE PkgConfig::SPDLOG)
    endif()
endif()
