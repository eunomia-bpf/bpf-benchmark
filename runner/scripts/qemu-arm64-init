#!/bin/sh

mount -t proc proc /proc
mount -t sysfs sysfs /sys
mount -t devtmpfs devtmpfs /dev 2>/dev/null || true

[ -d /run ] || mkdir -p /run
[ -d /tmp ] || mkdir -p /tmp
[ -d /sys/kernel/debug ] || mkdir -p /sys/kernel/debug
[ -d /sys/fs/bpf ] || mkdir -p /sys/fs/bpf

mount -t debugfs debugfs /sys/kernel/debug 2>/dev/null || true
mount -t bpf bpffs /sys/fs/bpf 2>/dev/null || true
ulimit -l unlimited 2>/dev/null || true

export HOME=/root
export BPFREJIT_INSIDE_RUNTIME_CONTAINER=1
export BPFREJIT_IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark
export PYTHONPATH=/home/yunwei37/workspace/bpf-benchmark
export PATH=/home/yunwei37/workspace/bpf-benchmark/runner/build-arm64-llvmbpf:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

cd /home/yunwei37/workspace/bpf-benchmark || exit 127

if [ ! -x /qemu-run.sh ]; then
    echo "missing executable /qemu-run.sh" >&2
    status=127
else
    /qemu-run.sh
    status=$?
fi

echo "$status" >/qemu-status
sync

if [ -w /proc/sys/kernel/sysrq ]; then
    echo 1 >/proc/sys/kernel/sysrq
fi
if [ -w /proc/sysrq-trigger ]; then
    echo o >/proc/sysrq-trigger
    while :; do
        sleep 60 2>/dev/null || true
    done
fi

exit "$status"
