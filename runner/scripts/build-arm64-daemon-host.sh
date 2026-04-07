#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
RUST_TARGET="${ARM64_HOST_DAEMON_RUST_TARGET:-aarch64-unknown-linux-gnu}"
CROSS_LINKER_BIN="${ARM64_HOST_CARGO_LINKER:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}gcc}"
TARGET_DIR="${ARM64_HOST_DAEMON_TARGET_DIR:-$HOST_CACHE_ROOT/daemon-host-cross/target}"
OUTPUT_DIR="${ARM64_HOST_DAEMON_OUTPUT_DIR:-$HOST_CACHE_ROOT/daemon-host-cross/output}"
OUTPUT_BINARY="${ARM64_HOST_DAEMON_BINARY:-$OUTPUT_DIR/bpfrejit-daemon}"
CARGO_HOME_DIR="${ARM64_HOST_DAEMON_CARGO_HOME:-$HOST_CACHE_ROOT/cargo-home-host-daemon}"
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
LINKER_WRAPPER="$TOOLCHAIN_BIN_DIR/aarch64-linux-gnu-gcc-sysroot"

log() {
    printf '[arm64-daemon-host] %s\n' "$*" >&2
}

die() {
    printf '[arm64-daemon-host][ERROR] %s\n' "$*" >&2
    exit 1
}

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

require_command cargo
require_command file
require_command "$CROSS_LINKER_BIN"

ARM64_SYSROOT_ROOT="$SYSROOT_ROOT" \
ARM64_SYSROOT_LOCK_FILE="$SYSROOT_LOCK_FILE" \
ARM64_SYSROOT_REMOTE_HOST="$SYSROOT_REMOTE_HOST" \
ARM64_SYSROOT_REMOTE_USER="$SYSROOT_REMOTE_USER" \
ARM64_SYSROOT_SSH_KEY_PATH="$SYSROOT_SSH_KEY_PATH" \
    bash "$ROOT_DIR/runner/scripts/prepare-arm64-sysroot.sh" >/dev/null

mkdir -p "$TARGET_DIR" "$OUTPUT_DIR" "$CARGO_HOME_DIR" "$TOOLCHAIN_BIN_DIR"
cat >"$LINKER_WRAPPER" <<EOF
#!/usr/bin/env bash
exec "$CROSS_LINKER_BIN" --sysroot="$SYSROOT_ROOT" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
chmod +x "$LINKER_WRAPPER"

log "Building ARM64 daemon on host with target ${RUST_TARGET}"
CARGO_HOME="$CARGO_HOME_DIR" \
CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="$LINKER_WRAPPER" \
CARGO_TARGET_DIR="$TARGET_DIR" \
    cargo build \
        --release \
        --target "$RUST_TARGET" \
        --manifest-path "$ROOT_DIR/daemon/Cargo.toml"

cp "$TARGET_DIR/$RUST_TARGET/release/bpfrejit-daemon" "$OUTPUT_BINARY"
file "$OUTPUT_BINARY" | grep -F "ARM aarch64" >/dev/null \
    || die "host daemon cross-build did not produce an ARM64 binary: ${OUTPUT_BINARY}"
