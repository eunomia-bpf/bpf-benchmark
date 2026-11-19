#!/bin/bash
# Coordinator: one image from the frozen recipe and the six-app check after the helper unification
# (ded33d751, 5319f359d). Holds batch EX from the image build to the last check.
set -euo pipefail
cd /workspaces/repository
# The Workspace pod since 16:25 UTC has Go here; the cilium-agent rebuild needs it.
export PATH=/usr/local/go/bin:/usr/local/cargo/bin:$PATH
base=/workspaces/kprog-raw/coordinator/helpers-unified-20261119
out=$base/batch-$(date -u +%Y%m%dT%H%M%SZ)-$$
install -d "$out"; printf '%s\n' "$out" > "$base/latest"
exec > "$out/run.log" 2>&1
progress() { printf '%s %s\n' "$(date -u +%FT%TZ)" "$1" >> "$out/progress.log"; }
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
git rev-parse HEAD > "$out/source-commit"
progress "image start at $(cat "$out/source-commit")"
rc=0; set +e
(
  set -e
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -x 9
    taskset -c 8-23 prlimit --as=103079215104 -- make -f kprog/perf/one-image/Makefile image JOBS=16 ) > "$out/image.log" 2>&1
  progress 'image done; check start'
  ( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    make -f kprog/perf/one-image/Makefile check LOGS="$out/check" ) > "$out/check.log" 2>&1
)
rc=$?; set -e
printf '%s\n' "$rc" > "$out/exit-code"; progress "batch done rc=$rc"
