#!/bin/bash
# usage: build-loader.sh <build-dir>; configuration of C's af422c391 runtime loader build
set -e
B=$1; R=/workspaces/repository
cmake -S $R/kprog/libnativeloader -B $B -DNATIVE_LOADER_REPO_ROOT=$R \
  -DNATIVE_LOADER_LIBBPF_PREFIX=$R/runner/build-llvmbpf/vendor/libbpf/prefix \
  -DNATIVE_LOADER_LIBBPF_LIBRARY=$R/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
  -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=/var/tmp/kprog-tmp/C/stock-entry/loader-offsets
taskset -c 8-19 cmake --build $B --target native_loader native_loader_shared trusted-native-loader -j 6
echo BUILD_DONE
