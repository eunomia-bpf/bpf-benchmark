#!/bin/bash
set -euo pipefail
cd /workspaces/repository
mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
insmod kprog/tv/build-x86/bpf_x86_native_lab.ko
PATH=/usr/lib/llvm-18/bin:$PATH PYTHONDONTWRITEBYTECODE=1 python3 kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py check --out "${1:-/workspaces/repository/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp}"
