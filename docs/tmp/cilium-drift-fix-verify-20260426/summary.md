# Cilium Drift Fix Verify - 2026-04-26

## Scope

Validate the latest `cilium` program-ID drift fix with a VM corpus smoke run.

- Commit confirmed: `cc762f62 Fix cilium program ID drift: rediscover programs on ID disappearance`
- Command: `make vm-corpus SAMPLES=1`
- Run token: `run.x86-kvm.corpus.6e66f52f`
- Artifact dir: `corpus/results/x86_kvm_corpus_20260426_080131_826312`

## Result

- Top-level corpus status: `error`
- Per-case status: `21/22 ok`
- The only failing case was `tracee/monitor`
- `cilium/agent` completed successfully; the previous drift failure signature did not recur

## Cilium Focus

Previous failing artifact from the same day:

- `corpus/results/x86_kvm_corpus_20260426_072112_513581/metadata.json`
- Error: `cilium/agent: tracked BPF program ids disappeared before baseline: ...`

Current verification artifact:

- `cilium/agent` status: `ok`
- `cilium/agent` applied/requested: `16/16`
- `cilium/agent` error: empty
- Search in current artifact for `tracked BPF program ids disappeared`: no matches
- `cilium/agent` baseline BPF IDs and post-ReJIT BPF IDs matched exactly:
  `140,141,213,214,215,217,219,220,221,224,226,228,231,233,234,236`

Conclusion for the target fix:

- The `cilium` program-ID drift issue is fixed in this smoke corpus run.
- The run no longer aborts in `cilium/agent` before baseline collection.

## Per-Case Status

| App | Status | Applied/Requested | Error |
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
| `cilium/agent` | `ok` | `16/16` |  |
| `tetragon/observer` | `ok` | `287/287` |  |
| `katran` | `ok` | `3/3` |  |
| `tracee/monitor` | `error` | `157/158` | `prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)` |
| `bpftrace/capable` | `ok` | `1/1` |  |
| `bpftrace/biosnoop` | `ok` | `2/2` |  |
| `bpftrace/vfsstat` | `ok` | `2/2` |  |
| `bpftrace/runqlat` | `ok` | `3/3` |  |
| `bpftrace/tcplife` | `ok` | `1/1` |  |
| `bpftrace/tcpretrans` | `ok` | `1/1` |  |

## Notes

- This was a verification-only run. No commit was created.
- The remaining failure is unrelated to the `cilium` drift fix: `tracee/monitor` hit a single-program ReJIT `EINVAL` on `prog 665`.
