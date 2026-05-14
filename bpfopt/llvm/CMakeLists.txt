cmake_minimum_required(VERSION 3.16)
project(bpfopt_llvm LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SPDLOG REQUIRED IMPORTED_TARGET spdlog)

find_program(LLVM_CONFIG_EXECUTABLE
  NAMES llvm-config llvm-config-${LLVM_VERSION_MAJOR}
  HINTS ${LLVM_TOOLS_BINARY_DIR}
)
if(NOT LLVM_CONFIG_EXECUTABLE)
  message(FATAL_ERROR "llvm-config not found")
endif()

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --ldflags --libs --system-libs
          core support target analysis ipo transformutils passes bitreader
          asmparser linker mc mcparser mcdisassembler object executionengine
          runtimedyld orcjit mcjit native bpf x86 aarch64
  OUTPUT_VARIABLE LLVM_LINK_FLAGS_RAW
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
separate_arguments(LLVM_LINK_FLAGS UNIX_COMMAND "${LLVM_LINK_FLAGS_RAW}")

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
