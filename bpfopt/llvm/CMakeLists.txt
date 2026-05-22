cmake_minimum_required(VERSION 3.16)
project(bpfopt_llvm LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SPDLOG REQUIRED IMPORTED_TARGET spdlog)

# Resolve LLVM component libraries via the CMake config package rather than
# shelling out to llvm-config: the in-repo kinsn LLVM build does not ship a
# working llvm-config, and the component targets carry their own transitive
# system-lib dependencies (zlib, zstd, etc.).
# bpfopt-llvm emits BPF object code (BPF backend mandatory). The host backend
# is added when the LLVM build has it — the umbrella component names (x86 /
# aarch64) are not in this config's component map, so list the per-target libs
# explicitly (as for bpf*).
set(BPFOPT_LLVM_COMPONENTS
  core support target analysis ipo transformutils passes bitreader
  asmparser linker mc mcparser mcdisassembler object executionengine
  runtimedyld orcjit mcjit
  bpfcodegen bpfasmparser bpfdisassembler bpfdesc bpfinfo
)
if("X86" IN_LIST LLVM_TARGETS_TO_BUILD)
  list(APPEND BPFOPT_LLVM_COMPONENTS
    x86codegen x86asmparser x86desc x86disassembler x86info)
endif()
if("AArch64" IN_LIST LLVM_TARGETS_TO_BUILD)
  list(APPEND BPFOPT_LLVM_COMPONENTS
    aarch64codegen aarch64asmparser aarch64desc aarch64disassembler
    aarch64info aarch64utils)
endif()
llvm_map_components_to_libnames(LLVM_LINK_FLAGS ${BPFOPT_LLVM_COMPONENTS})

# Match the LLVM build's RTTI setting; the in-repo kinsn LLVM is built without
# RTTI, so compiling our translation units with RTTI on leaves typeinfo symbols
# (ErrorInfoBase, format_adapter) unresolved at link time.
if(NOT LLVM_ENABLE_RTTI)
  add_compile_options(-fno-rtti)
endif()

set(LLVMBPF_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/llvmbpf")

add_library(llvmbpf_vm STATIC
  "${LLVMBPF_DIR}/src/llvm_jit_context.cpp"
  "${LLVMBPF_DIR}/src/compiler.cpp"
  "${LLVMBPF_DIR}/src/compiler_utils.cpp"
  "${LLVMBPF_DIR}/src/vm.cpp"
)
target_include_directories(llvmbpf_vm
  PUBLIC
    "${LLVMBPF_DIR}/include"
  PRIVATE
    "${LLVMBPF_DIR}/src"
    ${LLVM_INCLUDE_DIRS}
)
target_compile_definitions(llvmbpf_vm PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_WARN)
target_link_libraries(llvmbpf_vm PUBLIC PkgConfig::SPDLOG ${LLVM_LINK_FLAGS})

add_executable(bpfopt-llvm src/main.cpp)
set_target_properties(bpfopt-llvm PROPERTIES OUTPUT_NAME bpfopt)
target_include_directories(bpfopt-llvm
  PRIVATE
    "${LLVMBPF_DIR}/include"
    "${LLVMBPF_DIR}/src"
    ${LLVM_INCLUDE_DIRS}
)
target_compile_definitions(bpfopt-llvm PRIVATE ${LLVM_DEFINITIONS})
target_link_libraries(bpfopt-llvm PRIVATE llvmbpf_vm ${LLVM_LINK_FLAGS})
