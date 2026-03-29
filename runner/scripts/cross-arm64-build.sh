#!/usr/bin/env bash
# Cross-build ARM64 micro_exec + daemon directly on the host using native
# cross-compilers. This avoids binfmt/QEMU emulation of an entire ARM64
# userspace.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"

JOBS="${ARM64_CROSSBUILD_JOBS:-4}"
TARGET_TRIPLE="${ARM64_RUST_TARGET:-aarch64-unknown-linux-gnu}"
CROSS_COMPILE_PREFIX="${CROSS_COMPILE_ARM64:-aarch64-linux-gnu-}"
TARGET_CPU="${ARM64_CROSSBUILD_TARGET_CPU:-cortex-a72}"
MICRO_EXEC_ENABLE_LLVMBPF="${MICRO_EXEC_ENABLE_LLVMBPF:-OFF}"
OUTPUT_ROOT="${ARM64_CROSSBUILD_OUTPUT_DIR:-${OUT_DIR:-}}"
BUILD_ROOT="${ARM64_CROSSBUILD_BUILD_ROOT:-${REPO_ROOT}/.cache/arm64-crossbuild-work}"
RUNNER_BUILD_DIR="${BUILD_ROOT}/runner"
DAEMON_TARGET_DIR="${BUILD_ROOT}/daemon-target"
LOCAL_SYSROOT_DIR="${BUILD_ROOT}/sysroot"
LOCAL_DEB_DIR="${BUILD_ROOT}/debs"

log() {
    printf '[cross-arm64] %s\n' "$*" >&2
}

die() {
    printf '[cross-arm64][ERROR] %s\n' "$*" >&2
    exit 1
}

require_command() {
    local cmd="$1"
    command -v "$cmd" >/dev/null 2>&1 || die "missing required command: ${cmd}"
}

if [[ -z "${OUTPUT_ROOT}" ]]; then
    if [[ -d /out ]]; then
        OUTPUT_ROOT=/out
    else
        die "ARM64_CROSSBUILD_OUTPUT_DIR (or OUT_DIR) must be set when /out is unavailable"
    fi
fi

CC="${CROSS_COMPILE_PREFIX}gcc"
CXX="${CROSS_COMPILE_PREFIX}g++"
AR="${CROSS_COMPILE_PREFIX}ar"
AS="${CROSS_COMPILE_PREFIX}as"
LD="${CROSS_COMPILE_PREFIX}ld"
READELF="${CROSS_COMPILE_PREFIX}readelf"
STRIP="${CROSS_COMPILE_PREFIX}strip"

require_command make
require_command cmake
require_command cargo
require_command rustup
require_command file
require_command pkg-config
require_command "$CC"
require_command "$CXX"
require_command "$AR"
require_command "$AS"
require_command "$LD"
require_command "$READELF"
require_command "$STRIP"
require_command dpkg-deb

if ! rustup target list --installed | grep -Fx "$TARGET_TRIPLE" >/dev/null; then
    log "Installing Rust target ${TARGET_TRIPLE}"
    rustup target add "$TARGET_TRIPLE"
fi

