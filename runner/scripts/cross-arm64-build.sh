#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
SOURCE_REPO_ROOT="${ARM64_SOURCE_REPO_ROOT:-${REPO_ROOT}/runner/repos}"

JOBS="${ARM64_CROSSBUILD_JOBS:-4}"
PREFERRED_LLVM_SUFFIX="${ARM64_CROSSBUILD_LLVM_SUFFIX:-20}"
MICRO_EXEC_ENABLE_LLVMBPF="${MICRO_EXEC_ENABLE_LLVMBPF:-OFF}"
SCX_PACKAGES_RAW="${ARM64_CROSSBUILD_SCX_PACKAGES:-}"
ONLY_SCX="${ARM64_CROSSBUILD_ONLY_SCX:-0}"
BENCH_REPOS_RAW="${ARM64_CROSSBUILD_BENCH_REPOS:-}"
ONLY_BENCH="${ARM64_CROSSBUILD_ONLY_BENCH:-0}"
OUTPUT_ROOT="${ARM64_CROSSBUILD_OUTPUT_DIR:-${OUT_DIR:-}}"
BUILD_ROOT="${ARM64_CROSSBUILD_BUILD_ROOT:-/tmp/codex/arm64-crossbuild-work}"
HOST_UID="${HOST_UID:-}"
HOST_GID="${HOST_GID:-}"
RUNNER_BUILD_DIR="${BUILD_ROOT}/runner"
RUNNER_VENDOR_BUILD_DIR="${BUILD_ROOT}/runner-vendor"
DAEMON_TARGET_DIR="${BUILD_ROOT}/daemon-target"
LLVMBPF_BUILD_DIR="${BUILD_ROOT}/llvmbpf-build"
LLVMBPF_LIBRARY="${BUILD_ROOT}/libllvmbpf_vm.a"
SCX_BUILD_REPO_ROOT="${BUILD_ROOT}/runner/repos"
SCX_BUILD_REPO_DIR="${SCX_BUILD_REPO_ROOT}/scx"
BENCH_BUILD_REPO_ROOT="${BUILD_ROOT}/benchmark/repos"
BENCH_STAGE_ROOT="${BUILD_ROOT}/benchmark/stage"
KATRAN_BUILD_ROOT="${ARM64_KATRAN_BUILD_ROOT:-/tmp/codex/katranbuild}"
KATRAN_SOURCE_DIR="${KATRAN_BUILD_ROOT}/src"
KATRAN_BUILD_DIR="${KATRAN_SOURCE_DIR}/_build"
KATRAN_INSTALL_DIR="${KATRAN_BUILD_DIR}/deps"
TOOLCHAIN_BIN_DIR="${BUILD_ROOT}/toolchain/bin"
NATIVE_CARGO_LINKER="${ARM64_NATIVE_CARGO_LINKER:-gcc}"
CLANG_BIN=""
CLANGXX_BIN=""
LLC_BIN=""
LLVM_CONFIG_BIN=""
LLVM_STRIP_BIN=""
LLVM_OBJCOPY_BIN=""
LD_LLD_BIN=""

log() {
    printf '[cross-arm64] %s\n' "$*" >&2
}

die() {
    printf '[cross-arm64][ERROR] %s\n' "$*" >&2
    exit 1
}

fix_output_ownership() {
    if [[ "${EUID}" -ne 0 ]]; then
        return 0
    fi
    if [[ -z "${HOST_UID}" || -z "${HOST_GID}" ]]; then
        return 0
    fi
    [[ -e "${OUTPUT_ROOT}" ]] || return 0
    chown -R "${HOST_UID}:${HOST_GID}" "${OUTPUT_ROOT}"
    if [[ -n "${CARGO_HOME:-}" && -e "${CARGO_HOME}" ]]; then
        chown -R "${HOST_UID}:${HOST_GID}" "${CARGO_HOME}"
    fi
}

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
    die "missing LLVM tool for ARM64 crossbuild: ${base}"
}

