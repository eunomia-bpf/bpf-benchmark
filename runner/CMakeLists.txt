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
set(MICRO_KERNEL_OFFSETS_INCLUDE "${MICRO_REPO_ROOT}/micro/programs/build-x86" CACHE PATH "kernel_offsets.h include directory")

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
    src/native_lab_runner.cpp
    src/native_runner.cpp
    src/perf_counters.cpp
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    if(NOT DEFINED LLVM_DIR OR "${LLVM_DIR}" STREQUAL "")
        message(FATAL_ERROR "MICRO_EXEC_ENABLE_LLVMBPF=ON requires explicit LLVM_DIR")
    endif()

    find_package(LLVM REQUIRED CONFIG PATHS "${LLVM_DIR}" NO_DEFAULT_PATH)
    pkg_check_modules(SPDLOG REQUIRED IMPORTED_TARGET spdlog)

    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|i[3-6]86)$")
        set(MICRO_EXEC_NATIVE_LLVM_TARGET X86)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64)$")
        set(MICRO_EXEC_NATIVE_LLVM_TARGET AArch64)
    else()
        message(FATAL_ERROR "run-llvmbpf does not know the native LLVM target for ${CMAKE_SYSTEM_PROCESSOR}")
    endif()

    if(NOT "${MICRO_EXEC_NATIVE_LLVM_TARGET}" IN_LIST LLVM_TARGETS_TO_BUILD)
        message(FATAL_ERROR
            "run-llvmbpf requires LLVM target ${MICRO_EXEC_NATIVE_LLVM_TARGET}; "
            "selected LLVM at ${LLVM_DIR} was built with LLVM_TARGETS_TO_BUILD=${LLVM_TARGETS_TO_BUILD}. "
            "Set LLVM_DIR/RUN_LLVM_DIR to a full LLVM build or rebuild the selected LLVM with the native target enabled.")
    endif()

    # Keep this list aligned with bpfopt/llvm/CMakeLists.txt so host-cross
    # builds can link against target LLVM libraries without executing a target
    # llvm-config binary on the host. Some LLVM builds are target-limited, so
    # only request host target libraries when the selected LLVM provides them.
    set(MICRO_EXEC_LLVM_COMPONENTS
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
    )
    if("BPF" IN_LIST LLVM_TARGETS_TO_BUILD)
        list(APPEND MICRO_EXEC_LLVM_COMPONENTS
            BPFCodeGen BPFAsmParser BPFDisassembler BPFDesc BPFInfo
        )
    endif()
    if("X86" IN_LIST LLVM_TARGETS_TO_BUILD)
        list(APPEND MICRO_EXEC_LLVM_COMPONENTS
            X86CodeGen X86Desc X86Info X86AsmParser
        )
    endif()
    if("NVPTX" IN_LIST LLVM_TARGETS_TO_BUILD)
        list(APPEND MICRO_EXEC_LLVM_COMPONENTS
            NVPTXCodeGen NVPTXDesc NVPTXInfo
        )
    endif()
    if("AArch64" IN_LIST LLVM_TARGETS_TO_BUILD)
        list(APPEND MICRO_EXEC_LLVM_COMPONENTS
            AArch64CodeGen AArch64Desc AArch64Info AArch64AsmParser
        )
    endif()
    llvm_map_components_to_libnames(MICRO_EXEC_LLVM_LIBS ${MICRO_EXEC_LLVM_COMPONENTS})

    if(NOT LLVM_ENABLE_RTTI)
        add_compile_options(-fno-rtti)
    endif()

    list(APPEND MICRO_EXEC_SOURCES
        src/llvmbpf_runner.cpp
        "${MICRO_REPO_ROOT}/vendor/llvmbpf/src/llvm_jit_context.cpp"
        "${MICRO_REPO_ROOT}/vendor/llvmbpf/src/compiler.cpp"
        "${MICRO_REPO_ROOT}/vendor/llvmbpf/src/compiler_utils.cpp"
        "${MICRO_REPO_ROOT}/vendor/llvmbpf/src/vm.cpp"
    )
endif()

add_executable(micro_exec ${MICRO_EXEC_SOURCES})

target_link_options(micro_exec PRIVATE -static-libstdc++)

target_include_directories(micro_exec
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${MICRO_LIBBPF_PREFIX}/include"
        "${MICRO_REPO_ROOT}/vendor/libbpf/include"
        "${MICRO_REPO_ROOT}/vendor/libbpf/include/uapi"
        "/artifacts/kernel"
        "${MICRO_KERNEL_OFFSETS_INCLUDE}"
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    target_compile_definitions(
        micro_exec
        PRIVATE
            MICRO_EXEC_ENABLE_LLVMBPF=1
            SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO
    )
    target_include_directories(
        micro_exec
        PRIVATE
            "${MICRO_REPO_ROOT}/vendor/llvmbpf/include"
            "${MICRO_REPO_ROOT}/vendor/llvmbpf/src"
            "${LLVM_INCLUDE_DIRS}"
    )
endif()

target_link_libraries(micro_exec
    PRIVATE
        vendor_libbpf
        PkgConfig::LIBELF
        PkgConfig::ZLIB
        PkgConfig::YAMLCPP
        ${CMAKE_DL_LIBS}
)

if(MICRO_EXEC_ENABLE_LLVMBPF)
    target_link_libraries(micro_exec
        PRIVATE
            ${MICRO_EXEC_LLVM_LIBS}
            PkgConfig::SPDLOG
    )
endif()
