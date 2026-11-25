#!/bin/bash
set -euo pipefail
cd /workspaces/repository
output=$1
app=${2:-otelcol-ebpf-profiler/profiling}
loader=${3:-/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader}
bounds=${4:-/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds}
# The checked path runs on both ISAs. x86 keeps its installed tools and
# endpoint; arm64 names its own base, which carries the aarch64 checked
# loaders, the aarch64 native-link and the arm64 lab module.
arch=${5:-x86}
if [ "$arch" = arm64 ]; then
    verified_base=${KPROG_VERIFIED_ARM64:-/workspaces/.agent-state/kprog-ck/verified-arm64}
    endpoint=/sys/kernel/debug/bpf_arm64_native_lab/specializer
    module=/artifacts/kinsn/bpf_arm64_native_lab.ko
    native_link=$verified_base/native-link
    codex=2
else
    verified_base=/workspaces/.agent-state/kprog-ck/verified-compiler
    endpoint=/sys/kernel/debug/bpf_x86_native_lab/specializer
    module=/workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
    native_link=/workspaces/repository/kprog/x86/native_lab/native_link/target/release/native-link
    codex=1
fi
export CLANG=/workspaces/repository/kprog/stock-path/bin/clang
python3 kprog/trusted_service.py --arch "$codex" \
    --endpoint "$endpoint" \
    --module "$module" \
    --state "$output/state" --results "$output/service.tar.gz" \
    --native-link "$native_link" \
    --loader "$loader" \
    --execution-mode checked-sim-c \
    --sim-native-compiler "$verified_base/compile-sim-ir" \
    --sim-context-compiler "$verified_base/context-lower" \
    --sim-public-layout "$verified_base/public-layout.json" \
    --sim-physical-layout "$verified_base/physical-layout.json" \
    --sim-bounds-compiler "$bounds" \
    --run python3 /workspaces/repository/kprog/test/verified_corpus.py "$app" 1 10 1