# Authoritative Corpus Benchmark (2026-04-26)

## Run

- Command: `make vm-corpus SAMPLES=30`
- Result dir: `corpus/results/x86_kvm_corpus_20260426_064450_309533`
- Samples: `30`
- Started at: `2026-04-26T06:44:50.309533+00:00`
- Finished at: `2026-04-26T06:53:05.798049+00:00`
- Suite status: `error`
- Make exit code: `2` (`corpus/driver.py` exited with code `1`)

## Git Context

- `7b67f722 Add metadata files for various benchmark runs including bcc, bpftrace, katran, tetragon, and tracee`
- `ed4a8c65 Add docs/tmp reports from app expansion work`
- `a26db312 Add CLAUDE.md rules and rename /default app entries`
- `30dc544f benchmark: keep only supported macro apps`
- `764043c5 Remove scx from the benchmark framework`

## Program Counts

- `rejit_result.program_counts` was not emitted for any app in the final artifact.
- Effective ReJIT requests/applies: `0/0`, because the suite hit a fatal pre-baseline refresh error on `cilium/agent` and never entered `apply_rejit`.

## Per-App Status

| app | status | applied/requested |
| --- | --- | --- |
| `bcc/capable` | `error` | `n/a` |
| `bcc/execsnoop` | `error` | `n/a` |
| `bcc/bindsnoop` | `error` | `n/a` |
| `bcc/biosnoop` | `error` | `n/a` |
| `bcc/vfsstat` | `error` | `n/a` |
| `bcc/opensnoop` | `error` | `n/a` |
| `bcc/syscount` | `error` | `n/a` |
| `bcc/tcpconnect` | `error` | `n/a` |
| `bcc/tcplife` | `error` | `n/a` |
| `bcc/runqlat` | `error` | `n/a` |
| `calico/felix` | `error` | `n/a` |
| `otelcol-ebpf-profiler/profiling` | `error` | `n/a` |
| `cilium/agent` | `error` | `n/a` |
| `tetragon/observer` | `error` | `n/a` |
| `katran` | `error` | `n/a` |
| `tracee/monitor` | `error` | `n/a` |
| `bpftrace/capable` | `error` | `n/a` |
| `bpftrace/biosnoop` | `error` | `n/a` |
| `bpftrace/vfsstat` | `error` | `n/a` |
| `bpftrace/runqlat` | `error` | `n/a` |
| `bpftrace/tcplife` | `error` | `n/a` |
| `bpftrace/tcpretrans` | `error` | `n/a` |

## Errors

- Fatal suite error inherited by 18 apps:

```text
cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[98, 99, 101, 102, 104, 106, 107, 108, 109, 110, 111, 112, 113, 115, 116, 118, 119, 120, 121, 122, 123, 125, 126, 129, 130, 131, 132, 133, 135, 136, 137, 138, 139, 140, 141, 144, 148, 151, 156, 157, 158, 160, 161, 164, 167], tracked_ids=[72, 73, 98, 99, 101, 102, 104, 106, 107, 108, 109, 110, 111, 112, 113, 115, 116, 118, 119, 120, 121, 122, 123, 125, 126, 129, 130, 131, 132, 133, 135, 136, 137, 138, 139, 140, 141, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167]
```

- Affected apps: `bcc/capable`, `bcc/execsnoop`, `bcc/bindsnoop`, `bcc/biosnoop`, `bcc/vfsstat`, `bcc/opensnoop`, `bcc/syscount`, `bcc/tcpconnect`, `bcc/tcplife`, `bcc/runqlat`, `otelcol-ebpf-profiler/profiling`, `cilium/agent`, `tetragon/observer`, `katran`, `tracee/monitor`, `bpftrace/capable`, `bpftrace/tcplife`, `bpftrace/tcpretrans`

- `calico/felix`:

