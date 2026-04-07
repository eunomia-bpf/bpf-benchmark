#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
HOST_CACHE_ROOT="${ARM64_HOST_CACHE_ROOT:-$ROOT_DIR/.cache/arm64-host}"
SOURCE_ROOT="${ARM64_WORKLOAD_TOOLS_SOURCE_ROOT:-$ROOT_DIR/runner/repos}"
BUILD_ROOT="${ARM64_WORKLOAD_TOOLS_BUILD_ROOT:-$HOST_CACHE_ROOT/workload-tools-host}"
OUTPUT_ROOT="${ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT:-$HOST_CACHE_ROOT/workload-tools-output}"
TOOLS_RAW="${ARM64_WORKLOAD_TOOLS_LIST:-}"
SYSROOT_ROOT="${ARM64_SYSROOT_ROOT:-$HOST_CACHE_ROOT/sysroot}"
SYSROOT_LOCK_FILE="${ARM64_SYSROOT_LOCK_FILE:-$HOST_CACHE_ROOT/sysroot.lock}"
SYSROOT_REMOTE_HOST="${ARM64_SYSROOT_REMOTE_HOST:-}"
SYSROOT_REMOTE_USER="${ARM64_SYSROOT_REMOTE_USER:-ec2-user}"
SYSROOT_SSH_KEY_PATH="${ARM64_SYSROOT_SSH_KEY_PATH:-}"
TOOLCHAIN_PREFIX="${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}"
HOST_CC_BIN="${ARM64_WORKLOAD_TOOLS_HOST_CC:-gcc}"
STRIP_BIN="${ARM64_WORKLOAD_TOOLS_STRIP:-${TOOLCHAIN_PREFIX}strip}"
READELF_BIN="${ARM64_WORKLOAD_TOOLS_READELF:-${TOOLCHAIN_PREFIX}readelf}"
WORKLOAD_ROOT="$BUILD_ROOT/workload-tools"
WORKLOAD_SRC_ROOT="$WORKLOAD_ROOT/src"
WORKLOAD_TOOLCHAIN_DIR="$WORKLOAD_ROOT/toolchain/bin"
WORKLOAD_CROSS_PREFIX="$WORKLOAD_TOOLCHAIN_DIR/${TOOLCHAIN_PREFIX}"
SYSROOT_USR_LIB_DIR="$SYSROOT_ROOT/usr/lib"
SYSROOT_LIB_DIR="$SYSROOT_ROOT/usr/lib64"
SYSROOT_LEGACY_LIB_DIR="$SYSROOT_ROOT/lib"
SYSROOT_ALT_LIB_DIR="$SYSROOT_ROOT/lib64"
SYSROOT_PKGCONFIG_DIR="$SYSROOT_LIB_DIR/pkgconfig"
OUTPUT_TOOL_ROOT="$OUTPUT_ROOT/workload-tools"
OUTPUT_TOOL_BIN_DIR="$OUTPUT_TOOL_ROOT/bin"
OUTPUT_TOOL_LIB_DIR="$OUTPUT_TOOL_ROOT/lib"

log() {
    printf '[arm64-workload-tools-host] %s\n' "$*" >&2
}

