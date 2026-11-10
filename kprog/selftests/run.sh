#!/bin/sh
# Run the selftest sweep in the kernel the native path needs.
#
# The lab module is built for the vendored kernel tree, so it only loads in
# a guest booted from that tree's image; the host runs a different kernel
# and rejects every module with a vermagic mismatch.  One guest boot covers
# the whole sweep, because `submit.py` starts the trusted service itself.
set -eu

ROOT=$(cd "$(dirname "$0")/../.." && pwd)
IMAGE=$ROOT/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage
MODULE=$ROOT/kprog/tv/build-x86/bpf_x86_native_lab.ko

# The module must be built against the tree the image came from; the two
# output directories are separate and a stale module fails to load with a
# symbol-version error rather than a build error.
make -C "$ROOT/kprog/tv" module-check KDIR="$ROOT/kprog/tv/build-kernel-x86"

# The guest is pinned to host CPUs 0-7, which is the set lane R times on.
# `vng` always asks QEMU for the same QMP port, so a guest another lane
# keeps resident blocks this one at startup; retry until the port frees.
attempt=0
while :; do
    attempt=$((attempt + 1))
    if taskset -c 0-7 vng --pin 0-7 --name kprog-selftests --run "$IMAGE" \
        --cwd "$ROOT" --rwdir "$ROOT" --overlay-rwdir /tmp \
        --disable-monitor --cpus 2 --memory 4G \
        --append 'loglevel=4 panic=30 oops=panic' \
        --exec "mkdir -p /sys/fs/bpf; \
            mountpoint -q /sys/kernel/debug || \
            mount -t debugfs debugfs /sys/kernel/debug; \
            mountpoint -q /sys/fs/bpf || mount -t bpf bpf /sys/fs/bpf; \
            insmod $MODULE; \
            cd $ROOT && python3 kprog/selftests/selftests.py && \
            python3 kprog/selftests/submit.py"; then
        exit 0
    fi
    if [ "$attempt" -ge 120 ]; then
        echo "no free QMP port after $attempt attempts" >&2
        exit 1
    fi
    sleep 5
done