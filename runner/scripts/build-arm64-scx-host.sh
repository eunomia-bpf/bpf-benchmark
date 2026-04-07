#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
SOURCE_REPO_ROOT="${ARM64_SCX_SOURCE_REPO_ROOT:-$ROOT_DIR/runner/repos}"
BUILD_ROOT="${ARM64_SCX_BUILD_ROOT:-$HOST_CACHE_ROOT/scx-host-build}"
PROMOTE_ROOT="${ARM64_SCX_PROMOTE_ROOT:-$HOST_CACHE_ROOT/binaries}"
CARGO_HOME_DIR="${ARM64_SCX_CARGO_HOME:-$HOST_CACHE_ROOT/cargo-home-host-scx}"
PACKAGES_RAW="${ARM64_SCX_PACKAGES:-}"
TARGET_TRIPLE="${ARM64_SCX_TARGET_TRIPLE:-aarch64-unknown-linux-gnu}"
NATIVE_CARGO_LINKER_BIN="${ARM64_NATIVE_CARGO_LINKER:-${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}gcc}"
SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$HOST_CACHE_ROOT/sysroot}"
SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$HOST_CACHE_ROOT/sysroot.lock}"
SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-ec2-user}"
SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-}"
SYSROOT_USR_LIB_DIR="$SYSROOT_ROOT/usr/lib"
SYSROOT_LIB_DIR="$SYSROOT_ROOT/usr/lib64"
SYSROOT_LEGACY_LIB_DIR="$SYSROOT_ROOT/lib"
SYSROOT_ALT_LIB_DIR="$SYSROOT_ROOT/lib64"
SYSROOT_PKGCONFIG_DIR="$SYSROOT_LIB_DIR/pkgconfig"
SCX_BUILD_REPO_ROOT="$BUILD_ROOT/runner/repos"
SCX_BUILD_REPO_DIR="$SCX_BUILD_REPO_ROOT/scx"
TOOLCHAIN_BIN_DIR="$BUILD_ROOT/toolchain/bin"
PREFERRED_LLVM_SUFFIX="${ARM64_CROSSBUILD_LLVM_SUFFIX:-20}"
READELF_BIN="${ARM64_CROSSBUILD_READELF:-aarch64-linux-gnu-readelf}"
LINKER_WRAPPER="$TOOLCHAIN_BIN_DIR/aarch64-linux-gnu-gcc-sysroot"
RUSTFMT_BIN="${ARM64_CROSSBUILD_RUSTFMT:-rustfmt}"
HOST_PYTHON_BIN="${ARM64_HOST_PYTHON_BIN:-python3}"

log() {
    printf '[arm64-scx-host] %s\n' "$*" >&2
}

