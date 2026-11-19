#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=/workspaces/kprog-raw/perf/native-private-stack-20261119/candidate-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > /workspaces/kprog-raw/perf/native-private-stack-20261119/latest-candidate
exec > "$out/run.log" 2>&1
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
printf '%s waiting for batch EX\n' "$(date -u +%FT%TZ)" > "$out/progress.txt"
flock -x 7
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
printf '%s waiting for image EX\n' "$(date -u +%FT%TZ)" > "$out/progress.txt"
flock -x 9
run_candidate() {
  printf '%s applying native private-arena rule\n' "$(date -u +%FT%TZ)" > "$out/progress.txt"
  git apply --check kprog/results/native-private-stack-20261119/implementation.patch
  git apply kprog/results/native-private-stack-20261119/implementation.patch
  taskset -c 18 prlimit --as=17179869184 -- make -C kprog/libnativeloader checked-sim-stage > "$out/stage.log" 2>&1
  taskset -c 18 prlimit --as=17179869184 -- make -f kprog/results/native-private-stack-20261119/Makefile test OUT="$out" MODE=normalized
  taskset -c 18 prlimit --as=17179869184 -- make -f kprog/results/checked-probe-c-20261119/Makefile replay OUT="$out" > "$out/bcc-replay.log" 2>&1
  install -d "$out/array"
  taskset -c 18 prlimit --as=17179869184 -- make -f kprog/results/checked-array-c-20261119/Makefile test pipeline OUT="$out/array" > "$out/array.log" 2>&1
  taskset -c 18 python3 kprog/results/native-private-stack-20261119/publish.py "$out" "$(date -u +%FT%TZ)"
  printf '%s tests and publication complete\n' "$(date -u +%FT%TZ)" > "$out/progress.txt"
}
rc=0
# Disable errexit only around a subshell, whose own errexit remains active.
set +e
( set -e; run_candidate )
rc=$?
set -e
printf '%s\n' "$rc" > "$out/exit-code"
date -u +%FT%TZ > "$out/finished"
exit "$rc"