prepare_llvm_toolchain() {
    CLANG_BIN="$(resolve_llvm_tool clang)"
    CLANGXX_BIN="$(resolve_llvm_tool clang++)"
    LLC_BIN="$(resolve_llvm_tool llc)"
    LLVM_CONFIG_BIN="$(resolve_llvm_tool llvm-config)"
    LLVM_STRIP_BIN="$(resolve_llvm_tool llvm-strip)"
    LLVM_OBJCOPY_BIN="$(resolve_llvm_tool llvm-objcopy)"
    LD_LLD_BIN="$(resolve_llvm_tool ld.lld)"

    rm -rf "${TOOLCHAIN_BIN_DIR}"
    mkdir -p "${TOOLCHAIN_BIN_DIR}"
    ln -sfn "$(command -v "${CLANG_BIN}")" "${TOOLCHAIN_BIN_DIR}/clang"
    ln -sfn "$(command -v "${CLANGXX_BIN}")" "${TOOLCHAIN_BIN_DIR}/clang++"
    ln -sfn "$(command -v "${LLC_BIN}")" "${TOOLCHAIN_BIN_DIR}/llc"
    ln -sfn "$(command -v "${LLVM_CONFIG_BIN}")" "${TOOLCHAIN_BIN_DIR}/llvm-config"
    ln -sfn "$(command -v "${LLVM_STRIP_BIN}")" "${TOOLCHAIN_BIN_DIR}/llvm-strip"
    ln -sfn "$(command -v "${LLVM_OBJCOPY_BIN}")" "${TOOLCHAIN_BIN_DIR}/llvm-objcopy"
    ln -sfn "$(command -v "${LD_LLD_BIN}")" "${TOOLCHAIN_BIN_DIR}/ld.lld"
    # Generated scx bindgen/skeleton output should not depend on rustfmt
    # availability or rustfmt correctness inside the ARM crossbuild container.
    cat >"${TOOLCHAIN_BIN_DIR}/rustfmt" <<'EOF'
#!/usr/bin/env bash
cat
EOF
    chmod +x "${TOOLCHAIN_BIN_DIR}/rustfmt"
    ln -sfn rustfmt "${TOOLCHAIN_BIN_DIR}/disable_rustfmt"
    export PATH="${TOOLCHAIN_BIN_DIR}:${PATH}"
}

if [[ -z "${OUTPUT_ROOT}" ]]; then
    if [[ -d /out ]]; then
        OUTPUT_ROOT=/out
    else
        die "ARM64_CROSSBUILD_OUTPUT_DIR (or OUT_DIR) must be set when /out is unavailable"
    fi
fi

require_command make
require_command cmake
require_command cargo
require_command file
require_command ldd
require_command python3
prepare_llvm_toolchain

trap fix_output_ownership EXIT

if [[ "$(uname -m)" != "aarch64" ]]; then
    die "cross-arm64-build.sh must run inside an aarch64 userspace (use make cross-arm64)"
fi

mkdir -p "${OUTPUT_ROOT}/lib"
if [[ "${ONLY_SCX}" != "1" ]]; then
    mkdir -p "${OUTPUT_ROOT}/runner/build" "${OUTPUT_ROOT}/daemon/build"
fi
mkdir -p "${BUILD_ROOT}"
if [[ "${ONLY_SCX}" != "1" ]]; then
    rm -rf "${RUNNER_BUILD_DIR}" "${DAEMON_TARGET_DIR}"
fi

prepare_repo_copy() {
    local repo_name="$1"
    local dest_dir="$2"
    [[ -d "${SOURCE_REPO_ROOT}/${repo_name}" ]] || die "source repo ${SOURCE_REPO_ROOT}/${repo_name} is missing; fetch it locally first"
    rm -rf "${dest_dir}"
    mkdir -p "$(dirname "${dest_dir}")"
    cp -a "${SOURCE_REPO_ROOT}/${repo_name}" "${dest_dir}"
}

