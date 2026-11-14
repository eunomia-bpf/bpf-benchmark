#!/bin/bash
set -euo pipefail
cd /workspaces/repository
output=$1
export PATH=/workspaces/repository/kprog/perf/may29-image/eqcodex-bin:$PATH
export EQCODEX_OUT=/workspaces/repository/corpus/results/perf-otel-whole-word-checked-20261114
export EQCODEX_ALL_JIT_PROGRAMS=1
export CLANG=/workspaces/repository/kprog/stock-path/bin/clang
export KPROG_BPF_WHOLE_WORD_SPILLS=1
python3 kprog/trusted_service.py --arch 1 \
    --endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
    --module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
    --state "$output/state" --results "$output/service.tar.gz" \
    --native-link /workspaces/repository/corpus/results/perf-corrected-all-lto-linker-20261114/native-link-on \
    --loader /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader \
    --execution-mode checked-sim-c \
    --sim-native-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir \
    --sim-context-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/context-lower \
    --sim-public-layout /workspaces/.agent-state/kprog-ck/verified-compiler/public-layout.json \
    --sim-physical-layout /workspaces/.agent-state/kprog-ck/verified-compiler/physical-layout.json \
    --sim-bounds-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds \
    --run env BPFREJIT_SHIM_NATIVE_MANIFEST=/workspaces/repository/corpus/results/perf-combined-codegen-source-all-20261114/manifest-context.json \
    python3 /workspaces/repository/kprog/test/verified_corpus.py otelcol-ebpf-profiler/profiling 1 10 1
