#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
CACHE_DIR="$ROOT_DIR/.cache/runner-contracts"

# shellcheck source=runner/scripts/load_run_contract.sh
source "$ROOT_DIR/runner/scripts/load_run_contract.sh"

die() {
    printf '[run-target-suite][ERROR] %s\n' "$*" >&2
    exit 1
}

usage() {
    cat <<'EOF'
usage:
  run_target_suite.sh run <target> <suite>
  run_target_suite.sh terminate <target>
EOF
}

action="${1:-}"
target_name="${2:-}"
suite_name="${3:-}"
manifest_path=""

case "$action" in
    run)
        [[ -n "$target_name" && -n "$suite_name" ]] || {
            usage
            exit 1
        }
        mkdir -p "$CACHE_DIR"
        manifest_path="$(mktemp "$CACHE_DIR/run.${target_name}.${suite_name}.XXXXXX.env")"
        trap 'rm -f "$manifest_path"' EXIT
        run_contract_write_manifest "$target_name" "$suite_name" "$manifest_path"
        # shellcheck disable=SC1090
        source "$manifest_path"
        if [[ "$RUN_EXECUTOR" == "kvm" ]]; then
            "$ROOT_DIR/runner/scripts/prepare_run_inputs.sh" "$manifest_path"
        fi
        case "$RUN_EXECUTOR" in
            kvm)
                "$ROOT_DIR/runner/scripts/kvm_executor.sh" "$manifest_path"
                ;;
            aws-ssh)
                "$ROOT_DIR/runner/scripts/aws_executor.sh" run "$manifest_path"
                ;;
            *)
                die "unsupported executor: ${RUN_EXECUTOR}"
                ;;
        esac
        ;;
    terminate)
        [[ -n "$target_name" ]] || {
            usage
            exit 1
        }
        mkdir -p "$CACHE_DIR"
        manifest_path="$(mktemp "$CACHE_DIR/terminate.${target_name}.XXXXXX.env")"
        trap 'rm -f "$manifest_path"' EXIT
        run_contract_write_target_manifest "$target_name" "$manifest_path"
        # shellcheck disable=SC1090
        source "$manifest_path"
        case "$RUN_EXECUTOR" in
            aws-ssh)
                "$ROOT_DIR/runner/scripts/aws_executor.sh" terminate "$manifest_path"
                ;;
            *)
                die "terminate is only valid for AWS targets"
                ;;
        esac
        ;;
    *)
        usage
        exit 1
        ;;
esac