die() {
    printf '[arm64-scx-host][ERROR] %s\n' "$*" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/local_prep_common_lib.sh"
# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/arm64_runtime_bundle_lib.sh"

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

resolve_llvm_tool() {
    local base="$1"
    local candidate
    for candidate in "${base}-${PREFERRED_LLVM_SUFFIX}" "${base}${PREFERRED_LLVM_SUFFIX}" "$base"; do
        if command -v "$candidate" >/dev/null 2>&1; then
            printf '%s\n' "$candidate"
            return 0
        fi
    done
    die "missing LLVM tool for ARM64 scx host build: ${base}"
}

prepare_toolchain_dir() {
    rm -rf "$TOOLCHAIN_BIN_DIR"
    mkdir -p "$TOOLCHAIN_BIN_DIR"
    cat >"$LINKER_WRAPPER" <<EOF
#!/usr/bin/env bash
exec "$NATIVE_CARGO_LINKER_BIN" --sysroot="$SYSROOT_ROOT" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
    chmod +x "$LINKER_WRAPPER"
}

prepare_scx_checkout() {
    local archive_commit
    [[ -d "${SOURCE_REPO_ROOT}/scx" ]] || die "source repo ${SOURCE_REPO_ROOT}/scx is missing; fetch it locally first"
    git -C "${SOURCE_REPO_ROOT}/scx" rev-parse --is-inside-work-tree >/dev/null 2>&1 \
        || die "source repo ${SOURCE_REPO_ROOT}/scx is not a git checkout"
    git_path_is_clean "${SOURCE_REPO_ROOT}/scx" \
        || die "source repo ${SOURCE_REPO_ROOT}/scx has local modifications and cannot be sealed"
    archive_commit="$(git -C "${SOURCE_REPO_ROOT}/scx" rev-parse HEAD)"
    rm -rf "$SCX_BUILD_REPO_DIR"
    mkdir -p "$SCX_BUILD_REPO_DIR"
    log "Staging tracked scx checkout at ${archive_commit} into ${SCX_BUILD_REPO_DIR}"
    git -C "${SOURCE_REPO_ROOT}/scx" archive --format=tar "$archive_commit" | tar -xf - -C "$SCX_BUILD_REPO_DIR"
}

build_scx_artifacts() {
    local package
    local -a packages=()
    local -a scx_args=()
    local current_release_dir
    local destination
    local clang_bin llc_bin llvm_config_bin llvm_objcopy_bin llvm_strip_bin

    [[ -n "$PACKAGES_RAW" ]] || die "ARM64_SCX_PACKAGES must not be empty"
    IFS=',' read -r -a packages <<<"$PACKAGES_RAW"
    for package in "${packages[@]}"; do
        [[ -n "$package" ]] || continue
        scx_args+=(--package "$package")
    done
    [[ "${#scx_args[@]}" -gt 0 ]] || die "ARM64_SCX_PACKAGES did not contain any valid package names"

    ARM64_SYSROOT_ROOT="$SYSROOT_ROOT" \
    ARM64_SYSROOT_LOCK_FILE="$SYSROOT_LOCK_FILE" \
    ARM64_SYSROOT_REMOTE_HOST="$SYSROOT_REMOTE_HOST" \
    ARM64_SYSROOT_REMOTE_USER="$SYSROOT_REMOTE_USER" \
    ARM64_SYSROOT_SSH_KEY_PATH="$SYSROOT_SSH_KEY_PATH" \
        bash "$ROOT_DIR/runner/scripts/prepare-arm64-sysroot.sh" >/dev/null

    clang_bin="$(resolve_llvm_tool clang)"
    llc_bin="$(resolve_llvm_tool llc)"
    llvm_config_bin="$(resolve_llvm_tool llvm-config)"
    llvm_objcopy_bin="$(resolve_llvm_tool llvm-objcopy)"
    llvm_strip_bin="$(resolve_llvm_tool llvm-strip)"

    mkdir -p "$PROMOTE_ROOT" "$CARGO_HOME_DIR"
    prepare_toolchain_dir
    log "Building ARM64 scx artifacts on host for ${PACKAGES_RAW}"
    env \
        PATH="$TOOLCHAIN_BIN_DIR:$PATH" \
        CARGO_HOME="$CARGO_HOME_DIR" \
        CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="$LINKER_WRAPPER" \
        RUSTFMT="$RUSTFMT_BIN" \
        RUSTFLAGS="-L native=${SYSROOT_LIB_DIR} -L native=${SYSROOT_ALT_LIB_DIR}${RUSTFLAGS:+ ${RUSTFLAGS}}" \
        PKG_CONFIG_SYSROOT_DIR="${SYSROOT_ROOT}" \
        PKG_CONFIG_LIBDIR="${SYSROOT_PKGCONFIG_DIR}:${SYSROOT_ROOT}/usr/share/pkgconfig" \
        C_INCLUDE_PATH="${SYSROOT_ROOT}/usr/include${C_INCLUDE_PATH:+:${C_INCLUDE_PATH}}" \
        CPLUS_INCLUDE_PATH="${SYSROOT_ROOT}/usr/include${CPLUS_INCLUDE_PATH:+:${CPLUS_INCLUDE_PATH}}" \
        SCX_TARGET_TRIPLE="$TARGET_TRIPLE" \
        SCX_BUILD_JOBS="${ARM64_CROSSBUILD_JOBS:-4}" \
        BPF_CLANG="$clang_bin" \
        CLANG="$clang_bin" \
        LLC="$llc_bin" \
        LLVM_CONFIG="$llvm_config_bin" \
        LLVM_OBJCOPY="$llvm_objcopy_bin" \
        LLVM_STRIP="$llvm_strip_bin" \
        CC="$clang_bin" \
        CXX="${clang_bin/clang/clang++}" \
        "$HOST_PYTHON_BIN" "$ROOT_DIR/runner/scripts/build_scx_artifacts.py" \
            --force \
            --jobs "${ARM64_CROSSBUILD_JOBS:-4}" \
            --target-triple "$TARGET_TRIPLE" \
            --repo-root "$SCX_BUILD_REPO_ROOT" \
            --promote-root "$PROMOTE_ROOT" \
            "${scx_args[@]}"

    current_release_dir="$SCX_BUILD_REPO_DIR/target/$TARGET_TRIPLE/release"
    mkdir -p "$PROMOTE_ROOT/runner/repos/scx/target/release"
    for package in "${packages[@]}"; do
        [[ -n "$package" ]] || continue
        [[ -x "$current_release_dir/$package" ]] || die "expected scx binary missing after build: $current_release_dir/$package"
        destination="$PROMOTE_ROOT/runner/repos/scx/target/release/$package"
        cp "$current_release_dir/$package" "$destination"
        arm64_bundle_copy_runtime_bundle "$destination" "$PROMOTE_ROOT/lib"
    done
}

require_command "$HOST_PYTHON_BIN"
require_command cargo
require_command file
require_command readelf
require_command git
require_command tar
require_command "$NATIVE_CARGO_LINKER_BIN"
require_command "$READELF_BIN"
require_command "$RUSTFMT_BIN"

prepare_scx_checkout
build_scx_artifacts
