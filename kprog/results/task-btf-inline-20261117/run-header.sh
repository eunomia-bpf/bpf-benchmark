#!/bin/bash
# Instantiate the changed loader layout writer without another loader build.
set -euo pipefail
cd /workspaces/repository
raw=/workspaces/kprog-raw/perf/task-btf-inline-20261117
install -d "$raw"
exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
flock -s 8
ulimit -v 2097152
printf '%s header start\n' "$(date -u +%FT%TZ)" >> "$raw/header-progress.log"
status=0
taskset -c 19 c++ -std=c++20 -Wall -Wextra -Werror \
    -I. -Irunner/build-llvmbpf/vendor/libbpf/prefix/include \
    -Ivendor/libbpf/include -Ivendor/libbpf/include/uapi \
    -fsyntax-only -x c++ - > "$raw/header.log" 2>&1 <<'CPP' || status=$?
#include "kprog/libnativeloader/src/native_loader_lto.hpp"
void instantiate_layout(std::ostream &out, const btf *types) {
    native_lto::write_layout(out, types, [](const char *) -> uint64_t { return 1; });
}
CPP
printf '%s header exit %s\n' "$(date -u +%FT%TZ)" "$status" >> "$raw/header-progress.log"
exit "$status"
