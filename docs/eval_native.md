# Native Execution Evaluation

Date: 2026-05-26

This document tracks the authoritative evaluation of the native execution path
against the existing eBPF JIT paths. It is intentionally a post-hoc analysis
document: the benchmark framework records raw counters and workload payloads,
while all aggregation and interpretation live here or in external analysis
scripts.

## Status

| Area | Status | Artifact |
| --- | --- | --- |
| Micro stage1 | complete | `micro/results/x86_kvm_micro_20260526_210952_650695/metadata.json` |
| Micro stage2 | complete | `micro/results/x86_kvm_micro_20260526_210434_440390/metadata.json` |
| Corpus, BPF stats on | running | pending |
| Corpus, BPF stats off | pending | pending |
| Corpus, workload-only no eBPF | pending | pending |

## Setup

- Platform: x86 KVM (`make` default target).
- Kernel/runtime image: repository default build used by `make micro` and
  `make corpus`.
- Micro samples: `SAMPLES=3`, `WARMUPS=0`, `INNER_REPEAT=100000`.
- Corpus samples: `SAMPLES=3`, `WORKLOAD_DURATION=180`.
- Corpus apps: `bcc/set`, `otelcol-ebpf-profiler/profiling`,
  `cilium/agent`, `tetragon/observer`, `katran`, `tracee/monitor`.

## Commands

Micro stage1:

```sh
RUNTIMES="native llvmbpf native_kernel kernel" \
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 TIMEOUT=2400 \
make micro
```

Micro stage2:

```sh
SUITE=micro/config/micro_stage2.yaml \
RUNTIMES="native llvmbpf native_kernel kernel" \
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 TIMEOUT=2400 \
make micro
```

Corpus native with BPF runtime counters enabled:

```sh
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=1 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=14400 \
make corpus
```

Corpus native with BPF runtime counters disabled:

```sh
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=14400 \
make corpus
```

Corpus workload-only no-eBPF baseline:

```sh
BPFREJIT_CORPUS_APPS="<app>" \
BPFREJIT_CORPUS_WORKLOAD_ONLY=1 BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=14400 \
make corpus
```

## Progress Log

- 2026-05-26: Micro stage2 completed for 13 benchmarks across
  `native`, `llvmbpf`, `native_kernel`, and `kernel`; all runtimes returned
  matching results.
- 2026-05-26: Micro stage1 completed for 29 benchmarks across
  `native`, `llvmbpf`, `native_kernel`, and `kernel`; all runtimes returned
  matching results.

