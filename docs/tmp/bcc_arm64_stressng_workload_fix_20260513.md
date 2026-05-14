# bcc ARM64 stress-ng workload fix (2026-05-13)

## Verdict

`bcc/set` is not failing on the `rename` stressor; it is failing because the shared `stress_ng_os_io_network` workload lets an unnecessary SCTP stressor fail under the ARM64 `t4g.small` + BCC tracing load, and the recommended fix is a smaller BCC-specific stress-ng workload that excludes SCTP and other fringe stressors while still exercising the BCC programs.

## Failure root cause

Observed artifact:

- `corpus/results/aws_arm64_corpus_20260513_221545_067112/details/apps/bcc__set.json`
- app status: `error`
- baseline/post workload records: absent, because `run_stress_ng_class_load()` raises before `_record_run()`
- error tail starts at a normal metrics row:

```text
stress_ng_os_io_network workload failed: stress-ng: metrc: [2699] rename ...
...
stress-ng: info:  [2699] passed: 250: ... sctp (2) ... rename (4) ... fcntl (4)
stress-ng: info:  [2699] failed: 2: sctp (2)
stress-ng: info:  [2699] unsuccessful run completed in 26.53 secs
```

`stress-ng: metrc: [2699] rename ...` is the `--metrics-brief` table row for the `--rename 4` stressor. It is not the failing condition. The failure line is `failed: 2: sctp (2)`.

The BCC result does not serialize the command or return code because the runner throws on nonzero return before producing a `WorkloadResult`. Reconstructed from `runner/libs/workload.py`, the same run's successful stress-ng workload records, and `workload_seconds=10`, the command is:

```text
/usr/bin/stress-ng --cap 4 --eventfd 4 --get 4 --prctl 4 --set 4 --dup 4 --kill 4 --sigfd 4 --signal 4 --pty 4 --itimer 4 --timerfd 4 --exec 4 --fork 4 --vfork 4 --clone 4 --ptrace 4 --futex 4 --sem 4 --aio 4 --aiol 4 --hdd 4 --hdd-bytes 128M --io 4 --iomix 4 --iomix-bytes 128M --io-uring 4 --sync-file 4 --epoll 4 --netdev 4 --sctp 4 --sock 4 --sockdiag 4 --sockfd 4 --sockpair 4 --sockmany 4 --udp 4 --udp-flood 4 --mmap 4 --mmap-bytes 16M --mprotect 4 --mremap 4 --mremap-bytes 16M --madvise 4 --access 4 --chdir 4 --chmod 4 --chown 4 --dentry 4 --dir 4 --dirmany 4 --fallocate 4 --fallocate-bytes 128M --file-ioctl 4 --filename 4 --flock 4 --fpunch 4 --fpunch-bytes 32M --fstat 4 --getdent 4 --hdd 4 --hdd-bytes 128M --inotify 4 --open 4 --open-max 1024 --rename 4 --touch 4 --utime 4 --link 4 --symlink 4 --mknod 4 --fcntl 4 --epoll-port 22717 --sctp-port 22817 --sock-port 22917 --sockfd-port 23017 --timeout 10s --metrics-brief --temp-path /var/tmp/bpfrejit-runtime/vhwwzm
```

Effective exit code is `2`: stress-ng documents exit status 2 as "one or more stressors failed". The runner does not persist the numeric return code in the error result.

This is not a filesystem permission issue:

- The command already passes `--temp-path /var/tmp/bpfrejit-runtime/vhwwzm`.
- `run_stress_ng_class_load()` also sets `cwd=temp_root`.
- `rename` completed and reported `36168` bogo ops.

This is not evidence that the `rename` stressor is incompatible with AL2023 ARM64. The stress-ng binary runs inside the Ubuntu 24.04 runtime image (`runner/containers/runner-runtime.Dockerfile` installs `stress-ng`), not directly from the AL2023 host. The ARM64 kernel has SCTP configured as a module (`CONFIG_IP_SCTP=m`), and the same workload's SCTP stressor passed for other apps in the same run.

## Comparison: x86 vs arm64

