#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
JOBS="${ARM64_CROSSBUILD_JOBS:-4}"
TEST_MODE="$(printf '%s' "${ARM64_TEST_MODE:-test}" | tr '[:upper:]' '[:lower:]')"
ARTIFACTS_ROOT="${ARM64_TEST_ARTIFACTS_ROOT:-$HOST_CACHE_ROOT/test-artifacts}"
UNITTEST_BUILD_DIR="${ARM64_TEST_UNITTEST_BUILD_DIR:-${ARTIFACTS_ROOT}/unittest/build-arm64}"
NEGATIVE_BUILD_DIR="${ARM64_TEST_NEGATIVE_BUILD_DIR:-${ARTIFACTS_ROOT}/negative/build-arm64}"
DAEMON_OUTPUT_DIR="${ARM64_TEST_DAEMON_OUTPUT_DIR:-${ARTIFACTS_ROOT}/daemon}"
UPSTREAM_SELFTEST_OUTPUT_DIR="${ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR:-${ARTIFACTS_ROOT}/upstream-bpf-selftests}"
UPSTREAM_SELFTEST_LLVM_SUFFIX="${ARM64_UPSTREAM_SELFTEST_LLVM_SUFFIX:-}"
PREBUILT_DAEMON_BINARY="${ARM64_TEST_PREBUILT_DAEMON_BINARY:-}"
VMLINUX_BTF="${VMLINUX_BTF:-}"
HOST_PYTHON_BIN="${ARM64_HOST_PYTHON_BIN:-python3}"
SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$HOST_CACHE_ROOT/sysroot}"
SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$HOST_CACHE_ROOT/sysroot.lock}"
SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-ec2-user}"
SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-}"
SYSROOT_USR_LIB_DIR="$SYSROOT_ROOT/usr/lib"
SYSROOT_LIB_DIR="$SYSROOT_ROOT/usr/lib64"
SYSROOT_LEGACY_LIB_DIR="$SYSROOT_ROOT/lib"
SYSROOT_ALT_LIB_DIR="$SYSROOT_ROOT/lib64"
SYSROOT_PKGCONFIG_LIBDIR="$SYSROOT_USR_LIB_DIR/pkgconfig:$SYSROOT_LIB_DIR/pkgconfig:$SYSROOT_LEGACY_LIB_DIR/pkgconfig:$SYSROOT_ALT_LIB_DIR/pkgconfig:$SYSROOT_ROOT/usr/share/pkgconfig"
CROSS_CC_BIN="${ARM64_HOST_TEST_CC:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}gcc}"
TOOLCHAIN_BIN_DIR="${ARTIFACTS_ROOT}/toolchain/bin"
SYSROOT_CC_WRAPPER="$TOOLCHAIN_BIN_DIR/aarch64-linux-gnu-gcc-sysroot"
PREFERRED_CLANG="${ARM64_HOST_TEST_BPF_CLANG:-}"

log() {
    printf '[arm64-repo-tests-host] %s\n' "$*" >&2
}

die() {
    printf '[arm64-repo-tests-host][ERROR] %s\n' "$*" >&2
    exit 1
}

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

resolve_clang() {
    local candidate
    if [[ -n "$PREFERRED_CLANG" ]]; then
        command -v "$PREFERRED_CLANG" >/dev/null 2>&1 || die "requested clang is missing: ${PREFERRED_CLANG}"
        printf '%s\n' "$PREFERRED_CLANG"
        return 0
    fi
    for candidate in clang-20 clang; do
        if command -v "$candidate" >/dev/null 2>&1; then
            printf '%s\n' "$candidate"
            return 0
        fi
    done
    die "missing clang for ARM64 repo-owned test build"
}

copy_optional_libs() {
    local lib_dir="$1"
    local pattern
    mkdir -p "$UNITTEST_BUILD_DIR/lib"
    for pattern in libelf.so* libz.so* libzstd.so*; do
        for path in "$lib_dir"/$pattern; do
            [[ -e "$path" ]] || continue
            cp -a "$path" "$UNITTEST_BUILD_DIR/lib/"
        done
    done
}

prepare_cc_wrapper() {
    mkdir -p "$TOOLCHAIN_BIN_DIR"
cat >"$SYSROOT_CC_WRAPPER" <<EOF
#!/usr/bin/env bash
exec "$CROSS_CC_BIN" --sysroot="$SYSROOT_ROOT" \
    -isystem "$SYSROOT_ROOT/usr/include" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
    chmod +x "$SYSROOT_CC_WRAPPER"
}

