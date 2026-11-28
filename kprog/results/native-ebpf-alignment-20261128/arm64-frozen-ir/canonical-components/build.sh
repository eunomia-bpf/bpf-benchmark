#!/bin/bash
set -euo pipefail
cd /workspaces/repository
export CARGO_BUILD_JOBS=2
export CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc
export CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_RUSTFLAGS="-C link-arg=--sysroot=$PWD/.cache/aarch64-sysroot -C link-arg=-L$PWD/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -C link-arg=-Wl,-rpath-link,$PWD/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu"
make -C vendor/bpf ARCH=arm64 /workspaces/repository/vendor/build/native-bpf/arm64/stage/kprog-perf-context-lto -j2
cargo build --release --target aarch64-unknown-linux-gnu --manifest-path kprog/x86/native_lab/native_link/Cargo.toml -j2
