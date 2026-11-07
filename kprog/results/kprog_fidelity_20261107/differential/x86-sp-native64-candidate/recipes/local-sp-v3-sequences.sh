#!/bin/bash
set -uo pipefail
cd /workspaces/repository
state=/workspaces/.agent-state/kprog-lanes/F
root=$PWD
reference=$root/kprog/fidelity/build-multiply-xchg/source/kprog/fidelity/build-cpu/reference
trap 'rc=$?; printf "%s\n" "$rc" > "$state/local-sp-v3-sequences.exit"' EXIT
for version in audit; do
 if [ "$version" = before ]; then source=$root/kprog/fidelity/build-sp-entry-replay/source;else source=$root/kprog/fidelity/build-sp-v3/source;fi
 build=$root/kprog/fidelity/build-sp-v3-sequences
 out=$root/kprog/results/kprog_fidelity_20261107/differential/x86-sp-v3-sequences
 mkdir -p "$out"
 taskset -c 20-23 python3 kprog/fidelity/x86_stack.py --source "$source" --out "$build" > "$out/generate.log" 2>&1
 rc=$?;if [ "$rc" -ne 0 ];then exit "$rc";fi
 taskset -c 20-23 cc -O1 -g -std=gnu11 -static -Ivendor/libbpf/src -Ivendor/libbpf/include/uapi "$source/kprog/fidelity/driver.c" "$build/generated.c" "$build/native.S" -o "$build/cpu-differential" > "$out/build.log" 2>&1
 rc=$?;if [ "$rc" -ne 0 ];then exit "$rc";fi
 taskset -c 20-23 "$build/cpu-differential" 1024 "$out" "$out/cpu-states.bin" > "$out/cpu.log" 2>&1
 cpu_rc=$?
 taskset -c 20-23 python3 kprog/fidelity/reference_check.py --reuse-trace --linear-paths --binary "$build/cpu-differential" --reference "$reference" --arch x86 --cases 1024 --out "$out" > "$out/reference.log" 2>&1
 ref_rc=$?
 printf 'cpu=%s\nreference=%s\n' "$cpu_rc" "$ref_rc" > "$out/stages.txt"
 if [ "$cpu_rc" -gt 1 ] || [ "$ref_rc" -gt 1 ];then echo "unexpected failure in $version";exit 1;fi
 if [ "$version" = audit ] && { [ "$cpu_rc" -ne 0 ] || [ "$ref_rc" -ne 0 ]; };then echo 'fixed sequence differences remain';exit 1;fi
 echo "$version sequence stage complete: CPU=$cpu_rc reference=$ref_rc"
done
