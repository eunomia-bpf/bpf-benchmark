#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?; echo "$rc" > "$state/projection-before.exit"' EXIT
sha256sum kprog/x86/x86_sim_local_bpf.h kprog/libnativeloader/build/trusted-native-loader kprog/tv/build-x86/bpf_x86_native_lab.ko > "$out/before-pins.txt"
taskset -c 20-23 make -f "$out/Makefile" build PHASE=before
make -f "$out/Makefile" kvm PHASE=before
