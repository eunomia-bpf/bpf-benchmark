#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
ACTION="${1:-}"
MANIFEST_PATH="${2:-}"
LOCAL_STATE_PATH="${3:-}"

[[ -n "$ACTION" ]] || {
    printf '[aws-executor][ERROR] usage: aws_executor.sh <run|terminate> <manifest_path> [local_state_path]\n' >&2
    exit 1
}
[[ -n "$MANIFEST_PATH" ]] || {
    printf '[aws-executor][ERROR] manifest path is required\n' >&2
    exit 1
}
[[ -f "$MANIFEST_PATH" ]] || {
    printf '[aws-executor][ERROR] manifest is missing: %s\n' "$MANIFEST_PATH" >&2
    exit 1
}

# shellcheck disable=SC1090
source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"

run_remote_suite() {
    local ip="$1"
    local stamp local_result_dir local_archive local_log remote_run_dir remote_archive remote_log remote_tool_root
    wait_for_ssh "$ip"
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "local bundle path is unset; local bundle preparation did not run"
    [[ -f "${RUN_BUNDLE_TAR}" ]] || die "prepared remote bundle is missing: ${RUN_BUNDLE_TAR}"
    setup_remote_runtime_prereqs "$ip"

    stamp="${RUN_SUITE_NAME}_${RUN_TOKEN}_$(date -u +%Y%m%d_%H%M%S)"
    local_result_dir="$RESULTS_DIR/$stamp"
    local_archive="$local_result_dir/results.tar.gz"
    local_log="$local_result_dir/remote.log"
    remote_run_dir="$RUN_REMOTE_STAGE_DIR/runs/$stamp"
    remote_tool_root="$(remote_prereq_workload_tool_root)"
    remote_archive="$remote_run_dir/results.tar.gz"
    remote_log="$remote_run_dir/remote.log"
    mkdir -p "$local_result_dir"

    ssh_bash "$ip" "$remote_run_dir" <<'EOF'
set -euo pipefail
run_dir="$1"
sudo rm -rf "$run_dir"
mkdir -p "$run_dir"
EOF
    scp_to "$ip" "$RUN_BUNDLE_TAR" "$remote_run_dir/bundle.tar.gz"
    local remote_status=0
    set +e
    ssh_bash "$ip" "$remote_run_dir" "$remote_archive" "$remote_log" "$remote_tool_root" <<'EOF'
set -euo pipefail
run_dir="$1"
archive_path="$2"
log_path="$3"
tool_root="$4"
workspace="$run_dir/workspace"
bundle_path="$run_dir/bundle.tar.gz"
sudo rm -rf "$workspace"
mkdir -p "$workspace"
tar -xzf "$bundle_path" -C "$workspace"
rm -f "$bundle_path"
if [[ -d "$tool_root" ]]; then
    mkdir -p "$workspace/.cache"
    mkdir -p "$workspace/.cache/workload-tools"
    cp -a "$tool_root/." "$workspace/.cache/workload-tools/"
fi
test -f "$workspace/run-contract.env"
# shellcheck disable=SC1090
source "$workspace/run-contract.env"
[[ -n "${RUN_SUITE_ENTRYPOINT:-}" ]] || exit 1
chmod +x "$workspace/$RUN_SUITE_ENTRYPOINT"
    sudo -E bash "$workspace/$RUN_SUITE_ENTRYPOINT" \
        "$workspace" "$workspace/run-contract.env" "$archive_path" >"$log_path" 2>&1
EOF
    remote_status=$?
    set -e
    if ssh_bash "$ip" "$remote_log" <<'EOF' >/dev/null 2>&1
set -euo pipefail
test -f "$1"
EOF
    then
        scp_from "$ip" "$remote_log" "$local_log"
    fi
    (( remote_status == 0 )) || die "remote ${RUN_TARGET_NAME}/${RUN_SUITE_NAME} suite failed; inspect ${local_log}"
    scp_from "$ip" "$remote_archive" "$local_archive"
    tar -xzf "$local_archive" -C "$local_result_dir"
    ssh_bash "$ip" "$remote_run_dir" <<'EOF' >/dev/null 2>&1 || true
set -euo pipefail
sudo rm -rf "$1"
EOF
    log "Fetched ${RUN_TARGET_NAME}/${RUN_SUITE_NAME} results to ${local_result_dir}"
}

dedicated_instance_cleanup() {
    cleanup_local_run_prep_root
    if (( DEDICATED_RUN_ACTIVE == 0 )); then
        return 0
    fi
    load_state
    if [[ -n "${STATE_INSTANCE_ID:-}" ]]; then
        terminate_instance "${STATE_INSTANCE_ID}" || true
    fi
    rm -rf "$RUN_STATE_DIR"
}

run_shared_remote_execution() {
    with_state_lock load_state
    [[ -n "${STATE_INSTANCE_IP:-}" ]] || die "shared AWS run is missing STATE_INSTANCE_IP before remote execution"
    run_remote_suite "$STATE_INSTANCE_IP"
}

run_shared_suite_action() {
    load_local_state_if_present
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "local bundle path is unset; run canonical local prep first"
    [[ -f "${RUN_BUNDLE_TAR}" ]] || die "prepared remote bundle is missing: ${RUN_BUNDLE_TAR}"
    with_remote_execution_lock run_shared_remote_execution
}

run_suite_action() {
    local instance_ip=""
    if aws_instance_mode_is_shared; then
        run_shared_suite_action
        return 0
    fi

    DEDICATED_RUN_ACTIVE=1
    trap dedicated_instance_cleanup EXIT
    with_state_lock load_state
    instance_ip="${STATE_INSTANCE_IP:-}"
    [[ -n "$instance_ip" ]] || die "dedicated AWS run is missing STATE_INSTANCE_IP before remote execution"
    load_local_state_if_present
    [[ -n "${RUN_BUNDLE_TAR:-}" ]] || die "local bundle path is unset; run canonical local prep first"
    [[ -f "${RUN_BUNDLE_TAR}" ]] || die "prepared remote bundle is missing: ${RUN_BUNDLE_TAR}"
    run_remote_suite "$instance_ip"
    DEDICATED_RUN_ACTIVE=0
    trap - EXIT
    terminate_instance "${STATE_INSTANCE_ID:-}"
    rm -rf "$RUN_STATE_DIR"
}

main() {
    case "$ACTION" in
        run)
            run_suite_action
            ;;
        terminate)
            terminate_instance
            ;;
        *)
            die "unsupported aws executor action: ${ACTION}"
            ;;
    esac
}

main "$@"
