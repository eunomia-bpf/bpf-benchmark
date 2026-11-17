#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/bcc-helper-costs-20261117
    raw="$root/host-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s host exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    ulimit -v 2097152
    taskset -c 19 python3 kprog/results/bcc-helper-costs-20261117/analyze.py --output "$raw" > "$raw/analysis.log" 2>&1
    # Source-only comparison of the sole kernel's actual event-output bodies.
    for symbol in bpf_perf_event_output bpf_perf_event_output_tp bpf_perf_event_output_raw_tp; do
        taskset -c 19 objdump -d --disassemble="$symbol" /workspaces/.agent-state/kprog-ck/build-x86/vmlinux > "$raw/$symbol.txt"
    done
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/git
    flock -x 7
    out=kprog/results/bcc-helper-costs-20261117
    cp "$raw/costs.json" "$raw/readout.txt" "$out/"
    cp "$raw"/bpf_perf_event_output*.txt "$out/"
    printf '%s raw=%s\n' "$(date -u +%FT%TZ)" "$raw" > "$out/host-location.txt"
    git status --short --branch --untracked-files=no > "$raw/git-status.txt"
    git add -- "$out/costs.json" "$out/readout.txt" "$out/host-location.txt" \
        "$out/bpf_perf_event_output.txt" "$out/bpf_perf_event_output_tp.txt" "$out/bpf_perf_event_output_raw_tp.txt"
    git commit --only -m "record BCC helper ownership and current counter mix" -- "$out/costs.json" "$out/readout.txt" \
        "$out/host-location.txt" "$out/bpf_perf_event_output.txt" "$out/bpf_perf_event_output_tp.txt" \
        "$out/bpf_perf_event_output_raw_tp.txt" > "$raw/commit.log" 2>&1
    git push origin master > "$raw/push.log" 2>&1
    printf '%s analysis committed pushed raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
}
main
