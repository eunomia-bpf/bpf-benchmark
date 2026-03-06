#!/usr/bin/env bash
set -uo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
DUMP_DIR="${SCRIPT_DIR}/jit-dumps"
RUNNER="${SCRIPT_DIR}/build/runner/micro_exec"
OBJDUMP_BIN="${OBJDUMP:-objdump}"

log() {
    printf '[dump_all_jit] %s\n' "$*"
}

warn() {
    printf '[dump_all_jit] warning: %s\n' "$*" >&2
}

need_cmd() {
    if ! command -v "$1" >/dev/null 2>&1; then
        printf '[dump_all_jit] error: required command not found: %s\n' "$1" >&2
        exit 1
    fi
}

build_if_needed() {
    local needs_build=0

    if [[ ! -x "${RUNNER}" ]]; then
        needs_build=1
    fi

    if ! compgen -G "${SCRIPT_DIR}/programs/*.bpf.o" >/dev/null; then
        needs_build=1
    fi

    if [[ "${needs_build}" -eq 1 ]]; then
        log "building micro_exec and BPF programs"
        make -C "${SCRIPT_DIR}" micro_exec programs
    fi
}

load_benchmarks() {
    python3 - <<'PY'
from benchmark_catalog import CONFIG_PATH, load_suite

suite = load_suite(CONFIG_PATH)
for benchmark in suite.benchmarks.values():
    print(f"{benchmark.name}\t{benchmark.program_object}\t{benchmark.kernel_input_size}")
PY
}

run_dump() {
    local runtime="$1"
    local benchmark="$2"
    local program="$3"
    local kernel_input_size="$4"
    local work_dir="$5"
    local log_path="${DUMP_DIR}/${benchmark}.${runtime}.log"
    local dump_name="${benchmark}.${runtime}.bin"
    local tmp_dump="${work_dir}/${dump_name}"
    local final_dump="${DUMP_DIR}/${dump_name}"
    local final_asm="${DUMP_DIR}/${benchmark}.${runtime}.asm"

    rm -f "${log_path}" "${tmp_dump}" "${final_dump}" "${final_asm}"

    local -a command
    if [[ "${runtime}" == "llvmbpf" ]]; then
        command=(
            "${RUNNER}"
            run-llvmbpf
            --program "${program}"
            --io-mode staged
            --repeat 1
            --dump-jit
        )
    else
        command=(
            sudo -n
            "${RUNNER}"
            run-kernel
            --program "${program}"
            --io-mode staged
            --repeat 1
            --input-size "${kernel_input_size}"
            --dump-jit
        )
    fi

    log "${benchmark}: running ${runtime}"
    if (cd "${work_dir}" && "${command[@]}") >"${log_path}" 2>&1; then
        :
    else
        warn "${benchmark} ${runtime} command failed; see ${log_path}"
    fi

    if [[ ! -f "${tmp_dump}" ]]; then
        warn "${benchmark} ${runtime} produced no dump"
        return 1
    fi

    if [[ ! -s "${tmp_dump}" ]]; then
        warn "${benchmark} ${runtime} produced an empty dump"
        mv -f "${tmp_dump}" "${final_dump}"
        : >"${final_asm}"
        return 1
    fi

    mv -f "${tmp_dump}" "${final_dump}"
    if ! "${OBJDUMP_BIN}" -D -b binary -m i386:x86-64 "${final_dump}" >"${final_asm}" 2>>"${log_path}"; then
        warn "${benchmark} ${runtime} objdump failed; see ${log_path}"
        return 1
    fi

    return 0
}

main() {
    need_cmd python3
    need_cmd "${OBJDUMP_BIN}"
    need_cmd make
    build_if_needed

    mkdir -p "${DUMP_DIR}"

    local success_count=0
    local failure_count=0

    local bench_rows=()
    mapfile -t bench_rows < <(cd "${SCRIPT_DIR}" && load_benchmarks)
    if [[ "${#bench_rows[@]}" -eq 0 ]]; then
        warn "no benchmarks found in config/micro_pure_jit.yaml"
        exit 1
    fi

    local tmp_root="${DUMP_DIR}/.tmp"
    rm -rf "${tmp_root}"
    mkdir -p "${tmp_root}"

    local row benchmark program kernel_input_size work_dir
    for row in "${bench_rows[@]}"; do
        IFS=$'\t' read -r benchmark program kernel_input_size <<<"${row}"
        if [[ ! -f "${program}" ]]; then
            warn "${benchmark} missing program object: ${program}"
            failure_count=$((failure_count + 2))
            continue
        fi

        work_dir="${tmp_root}/${benchmark}"
        rm -rf "${work_dir}"
        mkdir -p "${work_dir}"

        if run_dump "llvmbpf" "${benchmark}" "${program}" "${kernel_input_size}" "${work_dir}"; then
            success_count=$((success_count + 1))
        else
            failure_count=$((failure_count + 1))
        fi

        if run_dump "kernel" "${benchmark}" "${program}" "${kernel_input_size}" "${work_dir}"; then
            success_count=$((success_count + 1))
        else
            failure_count=$((failure_count + 1))
        fi
    done

    rm -rf "${tmp_root}"
    log "completed: ${success_count} runtime dumps succeeded, ${failure_count} failed"
}

main "$@"
