#!/usr/bin/env bash
set -euo pipefail
cd /workspaces/repository
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 WARMUPS=1 BPFREJIT_CORPUS_BPF_STATS=0 KEEP_WORKDIRS=1 JOBS=4 RUN_TOKEN=katran-map-inline-20260919-90kzng44 make corpus -o /workspaces/repository/vendor/build/x86/linux/arch/x86/boot/bzImage -o host-kop-x86 -o host-rust-x86 -o host-bpfperf-x86 -o host-source-apps-x86 -o host-runner-x86 -o host-micro-programs-x86 -o host-stage2-programs-x86 -o host-x86-sim-proofs -o host-native-bpf-x86 -o host-llvm-x86 X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/katran-map-inline-trial:20260919-90kzng44 X86_RUNNER_RUNTIME_IMAGE_TAR=/tmp/katran-map-inline-trial-20260919-90kzng44/runtime.image.tar
