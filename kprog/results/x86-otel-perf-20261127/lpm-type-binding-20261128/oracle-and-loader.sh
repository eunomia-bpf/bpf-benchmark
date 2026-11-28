#!/bin/bash
set -eu
cd /workspaces/repository
RAW=/workspaces/kprog-raw/perf/lpm-type-binding-20261128
TMP=/var/tmp/kprog-tmp/perf/lpm-c-lto
exec 9>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 9
exec 8>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 8
ulimit -v 50331648
mkdir -p "$RAW" "$TMP"
clang++-18 -std=c++17 -Irunner/build-llvmbpf/vendor/libbpf/prefix/include -Ivendor/libbpf/include/uapi kprog/results/lpm-c-lto-20261120/layout.cpp runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o "$TMP/layout"
"$TMP/layout" /workspaces/.agent-state/kprog-ck/build-x86/vmlinux > "$RAW/layout.json"
clang-18 -O3 -march=native -mno-red-zone -mgeneral-regs-only -mllvm -x86-cmov-converter-force-all -fPIC -fomit-frame-pointer -fno-stack-protector -Xclang -fembed-bitcode=all -c kprog/results/lpm-c-lto-20261120/fixture.c -o "$TMP/fixture.o"
python3 kprog/results/lpm-c-lto-20261120/check.py "$RAW" "$TMP"
cmake --build runner/build-llvmbpf --target native_loader_shared -j2
strip --strip-unneeded runner/build-llvmbpf/native_loader/libnative_loader.so
