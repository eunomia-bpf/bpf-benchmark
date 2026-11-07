#!/bin/bash
set -euo pipefail
cd /workspaces/repository
root=$PWD;state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/local-sp-micro.exit"' EXIT
taskset -c 20-23 python3 "$state/sp_micro.py" build
taskset -c 20-23 vng --run "$root/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage" --cwd "$root" --disable-monitor --cpus 2 --mem 2G --rwdir "$root" --overlay-rwdir /tmp --exec "mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; insmod $root/kprog/fidelity/build-abi-fixed/module.ko && python3 $state/sp_micro.py load"
