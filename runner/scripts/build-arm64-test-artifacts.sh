#!/bin/bash
# Cross-build the current ARM64 repo-owned test artifacts inside Docker.
# Called by `make arm64-test-artifacts` with /workspace mounted to repo root.
#
# The current repo no longer uses tests/kernel/test_recompile. ARM64 selftest
# now consists of:
#   - tests/unittest (all rejit_* binaries + BPF fixtures)
#   - tests/negative (adversarial/fuzz helpers)
set -euo pipefail

JOBS="${ARM64_CROSSBUILD_JOBS:-4}"
ARTIFACTS_ROOT="${ARM64_TEST_ARTIFACTS_ROOT:-/workspace/.cache/aws-arm64/test-artifacts}"
UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-${ARTIFACTS_ROOT}/unittest/build-arm64}"
NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-${ARTIFACTS_ROOT}/negative/build-arm64}"
UPSTREAM_SELFTEST_SOURCE_DIR="${ARM64_UPSTREAM_SELFTEST_SOURCE_DIR:-/workspace/vendor/linux-framework/tools/testing/selftests/bpf}"
UPSTREAM_SELFTEST_OUTPUT_DIR="${ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR:-${ARTIFACTS_ROOT}/upstream-bpf-selftests}"
VMLINUX_BTF="${VMLINUX_BTF:-/workspace/vendor/linux-framework/build-arm64/vmlinux}"
DAEMON_TARGET_DIR="${ARM64_TEST_DAEMON_TARGET_DIR:-${ARTIFACTS_ROOT}/daemon-target}"
DAEMON_OUTPUT_DIR="${ARM64_TEST_DAEMON_OUTPUT_DIR:-${ARTIFACTS_ROOT}/daemon}"
CARGO_HOME_DIR="${ARM64_TEST_CARGO_HOME_DIR:-${ARTIFACTS_ROOT}/cargo-home}"
CARGO_TARGET_LINKER="gcc"
UPSTREAM_SELFTEST_SKEL_BLACKLIST="${UPSTREAM_SELFTEST_SKEL_BLACKLIST:-btf__% test_pinning_invalid.c test_sk_assign.c bpf_smc.c}"

if [ ! -f "$VMLINUX_BTF" ]; then
    echo "missing ARM64 kernel BTF image: $VMLINUX_BTF" >&2
    exit 1
fi

rm -rf "$UNITTEST_BUILD_DIR" "$NEGATIVE_BUILD_DIR"
mkdir -p "$UNITTEST_BUILD_DIR/lib" "$NEGATIVE_BUILD_DIR" "$DAEMON_OUTPUT_DIR" "$CARGO_HOME_DIR"

build_upstream_selftests() {
    UPSTREAM_SELFTEST_SOURCE_DIR="$UPSTREAM_SELFTEST_SOURCE_DIR" \
    UPSTREAM_SELFTEST_OUTPUT_DIR="$UPSTREAM_SELFTEST_OUTPUT_DIR" \
    UPSTREAM_SELFTEST_SKEL_BLACKLIST="$UPSTREAM_SELFTEST_SKEL_BLACKLIST" \
    JOBS="$JOBS" \
    VMLINUX_BTF="$VMLINUX_BTF" \
        /workspace/runner/scripts/build_upstream_selftests.sh
}

mapfile -t UNITTEST_TARGETS < <(
    {
        find /workspace/tests/unittest -maxdepth 1 -name 'rejit_*.c' -printf "$UNITTEST_BUILD_DIR/%f\n"
        find /workspace/tests/unittest/module -maxdepth 1 -name 'rejit_*.c' -printf "$UNITTEST_BUILD_DIR/module/%f\n"
    } | sed 's/\.c$//' | sort
)

make -C "/workspace/tests/unittest" -j"$JOBS" \
    BUILD_DIR="$UNITTEST_BUILD_DIR" \
    CC=gcc \
    PKG_CONFIG=pkg-config \
    VMLINUX_BTF="$VMLINUX_BTF" \
    all \
    "${UNITTEST_TARGETS[@]}"

make -C "/workspace/tests/negative" -j"$JOBS" \
    BUILD_DIR="$NEGATIVE_BUILD_DIR" \
    CC=gcc \
    all

CARGO_HOME="$CARGO_HOME_DIR" \
CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="$CARGO_TARGET_LINKER" \
CARGO_TARGET_DIR="$DAEMON_TARGET_DIR" \
    cargo build \
        --release \
        -j"$JOBS" \
        --manifest-path /workspace/daemon/Cargo.toml

cp "$DAEMON_TARGET_DIR/release/bpfrejit-daemon" "$DAEMON_OUTPUT_DIR/bpfrejit-daemon"
build_upstream_selftests

copy_runtime_libs() {
    local binary="$1"
    local lib

    while read -r lib; do
        case "$(basename "$lib")" in
            ld-linux-aarch64.so*|libc.so*|libm.so*|libpthread.so*|librt.so*|libdl.so*|libresolv.so*|libutil.so*)
                ;;
            libelf.so*|libgcc_s.so*|libstdc++.so*|libyaml-cpp.so*|libz.so*|libzstd.so*)
                cp -L "$lib" "$UNITTEST_BUILD_DIR/lib/"
                ;;
        esac
    done < <(ldd "$binary" | awk '/=> \// {print $3} /^\// {print $1}' | sort -u)
}

for binary in "$UNITTEST_BUILD_DIR"/rejit_* "$NEGATIVE_BUILD_DIR"/* "$DAEMON_OUTPUT_DIR"/bpfrejit-daemon; do
    [ -x "$binary" ] || continue
    copy_runtime_libs "$binary"
done

file "$UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "ARM aarch64"
file "$NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "ARM aarch64"
file "$DAEMON_OUTPUT_DIR/bpfrejit-daemon" | grep -F "ARM aarch64"
file "$UPSTREAM_SELFTEST_OUTPUT_DIR/test_verifier" | grep -F "ARM aarch64"
file "$UPSTREAM_SELFTEST_OUTPUT_DIR/test_progs" | grep -F "ARM aarch64"