build_vendor_bpftool() {
    make -C "${REPO_ROOT}/runner" BUILD_DIR="${RUNNER_VENDOR_BUILD_DIR}" JOBS=1 vendor_bpftool >/dev/null
}

build_bcc_artifacts() {
    local repo_dir="${BENCH_BUILD_REPO_ROOT}/bcc"
    local tool_dir="${repo_dir}/libbpf-tools"
    local bpftool="${RUNNER_VENDOR_BUILD_DIR}/vendor/bpftool/bootstrap/bpftool"
    local obj_path obj_name tool_name

    log "Building ARM64 bcc libbpf-tools artifacts"
    prepare_repo_copy "bcc" "${repo_dir}"
    build_vendor_bpftool
    [[ -x "${bpftool}" ]] || die "missing vendor bpftool for ARM64 bcc build: ${bpftool}"

    make -C "${tool_dir}" \
        -j "${JOBS}" \
        CLANG="${CLANG_BIN}" \
        LLVM_STRIP="${LLVM_STRIP_BIN}" \
        USE_BLAZESYM=0 \
        BPFTOOL="${bpftool}" \
        LIBBPF_SRC="${REPO_ROOT}/vendor/libbpf/src" >/dev/null

    mkdir -p \
        "${OUTPUT_ROOT}/runner/repos/bcc/libbpf-tools/.output" \
        "${OUTPUT_ROOT}/corpus/build/bcc/libbpf-tools"
    while IFS= read -r -d '' obj_path; do
        obj_name="$(basename "${obj_path}")"
        cp "${obj_path}" "${OUTPUT_ROOT}/runner/repos/bcc/libbpf-tools/.output/${obj_name}"
        cp "${obj_path}" "${OUTPUT_ROOT}/corpus/build/bcc/libbpf-tools/${obj_name}"
        tool_name="${obj_name%.bpf.o}"
        if [[ -x "${tool_dir}/${tool_name}" ]]; then
            cp "${tool_dir}/${tool_name}" "${OUTPUT_ROOT}/runner/repos/bcc/libbpf-tools/.output/${tool_name}"
        fi
    done < <(find "${tool_dir}/.output" -maxdepth 1 -type f -name '*.bpf.o' -print0)
}

build_katran_bpf_artifacts() {
    local repo_dir="${BENCH_BUILD_REPO_ROOT}/katran"
    local lib_dir="${repo_dir}/katran/lib"
    local work_dir="${BUILD_ROOT}/katran-bpf-build"
    local obj_path obj_name stage_name

    log "Building ARM64 katran BPF objects"
    rm -rf "${work_dir}"
    mkdir -p "${work_dir}/include" "${work_dir}/katran/lib" "${work_dir}/bpf"
    cp "${lib_dir}/Makefile-bpf" "${work_dir}/Makefile"
    cp -a "${lib_dir}/bpf" "${work_dir}/katran/lib/bpf"
    cp -a "${lib_dir}/linux_includes" "${work_dir}/katran/lib/linux_includes"
    while IFS= read -r -d '' obj_path; do
        cp "${obj_path}" "${work_dir}/include/$(basename "${obj_path}")"
    done < <(find "${lib_dir}/linux_includes" -maxdepth 1 -type f -print0)

    make -C "${work_dir}" -j "${JOBS}" CLANG="${CLANG_BIN}" LLC="${LLC_BIN}" >/dev/null

    mkdir -p "${OUTPUT_ROOT}/corpus/build/katran"
    while IFS= read -r -d '' obj_path; do
        obj_name="$(basename "${obj_path}")"
        stage_name="${obj_name}"
        if [[ "${stage_name}" == *.o && "${stage_name}" != *.bpf.o ]]; then
            stage_name="${stage_name%.o}.bpf.o"
        fi
        cp "${obj_path}" "${OUTPUT_ROOT}/corpus/build/katran/${stage_name}"
    done < <(find "${work_dir}/bpf" -maxdepth 1 -type f -name '*.o' -print0)
}

