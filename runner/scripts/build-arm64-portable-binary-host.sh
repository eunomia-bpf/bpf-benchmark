#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
INPUT_BINARY="${1:?usage: build-arm64-portable-binary-host.sh <input_binary> <real_output> <wrapper_output> <lib_output_dir>}"
REAL_OUTPUT="${2:?usage: build-arm64-portable-binary-host.sh <input_binary> <real_output> <wrapper_output> <lib_output_dir>}"
WRAPPER_OUTPUT="${3:?usage: build-arm64-portable-binary-host.sh <input_binary> <real_output> <wrapper_output> <lib_output_dir>}"
LIB_OUTPUT_DIR="${4:?usage: build-arm64-portable-binary-host.sh <input_binary> <real_output> <wrapper_output> <lib_output_dir>}"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$HOST_CACHE_ROOT/sysroot}"
SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$HOST_CACHE_ROOT/sysroot.lock}"
SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-ec2-user}"
SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-}"
READELF_BIN="${ARM64_PORTABLE_READELF:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}readelf}"
SYSROOT_USR_LIB_DIR="$SYSROOT_ROOT/usr/lib"
SYSROOT_LIB_DIR="$SYSROOT_ROOT/usr/lib64"
SYSROOT_LEGACY_LIB_DIR="$SYSROOT_ROOT/lib"
SYSROOT_ALT_LIB_DIR="$SYSROOT_ROOT/lib64"

log() {
    printf '[arm64-portable-binary-host] %s\n' "$*" >&2
}

die() {
    printf '[arm64-portable-binary-host][ERROR] %s\n' "$*" >&2
    exit 1
}

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/arm64_runtime_bundle_lib.sh"

write_wrapper() {
    cat >"$WRAPPER_OUTPUT" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUNDLE_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
LIB_DIR="$BUNDLE_ROOT/lib"
export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
exec "$SCRIPT_DIR/REAL_BINARY" "$@"
EOF
    sed -i "s|REAL_BINARY|$(basename "$REAL_OUTPUT")|g" "$WRAPPER_OUTPUT"
    chmod +x "$WRAPPER_OUTPUT"
}

require_command bash
require_command cp
require_command file
require_command "$READELF_BIN"

[[ -f "$INPUT_BINARY" ]] || die "input ARM64 binary is missing: ${INPUT_BINARY}"
file "$INPUT_BINARY" | grep -F "ARM aarch64" >/dev/null \
    || die "input binary is not ARM64: ${INPUT_BINARY}"

ARM64_SYSROOT_ROOT="$SYSROOT_ROOT" \
ARM64_SYSROOT_LOCK_FILE="$SYSROOT_LOCK_FILE" \
ARM64_SYSROOT_REMOTE_HOST="$SYSROOT_REMOTE_HOST" \
ARM64_SYSROOT_REMOTE_USER="$SYSROOT_REMOTE_USER" \
ARM64_SYSROOT_SSH_KEY_PATH="$SYSROOT_SSH_KEY_PATH" \
    bash "$ROOT_DIR/runner/scripts/prepare-arm64-sysroot.sh" >/dev/null

mkdir -p "$(dirname "$REAL_OUTPUT")" "$(dirname "$WRAPPER_OUTPUT")" "$LIB_OUTPUT_DIR"
cp "$INPUT_BINARY" "$REAL_OUTPUT"
arm64_bundle_copy_runtime_bundle "$REAL_OUTPUT" "$LIB_OUTPUT_DIR"
write_wrapper

file "$REAL_OUTPUT" | grep -F "ARM aarch64" >/dev/null \
    || die "portable output is not ARM64: ${REAL_OUTPUT}"
log "Staged portable ARM64 binary at ${WRAPPER_OUTPUT}"
