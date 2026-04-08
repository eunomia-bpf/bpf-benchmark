#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
BUILD_DIR="${ARM64_HOST_RUNNER_BUILD_DIR:-$HOST_CACHE_ROOT/runner-host-cross/build}"
OUTPUT_DIR="${ARM64_HOST_RUNNER_OUTPUT_DIR:-$HOST_CACHE_ROOT/runner-host-cross/output}"
OUTPUT_BINARY="${ARM64_HOST_RUNNER_BINARY:-$OUTPUT_DIR/micro_exec}"
CROSS_CC_BIN="${ARM64_HOST_RUNNER_CC:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}gcc}"
CROSS_CXX_BIN="${ARM64_HOST_RUNNER_CXX:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}g++}"
CROSS_AR_BIN="${ARM64_HOST_RUNNER_AR:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}ar}"
PKG_CONFIG_BIN="${ARM64_HOST_RUNNER_PKG_CONFIG:-pkg-config}"
MICRO_EXEC_ENABLE_LLVMBPF="${MICRO_EXEC_ENABLE_LLVMBPF:-OFF}"
SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$HOST_CACHE_ROOT/sysroot}"
SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$HOST_CACHE_ROOT/sysroot.lock}"
SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-ec2-user}"
SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-}"
SYSROOT_USR_LIB_DIR="$SYSROOT_ROOT/usr/lib"
SYSROOT_LIB_DIR="$SYSROOT_ROOT/usr/lib64"
SYSROOT_LEGACY_LIB_DIR="$SYSROOT_ROOT/lib"
SYSROOT_ALT_LIB_DIR="$SYSROOT_ROOT/lib64"
TOOLCHAIN_BIN_DIR="$OUTPUT_DIR/toolchain/bin"
CC_WRAPPER="$TOOLCHAIN_BIN_DIR/aarch64-linux-gnu-gcc-sysroot"
CXX_WRAPPER="$TOOLCHAIN_BIN_DIR/aarch64-linux-gnu-g++-sysroot"
PKG_CONFIG_WRAPPER="$TOOLCHAIN_BIN_DIR/pkg-config"

log() {
    printf '[arm64-runner-host] %s\n' "$*" >&2
}

die() {
    printf '[arm64-runner-host][ERROR] %s\n' "$*" >&2
    exit 1
}

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

require_command cmake
require_command make
require_command file
require_command "$CROSS_CC_BIN"
require_command "$CROSS_CXX_BIN"
require_command "$CROSS_AR_BIN"
require_command "$PKG_CONFIG_BIN"

if [[ "$MICRO_EXEC_ENABLE_LLVMBPF" == "ON" ]]; then
    die "host ARM64 runner cross-build does not support MICRO_EXEC_ENABLE_LLVMBPF=ON yet"
fi

ARM64_SYSROOT_ROOT="$SYSROOT_ROOT" \
ARM64_SYSROOT_LOCK_FILE="$SYSROOT_LOCK_FILE" \
ARM64_SYSROOT_REMOTE_HOST="$SYSROOT_REMOTE_HOST" \
ARM64_SYSROOT_REMOTE_USER="$SYSROOT_REMOTE_USER" \
ARM64_SYSROOT_SSH_KEY_PATH="$SYSROOT_SSH_KEY_PATH" \
    bash "$ROOT_DIR/runner/scripts/prepare-arm64-sysroot.sh" >/dev/null

mkdir -p "$BUILD_DIR" "$OUTPUT_DIR" "$TOOLCHAIN_BIN_DIR"
cat >"$CC_WRAPPER" <<EOF
#!/usr/bin/env bash
exec "$CROSS_CC_BIN" --sysroot="$SYSROOT_ROOT" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
cat >"$CXX_WRAPPER" <<EOF
#!/usr/bin/env bash
exec "$CROSS_CXX_BIN" --sysroot="$SYSROOT_ROOT" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
cat >"$PKG_CONFIG_WRAPPER" <<EOF
#!/usr/bin/env bash
export PKG_CONFIG_SYSROOT_DIR="$SYSROOT_ROOT"
export PKG_CONFIG_LIBDIR="$SYSROOT_ROOT/usr/lib64/pkgconfig:$SYSROOT_ROOT/usr/lib/pkgconfig"
exec "$PKG_CONFIG_BIN" "\$@"
EOF
chmod +x "$CC_WRAPPER" "$CXX_WRAPPER" "$PKG_CONFIG_WRAPPER"

log "Building ARM64 runner on host"
CC="$CC_WRAPPER" \
CXX="$CXX_WRAPPER" \
AR="$CROSS_AR_BIN" \
PKG_CONFIG="$PKG_CONFIG_WRAPPER" \
MICRO_EXEC_ENABLE_LLVMBPF=OFF \
    make -C "$ROOT_DIR/runner" \
        BUILD_DIR="$BUILD_DIR" \
        JOBS=1 \
        micro_exec >/dev/null

cp "$BUILD_DIR/micro_exec" "$OUTPUT_BINARY"
file "$OUTPUT_BINARY" | grep -F "ARM aarch64" >/dev/null \
    || die "host runner cross-build did not produce an ARM64 binary: ${OUTPUT_BINARY}"