case "$TEST_MODE" in
    selftest)
        NEED_UNITTEST=1
        NEED_NEGATIVE=1
        NEED_DAEMON=1
        NEED_UPSTREAM=1
        ;;
    negative)
        NEED_UNITTEST=0
        NEED_NEGATIVE=1
        NEED_DAEMON=0
        NEED_UPSTREAM=0
        ;;
    test)
        NEED_UNITTEST=1
        NEED_NEGATIVE=1
        NEED_DAEMON=1
        NEED_UPSTREAM=1
        ;;
    *)
        die "unsupported ARM64_TEST_MODE: $TEST_MODE"
        ;;
esac

require_command make
require_command file
require_command "$HOST_PYTHON_BIN"
require_command "$CROSS_CC_BIN"
CLANG_BIN="$(resolve_clang)"

if [[ "$NEED_UNITTEST" -eq 1 || "$NEED_NEGATIVE" -eq 1 ]]; then
    if [[ "$NEED_UNITTEST" -eq 1 ]]; then
        [[ -n "$VMLINUX_BTF" ]] || die "VMLINUX_BTF is required for ARM64 unittest host build"
        [[ -f "$VMLINUX_BTF" ]] || die "missing ARM64 kernel BTF image: $VMLINUX_BTF"
        VMLINUX_BTF="$(realpath "$VMLINUX_BTF")"
    fi
    ARM64_SYSROOT_ROOT="$SYSROOT_ROOT" \
    ARM64_SYSROOT_LOCK_FILE="$SYSROOT_LOCK_FILE" \
    ARM64_SYSROOT_REMOTE_HOST="$SYSROOT_REMOTE_HOST" \
    ARM64_SYSROOT_REMOTE_USER="$SYSROOT_REMOTE_USER" \
    ARM64_SYSROOT_SSH_KEY_PATH="$SYSROOT_SSH_KEY_PATH" \
        bash "$ROOT_DIR/runner/scripts/prepare-arm64-sysroot.sh" >/dev/null
fi

rm -rf "$UNITTEST_BUILD_DIR" "$NEGATIVE_BUILD_DIR" "$DAEMON_OUTPUT_DIR"
rm -rf "$UPSTREAM_SELFTEST_OUTPUT_DIR"
mkdir -p "$UNITTEST_BUILD_DIR/lib" "$NEGATIVE_BUILD_DIR" "$DAEMON_OUTPUT_DIR"
prepare_cc_wrapper

if [[ "$NEED_UNITTEST" -eq 1 ]]; then
    log "Building ARM64 repo-owned unittest binaries on host"
    make -C "$ROOT_DIR/tests/unittest" \
        BUILD_DIR="$UNITTEST_BUILD_DIR" \
        CC="$SYSROOT_CC_WRAPPER" \
        CLANG="$CLANG_BIN" \
        VMLINUX_BTF="$VMLINUX_BTF" \
        "HOST_EXT_LIBS=-L${SYSROOT_USR_LIB_DIR} -L${SYSROOT_LIB_DIR} -L${SYSROOT_LEGACY_LIB_DIR} -L${SYSROOT_ALT_LIB_DIR} -Wl,-rpath-link,${SYSROOT_USR_LIB_DIR} -Wl,-rpath-link,${SYSROOT_LIB_DIR} -Wl,-rpath-link,${SYSROOT_LEGACY_LIB_DIR} -Wl,-rpath-link,${SYSROOT_ALT_LIB_DIR} -lelf -lz -lzstd" \
        clean >/dev/null
    make -C "$ROOT_DIR/tests/unittest" -j"$JOBS" \
        BUILD_DIR="$UNITTEST_BUILD_DIR" \
        CC="$SYSROOT_CC_WRAPPER" \
        CLANG="$CLANG_BIN" \
        VMLINUX_BTF="$VMLINUX_BTF" \
        "HOST_EXT_LIBS=-L${SYSROOT_USR_LIB_DIR} -L${SYSROOT_LIB_DIR} -L${SYSROOT_LEGACY_LIB_DIR} -L${SYSROOT_ALT_LIB_DIR} -Wl,-rpath-link,${SYSROOT_USR_LIB_DIR} -Wl,-rpath-link,${SYSROOT_LIB_DIR} -Wl,-rpath-link,${SYSROOT_LEGACY_LIB_DIR} -Wl,-rpath-link,${SYSROOT_ALT_LIB_DIR} -lelf -lz -lzstd" \
        all >/dev/null
    copy_optional_libs "$SYSROOT_LIB_DIR"
    copy_optional_libs "$SYSROOT_USR_LIB_DIR"
    copy_optional_libs "$SYSROOT_ALT_LIB_DIR"
    copy_optional_libs "$SYSROOT_LEGACY_LIB_DIR"
