#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?; echo "$rc" > "$state/stage2-trusted.exit"' EXIT
sha256sum kprog/x86/x86_sim_local_bpf.h kprog/libnativeloader/build/trusted-native-loader kprog/tv/build-x86/bpf_x86_native_lab.ko kprog/tv/build-kernel-x86/arch/x86/boot/bzImage > "$out/kernel-pins-before.txt"
make -f "$out/Makefile" build
make -f "$out/Makefile" kvm
sha256sum kprog/x86/x86_sim_local_bpf.h kprog/libnativeloader/build/trusted-native-loader kprog/tv/build-x86/bpf_x86_native_lab.ko kprog/tv/build-kernel-x86/arch/x86/boot/bzImage > "$out/kernel-pins-after.txt"
