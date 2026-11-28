#!/bin/bash
set -eu
cd /workspaces/repository
OUT=/workspaces/repository/kprog/results/x86-otel-perf-20261127/lpm-type-binding-20261128
trap 'rc=$?; printf "%s\n" "$rc" > "$OUT/build.exit"' EXIT
exec 9>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 9
exec 8>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 8
ulimit -v 50331648
export CARGO_BUILD_JOBS=2
taskset -c 16,18 make -B -C vendor/bpf ARCH=x86 /workspaces/repository/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto
cd kprog/x86/native_lab/native_link
taskset -c 16,18 cargo build --release -j2 < /dev/null
taskset -c 16,18 cargo test -j2 < /dev/null
