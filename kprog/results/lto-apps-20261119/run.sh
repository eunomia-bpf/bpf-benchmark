#!/bin/bash
# Coordinator: LTO configuration timing on the apps with the larger program-body share, one app after another.
# Waits for perf's numeric repair worker 407693 and for committed request-time inputs, then holds batch EX.
set -euo pipefail
cd /workspaces/repository
apps=${*:-tracee/monitor}
base=/workspaces/kprog-raw/coordinator/lto-apps-20261119
install -d "$base"
progress() { printf '%s %s\n' "$(date -u +%FT%TZ)" "$1" >> "$base/progress.log"; }
progress "queued: $apps"
while kill -0 407693 2>/dev/null; do sleep 60; done
inputs='kprog/x86 kprog/trusted_generation.py kprog/trusted_service.py kprog/trusted_compile.py kprog/libnativeloader kprog/stock-path kprog/formal/generated'
while [ -n "$(git status --porcelain -- $inputs)" ]; do sleep 120; done
exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
flock -x 7
for app in $apps; do
    out=$base/$(echo "$app" | tr / _)-$(date -u +%Y%m%dT%H%M%SZ)
    install -d "$out"
    git rev-parse HEAD > "$out/source-commit"
    progress "$app start at $(cat "$out/source-commit") -> $out"
    set +e
    (
        exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -x 8
        exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
        make -f kprog/results/lto-apps-20261119/Makefile checked-timing APP="$app" OUT="$out/timing"
    ) > "$out/timing.log" 2>&1
    rc=$?
    set -e
    printf '%s\n' "$rc" > "$out/exit-code"
    progress "$app done rc=$rc run=$(grep -a -o 'x86_kvm_corpus_2026[0-9_]*' "$out/timing.log" | tail -1)"
done
progress 'all done'
