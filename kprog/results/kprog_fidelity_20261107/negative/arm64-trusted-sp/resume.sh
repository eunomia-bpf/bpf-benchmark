#!/bin/bash
set -euo pipefail
cd /workspaces/repository
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?; echo "$rc" > "$state/arm64-trusted-continuation.exit"' EXIT
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile qemu