sync_katran_source_tree() {
    local repo_dir="$1"
    mkdir -p "${KATRAN_SOURCE_DIR}"
    find "${KATRAN_SOURCE_DIR}" -mindepth 1 -maxdepth 1 ! -name '_build' -exec rm -rf {} +
    cp -a "${repo_dir}/." "${KATRAN_SOURCE_DIR}/"
}

prepare_local_katran_dependencies() {
    local src_dir="$1"
    local build_dir="$2"
    local install_dir="$3"

    log "Preparing local ARM64 Katran dependencies"
    (
        cd "$src_dir"
        env \
            CC="${CLANG_BIN}" \
            CXX="${CLANGXX_BIN}" \
            LD="${LD_LLD_BIN}" \
            CLANG="${CLANG_BIN}" \
            LLC="${LLC_BIN}" \
            LLVM_CONFIG="${LLVM_CONFIG_BIN}" \
            LLVM_OBJCOPY="${LLVM_OBJCOPY_BIN}" \
            LLVM_STRIP="${LLVM_STRIP_BIN}" \
            INSTALL_DEPS_ONLY=1 \
            BUILD_EXAMPLE_GRPC=1 \
            NCPUS="${JOBS}" \
            bash "$src_dir/build_katran.sh" -p "$build_dir" -i "$install_dir"
    )
}

build_katran_binary_with_wrapper() {
    local src_dir="$1"
    local build_dir="$2"
    local install_dir="$3"
    local cmake_build_dir="$build_dir/build"

    mkdir -p "$cmake_build_dir"
    (
        cd "$cmake_build_dir"
        CC="${CLANG_BIN}" \
        CXX="${CLANGXX_BIN}" \
        LD="${LD_LLD_BIN}" \
        cmake -G Ninja \
            -DCMAKE_C_COMPILER="${CLANG_BIN}" \
            -DCMAKE_CXX_COMPILER="${CLANGXX_BIN}" \
            -DCMAKE_LINKER="${LD_LLD_BIN}" \
            -DCMAKE_PREFIX_PATH="$install_dir" \
            -DCMAKE_INSTALL_PREFIX="$install_dir" \
            -DCMAKE_BUILD_TYPE=RelWithDebInfo \
            -DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON \
            -DLIB_BPF_PREFIX="$install_dir" \
            -DCMAKE_CXX_STANDARD=17 \
            -DBUILD_TESTS=OFF \
            -DCMAKE_BUILD_EXAMPLE_GRPC=ON \
            -DCMAKE_BUILD_EXAMPLE_THRIFT=OFF \
            -DCMAKE_BUILD_TOOLS=OFF \
            -DCMAKE_BUILD_KATRAN_TPR=OFF \
            "$src_dir"
        cmake --build . -j "${JOBS}" --target katran_server_grpc
    )
}

build_katran_server_bundle() {
    local repo_dir="${BENCH_BUILD_REPO_ROOT}/katran"
    local bundle_dir="${OUTPUT_ROOT}/katran"
    local binary_path="${KATRAN_BUILD_DIR}/build/example_grpc/katran_server_grpc"

    log "Building local ARM64 katran_server_grpc bundle"
    sync_katran_source_tree "${repo_dir}"
    rm -rf "${KATRAN_BUILD_DIR}/build" "${bundle_dir}"
    prepare_local_katran_dependencies "${KATRAN_SOURCE_DIR}" "${KATRAN_BUILD_DIR}" "${KATRAN_INSTALL_DIR}"
    build_katran_binary_with_wrapper "${KATRAN_SOURCE_DIR}" "${KATRAN_BUILD_DIR}" "${KATRAN_INSTALL_DIR}"
    [[ -x "${binary_path}" ]] || die "missing local ARM64 katran_server_grpc: ${binary_path}"
    file "${binary_path}" | grep -F "ARM aarch64" >/dev/null \
        || die "local Katran build did not produce an ARM64 server: ${binary_path}"
    mkdir -p "${bundle_dir}/bin" "${bundle_dir}/lib"
    cp "${binary_path}" "${bundle_dir}/bin/katran_server_grpc"
    copy_runtime_bundle "${bundle_dir}/bin/katran_server_grpc" "${bundle_dir}/lib"
}

