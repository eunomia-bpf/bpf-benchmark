#!/bin/bash
# Replicate of the current-module kinsn arm with the finer probes (lowering, do_check),
# started after queue-1 has finished.
cd /home/yunwei37/workspace/bpf-benchmark-rerun-20261009/micro/results/kinsn_load_time_current_20261011
until grep -q queue-done runs/queue-1.log; do sleep 20; done
./host-run.sh kinsn-current-r2 - suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=4 WARMUPS=0 INNER_REPEAT=10 BPFREJIT_BENCH_PASSES=kinsn
echo queue-done
