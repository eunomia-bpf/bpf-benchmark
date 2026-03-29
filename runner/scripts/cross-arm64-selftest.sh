#!/bin/bash
# Cross-build the current ARM64 selftest suite inside Docker.
# Called by `make selftest-arm64` with /workspace mounted to repo root.
#
# The current repo no longer uses tests/kernel/test_recompile. ARM64 selftest
# now consists of:
#   - tests/unittest (all rejit_* binaries + BPF fixtures)
#   - tests/negative (adversarial/fuzz helpers)
set -euo pipefail

JOBS="${ARM64_CROSSBUILD_JOBS:-4}"
UNITTEST_BUILD_DIR="/workspace/tests/unittest/build-arm64"
NEGATIVE_BUILD_DIR="/workspace/tests/negative/build-arm64"

rm -rf "$UNITTEST_BUILD_DIR" "$NEGATIVE_BUILD_DIR"
mkdir -p "$UNITTEST_BUILD_DIR/lib" "$NEGATIVE_BUILD_DIR"

if [ ! -d "/workspace/tests/unittest/build/progs" ]; then
    echo "missing host-built BPF fixtures: /workspace/tests/unittest/build/progs" >&2
    exit 1
fi

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
    "${UNITTEST_TARGETS[@]}"

rm -rf "$UNITTEST_BUILD_DIR/progs"
cp -a /workspace/tests/unittest/build/progs "$UNITTEST_BUILD_DIR/"

make -C "/workspace/tests/negative" -j"$JOBS" \
    BUILD_DIR="$NEGATIVE_BUILD_DIR" \
    CC=gcc \
    all

copy_runtime_libs() {
    local binary="$1"
    local lib

    while read -r lib; do
        case "$(basename "$lib")" in
            libelf.so*|libz.so*|libzstd.so*)
                cp -L "$lib" "$UNITTEST_BUILD_DIR/lib/"
                ;;
        esac
    done < <(ldd "$binary" | awk '/=> \// {print $3} /^\// {print $1}' | sort -u)
}

for binary in "$UNITTEST_BUILD_DIR"/rejit_* "$NEGATIVE_BUILD_DIR"/*; do
    [ -x "$binary" ] || continue
    copy_runtime_libs "$binary"
done

file "$UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "ARM aarch64"
file "$NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "ARM aarch64"
