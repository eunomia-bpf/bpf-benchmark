#!/bin/bash
set -euo pipefail
cd /workspaces/repository
output=$1
export CLANG=/workspaces/repository/kprog/stock-path/bin/clang
python3 kprog/trusted_service.py --arch 1 \
    --endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
    --module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
    --state "$output/state" --results "$output/service.tar.gz" \
    --native-link /workspaces/repository/kprog/x86/native_lab/native_link/target/release/native-link \
    --loader /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader \
    --execution-mode checked-sim-c \
    --sim-native-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir \
    --sim-context-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/context-lower \
    --sim-public-layout /workspaces/.agent-state/kprog-ck/verified-compiler/public-layout.json \
    --sim-physical-layout /workspaces/.agent-state/kprog-ck/verified-compiler/physical-layout.json \
    --sim-bounds-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds \
    --run python3 /workspaces/repository/kprog/test/verified_corpus.py otelcol-ebpf-profiler/profiling 1 10 1