build_katran_artifacts() {
    local repo_dir="${BENCH_BUILD_REPO_ROOT}/katran"
    prepare_repo_copy "katran" "${repo_dir}"
    build_katran_bpf_artifacts
    build_katran_server_bundle
}

build_benchmark_repo_artifacts() {
    local repo
    [[ -n "${BENCH_REPOS_RAW}" ]] || return 0
    IFS=',' read -r -a repos <<<"${BENCH_REPOS_RAW}"
    for repo in "${repos[@]}"; do
        [[ -n "${repo}" ]] || continue
        case "${repo}" in
            bcc)
                build_bcc_artifacts
                ;;
            katran)
                build_katran_artifacts
                ;;
            tracee)
                build_tracee_artifacts
                ;;
            tetragon)
                build_tetragon_artifacts
                ;;
            *)
                die "unsupported ARM64 benchmark crossbuild repo: ${repo}"
                ;;
        esac
    done
}

build_isolated_native_corpus_repo() {
    local repo_name="$1"
    local stage_dir="${BENCH_STAGE_ROOT}/${repo_name}"

    log "Building isolated ARM64 ${repo_name} artifacts"
    prepare_repo_copy "${repo_name}" "${BENCH_BUILD_REPO_ROOT}/${repo_name}"
    rm -rf "${stage_dir}"
    mkdir -p "${BENCH_STAGE_ROOT}"
    RUNNER_REPOS_DIR_OVERRIDE="${BENCH_BUILD_REPO_ROOT}" \
        python3 "${REPO_ROOT}/runner/scripts/build_corpus_native.py" \
            --jobs "${JOBS}" \
            --build-root "${BENCH_STAGE_ROOT}" \
            --repo "${repo_name}"
    [[ -d "${stage_dir}" ]] || die "missing staged ARM64 ${repo_name} artifacts: ${stage_dir}"
}

copy_staged_corpus_repo_tree() {
    local repo_name="$1"
    local stage_dir="${BENCH_STAGE_ROOT}/${repo_name}"
    local output_dir="${OUTPUT_ROOT}/corpus/build/${repo_name}"

    [[ -d "${stage_dir}" ]] || die "missing staged ARM64 ${repo_name} tree: ${stage_dir}"
    rm -rf "${output_dir}"
    mkdir -p "${output_dir}"
    cp -a "${stage_dir}/." "${output_dir}/"
}

build_tracee_artifacts() {
    local binary_path

    build_isolated_native_corpus_repo "tracee"
    binary_path="${BENCH_STAGE_ROOT}/tracee/bin/tracee"
    [[ -x "${binary_path}" ]] || die "missing staged ARM64 tracee binary: ${binary_path}"
    file "${binary_path}" | grep -F "ARM aarch64" >/dev/null \
        || die "staged tracee binary is not ARM64: ${binary_path}"
    copy_staged_corpus_repo_tree "tracee"
}

build_tetragon_artifacts() {
    local binary_path

    build_isolated_native_corpus_repo "tetragon"
    binary_path="${BENCH_STAGE_ROOT}/tetragon/bin/tetragon"
    [[ -x "${binary_path}" ]] || die "missing staged ARM64 tetragon binary: ${binary_path}"
    file "${binary_path}" | grep -F "ARM aarch64" >/dev/null \
        || die "staged tetragon binary is not ARM64: ${binary_path}"
    copy_staged_corpus_repo_tree "tetragon"
}

