#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
MANIFEST_PATH="${1:?usage: prepare_local_inputs.sh <manifest_path> [remote_prep_state_path]}"
REMOTE_PREP_STATE_PATH="${2:-}"
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[prepare-local-inputs][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}
# shellcheck disable=SC1090
source "$MANIFEST_PATH"

die() {
    printf '[prepare-local-inputs][ERROR] %s\n' "$*" >&2
    exit 1
}

[[ -n "${RUN_HOST_PYTHON_BIN:-}" ]] || die "manifest host python is missing"
HOST_PYTHON_BIN="${RUN_HOST_PYTHON_BIN}"

prepare_aws_workspace() {
    [[ -n "$REMOTE_PREP_STATE_PATH" ]] || die "AWS local prep requires an explicit remote-prep state path"
    [[ -f "$REMOTE_PREP_STATE_PATH" ]] || die "AWS remote-prep state is missing: ${REMOTE_PREP_STATE_PATH}"
    # shellcheck disable=SC1090
    ACTION="run"
    # shellcheck disable=SC2034
    AWS_REMOTE_PREP_STATE_PATH="$REMOTE_PREP_STATE_PATH"
    source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"
    # shellcheck disable=SC1090
    source "$ROOT_DIR/runner/scripts/aws_prep_paths_lib.sh"
    # shellcheck disable=SC1090
    source "$ROOT_DIR/runner/scripts/aws_local_prep_lib.sh"
    aws_prepare_local_action
}

case "${RUN_EXECUTOR}" in
    kvm)
        # shellcheck disable=SC1090
        source "$ROOT_DIR/runner/scripts/kvm_local_prep_lib.sh"
        kvm_prepare_local_action
        ;;
    aws-ssh)
        prepare_aws_workspace
        ;;
    *)
        die "unsupported executor for local prep: ${RUN_EXECUTOR}"
        ;;
esac
