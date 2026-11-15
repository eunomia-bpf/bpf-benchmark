#!/usr/bin/env bash
set -euo pipefail
pc32_output=$1
pc32_root=/workspaces/repository
pc32_state=/var/tmp/kprog-tmp/perf/image-pc32-state
install -d "$pc32_state/var-tmp" "$pc32_output"
finish_pc32() {
    pc32_status=$?
    trap - EXIT
    rm -f "$pc32_state/var-tmp/runtime.image.tar" "$pc32_state/var-tmp/bpf-benchmark-docker.img"
    printf -- '- %s PERF guest image PC32 check: removed scratch image copies in %s; raw retained %s.\n' \
        "$(date -u +%FT%TZ)" "$pc32_state" "$pc32_output" >> "$pc32_root/kprog/docs/cleanup-log.md"
    exit "$pc32_status"
}
trap finish_pc32 EXIT
ln "$pc32_root/.cache/container-images/x86_64-runner-runtime.image.tar" "$pc32_state/var-tmp/runtime.image.tar"
taskset -c 16-17 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
    --cwd "$pc32_root" --rwdir "$pc32_root" --rwdir "$pc32_output" \
    --rwdir "/var/tmp=$pc32_state/var-tmp" \
    --rwdir "$pc32_output/inputs=/var/tmp/kprog-tmp/perf/native-relocations" \
    --rodir "$pc32_output/layout=/var/tmp/kprog-tmp/perf/kernel-layout" \
    --overlay-rwdir /run --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 4G \
    --append 'loglevel=4 panic=30 oops=panic' \
    --exec "make -r -f kprog/test/native-relocations.mk guest-image-pc32 OUTPUT=$pc32_output"