build_llvmbpf_if_needed() {
    if [[ "${MICRO_EXEC_ENABLE_LLVMBPF}" != "ON" ]]; then
        return 0
    fi
    log "Building ARM64 llvmbpf static library"
    cmake -S "${REPO_ROOT}/vendor/llvmbpf" -B "${LLVMBPF_BUILD_DIR}" \
        -DCMAKE_BUILD_TYPE=Release \
        -DLLVM_DIR="$(${LLVM_CONFIG_BIN} --cmakedir)"
    cmake --build "${LLVMBPF_BUILD_DIR}" --target llvmbpf_vm -j "${JOBS}"
    [[ -f "${LLVMBPF_LIBRARY}" ]] || die "missing ARM64 llvmbpf archive: ${LLVMBPF_LIBRARY}"
}

build_runner() {
    log "Building ARM64 runner (MICRO_EXEC_ENABLE_LLVMBPF=${MICRO_EXEC_ENABLE_LLVMBPF})"
    make -C "${REPO_ROOT}/runner" \
        BUILD_DIR="${RUNNER_BUILD_DIR}" \
        JOBS="1" \
        LLVM_CONFIG="${LLVM_CONFIG_BIN}" \
        LLVMBPF_LLVM_DIR="$(${LLVM_CONFIG_BIN} --cmakedir)" \
        MICRO_EXEC_ENABLE_LLVMBPF="${MICRO_EXEC_ENABLE_LLVMBPF}" \
        MICRO_LLVMBPF_LIBRARY="${LLVMBPF_LIBRARY}" \
        MICRO_LLVMBPF_BUILD_CACHE="${LLVMBPF_BUILD_DIR}/CMakeCache.txt" \
        micro_exec
}

build_daemon() {
    log "Building ARM64 daemon"
    CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="${NATIVE_CARGO_LINKER}" \
    CARGO_TARGET_DIR="${DAEMON_TARGET_DIR}" \
    CC="${CLANG_BIN}" \
    CXX="${CLANGXX_BIN}" \
        cargo build \
            --release \
            -j "${JOBS}" \
            --manifest-path "${REPO_ROOT}/daemon/Cargo.toml"
}

