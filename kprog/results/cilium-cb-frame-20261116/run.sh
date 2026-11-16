#!/bin/bash
set -uo pipefail
cd /workspaces/repository
make -f kprog/results/cilium-cb-frame-20261116/Makefile host
status=$?
printf '%s\n' "$status" > /workspaces/kprog-raw/perf/20261116-cilium-cb-frame/exit-code
date -u +%FT%TZ > /workspaces/kprog-raw/perf/20261116-cilium-cb-frame/controller-finished
exit "$status"
