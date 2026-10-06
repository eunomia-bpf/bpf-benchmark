#!/usr/bin/env bash
set -euo pipefail
cd /workspaces/repository
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=bcc/set,tracee/monitor BPFREJIT_BENCH_PASSES=context_specialize SAMPLES=1 WORKLOAD_DURATION=30 WARMUPS=1 BPFREJIT_CORPUS_BPF_STATS=0 KEEP_WORKDIRS=1 RUN_TOKEN=corpus-five-app-trials-20260919-a87nyqy4-context make corpus -o runtime-kernel-image X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/katran-map-inline-trial:20260919-90kzng44 X86_RUNNER_RUNTIME_IMAGE_TAR=/tmp/katran-map-inline-trial-20260919-90kzng44/runtime.image.tar
