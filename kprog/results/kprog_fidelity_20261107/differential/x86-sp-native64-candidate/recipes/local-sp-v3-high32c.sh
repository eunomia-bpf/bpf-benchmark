#!/bin/bash
set -euo pipefail
cd /workspaces/repository
root=$PWD;state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/local-sp-v3-high32c.exit"' EXIT
taskset -c 20-23 python3 "$state/sp_v3_high32c.py" build
taskset -c 20-23 vng --run "$root/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage" --cwd "$root" --disable-monitor --cpus 2 --mem 2G --rwdir "$root" --overlay-rwdir /tmp --exec "mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; insmod $root/kprog/fidelity/build-abi-fixed/module.ko capture_checked=1 && cd $root/kprog/fidelity && python3 $state/sp_v3_high32c.py check"