die() {
    printf '[arm64-workload-tools-host][ERROR] %s\n' "$*" >&2
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

copy_sibling_lib_wrapper() {
    local wrapper="$1"
    local real_name="$2"
    cat >"$wrapper" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
LIB_DIR="$(cd "$SCRIPT_DIR/../lib" && pwd)"
export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
exec "$SCRIPT_DIR/REAL_BINARY" "$@"
EOF
    sed -i "s|REAL_BINARY|${real_name}|g" "$wrapper"
    chmod +x "$wrapper"
}

prepare_toolchain_dir() {
    local wrapper driver target_bin
    rm -rf "$WORKLOAD_TOOLCHAIN_DIR"
    mkdir -p "$WORKLOAD_TOOLCHAIN_DIR"
    for wrapper in gcc g++; do
        target_bin="$(command -v "${TOOLCHAIN_PREFIX}${wrapper}")"
        cat >"$WORKLOAD_TOOLCHAIN_DIR/$wrapper" <<EOF
#!/usr/bin/env bash
exec "$target_bin" --sysroot="$SYSROOT_ROOT" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
        chmod +x "$WORKLOAD_TOOLCHAIN_DIR/$wrapper"
        driver="$WORKLOAD_TOOLCHAIN_DIR/${TOOLCHAIN_PREFIX}${wrapper}"
        cat >"$driver" <<EOF
#!/usr/bin/env bash
exec "$target_bin" --sysroot="$SYSROOT_ROOT" \
    -Wl,-rpath-link,"$SYSROOT_USR_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_LEGACY_LIB_DIR" \
    -Wl,-rpath-link,"$SYSROOT_ALT_LIB_DIR" \
    "\$@"
EOF
        chmod +x "$driver"
    done
    ln -sfn "$(command -v "${TOOLCHAIN_PREFIX}ar")" "$WORKLOAD_TOOLCHAIN_DIR/${TOOLCHAIN_PREFIX}ar"
    ln -sfn "$(command -v "${TOOLCHAIN_PREFIX}ranlib")" "$WORKLOAD_TOOLCHAIN_DIR/${TOOLCHAIN_PREFIX}ranlib"
    ln -sfn "$(command -v "${TOOLCHAIN_PREFIX}strip")" "$WORKLOAD_TOOLCHAIN_DIR/${TOOLCHAIN_PREFIX}strip"
}

prepare_source_checkout() {
    local repo_url="$1"
    local dest_dir="$2"
    rm -rf "$dest_dir"
    git clone --depth 1 "$repo_url" "$dest_dir" >/dev/null
    require_nonempty_dir "$dest_dir"
}

stage_portable_binary() {
    local tool_name="$1"
    local source_binary="$2"
    local real_binary="$OUTPUT_TOOL_BIN_DIR/${tool_name}.real"
    [[ -x "$source_binary" ]] || die "missing built ARM64 workload tool binary: ${source_binary}"
    mkdir -p "$OUTPUT_TOOL_BIN_DIR" "$OUTPUT_TOOL_LIB_DIR"
    cp "$source_binary" "$real_binary"
    "$STRIP_BIN" "$real_binary" >/dev/null 2>&1 || true
    file "$real_binary" | grep -F "ARM aarch64" >/dev/null \
        || die "built workload tool is not ARM64: ${real_binary}"
    arm64_bundle_copy_runtime_bundle "$real_binary" "$OUTPUT_TOOL_LIB_DIR"
    copy_sibling_lib_wrapper "$OUTPUT_TOOL_BIN_DIR/${tool_name}" "${tool_name}.real"
}

build_hackbench_tool() {
    local src_root="$WORKLOAD_SRC_ROOT/rt-tests"
    log "Building ARM64 hackbench on host"
    prepare_source_checkout "https://git.kernel.org/pub/scm/utils/rt-tests/rt-tests.git" "$src_root"
    env CROSS_COMPILE="${WORKLOAD_CROSS_PREFIX}" \
        make -C "$src_root" -j"$(nproc)" hackbench >/dev/null
    stage_portable_binary "hackbench" "$src_root/hackbench"
}

build_sysbench_tool() {
    local src_root="$WORKLOAD_SRC_ROOT/sysbench"
    log "Building ARM64 sysbench on host"
    prepare_source_checkout "https://github.com/akopytov/sysbench.git" "$src_root"
    (
        cd "$src_root"
        CC="$WORKLOAD_TOOLCHAIN_DIR/gcc" \
        CXX="$WORKLOAD_TOOLCHAIN_DIR/g++" \
        AR="${WORKLOAD_CROSS_PREFIX}ar" \
        RANLIB="${WORKLOAD_CROSS_PREFIX}ranlib" \
        STRIP="${WORKLOAD_CROSS_PREFIX}strip" \
        PKG_CONFIG_SYSROOT_DIR="$SYSROOT_ROOT" \
        PKG_CONFIG_LIBDIR="$SYSROOT_PKGCONFIG_DIR:$SYSROOT_ROOT/usr/share/pkgconfig" \
            ./autogen.sh >/dev/null
        CC="$WORKLOAD_TOOLCHAIN_DIR/gcc" \
        CXX="$WORKLOAD_TOOLCHAIN_DIR/g++" \
        AR="${WORKLOAD_CROSS_PREFIX}ar" \
        RANLIB="${WORKLOAD_CROSS_PREFIX}ranlib" \
        STRIP="${WORKLOAD_CROSS_PREFIX}strip" \
        PKG_CONFIG_SYSROOT_DIR="$SYSROOT_ROOT" \
        PKG_CONFIG_LIBDIR="$SYSROOT_PKGCONFIG_DIR:$SYSROOT_ROOT/usr/share/pkgconfig" \
            ./configure --host=aarch64-linux-gnu --without-mysql --without-pgsql --prefix="$src_root/install" >/dev/null
        make \
            HOST_CC="$HOST_CC_BIN" \
            CROSS="${WORKLOAD_CROSS_PREFIX}" \
            TARGET_SYS=Linux \
            CK_CONFIGURE_FLAGS="--platform=aarch64" \
            -j"$(nproc)" >/dev/null
        make \
            HOST_CC="$HOST_CC_BIN" \
            CROSS="${WORKLOAD_CROSS_PREFIX}" \
            TARGET_SYS=Linux \
            CK_CONFIGURE_FLAGS="--platform=aarch64" \
            install >/dev/null
    )
    stage_portable_binary "sysbench" "$src_root/install/bin/sysbench"
}

build_wrk_tool() {
    local src_root="$WORKLOAD_SRC_ROOT/wrk"
    local luajit_dir
    local openssl_root="$src_root/obj/openssl-root"
    log "Building ARM64 wrk on host"
    prepare_source_checkout "https://github.com/wg/wrk.git" "$src_root"
    (
        cd "$src_root"
        unzip -q deps/LuaJIT*.zip -d obj >/dev/null
        luajit_dir="$(echo obj/LuaJIT-*)"
        make -C "$luajit_dir" \
                HOST_CC="$HOST_CC_BIN" \
                CROSS="${WORKLOAD_CROSS_PREFIX}" \
                TARGET_SYS=Linux \
                TARGET_FLAGS="--sysroot=$SYSROOT_ROOT" \
                PREFIX="$src_root/obj" \
                BUILDMODE=static install >/dev/null
        ln -sfn "luajit-2.1.0-beta3" "$src_root/obj/bin/luajit"
        find "$src_root/obj/include/luajit-2.1" -maxdepth 1 -type f -exec ln -sfn '{}' "$src_root/obj/include/" \;
        mkdir -p "$openssl_root"
        ln -sfn "$SYSROOT_ROOT/usr/include" "$openssl_root/include"
        ln -sfn "$SYSROOT_ROOT/usr/lib64" "$openssl_root/lib"
        PATH="$src_root/obj/bin:$PATH" \
            make \
                CC="$WORKLOAD_TOOLCHAIN_DIR/gcc" \
                STRIP="${WORKLOAD_CROSS_PREFIX}strip" \
                WITH_LUAJIT="$src_root/obj" \
                WITH_OPENSSL="$openssl_root" \
                -j"$(nproc)" >/dev/null
    )
    stage_portable_binary "wrk" "$src_root/wrk"
}

build_requested_tools() {
    local tool
    [[ -n "$TOOLS_RAW" ]] || die "ARM64_WORKLOAD_TOOLS_LIST must not be empty"
    rm -rf "$WORKLOAD_SRC_ROOT" "$OUTPUT_TOOL_ROOT"
    mkdir -p "$WORKLOAD_SRC_ROOT" "$OUTPUT_TOOL_BIN_DIR" "$OUTPUT_TOOL_LIB_DIR"
    IFS=',' read -r -a _workload_tools <<<"$TOOLS_RAW"
    for tool in "${_workload_tools[@]}"; do
        [[ -n "$tool" ]] || continue
        case "$tool" in
            hackbench) build_hackbench_tool ;;
            sysbench) build_sysbench_tool ;;
            wrk) build_wrk_tool ;;
            *) die "unsupported ARM64 workload tool: ${tool}" ;;
        esac
    done
}

require_command git
require_command unzip
require_command "$HOST_CC_BIN"
require_command "${TOOLCHAIN_PREFIX}ar"
require_command "${TOOLCHAIN_PREFIX}ranlib"
require_command "${TOOLCHAIN_PREFIX}gcc"
require_command "${TOOLCHAIN_PREFIX}g++"
require_command "$READELF_BIN"
require_command "$STRIP_BIN"

ARM64_SYSROOT_ROOT="$SYSROOT_ROOT" \
ARM64_SYSROOT_LOCK_FILE="$SYSROOT_LOCK_FILE" \
ARM64_SYSROOT_REMOTE_HOST="$SYSROOT_REMOTE_HOST" \
ARM64_SYSROOT_REMOTE_USER="$SYSROOT_REMOTE_USER" \
ARM64_SYSROOT_SSH_KEY_PATH="$SYSROOT_SSH_KEY_PATH" \
    bash "$ROOT_DIR/runner/scripts/prepare-arm64-sysroot.sh" >/dev/null

prepare_toolchain_dir
build_requested_tools
