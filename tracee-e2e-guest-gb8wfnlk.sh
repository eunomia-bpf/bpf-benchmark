#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
cd "/home/yunwei37/workspace/bpf-benchmark" && source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; bpftool btf dump file /sys/kernel/btf/vmlinux format raw 2>/dev/null | grep "FUNC " | grep -v "linkage=static" | grep -iE "nanosleep|vfs_read|vfs_write|do_read|do_write" | head -20
