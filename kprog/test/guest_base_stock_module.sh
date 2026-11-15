#!/usr/bin/env bash
# A targeted stock-module load probe, not a benchmark admission check.
set -euo pipefail
base_probe_output=$1
trap 'dmesg > "$base_probe_output/kernel.log"' EXIT
uname -a > "$base_probe_output/uname.txt"
insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
cat /proc/modules > "$base_probe_output/modules.txt"
printf '{"stock_module_loaded":true}\n' > "$base_probe_output/result.json"