prepare_local_arm64_sysroot() {
    local -a packages=(
        libyaml-cpp-dev:arm64
        libyaml-cpp0.8:arm64
        libelf-dev:arm64
        libelf1t64:arm64
        zlib1g-dev:arm64
        zlib1g:arm64
        libzstd-dev:arm64
        libzstd1:arm64
    )
    local deb

    log "Preparing local ARM64 sysroot under ${LOCAL_SYSROOT_DIR}"
    rm -rf "${LOCAL_SYSROOT_DIR}" "${LOCAL_DEB_DIR}"
    mkdir -p "${LOCAL_SYSROOT_DIR}" "${LOCAL_DEB_DIR}"

    (
        cd "${LOCAL_DEB_DIR}"
        apt-get download "${packages[@]}" >/dev/null
        for deb in ./*.deb; do
            dpkg-deb -x "${deb}" "${LOCAL_SYSROOT_DIR}"
        done
    )
}

build_pkg_config_env() {
    local sysroot="$1"
    local -a dirs=(
        "${sysroot}/usr/lib/aarch64-linux-gnu/pkgconfig"
        "${sysroot}/usr/lib/pkgconfig"
        "${sysroot}/usr/share/pkgconfig"
    )
    printf '%s\n' "${dirs[@]}" | awk 'NF && !seen[$0]++' | paste -sd:
}

detect_missing_target_pkg() {
    local pkg
    for pkg in yaml-cpp libelf zlib; do
        if ! pkg-config --exists "$pkg"; then
            printf '%s\n' "$pkg"
            return 0
        fi
    done
    return 1
}

DEFAULT_PKG_CONFIG_LIBDIR="$(build_pkg_config_env /)"
DEFAULT_PKG_CONFIG_SYSROOT_DIR=/

export PKG_CONFIG_LIBDIR="${ARM64_PKG_CONFIG_LIBDIR:-$DEFAULT_PKG_CONFIG_LIBDIR}"
export PKG_CONFIG_SYSROOT_DIR="${ARM64_PKG_CONFIG_SYSROOT_DIR:-$DEFAULT_PKG_CONFIG_SYSROOT_DIR}"
export CMAKE_BUILD_PARALLEL_LEVEL="$JOBS"
export CC
export CXX
export AR
export AS
export LD
export STRIP
export CFLAGS="${CFLAGS:+$CFLAGS }-mcpu=${TARGET_CPU}"
export CXXFLAGS="${CXXFLAGS:+$CXXFLAGS }-mcpu=${TARGET_CPU}"
export RUSTFLAGS="${RUSTFLAGS:+$RUSTFLAGS }-C target-cpu=${TARGET_CPU}"
TARGET_ENV_TRIPLE="${TARGET_TRIPLE^^}"
TARGET_ENV_TRIPLE="${TARGET_ENV_TRIPLE//-/_}"
printf -v CARGO_LINKER_ENV_VAR 'CARGO_TARGET_%s_LINKER' "${TARGET_ENV_TRIPLE}"
export "${CARGO_LINKER_ENV_VAR}=${CC}"

if [[ -z "${ARM64_PKG_CONFIG_LIBDIR:-}" ]] || [[ -z "${ARM64_PKG_CONFIG_SYSROOT_DIR:-}" ]]; then
    if missing_pkg="$(detect_missing_target_pkg)"; then
        log "Target pkg-config module '${missing_pkg}' is unavailable under PKG_CONFIG_LIBDIR=${PKG_CONFIG_LIBDIR}; falling back to a local ARM64 sysroot"
        prepare_local_arm64_sysroot
        export PKG_CONFIG_LIBDIR="$(build_pkg_config_env "${LOCAL_SYSROOT_DIR}")"
        export PKG_CONFIG_SYSROOT_DIR="${LOCAL_SYSROOT_DIR}"
    fi
fi

for pkg in yaml-cpp libelf zlib; do
    if ! pkg-config --exists "$pkg"; then
        die "missing target pkg-config module '${pkg}' under PKG_CONFIG_LIBDIR=${PKG_CONFIG_LIBDIR}"
    fi
done

if [[ "${MICRO_EXEC_ENABLE_LLVMBPF}" == "ON" ]] && ! find /usr/lib/aarch64-linux-gnu /usr/aarch64-linux-gnu/lib -maxdepth 2 -name 'libLLVM*.so*' 2>/dev/null | grep -q .; then
    die "MICRO_EXEC_ENABLE_LLVMBPF=ON requires ARM64 LLVM runtime/devel libraries on the host. Install a target sysroot or rerun with MICRO_EXEC_ENABLE_LLVMBPF=OFF."
fi

mkdir -p "$OUTPUT_ROOT/runner/build" "$OUTPUT_ROOT/daemon/build" "$OUTPUT_ROOT/lib"
rm -rf "$RUNNER_BUILD_DIR" "$DAEMON_TARGET_DIR"
mkdir -p "$RUNNER_BUILD_DIR" "$DAEMON_TARGET_DIR"

log "Building ARM64 runner (MICRO_EXEC_ENABLE_LLVMBPF=${MICRO_EXEC_ENABLE_LLVMBPF})"
make -C "${REPO_ROOT}/runner" \
    BUILD_DIR="$RUNNER_BUILD_DIR" \
    JOBS="$JOBS" \
    MICRO_EXEC_ENABLE_LLVMBPF="$MICRO_EXEC_ENABLE_LLVMBPF" \
    micro_exec

log "Building ARM64 daemon"
CARGO_TARGET_DIR="$DAEMON_TARGET_DIR" \
    cargo build \
        --release \
        --target "$TARGET_TRIPLE" \
        -j "$JOBS" \
        --manifest-path "${REPO_ROOT}/daemon/Cargo.toml"

cp "${RUNNER_BUILD_DIR}/micro_exec" "${OUTPUT_ROOT}/runner/build/micro_exec.real"
cp "${DAEMON_TARGET_DIR}/${TARGET_TRIPLE}/release/bpfrejit-daemon" "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon.real"

collect_library_search_dirs() {
    local sysroot gcc_search
    sysroot="$("$CC" -print-sysroot)"
    gcc_search="$("$CC" -print-search-dirs | awk -F= '/^libraries: =/ {print $2}')"
    {
        printf '%s\n' \
            "${PKG_CONFIG_SYSROOT_DIR}/lib/aarch64-linux-gnu" \
            "${PKG_CONFIG_SYSROOT_DIR}/usr/lib/aarch64-linux-gnu" \
            "/usr/lib/aarch64-linux-gnu" \
            "/usr/aarch64-linux-gnu/lib" \
            "${sysroot}/lib" \
            "${sysroot}/lib64" \
            "${sysroot}/usr/lib" \
            "${sysroot}/usr/lib/aarch64-linux-gnu"
        tr ':' '\n' <<<"${gcc_search}"
        dirname "$("$CXX" -print-file-name=libstdc++.so)"
        dirname "$("$CC" -print-file-name=libgcc_s.so.1)"
    } | awk 'NF && !seen[$0]++'
}

mapfile -t TARGET_LIBRARY_DIRS < <(collect_library_search_dirs)

resolve_target_library() {
    local soname="$1"
    local dir candidate
    for dir in "${TARGET_LIBRARY_DIRS[@]}"; do
        [[ -d "$dir" ]] || continue
        candidate="${dir}/${soname}"
        if [[ -e "$candidate" ]]; then
            printf '%s\n' "$candidate"
            return 0
        fi
    done
    return 1
}

should_bundle_runtime_library() {
    local soname="$1"
    case "$soname" in
        ld-linux-aarch64.so.1|libc.so.6|libm.so.6|libpthread.so.0|librt.so.1|libdl.so.2|libresolv.so.2|libutil.so.1)
            return 1
            ;;
    esac
    return 0
}

copy_target_runtime_bundle() {
    local binary="$1"
    local -a queue=("$binary")
    local current resolved soname interpreter
    declare -A seen=()

    while ((${#queue[@]})); do
        current="${queue[0]}"
        queue=("${queue[@]:1}")
        [[ -e "$current" ]] || continue
        if [[ -n "${seen["$current"]:-}" ]]; then
            continue
        fi
        seen["$current"]=1

        while IFS= read -r soname; do
            [[ -n "$soname" ]] || continue
            if ! should_bundle_runtime_library "$soname"; then
                continue
            fi
            resolved="$(resolve_target_library "$soname" || true)"
            [[ -n "$resolved" ]] || die "unable to resolve ARM64 runtime library ${soname} needed by ${current}"
            cp -L "$resolved" "${OUTPUT_ROOT}/lib/"
            queue+=("$resolved")
        done < <("$READELF" -d "$current" | sed -n "s/.*Shared library: \\[\\(.*\\)\\]/\\1/p")

        interpreter="$("$READELF" -l "$current" | sed -n "s/.*Requesting program interpreter: \\(.*\\)]/\\1/p" | tr -d '[')"
        if [[ -n "$interpreter" && -e "$interpreter" ]] && should_bundle_runtime_library "$(basename "$interpreter")"; then
            cp -L "$interpreter" "${OUTPUT_ROOT}/lib/"
        fi
    done
}

copy_target_runtime_bundle "${OUTPUT_ROOT}/runner/build/micro_exec.real"
copy_target_runtime_bundle "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon.real"

for pair in "runner/build/micro_exec:micro_exec.real" "daemon/build/bpfrejit-daemon:bpfrejit-daemon.real"; do
    wrapper="${OUTPUT_ROOT}/${pair%%:*}"
    real="${pair##*:}"
    cat >"$wrapper" <<'WRAPPER'
#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUNDLE_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
LIB_DIR="$BUNDLE_ROOT/lib"
export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
exec "$SCRIPT_DIR/REAL_BINARY" "$@"
WRAPPER
    sed -i "s|REAL_BINARY|${real}|g" "$wrapper"
    chmod +x "$wrapper"
done

file "${OUTPUT_ROOT}/runner/build/micro_exec.real"
file "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon.real"