```text
local etcd did not become healthy within 20s: [WARNING] Deprecated '--logger=capnslog' flag is set; use '--logger=zap' flag instead
2026-04-26 06:45:39.811033 W | embed: Running http and grpc server on single port. This is not recommended for production.
2026-04-26 06:45:39.811072 I | etcdmain: etcd Version: 3.4.30
2026-04-26 06:45:39.811074 I | etcdmain: Git SHA: Not provided (use ./build instead of go build)
2026-04-26 06:45:39.811075 I | etcdmain: Go Version: go1.22.2
2026-04-26 06:45:39.811076 I | etcdmain: Go OS/Arch: linux/amd64
2026-04-26 06:45:39.811078 I | etcdmain: setting maximum number of CPUs to 4, total number of available CPUs is 4
2026-04-26 06:45:39.811080 N | etcdmain: failed to detect default host (could not find default route)
[WARNING] Deprecated '--logger=capnslog' flag is set; use '--logger=zap' flag instead
2026-04-26 06:45:39.811111 W | embed: Running http and grpc server on single port. This is not recommended for production.
2026-04-26 06:45:39.811226 I | embed: name = calico
2026-04-26 06:45:39.811231 I | embed: data dir = /var/tmp/calicorunner_ncu6tybi/etcd/data
2026-04-26 06:45:39.811233 I | embed: member dir = /var/tmp/calicorunner_ncu6tybi/etcd/data/member
2026-04-26 06:45:39.811234 I | embed: heartbeat = 100ms
2026-04-26 06:45:39.811235 I | embed: election = 1000ms
2026-04-26 06:45:39.811237 I | embed: snapshot count = 100000
2026-04-26 06:45:39.811243 I | embed: advertise client URLs = http://127.0.0.1:49177
2026-04-26 06:45:39.811261 W | pkg/fileutil: check file permission: directory "/var/tmp/calicorunner_ncu6tybi/etcd/data" exist, but the permission is "drwxr-xr-x". The recommended permission is "-rwx------" to prevent possible unprivileged access to the data.
2026-04-26 06:45:59.680178 W | wal: sync duration of 10.325369381s, expected less than 1s
2026-04-26 06:45:59.731772 I | etcdserver: starting member 4ac19f726c865bf in cluster cefa77e4af181c7c
raft2026/04/26 06:45:59 INFO: 4ac19f726c865bf switched to configuration voters=()
raft2026/04/26 06:45:59 INFO: 4ac19f726c865bf became follower at term 0
raft2026/04/26 06:45:59 INFO: newRaft 4ac19f726c865bf [peers: [], term: 0, commit: 0, applied: 0, lastindex: 0, lastterm: 0]
raft2026/04/26 06:45:59 INFO: 4ac19f726c865bf became follower at term 1
raft2026/04/26 06:45:59 INFO: 4ac19f726c865bf switched to configuration voters=(336672621444228543)
2026-04-26 06:45:59.949325 W | auth: simple token is not cryptographically signed
2026-04-26 06:46:00.095895 I | etcdserver: starting server... [version: 3.4.30, cluster version: to_be_decided]
2026-04-26 06:46:00.095979 I | pkg/fileutil: started to purge file, dir: /var/tmp/calicorunner_ncu6tybi/etcd/data/member/snap, suffix: snap.db, max: 5, interval: 30s
2026-04-26 06:46:00.096003 I | pkg/fileutil: started to purge file, dir: /var/tmp/calicorunner_ncu6tybi/etcd/data/member/snap, suffix: snap, max: 5, interval: 30s
2026-04-26 06:46:00.096016 I | pkg/fileutil: started to purge file, dir: /var/tmp/calicorunner_ncu6tybi/etcd/data/member/wal, suffix: wal, max: 5, interval: 30s
2026-04-26 06:46:00.096143 I | etcdserver: 4ac19f726c865bf as single-node; fast-forwarding 9 ticks (election ticks 10)
2026-04-26 06:46:00.096629 I | embed: listening for peers on 127.0.0.1:43589
raft2026/04/26 06:46:00 INFO: 4ac19f726c865bf switched to configuration voters=(336672621444228543)
2026-04-26 06:46:00.116218 I | etcdserver/membership: added member 4ac19f726c865bf [http://127.0.0.1:43589] to cluster cefa77e4af181c7c
```

- `bpftrace/biosnoop`, `bpftrace/vfsstat`, `bpftrace/runqlat`:

```text
BPF program set did not stabilize before timeout (timeout_s=60, last_program_count=0, last_program_ids=<none>, peak_program_count=0, peak_program_ids=<none>)
```

## Notes

- This run preserved a debug artifact path: `.state/runner-contracts/run.x86-kvm.corpus.bd261087` (directory existed but was empty after the failure).
- During the run, an unrelated host-side `docker build --platform linux/arm64 ... runner-runtime:arm64` process was also running. This adds host resource contention and should be kept in mind when interpreting timing-sensitive failures such as the Calico etcd startup issue.
