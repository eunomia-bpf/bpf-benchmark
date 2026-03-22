#!/bin/bash
# Cross-build ARM64 kernel selftest (test_recompile) inside Docker.
# Called by `make selftest-arm64` with /workspace mounted to repo root.
#
# Environment variables:
#   ARM64_SELFTEST_GUEST_ROOT - guest-side root for test_recompile paths
set -eu -o pipefail

GUEST_ROOT="${ARM64_SELFTEST_GUEST_ROOT:-/mnt/tests/kernel}"

make -C "/workspace/tests/kernel" \
    RUNNER_BUILD_DIR="/workspace/tests/kernel/build-arm64" \
    BPF_BUILD_DIR="/workspace/tests/kernel/build" \
    LIBBPF_BUILD_DIR="/workspace/tests/kernel/build-arm64/vendor/libbpf" \
    TEST_KERNEL_ROOT="$GUEST_ROOT" \
    CC=gcc AR=ar \
    CFLAGS="-O2 -g -Wall -Wextra -no-pie" \
    PKG_CONFIG=pkg-config \
    "/workspace/tests/kernel/build-arm64/test_recompile"

cp -L /usr/lib64/libelf.so.1 "/workspace/tests/kernel/build-arm64/lib/libelf.so.1"
cp -L /usr/lib64/libz.so.1 "/workspace/tests/kernel/build-arm64/lib/libz.so.1"
cp -L /usr/lib64/libzstd.so.1 "/workspace/tests/kernel/build-arm64/lib/libzstd.so.1"
