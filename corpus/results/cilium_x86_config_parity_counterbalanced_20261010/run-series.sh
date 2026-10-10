#!/usr/bin/env bash
set -euo pipefail

root=$(cd "$(dirname "$0")/../../.." && pwd)
out="$root/corpus/results/cilium_x86_config_parity_counterbalanced_20261010"
coord=/home/yunwei37/workspace/codex-runs/COORDINATION.md
runs="$out/runs-fixed.tsv"
install -d "$out/logs-fixed"

if [[ ! -f "$runs" ]]; then
    printf 'cell\tstats\tround\torder_group\trole\trun_dir\thost_boot_id\tstarted_utc\tended_utc\trc\n' >"$runs"
fi

initial_boot=$(cat /proc/sys/kernel/random/boot_id)
if [[ -f "$out/host-boot-id.fixed" ]]; then
    recorded_boot=$(tr -d '\n' <"$out/host-boot-id.fixed")
    if [[ "$recorded_boot" != "$initial_boot" ]]; then
        printf '%s agent1 HOST-REBOOT detected-before-timing-resume previous=%s current=%s\n' \
            "$(date -u +%Y-%m-%dT%H:%M:%SZ)" "$recorded_boot" "$initial_boot" >>"$coord"
    fi
else
    printf '%s\n' "$initial_boot" >"$out/host-boot-id.fixed"
fi

run_cell() {
    local stats=$1 round=$2 order_group=$3 role=$4 exclusive_state attempt log
    local cell="fixed-stats-${stats}-round-${round}-${order_group}-${role}"
    local prior_cell prior_stats prior_round prior_group prior_role prior_dir
    local prior_boot prior_started prior_ended prior_rc
    while IFS=$'\t' read -r prior_cell prior_stats prior_round prior_group prior_role \
        prior_dir prior_boot prior_started prior_ended prior_rc; do
        if [[ "$prior_cell" == "$cell" && "$prior_rc" == 0 && -n "$prior_dir" ]] \
            && jq -e '.status == "completed"' "$prior_dir/metadata.json" >/dev/null \
            && jq -e '.status == "ok"' "$prior_dir/details/apps/cilium__agent.json" >/dev/null; then
            return
        fi
    done < <(tail -n +2 "$runs")
    attempt=$(awk -F '\t' -v cell="$cell" 'NR > 1 && $1 == cell {n++} END {print n + 1}' "$runs")
    log="$out/logs-fixed/$cell.attempt-$attempt.log"

    tail -n 1 "$coord" >/dev/null
    exclusive_state=$(rg 'HOST-EXCLUSIVE|HOST-EXCLUSIVE-END' "$coord" | tail -n 1)
    if [[ "$exclusive_state" != *"HOST-EXCLUSIVE-END"* && \
          "$exclusive_state" != *"HOST-EXCLUSIVE agent1"* ]]; then
        printf 'another agent owns the host: %s\n' "$exclusive_state" >&2
        exit 1
    fi
    if pgrep -f 'qemu-system|virtme-run' >/dev/null; then
        printf 'refusing to start %s while another guest is running\n' "$cell" >&2
        exit 1
    fi

    local started ended boot rc run_dir
    started=$(date -u +%Y-%m-%dT%H:%M:%SZ)
    boot=$(cat /proc/sys/kernel/random/boot_id)
    printf '%s agent1 GUEST-START cilium-counterbalanced-%s cpu=0-7 vcpus=8 mem=64G duration=60s fresh-guest\n' \
        "$started" "$cell" >>"$coord"

    args=(
        -o x86-runner-runtime-image-tar corpus
        PLATFORM=kvm ARCH=x86 VM_CPU_PIN=0-7 VM_CPUS=8 VM_MEM=64G
        BPFREJIT_CORPUS_APPS=cilium/agent SAMPLES=1 WARMUPS=0
        WORKLOAD_DURATION=60 "BPFREJIT_CORPUS_BPF_STATS=$stats" TIMEOUT=2400
    )
    case "$role" in
        jit-native) args+=(BPFREJIT_SHIM_NATIVE_LOADER=post) ;;
        native-jit) args+=(BPFREJIT_SHIM_NATIVE_LOADER=baseline) ;;
        jit-jit) args+=(SKIP_REJIT=norejit) ;;
        *) printf 'unknown role: %s\n' "$role" >&2; exit 1 ;;
    esac

    set +e
    (cd "$root" && timeout --signal=INT --kill-after=30s 480s make "${args[@]}") \
        2>&1 | tee "$log"
    rc=${PIPESTATUS[0]}
    set -e
    ended=$(date -u +%Y-%m-%dT%H:%M:%SZ)
    run_dir=$(sed -n 's/.*"artifact_run_dir": "\([^"]*\)".*/\1/p' "$log" | tail -n 1)
    printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
        "$cell" "$stats" "$round" "$order_group" "$role" "$run_dir" \
        "$boot" "$started" "$ended" "$rc" >>"$runs"
    printf '%s agent1 GUEST-END cilium-counterbalanced-%s rc=%s result=%s\n' \
        "$ended" "$cell" "$rc" "${run_dir##*/}" >>"$coord"
    if [[ $rc -ne 0 || -z "$run_dir" ]] \
        || ! jq -e '.status == "completed"' "$run_dir/metadata.json" >/dev/null \
        || ! jq -e '.status == "ok"' "$run_dir/details/apps/cilium__agent.json" >/dev/null; then
        printf '%s failed; rerun this script after diagnosis\n' "$cell" >&2
        exit 1
    fi
}

for stats in 0 1; do
    for round in 1 2 3; do
        if (( round % 2 )); then
            run_cell "$stats" "$round" jit-native jit-jit
            run_cell "$stats" "$round" jit-native jit-native
            run_cell "$stats" "$round" native-jit native-jit
            run_cell "$stats" "$round" native-jit jit-jit
        else
            run_cell "$stats" "$round" native-jit jit-jit
            run_cell "$stats" "$round" native-jit native-jit
            run_cell "$stats" "$round" jit-native jit-native
            run_cell "$stats" "$round" jit-native jit-jit
        fi
    done
done
