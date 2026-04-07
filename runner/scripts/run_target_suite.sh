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
  run_target_suite.sh benchmark <target> <micro|corpus|e2e|all>
  run_target_suite.sh terminate <target>
EOF
}

action="${1:-}"
target_name="${2:-}"
suite_name="${3:-}"
manifest_path=""
local_state_path=""
remote_prep_state_path=""
prep_cleanup_armed="0"

cleanup_failed_dedicated_aws_prep() {
    local manifest="$1"
    (
        set -euo pipefail
        local root_dir="$ROOT_DIR"
        ROOT_DIR="$root_dir"
        ACTION="run"
        MANIFEST_PATH="$manifest"
        LOCAL_STATE_PATH=""
        AWS_REMOTE_PREP_STATE_PATH=""
        # shellcheck disable=SC1090
        source "$root_dir/runner/scripts/aws_common_lib.sh"
        [[ "${RUN_AWS_INSTANCE_MODE:-shared}" == "dedicated" ]] || exit 0
        load_state
        if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
            terminate_instance "${STATE_INSTANCE_ID}" || true
        fi
        rm -rf "$RUN_STATE_DIR"
    )
}

run_benchmark_action() {
    local target="$1"
    local mode="$2"
    local target_manifest=""
    case "$mode" in
        micro|corpus|e2e)
            exec "$0" run "$target" "$mode"
            ;;
        all)
            mkdir -p "$CACHE_DIR"
            target_manifest="$(mktemp "$CACHE_DIR/benchmark-target.${target}.XXXXXX.env")"
            trap 'rm -f "$manifest_path" "$local_state_path" "$remote_prep_state_path" "$target_manifest"' EXIT
            run_contract_write_target_manifest "$target" "$target_manifest"
            # shellcheck disable=SC1090
            source "$target_manifest"
            if [[ "${RUN_EXECUTOR}" != "aws-ssh" ]]; then
                "$0" run "$target" micro
                "$0" run "$target" corpus
                "$0" run "$target" e2e
                return 0
            fi
            local status=0
            "$0" run "$target" micro & p1=$!
            "$0" run "$target" corpus & p2=$!
            "$0" run "$target" e2e & p3=$!
            wait "$p1" || status=$?
            wait "$p2" || status=$?
            wait "$p3" || status=$?
            return "$status"
            ;;
        *)
            die "unsupported benchmark mode: ${mode}"
            ;;
    esac
}

case "$action" in
    run)
        [[ -n "$target_name" && -n "$suite_name" ]] || {
            usage
            exit 1
        }
        mkdir -p "$CACHE_DIR"
        manifest_path="$(mktemp "$CACHE_DIR/run.${target_name}.${suite_name}.XXXXXX.env")"
        local_state_path="$(mktemp "$CACHE_DIR/run-local.${target_name}.${suite_name}.XXXXXX.env")"
        remote_prep_state_path="$(mktemp "$CACHE_DIR/run-remote.${target_name}.${suite_name}.XXXXXX.env")"
        trap 'if [[ "$prep_cleanup_armed" == "1" ]]; then cleanup_failed_dedicated_aws_prep "$manifest_path"; fi; rm -f "$manifest_path" "$local_state_path" "$remote_prep_state_path"' EXIT
        run_contract_write_manifest "$target_name" "$suite_name" "$manifest_path"
        # shellcheck disable=SC1090
        source "$manifest_path"
        if [[ "$RUN_EXECUTOR" == "aws-ssh" ]]; then
            if [[ "${RUN_AWS_INSTANCE_MODE:-shared}" == "dedicated" ]]; then
                prep_cleanup_armed="1"
            fi
            bash "$ROOT_DIR/runner/scripts/aws_remote_prep.sh" "$manifest_path" >"$remote_prep_state_path"
            bash "$ROOT_DIR/runner/scripts/prepare_local_inputs.sh" \
                "$manifest_path" \
                "$remote_prep_state_path" >"$local_state_path"
            prep_cleanup_armed="0"
        else
            bash "$ROOT_DIR/runner/scripts/prepare_local_inputs.sh" "$manifest_path" >"$local_state_path"
        fi
        # shellcheck disable=SC1090
        source "$local_state_path"
        case "$RUN_EXECUTOR" in
            kvm)
                bash "$ROOT_DIR/runner/scripts/kvm_executor.sh" \
                    "$manifest_path" \
                    "$local_state_path"
                ;;
            aws-ssh)
                bash "$ROOT_DIR/runner/scripts/aws_executor.sh" run "$manifest_path" "$local_state_path"
                ;;
            *)
                die "unsupported executor: ${RUN_EXECUTOR}"
                ;;
        esac
        ;;
    benchmark)
        [[ -n "$target_name" && -n "$suite_name" ]] || {
            usage
            exit 1
        }
        run_benchmark_action "$target_name" "$suite_name"
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
                bash "$ROOT_DIR/runner/scripts/aws_executor.sh" terminate "$manifest_path"
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
