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

exec vng --run "$IMAGE" --cwd "$ROOT" --rwdir "$ROOT" --overlay-rwdir /tmp \
    --disable-monitor --cpus 2 --memory 4G \
    --append 'loglevel=4 panic=30 oops=panic' \
    --exec "mountpoint -q /sys/kernel/debug || \
        mount -t debugfs debugfs /sys/kernel/debug; \
        insmod $MODULE; \
        cd $ROOT && python3 kprog/selftests/selftests.py && \
        python3 kprog/selftests/submit.py"