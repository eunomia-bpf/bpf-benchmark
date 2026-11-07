#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$PWD/kprog/results/kprog_fidelity_20261107/differential/x86-sp-current-integration/sanitized
build=$PWD/kprog/formal/build/fidelity-stack
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/sp-sanitized.exit"' EXIT
mkdir -p "$out"
taskset -c 16-19 cc -O1 -g -std=gnu11 -fsanitize=undefined -fno-sanitize-recover=all -Ivendor/libbpf/src -Ivendor/libbpf/include/uapi kprog/fidelity/driver.c "$build/generated.c" "$build/native.S" -o "$build/cpu-sanitized" >"$out/build.log" 2>&1
taskset -c 16-19 "$build/cpu-sanitized" 1024 "$out" >"$out/cpu.log" 2>&1
