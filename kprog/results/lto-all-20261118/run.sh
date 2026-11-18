#!/bin/bash
# Coordinator 2026-11-18: one image with every LTO change since image 55c1c443 (PERF's map-dispatch fusion, tail short
# forms, named-map CFG, zero-tail sharing, trie addressing/prefix/flag/direct entry, UID packed load, clock field operands,
# runtime ARRAY operands and direct returns, dead helper IDs, inline helper labels), the core-compat.h single argument
# evaluation (9be7e30be), loader items 5a-5f, and the helper-context manifest line (every native entry binds the kernel
# functions the original program uses, e.g. bpf_perf_event_output_tp; kprog/results/helper-context-query-20261117).
# Order: the checked Tracee guest yields the image at its next request boundary (at most 40 minutes; raw stays), then
# image, one-image check, six apps breadth-first through the frozen entry with its defaults (3 x 180 s, stats off) for
# the 2026-05-29 floors, then the six apps again with stats on, 3 x 60 s, for per call. locks/batch is held from image
# build to the last timing run; host load is logged as the second top frame (CPU over the last 2 s).
set -u
cd /workspaces/repository
R=kprog/results/lto-all-20261118
T=kprog/results/flag-tuning-20261117
RAW=/workspaces/kprog-raw/lto-all-20261118
INPUTS="kprog/x86/native_lab/native_link kprog/libnativeloader kprog/x86/perf_context_lto.cpp kprog/x86/link_embedded_ir.cpp vendor/bpf/Makefile vendor/bpf/write_native_manifest.py bpfopt"
APPS="otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran"
mkdir -p "$RAW"
log() { echo "$(date -u +%FT%TZ) $*" >> "$RAW/progress.log"; }
load() { { echo "== $(date -u +%FT%TZ) $1"; cat /proc/loadavg; top -b -n 2 -d 2 -o %CPU | awk '/^top -/{n++} n==2' | sed -n '1,4p;7,14p'; } >> "$RAW/hostload.log"; }

# 1. the checked Tracee guest yields the image
Q=2754989
J=$(ls /workspaces/kprog-raw/verified/20261117-checked-hot/tracee/state/session-*/requests/requests.jsonl 2>/dev/null | head -1)
if [ -d /proc/$Q ] && grep -q qemu-system /proc/$Q/comm 2>/dev/null; then
  n0=$( [ -n "$J" ] && wc -l < "$J" || echo 0 ); log "checked Tracee guest $Q running, $n0 requests; waiting for the next request boundary (40 min at most)"
  for i in $(seq 1 40); do
    n=$( [ -n "$J" ] && wc -l < "$J" || echo 0 ); [ "$n" -gt "$n0" ] && break; [ -d /proc/$Q ] || break; sleep 60
  done
  if [ -d /proc/$Q ] && grep -q qemu-system /proc/$Q/comm 2>/dev/null; then
    log "stopping checked Tracee guest $Q at $( [ -n "$J" ] && wc -l < "$J") requests (raw stays)"; kill "$Q"
  fi
fi
until flock -n /workspaces/.agent-state/kprog-lanes/locks/image true; do log "waiting for the image lock"; sleep 60; done

# 2. committed build inputs, then the batch
while [ -n "$(git status --porcelain -- $INPUTS; ls vendor/bpf/*compat*.h | xargs git status --porcelain --)" ]; do
  log "waiting for committed build inputs"; sleep 120
done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
log "build at $(git rev-parse --short HEAD)"
if ! ( exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
       taskset -c 8-23 make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$RAW/image.log" 2>&1; then
  log "image FAILED"; exit 1
fi
log "image ok"
{ echo "image: $(docker image inspect --format '{{.Id}}' bpf-benchmark/kprog:current) source $(git rev-parse --short HEAD)"
  python3 "$T/textsize.py" vendor/build/native-bpf/x86/stage; } > "$RAW/summary.txt"
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
  make -f kprog/perf/one-image/Makefile check ) > "$RAW/check.log" 2>&1
tail -6 /workspaces/kprog-raw/one-image-runs/check.log >> "$RAW/summary.txt"
log "check finished"
cp "$RAW/summary.txt" "$R/summary.txt"; git commit -q -m "LTO batch 2026-11-18: image and one-image check" -- "$R/summary.txt" && git push -q origin HEAD:master

# 3. six apps, stats off, frozen entry defaults (floors); then stats on, 3 x 60 s (per call)
for phase in off on; do
  for app in $APPS; do
    a=$(echo "$app" | tr / _)
    ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
      load "before $phase $app"
      if [ $phase = off ]; then make -f kprog/perf/one-image/Makefile corpus APPS="$app"
      else make -f kprog/perf/one-image/Makefile corpus APPS="$app" SAMPLES=3 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=1; fi
      load "after $phase $app" ) > "$RAW/${a}_$phase.log" 2>&1
    run=$(grep -o '"artifact_run_dir": "[^"]*"' "$RAW/${a}_$phase.log" | tail -1 | cut -d'"' -f4)
    log "$phase $app run=$run"
    { echo "== $phase $app $run"
      if [ -n "$run" ]; then
        if [ $phase = off ]; then python3 "$T/may29_ratio.py" "off=$run"; else python3 "$T/may29_ratio.py" "off=$run" "on=$run"; fi
        python3 "$T/inst.py" "$run"
        [ $phase = on ] && python3 kprog/results/arm-paths-20261116/paths.py "$run" | head -4
      fi; } >> "$RAW/summary.txt" 2>&1
    cp "$RAW/summary.txt" "$R/summary.txt"
    git commit -q -m "LTO batch 2026-11-18: $app (stats $phase)" -- "$R/summary.txt" && git push -q origin HEAD:master
  done
done
log "done"
