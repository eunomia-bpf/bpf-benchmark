#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?; echo "$rc" > "$state/projection-safety.exit"' EXIT
install -d "$out/after/safety"
sha256sum kprog/x86/x86_sim_local_bpf.h kprog/libnativeloader/build/trusted-native-loader kprog/tv/build-x86/bpf_x86_native_lab.ko kprog/tv/build-kernel-x86/arch/x86/boot/bzImage > "$out/after/safety/kernel-pins-before.txt"
taskset -c 20-23 make -f "$out/Makefile" safety-build
make -f "$out/Makefile" safety-kvm
sha256sum kprog/x86/x86_sim_local_bpf.h kprog/libnativeloader/build/trusted-native-loader kprog/tv/build-x86/bpf_x86_native_lab.ko kprog/tv/build-kernel-x86/arch/x86/boot/bzImage > "$out/after/safety/kernel-pins-after.txt"
