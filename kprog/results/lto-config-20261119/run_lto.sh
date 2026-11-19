#!/bin/bash
# Guest side of the LTO-configuration timing (design: checked-sim-c). Same service command as
# kprog/test/run_checked_otel.sh; the frozen corpus driver runs with the given samples, duration and stats.
set -euo pipefail
cd /workspaces/repository
output=$1 app=$2 loader=$3 bounds=$4 samples=$5 duration=$6 stats=$7
export CLANG=/workspaces/repository/kprog/stock-path/bin/clang
python3 kprog/trusted_service.py --arch 1 \
    --endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
    --module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
    --state "$output/state" --results "$output/service.tar.gz" \
    --native-link /workspaces/repository/kprog/x86/native_lab/native_link/target/release/native-link \
    --loader "$loader" \
    --execution-mode checked-sim-c \
    --sim-native-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir \
    --sim-context-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/context-lower \
    --sim-public-layout /workspaces/.agent-state/kprog-ck/verified-compiler/public-layout.json \
    --sim-physical-layout /workspaces/.agent-state/kprog-ck/verified-compiler/physical-layout.json \
    --sim-bounds-compiler "$bounds" \
    --run python3 /workspaces/repository/kprog/test/verified_corpus.py "$app" "$samples" "$duration" "$stats"
