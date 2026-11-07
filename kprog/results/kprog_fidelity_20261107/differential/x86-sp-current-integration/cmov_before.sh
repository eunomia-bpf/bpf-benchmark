#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=$PWD/kprog/results/kprog_fidelity_20261107/differential/x86-sp-current-integration/cmov-before
build=$PWD/kprog/formal/build/fidelity-stack
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\n" "$rc" > "$state/cmov-before.exit"' EXIT
mkdir -p "$out" "$build"
taskset -c 20-23 python3 kprog/fidelity/x86_stack.py --source "$PWD" --out "$build" >"$out/generate.log" 2>&1
taskset -c 20-23 cc -O1 -g -std=gnu11 -static -Ivendor/libbpf/src -Ivendor/libbpf/include/uapi kprog/fidelity/driver.c "$build/generated.c" "$build/native.S" -o "$build/cpu-differential" >"$out/build.log" 2>&1
set +e
taskset -c 20-23 "$build/cpu-differential" 1024 "$out" "$out/cpu-states.bin" >"$out/cpu.log" 2>&1
cpu=$?
taskset -c 20-23 python3 kprog/fidelity/reference_check.py --reuse-trace --linear-paths --binary "$build/cpu-differential" --reference "$PWD/kprog/formal/.lake/build/bin/reference" --arch x86 --cases 1024 --out "$out" >"$out/reference.log" 2>&1
ref=$?
printf 'cpu=%s\nreference=%s\n' "$cpu" "$ref" >"$out/stages.txt"
test "$cpu" -le 1 -a "$ref" -le 1
