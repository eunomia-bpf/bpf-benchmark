#!/bin/bash
set -euo pipefail
cd /workspaces/repository
out=kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir
trap 'printf "%s\n" "$?" > "$out/build.exit"' EXIT
ulimit -v 50331648
export CARGO_BUILD_JOBS=2
cargo test --manifest-path kprog/x86/native_lab/native_link/Cargo.toml -j2 -- --test-threads=1
