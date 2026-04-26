# P0 Fix Smoke Verification

- Date: `2026-04-26`
- Commit checked: `db754540 Fix P0 bugs: error propagation, program discovery, workload triggers`
- Command: `make vm-corpus SAMPLES=1`
- Result dir: `corpus/results/x86_kvm_corpus_20260426_072112_513581`
- Suite status: `error`

## Findings

- `cilium/agent` still fails with `tracked BPF program ids disappeared before baseline`, so the P0 fix did not resolve the smoke-corpus program ID drift. This run lost 45 tracked IDs out of 61 before baseline.
- The suite never reached baseline for any app, so no ReJIT happened. Every app finished with `status=error` and `applied/requested=0/0`.
- `calico/felix` appears to have gotten past its own etcd/felix startup path before the suite-wide failure. Its result carries the shared lifecycle fatal error instead of a startup exception, and `CalicoRunner.start()` only returns after `LocalEtcdSession.start()` and `calico-node -startup` both succeed (`runner/libs/app_runners/etcd_support.py:281-295`, `runner/libs/app_runners/calico.py:58-65`). Only runners whose `start()` returned are added to lifecycle sessions (`corpus/driver.py:258-268`, `corpus/driver.py:294-309`). No separate etcd log artifact was preserved for this run.

## cilium Fatal Error

```text
cilium/agent: tracked BPF program ids disappeared before baseline:
missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233]
tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]
```

## App Matrix

| App | Status | Applied/Requested |
| --- | --- | --- |
| bcc/capable | error | 0/0 |
| bcc/execsnoop | error | 0/0 |
| bcc/bindsnoop | error | 0/0 |
| bcc/biosnoop | error | 0/0 |
| bcc/vfsstat | error | 0/0 |
| bcc/opensnoop | error | 0/0 |
| bcc/syscount | error | 0/0 |
| bcc/tcpconnect | error | 0/0 |
| bcc/tcplife | error | 0/0 |
| bcc/runqlat | error | 0/0 |
| calico/felix | error | 0/0 |
| otelcol-ebpf-profiler/profiling | error | 0/0 |
| cilium/agent | error | 0/0 |
| tetragon/observer | error | 0/0 |
| katran | error | 0/0 |
| tracee/monitor | error | 0/0 |
| bpftrace/capable | error | 0/0 |
| bpftrace/biosnoop | error | 0/0 |
| bpftrace/vfsstat | error | 0/0 |
| bpftrace/runqlat | error | 0/0 |
| bpftrace/tcplife | error | 0/0 |
| bpftrace/tcpretrans | error | 0/0 |
