#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
ACTION="run"
MANIFEST_PATH="${1:?usage: aws_remote_prep.sh <manifest_path>}"

[[ -f "$MANIFEST_PATH" ]] || {
    printf '[aws-remote-prep][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"
# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/aws_prep_paths_lib.sh"
# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/aws_kernel_artifacts_lib.sh"
# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/aws_remote_prep_lib.sh"

with_state_lock ensure_instance_for_suite
load_state
printf 'STATE_INSTANCE_ID=%q\n' "${STATE_INSTANCE_ID:-}"
printf 'STATE_INSTANCE_IP=%q\n' "${STATE_INSTANCE_IP:-}"
printf 'STATE_REGION=%q\n' "${STATE_REGION:-}"
printf 'STATE_KERNEL_RELEASE=%q\n' "${STATE_KERNEL_RELEASE:-}"