Latest working x86 BCC result found:

- `corpus/results/x86_kvm_corpus_20260513_044032_268548/details/apps/bcc__set.json`
- status: `ok`
- selected workload: `stress_ng_os_io_network`
- both baseline and post-ReJIT workload commands returned `0`
- same stressor set, with `--timeout 15s`, x86-derived ports, and temp path `/var/tmp/bpfrejit-runtime/qgw`
- 21 BCC programs were measured, including raw syscall, VFS/open, capability, scheduler, TCP connect/life, and block I/O probes.

The ARM64 2026-05-13 run used the same shared workload shape. In that same ARM64 run, `bpftrace/set`, `tetragon/observer`, and `tracee/monitor` ran `stress_ng_os_io_network` successfully. The BCC-specific difference is that `bcc/set` has eight BCC tools attached, including high-rate raw syscall tracing, VFS tracing, sched tracing, TCP tracing, and block tracing. On a `t4g.small`, the shared workload launches roughly 250 stressor workers plus those tools; SCTP is not needed for any BCC program but can still fail the whole measurement.

Earlier ARM64 results also show this workload can fail on a different fringe stressor (`fcntl`) for other apps, so the broader issue is the all-in-one stress-ng workload being too broad and failure-sensitive on small ARM64 instances.

## Fix options

Option A: remove `sctp` from the shared `_STRESS_NG_NETWORK_STRESSORS`.

- Change: edit `runner/libs/workload.py` and delete `"sctp"` from `_STRESS_NG_NETWORK_STRESSORS`.
- Pros: minimal code diff; fixes the observed current failure; BCC does not need SCTP because `--sock` defaults to TCP and exercises `tcpconnect`/`tcplife`.
- Cons: shared workload still has many unrelated stressors and previous ARM64 artifacts show `fcntl` can also fail.

Option B/C: keep `rename`, but force or redirect temp path.

- Not useful for this failure. The command already uses `--temp-path`; `rename` passed; the failure was SCTP.
- A dedicated `/tmp/bcc-workload` would not address `failed: 2: sctp (2)`.

Option D: introduce a BCC-specific workload that exercises only what BCC loads.

- Add a new workload kind in `runner/libs/workload.py`, for example `stress_ng_bcc_set`.
- Stressors should cover:
  - syscount/raw syscalls: `get`, `eventfd`, `prctl`, `set`, `dup`
  - capable: `cap`
  - opensnoop/vfsstat: `open`, `hdd`, `touch`, `getdent`, `rename`, `utime`
  - biosnoop: `hdd` or `iomix`
  - runqlat: `futex`, `sem`, `switch`, `yield`
  - tcpconnect/tcplife: `sock` with default TCP
- Exclude at least `sctp`, `fcntl`, and root-skipped `exec`.
- Wire `bcc/set` to the new workload in `runner/libs/benchmark_catalog.py` and `runner/libs/app_runners/bcc_set.py`.

YAML override path check:

- There is no current `runner/config/bcc/aws_arm64.yaml` workload override path.
- `runner/config/passes/<pass>/<app>.yaml` is ReJIT pass configuration only. Katran's `runner/config/passes/map_inline/katran.yaml` overrides `map_inline` CLI arguments by app/program name; it does not override workloads or platforms.
- `corpus/config/benchmark_config.yaml` has platform pass policy only.
- `corpus/config/macro_apps.yaml` is schema v2 and lists app names only. Schema v1 can spell workloads, but the current BCC adapter rejects any workload other than the hard-coded BCC constant, so a YAML-only BCC ARM64 workload override will not work without code changes.

## Recommendation

Implement Option D for `bcc/set` on all platforms, not only ARM64: add a targeted `stress_ng_bcc_set` workload and wire BCC to it. This keeps x86/ARM64 BCC comparable, removes the observed SCTP failure source, avoids future failures from unrelated stressors like `fcntl`, and still drives the BCC program set that actually matters.

For a one-line emergency unblock only, remove `sctp` from the shared network stressor list, but treat that as a narrower fix than the evidence supports.
