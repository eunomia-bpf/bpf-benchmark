cmake_minimum_required(VERSION 3.16)
project(bpfopt_llvm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SPDLOG REQUIRED IMPORTED_TARGET spdlog)

llvm_map_components_to_libnames(LLVM_LIBS
  core
  support
  target
  analysis
  ipo
  transformutils
  bitreader
  asmparser
  linker
  mc
  mcparser
  mcdisassembler
  object
  executionengine
  runtimedyld
  orcjit
  mcjit
  native
  bpf
  x86
  aarch64
)

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
target_link_libraries(llvmbpf_vm PUBLIC PkgConfig::SPDLOG ${LLVM_LIBS})

add_executable(bpfopt-llvm src/main.cpp)
set_target_properties(bpfopt-llvm PROPERTIES OUTPUT_NAME bpfopt)
target_include_directories(bpfopt-llvm PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(bpfopt-llvm PRIVATE ${LLVM_DEFINITIONS})
target_link_libraries(bpfopt-llvm PRIVATE llvmbpf_vm ${LLVM_LIBS})
