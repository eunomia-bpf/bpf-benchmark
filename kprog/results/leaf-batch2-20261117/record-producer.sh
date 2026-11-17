#!/bin/bash
# Record the canonical producer outputs; installed app sizes come from the guest.
set -euo pipefail
cd /workspaces/repository
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
flock -s 9
stage=/workspaces/repository/vendor/build/native-bpf/x86/stage/cilium
printf 'Recorded UTC: %s\n' "$(date -u +%FT%TZ)"
printf 'Producer build: 2026-11-17T13:08:55Z to 13:09:03Z, exit 0\n'
printf 'Raw: /workspaces/kprog-raw/perf/leaf-batch2-20261117/cilium-20261117T130722Z-2576741/make.log\n'
printf 'Canonical staged object file bytes (includes embedded IR and debug information):\n'
stat --printf='%n %s\n' "$stage"/*.native.o
printf '\nELF section sizes; these are producer objects, not installed native sizes:\n'
llvm-size-18 -A "$stage"/*.native.o
