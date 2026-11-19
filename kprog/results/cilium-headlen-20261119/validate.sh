#!/bin/bash
set -euo pipefail
cd /workspaces/repository
base=/workspaces/kprog-raw/perf/cilium-headlen-20261119
out=$base/check-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"
printf '%s\n' "$out" > "$base/latest-check"
exec > "$out/run.log" 2>&1
finish(){ printf '%s\n' "$?" > "$out/exit-code"; date -u +%FT%TZ > "$out/finished"; }
trap finish EXIT
date -u +%FT%TZ > "$out/queued"
make -n -f kprog/results/b-pointer-difference-20261119/Makefile rebuild > "$out/rebuild-dry-run.log"
make -n -f kprog/results/cilium-headlen-20261119/Makefile check OUT="$out/fixture" MODE=after > "$out/check-dry-run.log"
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 9
git rev-parse HEAD > "$out/source-commit"
date -u +%FT%TZ > "$out/started"
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile rebuild
flock -s 9
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/cilium-headlen-20261119/Makefile check OUT="$out/fixture" MODE=after
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/b-pointer-difference-20261119/Makefile test OUT="$out/pointer-fixture" MODE=fixed
taskset -c 19 prlimit --as=4294967296 -- make -f kprog/results/constant-alu32-20261119/Makefile test OUT="$out/alu32" MODE=fixed
taskset -c 19 prlimit --as=8589934592 -- make -f kprog/results/b-pointer-difference-20261119/Makefile replay OUT="$out/katran" REQUEST=katran
date -u +%FT%TZ > "$out/compiler-ready"
printf -- '- LANE PERF %s: Combined canonical bounds compiler rebuilt; headlen/offset/ALU32 controls and captured Katran B replay pass, raw %s. Stock fixtures/40captured replay/current Cilium follow; no stock/app gain inferred.\n' "$(date -u +%FT%TZ)" "$out" >> /workspaces/.agent-state/kprog-lanes/COORDINATION.md
make -n -f kprog/results/cilium-headlen-20261119/Makefile stock-probe > "$out/stock-probe-dry-run.log"
taskset -c 19 make -f kprog/results/cilium-headlen-20261119/Makefile stock-probe
make -n -f kprog/results/cilium-headlen-20261119/Makefile stock OUT="$out/stock" FIXTURE="$out/fixture/fixture.bpf.o" > "$out/stock-dry-run.log"
make -f kprog/results/cilium-headlen-20261119/Makefile stock OUT="$out/stock" FIXTURE="$out/fixture/fixture.bpf.o"
make -n -f kprog/results/cilium-headlen-20261119/Makefile replay OUT="$out/replay" > "$out/replay-dry-run.log"
replay_status=0
taskset -c 8-11 prlimit --as=8589934592 -- make -f kprog/results/cilium-headlen-20261119/Makefile replay OUT="$out/replay" || replay_status=$?
printf '%s\n' "$replay_status" > "$out/replay-exit"
make -n -C kprog/libnativeloader checked-corpus CHECKED_APP=cilium/agent CHECKED_OUTPUT="$out/cilium" CHECKED_HOST_CPUS=18-19 > "$out/app-dry-run.log"
app_status=0
make -C kprog/libnativeloader checked-corpus CHECKED_APP=cilium/agent CHECKED_OUTPUT="$out/cilium" CHECKED_HOST_CPUS=18-19 || app_status=$?
printf '%s\n' "$app_status" > "$out/app-exit"
if [ "$replay_status" -ne 0 ]; then exit "$replay_status"; fi
exit "$app_status"
