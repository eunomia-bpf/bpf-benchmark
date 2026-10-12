#!/usr/bin/env bash
# Follow-up timing in the setup of ../cilium_x86_config_parity_counterbalanced_20261010:
# a fresh 8-vCPU, 64-GiB guest per cell pinned to host P-cores 0-7, 60 s phases, one guest at a time.
# cilium: the kinsn arm (JIT then kinsn) with JIT/JIT restart controls and two JIT->native bridge cells.
# katran: JIT/kinsn/native with native in both orders and JIT/JIT restart controls.
# Usage: run-series.sh cilium|katran
set -euo pipefail
export PATH="$HOME/.local/bin:$PATH"  # vng

root=$(cd "$(dirname "$0")/../../.." && pwd)
out="$root/corpus/results/x86_kinsn_cilium_katran_followup_20261011"
lock=/home/yunwei37/workspace/codex-runs/followup-20261011/host.lock
series=$1
runs="$out/runs-$series.tsv"
install -d "$out/logs"

case "$series" in
    cilium) app=cilium/agent; app_json=cilium__agent.json ;;
    katran) app=katran; app_json=katran.json ;;
    *) printf 'unknown series: %s\n' "$series" >&2; exit 2 ;;
esac

if [[ ! -f "$runs" ]]; then
    printf 'cell\tstats\tround\trole\trun_dir\thost_boot_id\tstarted_utc\tended_utc\trc\n' >"$runs"
fi

# The busiest host processes and the CPU each last ran on, to show what shared the host.
busy_snapshot() {
    {
        date -u +%Y-%m-%dT%H:%M:%SZ
        top -b -n 1 -o %CPU -w 160 | awk 'NR >= 7 && NR <= 22'
        for pid in $(top -b -n 1 -o %CPU | awk 'NR >= 8 && NR <= 22 && $9 > 10 {print $1}'); do
            printf '%s psr=%s allowed=%s\n' "$pid" "$(ps -o psr= -p "$pid" 2>/dev/null)" \
                "$(taskset -cp "$pid" 2>/dev/null | sed 's/.*: //')"
        done
    } >"$1" 2>&1 || true
}

cell_ok() {
    local dir=$1
    [[ -n "$dir" ]] \
        && jq -e '.status == "completed"' "$dir/metadata.json" >/dev/null 2>&1 \
        && jq -e '.status == "ok"' "$dir/details/apps/$app_json" >/dev/null 2>&1
}

cell_done() {
    local cell=$1 c s r ro dir b st en rc
    while IFS=$'\t' read -r c s r ro dir b st en rc; do
        if [[ "$c" == "$cell" && "$rc" == 0 ]] && cell_ok "$dir"; then
            return 0
        fi
    done < <(tail -n +2 "$runs")
    return 1
}

run_cell() {
    local stats=$1 round=$2 role=$3
    local cell="$series-stats-$stats-round-$round-$role"
    local attempt log started ended boot rc run_dir
    while ! cell_done "$cell"; do
        attempt=$(awk -F '\t' -v cell="$cell" 'NR > 1 && $1 == cell {n++} END {print n + 1}' "$runs")
        if (( attempt > 3 )); then
            printf '%s failed three times; stopping\n' "$cell" >&2
            exit 1
        fi
        log="$out/logs/$cell.attempt-$attempt.log"
        args=(
            -o x86-runner-runtime-image-tar corpus
            PLATFORM=kvm ARCH=x86 VM_CPU_PIN=0-7 VM_CPUS=8 VM_MEM=64G
            "BPFREJIT_CORPUS_APPS=$app" SAMPLES=1 WARMUPS=0
            WORKLOAD_DURATION=60 "BPFREJIT_CORPUS_BPF_STATS=$stats" TIMEOUT=2400
        )
        case "$role" in
            jit-kinsn) args+=(BPFREJIT_BENCH_PASSES=kinsn) ;;
            jit-native) args+=(BPFREJIT_SHIM_NATIVE_LOADER=post) ;;
            native-jit) args+=(BPFREJIT_SHIM_NATIVE_LOADER=baseline) ;;
            jit-jit) args+=(SKIP_REJIT=norejit) ;;
            *) printf 'unknown role: %s\n' "$role" >&2; exit 2 ;;
        esac

        exec 9>"$lock"
        flock 9
        # A failed cell's guest can take a while to exit; wait up to 10 minutes for any guest.
        for _ in $(seq 1 60); do
            pgrep -f '[q]emu-system|[v]irtme-run' >/dev/null || break
            sleep 10
        done
        if pgrep -f '[q]emu-system|[v]irtme-run' >/dev/null; then
            printf 'refusing to start %s while another guest is running\n' "$cell" >&2
            exit 1
        fi
        started=$(date -u +%Y-%m-%dT%H:%M:%SZ)
        boot=$(cat /proc/sys/kernel/random/boot_id)
        busy_snapshot "$out/logs/$cell.attempt-$attempt.busy-start.txt"
        set +e
        (cd "$root" && timeout --signal=INT --kill-after=30s 480s make "${args[@]}") >"$log" 2>&1
        rc=$?
        set -e
        busy_snapshot "$out/logs/$cell.attempt-$attempt.busy-end.txt"
        flock -u 9
        ended=$(date -u +%Y-%m-%dT%H:%M:%SZ)
        run_dir=$(sed -n 's/.*"artifact_run_dir": "\([^"]*\)".*/\1/p' "$log" | tail -n 1)
        printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' \
            "$cell" "$stats" "$round" "$role" "$run_dir" "$boot" "$started" "$ended" "$rc" >>"$runs"
        printf '%s %s attempt=%s rc=%s %s\n' "$ended" "$cell" "$attempt" "$rc" "${run_dir##*/}"
    done
}

if [[ "$series" == cilium ]]; then
    for round in 1 2 3 4 5 6; do
        if (( round % 2 )); then
            run_cell 0 "$round" jit-kinsn; run_cell 0 "$round" jit-jit
        else
            run_cell 0 "$round" jit-jit; run_cell 0 "$round" jit-kinsn
        fi
        if (( round == 2 || round == 5 )); then
            run_cell 0 "$round" jit-native
        fi
    done
    for round in 1 2 3; do
        if (( round % 2 )); then
            run_cell 1 "$round" jit-kinsn; run_cell 1 "$round" jit-jit
        else
            run_cell 1 "$round" jit-jit; run_cell 1 "$round" jit-kinsn
        fi
    done
else
    for stats in 0 1; do
        for round in 1 2 3; do
            if (( round % 2 )); then
                run_cell "$stats" "$round" jit-kinsn; run_cell "$stats" "$round" jit-native
                run_cell "$stats" "$round" native-jit; run_cell "$stats" "$round" jit-jit
            else
                run_cell "$stats" "$round" jit-jit; run_cell "$stats" "$round" native-jit
                run_cell "$stats" "$round" jit-native; run_cell "$stats" "$round" jit-kinsn
            fi
        done
    done
fi
echo "series $series done"
