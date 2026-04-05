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
[[ -n "${RUN_HOST_PYTHON_BIN:-}" ]] || die "manifest KVM host python is empty for suite ${RUN_SUITE_NAME}"
[[ -n "${RUN_VM_KERNEL_IMAGE:-}" ]] || die "manifest KVM kernel image is empty for suite ${RUN_SUITE_NAME}"
[[ -n "${RUN_VM_TIMEOUT_SECONDS:-}" ]] || die "manifest KVM timeout is empty for suite ${RUN_SUITE_NAME}"
[[ -n "${RUN_SUITE_ENTRYPOINT:-}" ]] || die "manifest suite entrypoint is empty"

suite_command() {
    cat <<EOF
cd "$REPO_ROOT" && \
bash "$REPO_ROOT/runner/scripts/install_guest_prereqs.sh" "$REPO_ROOT" "$MANIFEST_PATH" && \
bash "$REPO_ROOT/runner/scripts/validate_guest_prereqs.sh" "$REPO_ROOT" "$MANIFEST_PATH" && \
bash "$REPO_ROOT/${RUN_SUITE_ENTRYPOINT}" "$REPO_ROOT" "$MANIFEST_PATH"
EOF
}

cmd=(
    "${RUN_HOST_PYTHON_BIN}" "$RUNNER_DIR/scripts/run_vm_shell.py"
    --vm-backend "${RUN_VM_BACKEND}"
    --vm-executable "${RUN_VM_EXECUTABLE}"
    --vm-lock-scope "${RUN_VM_LOCK_SCOPE}"
    --vm-machine-name "${RUN_VM_MACHINE_NAME:-$RUN_TARGET_NAME}"
    --vm-machine-arch "${RUN_VM_MACHINE_ARCH:-$RUN_TARGET_ARCH}"
    --action "vm-${RUN_SUITE_NAME}"
    --kernel-image "${RUN_VM_KERNEL_IMAGE}"
    --timeout "${RUN_VM_TIMEOUT_SECONDS}"
    --command "$(suite_command)"
)

if [[ -n "${RUN_VM_CPUS:-}" ]]; then
    cmd+=(--cpus "${RUN_VM_CPUS}")
fi
if [[ -n "${RUN_VM_MEM:-}" ]]; then
    cmd+=(--mem "${RUN_VM_MEM}")
fi

"${cmd[@]}"
