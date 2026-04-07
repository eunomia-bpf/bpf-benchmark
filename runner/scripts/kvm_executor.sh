#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
RUNNER_DIR="$ROOT_DIR/runner"

MANIFEST_PATH="${1:?usage: kvm_executor.sh <manifest> <local_state_path>}"
LOCAL_STATE_PATH="${2:?usage: kvm_executor.sh <manifest> <local_state_path>}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[kvm-executor][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
[[ -f "$LOCAL_STATE_PATH" ]] || {
    printf '[kvm-executor][ERROR] local state file is missing: %s\n' "$LOCAL_STATE_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"
# shellcheck disable=SC1090
source "$LOCAL_STATE_PATH"

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
[[ -d "${RUN_LOCAL_STAGE_ROOT}" ]] || die "staged KVM workspace is missing: ${RUN_LOCAL_STAGE_ROOT}"
[[ -f "${RUN_LOCAL_STAGE_MANIFEST}" ]] || die "staged KVM manifest is missing: ${RUN_LOCAL_STAGE_MANIFEST}"

suite_command() {
    local workspace_root="${RUN_LOCAL_STAGE_ROOT}"
    local workspace_manifest="${RUN_LOCAL_STAGE_MANIFEST}"
    cat <<EOF
cd "$workspace_root" && \
bash "$workspace_root/runner/scripts/install_guest_prereqs.sh" "$workspace_root" "$workspace_manifest" && \
bash "$workspace_root/runner/scripts/validate_guest_prereqs.sh" "$workspace_root" "$workspace_manifest" && \
bash "$workspace_root/${RUN_SUITE_ENTRYPOINT}" "$workspace_root" "$workspace_manifest"
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
    --cwd "${RUN_LOCAL_STAGE_ROOT}"
    --rwdir "${RUN_LOCAL_STAGE_ROOT}"
    --command "$(suite_command)"
)

if [[ -n "${RUN_VM_CPUS:-}" ]]; then
    cmd+=(--cpus "${RUN_VM_CPUS}")
fi
if [[ -n "${RUN_VM_MEM:-}" ]]; then
    cmd+=(--mem "${RUN_VM_MEM}")
fi

"${cmd[@]}"
