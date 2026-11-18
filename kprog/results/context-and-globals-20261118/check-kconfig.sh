#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/context-and-globals-20261118
    raw="$root/kconfig-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    printf '%s\n' "$raw" > "$root/kconfig-raw.txt"
    trap 'status=$?; printf "%s kconfig exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.txt"' EXIT
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    ulimit -v 33554432
    taskset -c 19 c++ -std=c++20 -O1 -g0 -ffunction-sections -fdata-sections \
        -Ikprog/libnativeloader/include -Irunner/build-llvmbpf/vendor/libbpf/prefix/include \
        -Ivendor/libbpf/include -Ivendor/libbpf/include/uapi -Imicro/programs/build-x86 \
        kprog/results/context-and-globals-20261118/kconfig.cpp -Wl,--gc-sections \
        runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread \
        -o "$raw/kconfig" > "$raw/build.txt" 2>&1
    if taskset -c 19 "$raw/kconfig" > "$raw/contracts.txt" 2>&1; then status=0; else status=$?; fi
    printf '%s\n' "$status" > "$raw/contract-status.txt"
    taskset -c 19 python3 kprog/results/context-and-globals-20261118/prepare-kconfig.py "$raw" > "$raw/patch-context.txt" 2>&1
}
main
