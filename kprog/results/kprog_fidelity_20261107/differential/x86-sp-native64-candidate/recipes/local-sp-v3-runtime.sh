#!/bin/bash
set -euo pipefail
cd /workspaces/repository
root=$PWD;state=/workspaces/.agent-state/kprog-lanes/F
source=$root/kprog/fidelity/build-sp-v3/source
build=$root/kprog/fidelity/build-sp-v3-negative
out=$root/kprog/results/kprog_fidelity_20261107/negative/x86-sp-v3-negative
trap 'rc=$?;printf "%s\n" "$rc" > "$state/local-sp-v3-runtime.exit"' EXIT
mkdir -p "$out"
taskset -c 20-23 python3 "$source/kprog/fidelity/negative.py" build --arch x86 --build "$build"
taskset -c 20-23 python3 "$state/sp_v3_positive.py" build
taskset -c 20-23 vng --run "$root/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage" --cwd "$root" --disable-monitor --cpus 2 --mem 2G --rwdir "$root" --overlay-rwdir /tmp --exec "mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; insmod $root/kprog/fidelity/build-abi-fixed/module.ko capture_checked=1 && cd $root/kprog/fidelity && python3 $source/kprog/fidelity/negative.py bound --arch x86 --build $build --out $out --probe $root/kprog/fidelity/build-abi-fixed/bound-probe --companion $root/kprog/fidelity/build-abi-fixed/companion.bpf.o; neg=\$?; python3 $state/sp_v3_positive.py check; pos=\$?; test \$neg -eq 0 -a \$pos -eq 0"
