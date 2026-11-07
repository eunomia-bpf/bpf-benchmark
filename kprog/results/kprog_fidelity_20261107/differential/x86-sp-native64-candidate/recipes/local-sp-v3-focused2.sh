#!/bin/bash
set -euo pipefail
state=/workspaces/.agent-state/kprog-lanes/F
source=/workspaces/repository/kprog/fidelity/build-sp-v3/source
trap 'rc=$?;printf "%s\n" "$rc" > "$state/local-sp-v3-focused2.exit"' EXIT
cd "$source/kprog/formal"
mkdir -p build
for name in stack_index stack_arena mov_route xchg_route alu_mem_result_route;do
 taskset -c 16-19 cc -w -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_${name}_host.c -o build/test_x86_${name}_host
 taskset -c 16-19 ./build/test_x86_${name}_host
done
cp -a /workspaces/repository/kprog/formal/.lake .lake
export PATH=/root/.elan/bin:/usr/local/cargo/bin:$PATH
taskset -c 16-19 lake build KProgFormal.X86StackIndex KProgFormal.X86StackArena KProgFormal.X86XchgHandler KProgFormal.Refinement.X86NumericAddress
