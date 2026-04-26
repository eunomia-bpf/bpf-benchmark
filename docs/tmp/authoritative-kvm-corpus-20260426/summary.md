# Authoritative KVM x86 Corpus Run - 2026-04-26

## Run

- Command: `make vm-corpus SAMPLES=30`
- Result status: `error`
- Result generated at: `2026-04-26T09:50:35.925189+00:00`
- Artifact: `corpus/results/x86_kvm_corpus_20260426_085216_409418`
- Total applied/requested: `518/519`
- Blocking error: `tracee/monitor` failed with `prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)`

## Latest Commits

```text
724f68fb Fix remote workspace sync for AWS corpus runs
0be16ad5 Fix review-flagged bugs in P0 patches
cc762f62 Fix cilium program ID drift: rediscover programs on ID disappearance
```

## Per-App Status

| App | Status | Applied/Requested | Notes |
| --- | --- | --- | --- |
| `bcc/capable` | `ok` | `1/1` |  |
| `bcc/execsnoop` | `ok` | `2/2` |  |
| `bcc/bindsnoop` | `ok` | `3/3` |  |
| `bcc/biosnoop` | `ok` | `3/3` |  |
| `bcc/vfsstat` | `ok` | `5/5` |  |
| `bcc/opensnoop` | `ok` | `3/3` |  |
| `bcc/syscount` | `ok` | `2/2` |  |
| `bcc/tcpconnect` | `ok` | `3/3` |  |
| `bcc/tcplife` | `ok` | `1/1` |  |
| `bcc/runqlat` | `ok` | `3/3` |  |
| `calico/felix` | `ok` | `6/6` |  |
| `otelcol-ebpf-profiler/profiling` | `ok` | `13/13` |  |
| `cilium/agent` | `ok` | `16/16` | rediscovery warning seen during baseline, final app result still `ok` |
| `tetragon/observer` | `ok` | `287/287` |  |
| `katran` | `ok` | `3/3` |  |
| `tracee/monitor` | `error` | `157/158` | `prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)` |
| `bpftrace/capable` | `ok` | `1/1` |  |
| `bpftrace/biosnoop` | `ok` | `2/2` |  |
| `bpftrace/vfsstat` | `ok` | `2/2` |  |
| `bpftrace/runqlat` | `ok` | `3/3` |  |
| `bpftrace/tcplife` | `ok` | `1/1` |  |
| `bpftrace/tcpretrans` | `ok` | `1/1` |  |
