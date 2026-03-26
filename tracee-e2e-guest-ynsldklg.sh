#!/bin/bash
set -eu
cd /home/yunwei37/workspace/bpf-benchmark
export PATH="/usr/local/sbin:$PATH"
mkdir -p /home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp
. /home/yunwei37/workspace/.venv/bin/activate
/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh 2>/dev/null || true; python3 corpus/driver.py --guest-target-json /home/yunwei37/workspace/bpf-benchmark/corpus-rejit-vm-batch-e7olcarc.json --guest-result-json /home/yunwei37/workspace/bpf-benchmark/corpus-rejit-vm-batch-result-em0xk23d.json --runner /home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec --daemon /home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon --btf-custom-path /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/vmlinux --repeat 100 --timeout 240
