#!/bin/bash
set -eu
cd /workspaces/repository
exec 9>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 9
exec 8>/workspaces/.agent-state/kprog-lanes/locks/image
flock -x 8
ulimit -v 50331648
export CARGO_BUILD_JOBS=2
cd kprog/x86/native_lab/native_link
taskset -c 16,18 cargo build --release -j2 < /dev/null
taskset -c 16,18 cargo test -j2 < /dev/null
