#!/bin/bash
set -euo pipefail
cd /workspaces/repository
output=$1
app=${2:-otelcol-ebpf-profiler/profiling}
bounds=${4:-/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds}
# Both ISAs share the host compiler tools; loaders, layouts and modules
# use the canonical products for their architecture.
arch=${5:-x86}
verified_base=/workspaces/.agent-state/kprog-ck/verified-compiler
if [ "$arch" = arm64 ]; then
    loader=${3:-/workspaces/repository/runner/build-arm64-llvmbpf/native_loader/trusted-native-loader}
    layout_base=$verified_base/arm64
    bounds_args=()
    endpoint=/sys/kernel/debug/bpf_arm64_native_lab/specializer
    module=/workspaces/.agent-state/kprog-ck/verified-module/arm64/bpf_arm64_native_lab.ko
    native_link=/workspaces/repository/kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link
    codex=2
else
    loader=${3:-/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader}
    layout_base=$verified_base
    bounds_args=(--sim-bounds-compiler "$bounds")
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
    --sim-public-layout "$layout_base/public-layout.json" \
    --sim-physical-layout "$layout_base/physical-layout.json" \
    "${bounds_args[@]}" \
    --run python3 /workspaces/repository/kprog/test/verified_corpus.py "$app" 1 10 1