copy_runtime_bundle() {
    local binary="$1"
    local output_lib_dir="${2:-${OUTPUT_ROOT}/lib}"
    local -a queue=("$binary")
    local current lib resolved resolved_base requested_base soname
    declare -A seen=()

    mkdir -p "${output_lib_dir}"
    while ((${#queue[@]})); do
        current="${queue[0]}"
        queue=("${queue[@]:1}")
        [[ -e "${current}" ]] || continue
        if [[ -n "${seen["$current"]:-}" ]]; then
            continue
        fi
        seen["$current"]=1
        while IFS= read -r lib; do
            [[ -n "${lib}" ]] || continue
            resolved="$(readlink -f "${lib}")"
            resolved_base="$(basename "${resolved}")"
            requested_base="$(basename "${lib}")"
            case "${resolved_base}" in
                ld-linux-aarch64.so.1|libc.so.6|libm.so.6|libpthread.so.0|librt.so.1|libdl.so.2|libresolv.so.2|libutil.so.1)
                    continue
                    ;;
            esac
            cp -L "${resolved}" "${output_lib_dir}/${resolved_base}"
            if [[ "${requested_base}" != "${resolved_base}" ]]; then
                ln -sfn "${resolved_base}" "${output_lib_dir}/${requested_base}"
            fi
            soname="$(readelf -d "${resolved}" 2>/dev/null | sed -n 's/.*Library soname: \\[\\(.*\\)\\].*/\\1/p' | head -n1)"
            if [[ -n "${soname}" && "${soname}" != "${resolved_base}" ]]; then
                ln -sfn "${resolved_base}" "${output_lib_dir}/${soname}"
            fi
            queue+=("${resolved}")
        done < <(ldd "${current}" | awk '/=> \// {print $3} /^\// {print $1}' | sort -u)
    done
}

copy_wrapper() {
    local wrapper="$1"
    local real_name="$2"
    cat >"${wrapper}" <<'WRAPPER'
#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUNDLE_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
LIB_DIR="$BUNDLE_ROOT/lib"
export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
exec "$SCRIPT_DIR/REAL_BINARY" "$@"
WRAPPER
    sed -i "s|REAL_BINARY|${real_name}|g" "${wrapper}"
    chmod +x "${wrapper}"
}

prepare_scx_checkout() {
    [[ -d "${SOURCE_REPO_ROOT}/scx" ]] || die "source repo ${SOURCE_REPO_ROOT}/scx is missing; fetch it locally before cross-arm64"
    rm -rf "${SCX_BUILD_REPO_DIR}"
    mkdir -p "$(dirname "${SCX_BUILD_REPO_DIR}")"
    cp -a "${SOURCE_REPO_ROOT}/scx" "${SCX_BUILD_REPO_DIR}"
    rm -rf "${SCX_BUILD_REPO_DIR}/target"
}

build_scx_artifacts() {
    local package
    [[ -n "${SCX_PACKAGES_RAW}" ]] || return 0
    log "Building ARM64 scx artifacts: ${SCX_PACKAGES_RAW}"
    prepare_scx_checkout
    IFS=',' read -r -a packages <<<"${SCX_PACKAGES_RAW}"
    scx_args=()
    for package in "${packages[@]}"; do
        [[ -n "${package}" ]] || continue
        scx_args+=(--package "${package}")
    done
    CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="${NATIVE_CARGO_LINKER}" \
    SCX_BUILD_JOBS="${JOBS}" \
    BPF_CLANG="${CLANG_BIN}" \
    CLANG="${CLANG_BIN}" \
    LLC="${LLC_BIN}" \
    LLVM_CONFIG="${LLVM_CONFIG_BIN}" \
    LLVM_OBJCOPY="${LLVM_OBJCOPY_BIN}" \
    LLVM_STRIP="${LLVM_STRIP_BIN}" \
    CC="${CLANG_BIN}" \
    CXX="${CLANGXX_BIN}" \
        python3 "${REPO_ROOT}/runner/scripts/build_scx_artifacts.py" \
            --force \
            --jobs "${JOBS}" \
            --repo-root "${SCX_BUILD_REPO_ROOT}" \
            --promote-root "${OUTPUT_ROOT}" \
            "${scx_args[@]}"
    mkdir -p "${OUTPUT_ROOT}/runner/repos/scx/target/release" "${OUTPUT_ROOT}/corpus/build/scx"
    for package in "${packages[@]}"; do
        [[ -n "${package}" ]] || continue
        cp "${SCX_BUILD_REPO_DIR}/target/release/${package}" \
            "${OUTPUT_ROOT}/runner/repos/scx/target/release/${package}"
        copy_runtime_bundle "${OUTPUT_ROOT}/runner/repos/scx/target/release/${package}"
    done
}

build_scx_artifacts
if [[ "${ONLY_SCX}" == "1" ]]; then
    exit 0
fi

if [[ "${ONLY_BENCH}" == "1" ]]; then
    build_benchmark_repo_artifacts
    exit 0
fi

build_llvmbpf_if_needed
build_runner
build_daemon

cp "${RUNNER_BUILD_DIR}/micro_exec" "${OUTPUT_ROOT}/runner/build/micro_exec.real"
cp "${DAEMON_TARGET_DIR}/release/bpfrejit-daemon" "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon.real"

copy_runtime_bundle "${OUTPUT_ROOT}/runner/build/micro_exec.real"
copy_runtime_bundle "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon.real"

copy_wrapper "${OUTPUT_ROOT}/runner/build/micro_exec" "micro_exec.real"
copy_wrapper "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon" "bpfrejit-daemon.real"

file "${OUTPUT_ROOT}/runner/build/micro_exec.real" | grep -F "ARM aarch64"
file "${OUTPUT_ROOT}/daemon/build/bpfrejit-daemon.real" | grep -F "ARM aarch64"