fi

if [[ "$NEED_NEGATIVE" -eq 1 ]]; then
    log "Building ARM64 repo-owned negative binaries on host"
    make -C "$ROOT_DIR/tests/negative" \
        BUILD_DIR="$NEGATIVE_BUILD_DIR" \
        CC="$SYSROOT_CC_WRAPPER" \
        clean >/dev/null
    make -C "$ROOT_DIR/tests/negative" -j"$JOBS" \
        BUILD_DIR="$NEGATIVE_BUILD_DIR" \
        CC="$SYSROOT_CC_WRAPPER" \
        all >/dev/null
fi

if [[ "$NEED_DAEMON" -eq 1 ]]; then
    [[ -n "$PREBUILT_DAEMON_BINARY" ]] || die "missing ARM64_TEST_PREBUILT_DAEMON_BINARY"
    [[ -f "$PREBUILT_DAEMON_BINARY" ]] || die "missing prebuilt ARM64 daemon binary: $PREBUILT_DAEMON_BINARY"
    PREBUILT_DAEMON_BINARY="$(realpath "$PREBUILT_DAEMON_BINARY")"
    cp "$PREBUILT_DAEMON_BINARY" "$DAEMON_OUTPUT_DIR/bpfrejit-daemon"
fi

if [[ "$NEED_UPSTREAM" -eq 1 ]]; then
    log "Building ARM64 upstream selftests on host"
    UPSTREAM_SELFTEST_SOURCE_DIR="$ROOT_DIR/vendor/linux-framework/tools/testing/selftests/bpf" \
    UPSTREAM_SELFTEST_OUTPUT_DIR="$UPSTREAM_SELFTEST_OUTPUT_DIR" \
    UPSTREAM_SELFTEST_HOST_PYTHON_BIN="$HOST_PYTHON_BIN" \
    UPSTREAM_SELFTEST_ARCH="arm64" \
    UPSTREAM_SELFTEST_CROSS_COMPILE="${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}" \
    UPSTREAM_SELFTEST_SYSROOT_ROOT="$SYSROOT_ROOT" \
    UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR="$SYSROOT_PKGCONFIG_LIBDIR" \
    UPSTREAM_SELFTEST_LLVM_SUFFIX="$UPSTREAM_SELFTEST_LLVM_SUFFIX" \
    VMLINUX_BTF="$VMLINUX_BTF" \
        bash "$ROOT_DIR/runner/scripts/build_upstream_selftests.sh" >/dev/null
fi

if [[ "$NEED_UNITTEST" -eq 1 ]]; then
    file "$UNITTEST_BUILD_DIR/rejit_kinsn" | grep -F "ARM aarch64" >/dev/null \
        || die "host unittest cross-build did not produce ARM64 binaries"
fi
if [[ "$NEED_NEGATIVE" -eq 1 ]]; then
    file "$NEGATIVE_BUILD_DIR/adversarial_rejit" | grep -F "ARM aarch64" >/dev/null \
        || die "host negative cross-build did not produce ARM64 binaries"
fi
if [[ "$NEED_DAEMON" -eq 1 ]]; then
    file "$DAEMON_OUTPUT_DIR/bpfrejit-daemon" | grep -F "ARM aarch64" >/dev/null \
        || die "prebuilt daemon copy is not ARM64"
fi
if [[ "$NEED_UPSTREAM" -eq 1 ]]; then
    file "$UPSTREAM_SELFTEST_OUTPUT_DIR/test_verifier" | grep -F "ARM aarch64" >/dev/null \
        || die "host upstream test_verifier build did not produce ARM64 binaries"
    file "$UPSTREAM_SELFTEST_OUTPUT_DIR/test_progs" | grep -F "ARM aarch64" >/dev/null \
        || die "host upstream test_progs build did not produce ARM64 binaries"
fi
