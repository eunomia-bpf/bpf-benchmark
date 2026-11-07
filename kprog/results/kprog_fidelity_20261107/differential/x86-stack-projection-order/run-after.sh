#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=kprog/results/kprog_fidelity_20261107/differential/x86-stack-projection-order
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?; echo "$rc" > "$state/projection-after.exit"' EXIT
taskset -c 16-19 make -f "$out/Makefile" codegen PHASE=after
taskset -c 20-23 make -f "$out/Makefile" build PHASE=after
make -f "$out/Makefile" kvm PHASE=after
build=$PWD/kprog/formal/build/fidelity-stack
cpu=$PWD/$out/after/cpu
install -d "$cpu"
taskset -c 20-23 python3 kprog/fidelity/x86_stack.py --source "$PWD" --out "$build" > "$cpu/generate.log" 2>&1
taskset -c 20-23 cc -O1 -g -std=gnu11 -static -Ivendor/libbpf/src -Ivendor/libbpf/include/uapi kprog/fidelity/driver.c "$build/generated.c" "$build/native.S" -o "$build/cpu-differential" > "$cpu/build.log" 2>&1
taskset -c 20-23 "$build/cpu-differential" 1024 "$cpu" "$cpu/cpu-states.bin" > "$cpu/cpu.log" 2>&1
taskset -c 20-23 python3 kprog/fidelity/reference_check.py --reuse-trace --linear-paths --binary "$build/cpu-differential" --reference "$PWD/kprog/formal/.lake/build/bin/reference" --arch x86 --cases 1024 --out "$cpu" > "$cpu/reference.log" 2>&1
