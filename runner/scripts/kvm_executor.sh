#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RUNNER_DIR="$ROOT_DIR/runner"
REPO_ROOT="$ROOT_DIR"

MANIFEST_PATH="${1:?usage: kvm_executor.sh <manifest>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[kvm-executor][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

die() {
    printf '[kvm-executor][ERROR] %s\n' "$*" >&2
    exit 1
}

[[ "${RUN_EXECUTOR}" == "kvm" ]] || die "manifest executor is not kvm: ${RUN_EXECUTOR}"
[[ -n "${RUN_VM_BACKEND:-}" ]] || die "manifest VM backend is empty for suite ${RUN_SUITE_NAME}"
[[ -n "${RUN_VM_EXECUTABLE:-}" ]] || die "manifest VM executable is empty for suite ${RUN_SUITE_NAME}"
[[ -n "${RUN_VM_LOCK_SCOPE:-}" ]] || die "manifest VM lock scope is empty for suite ${RUN_SUITE_NAME}"
[[ -n "${RUN_SUITE_ENTRYPOINT:-}" ]] || die "manifest suite entrypoint is empty"

suite_command() {
    cat <<EOF
cd "$REPO_ROOT" && \
SCX_PROG_SHOW_RACE_MODE="${SCX_PROG_SHOW_RACE_MODE:-bpftool-loop}" \
SCX_PROG_SHOW_RACE_ITERATIONS="${SCX_PROG_SHOW_RACE_ITERATIONS:-20}" \
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT="${SCX_PROG_SHOW_RACE_LOAD_TIMEOUT:-20}" \
SCX_PROG_SHOW_RACE_SKIP_PROBE="${SCX_PROG_SHOW_RACE_SKIP_PROBE:-0}" \
FUZZ_ROUNDS="${FUZZ_ROUNDS:-1000}" \
PYTHON_BIN="${PYTHON:-python3}" \
bash "$REPO_ROOT/${RUN_SUITE_ENTRYPOINT}" "$REPO_ROOT" "$MANIFEST_PATH"
EOF
}

cmd=(
    "${PYTHON:-python3}" "$RUNNER_DIR/scripts/run_vm_shell.py"
    --vm-backend "${RUN_VM_BACKEND}"
    --vm-executable "${RUN_VM_EXECUTABLE}"
    --vm-lock-scope "${RUN_VM_LOCK_SCOPE}"
    --vm-machine-name "${RUN_VM_MACHINE_NAME:-$RUN_TARGET_NAME}"
    --vm-machine-arch "${RUN_VM_MACHINE_ARCH:-$RUN_TARGET_ARCH}"
    --action "vm-${RUN_SUITE_NAME}"
    --kernel-image "${BZIMAGE_PATH:-$REPO_ROOT/vendor/linux-framework/arch/x86/boot/bzImage}"
    --timeout "${RUN_VM_TIMEOUT_SECONDS:-7200}"
    --command "$(suite_command)"
)

if [[ -n "${RUN_VM_CPUS:-}" ]]; then
    cmd+=(--cpus "${RUN_VM_CPUS}")
fi
if [[ -n "${RUN_VM_MEM:-}" ]]; then
    cmd+=(--mem "${RUN_VM_MEM}")
fi

"${cmd[@]}"
