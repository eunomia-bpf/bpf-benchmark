#!/bin/bash
# Coordinator 2026-11-19: time the design's main configuration, LTO (checked-sim-c), on BCC. The guest runs on
# CPUs 0-7 with 8 vCPUs and 64 GiB like the frozen entry; the frozen corpus driver runs stats off 3 x 180 s,
# then stats on 3 x 60 s. Holds the timing lock exclusively and the image lock shared.
set -u
cd /workspaces/repository
R=kprog/results/lto-config-20261119
RAW=/workspaces/kprog-raw/lto-config-20261119
T=kprog/results/flag-tuning-20261117
KDIR=/workspaces/.agent-state/kprog-ck/build-x86
LOADER=/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
COMP=/workspaces/.agent-state/kprog-ck/verified-compiler
GB=/var/tmp/kprog-tmp/verified/lto-config
APPS=${*:-bcc/set}
mkdir -p "$RAW" "$GB"
log() { echo "$(date -u +%FT%TZ) $*" >> "$RAW/progress.log"; }
one() {  # app samples duration stats label
  local app=$1 samples=$2 dur=$3 stats=$4 out=$RAW/$5
  install -d "$out" "$out/loader-inputs" "$out/bounds-inputs"
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    make -C /workspaces/repository kvm-host-cpu >/dev/null 2>&1
    taskset -c 0-7 prlimit --as=103079215104 -- vng --run $KDIR/arch/x86/boot/bzImage \
      --cwd /workspaces/repository --rwdir /workspaces/repository --rwdir "$out" --rwdir /var/tmp=$GB \
      --rodir "$out/loader-inputs=$(dirname $LOADER)" --rodir "$out/bounds-inputs=$COMP" \
      --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
      --disable-monitor --verbose --cpus 8 --memory 64G --append 'loglevel=4 panic=30 oops=panic' \
      --exec "bash /workspaces/repository/$R/run_lto.sh $out $app $out/loader-inputs/$(basename $LOADER) $out/bounds-inputs/packet-bounds $samples $dur $stats"
  ) > "$out.log" 2>&1
  rm -f "$GB/bpf-benchmark-docker.img"
  local run; run=$(grep -a -o 'x86_kvm_corpus_2026[0-9_]*' "$out.log" | sort -u | tail -1); [ -n "$run" ] && run=/workspaces/repository/corpus/results/$run
  log "$5 $app run=$run"
  { echo "== LTO configuration (checked-sim-c) $5 $app $run"
    if [ -n "$run" ]; then
      if [ "$stats" = 0 ]; then python3 "$T/may29_ratio.py" "off=$run"; else python3 "$T/may29_ratio.py" "off=$run" "on=$run"; fi
      python3 "$T/inst.py" "$run"
      d=$run/details/shim-logs
      echo "function native replaced $(cat $d/*post_rejit* 2>/dev/null | grep -a -c 'native-loader replaced') failed $(cat $d/*post_rejit* 2>/dev/null | grep -a -c 'native-loader failed')"
    fi; } >> "$RAW/summary.txt" 2>&1
  cp "$RAW/summary.txt" "$R/summary.txt"
  git add "$R/summary.txt"; git commit -q -m "LTO configuration timing: $app ($5)" -- "$R/summary.txt" && git push -q origin HEAD:master
}
log "start $(git rev-parse --short HEAD)"
for app in $APPS; do a=$(echo $app | tr / _); one "$app" 3 180 0 "${a}-off"; done
for app in $APPS; do a=$(echo $app | tr / _); one "$app" 3 60 1 "${a}-on"; done
log "done"
