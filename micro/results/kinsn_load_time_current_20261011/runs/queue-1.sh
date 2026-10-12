#!/bin/bash
# Sequential measurement arms; each host-run.sh holds the host lock for its own guest only.
cd /home/yunwei37/workspace/bpf-benchmark-rerun-20261009/micro/results/kinsn_load_time_current_20261011
./host-run.sh kinsn-current - suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=4 WARMUPS=0 INNER_REPEAT=10 BPFREJIT_BENCH_PASSES=kinsn
./host-run.sh kinsn-june /home/yunwei37/workspace/codex-runs/kinsn-load-time-20261011/june-premods suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=4 WARMUPS=0 INNER_REPEAT=10 BPFREJIT_BENCH_PASSES=kinsn
./host-run.sh full-current - suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=2 WARMUPS=0 INNER_REPEAT=10
echo queue-done
