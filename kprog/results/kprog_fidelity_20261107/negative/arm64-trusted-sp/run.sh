#!/bin/bash
set -euo pipefail
cd /workspaces/repository
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?; echo "$rc" > "$state/arm64-trusted-safety.exit"' EXIT
make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile build
make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile qemu
