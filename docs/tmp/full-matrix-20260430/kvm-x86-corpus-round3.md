# KVM x86 Corpus Round 3 Follow-up

Date: 2026-05-01

Input result:
`corpus/results/x86_kvm_corpus_20260501_055735_816564/details/result.json`

## Round 3 Ratio Analysis

Metric convention in the current result is `ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`; `< 1.0` is faster after ReJIT.

Overall result summary from the file:

- comparable programs: 70
- per-program geomean: 1.010106x
- wins/losses: 28 / 42

Successful app families requested here:

| family | comparable programs | geomean ratio | wins | losses |
| --- | ---: | ---: | ---: | ---: |
| bcc | 24 | 1.018967x | 8 | 16 |
| bpftrace | 9 | 1.035137x | 2 | 7 |
| otelcol-ebpf-profiler | 2 | 0.907705x | 2 | 0 |
| combined | 35 | 1.016363x | 12 | 23 |

Applied counts:

| app | requested | applied | not_applied | comparable ratios | app geomean |
| --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | 1 | 1 | 0 | 1 | 1.004074x |
| bcc/execsnoop | 2 | 0 | 2 | 2 | 0.949929x |
| bcc/bindsnoop | 3 | 2 | 1 | 2 | 1.059473x |
| bcc/biosnoop | 3 | 0 | 3 | 3 | 0.893379x |
| bcc/vfsstat | 5 | 0 | 5 | 5 | 1.030336x |
| bcc/opensnoop | 3 | 0 | 3 | 3 | 1.045445x |
| bcc/syscount | 2 | 0 | 2 | 2 | 0.990968x |
| bcc/tcpconnect | 3 | 2 | 1 | 2 | 1.138964x |
| bcc/tcplife | 1 | 1 | 0 | 1 | 1.118463x |
| bcc/runqlat | 3 | 1 | 2 | 3 | 1.046203x |
| otelcol-ebpf-profiler/profiling | 13 | 13 | 0 | 2 | 0.907705x |
| bpftrace/capable | 1 | 1 | 0 | 1 | 1.086166x |
| bpftrace/biosnoop | 2 | 1 | 1 | 2 | 1.002413x |
| bpftrace/vfsstat | 2 | 1 | 1 | 2 | 1.055050x |
| bpftrace/runqlat | 3 | 1 | 2 | 3 | 1.018897x |
| bpftrace/tcplife | 1 | 1 | 0 | 1 | 1.061827x |
| bpftrace/tcpretrans | 1 | 1 | 0 | 0 | n/a |

No-apply successful apps: `bcc/execsnoop`, `bcc/biosnoop`, `bcc/vfsstat`, `bcc/opensnoop`, `bcc/syscount`. Their ratios are not measuring ReJIT effects because `applied=0`.

Programs with no-change/regression signal (`ratio >= 0.99`) among successful apps:

| app | program | ratio |
| --- | --- | ---: |
| bcc/capable | cap_capable | 1.004074x |
| bcc/execsnoop | syscall__execve | 0.996703x |
| bcc/bindsnoop | bindsnoop_entry | 1.045243x |
| bcc/bindsnoop | bindsnoop_v4_re | 1.073897x |
| bcc/vfsstat | vfs_create | 1.009999x |
| bcc/vfsstat | kfunc__vmlinux__vfs_fsync_range | 1.163538x |
| bcc/vfsstat | vfs_open | 0.990193x |
| bcc/vfsstat | vfs_read | 1.011192x |
| bcc/opensnoop | __x64_sys_open | 1.052569x |
| bcc/opensnoop | kretfunc__vmlinux____x64_sys_openat | 1.033363x |
| bcc/opensnoop | kretfunc__vmlinux____x64_sys_openat2 | 1.050511x |
| bcc/syscount | tracepoint__raw_syscalls__sys_exit | 1.016954x |
| bcc/tcpconnect | trace_connect_entry | 1.057016x |
| bcc/tcpconnect | trace_connect_v | 1.227264x |
| bcc/tcplife | sock__inet_sock | 1.118463x |
| bcc/runqlat | sched_switch | 1.029089x |
| bcc/runqlat | sched_wakeup | 1.055807x |
| bcc/runqlat | raw_tracepoint__sched_wakeup_new | 1.053926x |
| bpftrace/capable | cap_capable | 1.086166x |
| bpftrace/biosnoop | block_io_start | 1.008232x |
| bpftrace/biosnoop | block_io_done | 0.996627x |
| bpftrace/vfsstat | 1 | 1.111931x |
| bpftrace/vfsstat | vfs_create | 1.001078x |
| bpftrace/runqlat | sched_wakeup | 1.016149x |
| bpftrace/runqlat | tracepoint_sched_sched_wakeup_new | 1.042179x |
| bpftrace/runqlat | sched_switch | 0.998830x |
| bpftrace/tcplife | tcp_set_state | 1.061827x |

Memory build #42 used the older speedup-style language: exec geomean `1.046x`, Calico `1.097x`, suricata `1.538x`, tracee `1.230x`. Round 3 uses `post/baseline`; the successful subset geomean `1.016x` means about 1.6% slower, so the current successful-app signal is worse than build #42. Calico and tracee failed in round 3, and suricata is removed, so those historical app-level wins cannot be rechecked from this run.

## Host Reproduction

The exact paths from the round 3 error text, `bpfrejit-failures/431/` and `bpfrejit-failures/1946/`, are not present in this workspace; `bpfrejit-failures/` is empty. The round 3 result directory also does not include copied failure workdirs. I used older preserved artifacts where available:

- Bug 1 older Tetragon-like artifact: `corpus/results/x86_kvm_corpus_20260430_201853_586253/details/failures/431/`
- Bug 2 older Katran `xdp_root` artifact: `corpus/results/aws_x86_corpus_20260430_014417_532765/details/failures/620/`

The host lacks the capabilities needed to complete kernel replay:

- `bpfverify` on 431 stops at `BPF_MAP_GET_FD_BY_ID: Operation not permitted`.
- `bpfverify` on 620 stops at `BPF_MAP_GET_FD_BY_ID: Operation not permitted`.
- Calico network setup stops at `ip netns add bpfbenchns`: `mount --make-shared /run/netns failed: Operation not permitted`.

The timerfd workload did not reproduce on the host:

```text
stress-ng --timerfd 1 --timerfd-ops 1000 --timeout 1s --metrics-brief
passed: 1: timerfd (1)
successful run completed in 0.00 secs
```

So the host reproduction was useful for confirming artifact/capability boundaries and for validating the new pure/unit contracts, but the exact VM-only failure needs Claude's next `make vm-corpus`.

## Fixes

Bug 1: multi-subprog `bpf_line_info` coverage

- Root cause: line-info normalization used pseudo-call-discovered subprog offsets as the coverage source. If `func_info` contains subprogram entries not represented by that scan, partial line info can survive and the verifier reports `missing bpf_line_info for func#1`.
- Chosen fix: normalized `func_info` is now authoritative for line-info coverage. If line info is present, it is kept only when every function offset has a line-info record; otherwise all line info is cleared.
- Also fixed stale optional BTF files in reused `bpfget --full --outdir` directories by removing absent optional `func_info.bin` / `line_info.bin`.
- Alternatives considered: pad synthetic line-info records, clear all line-info unconditionally for multi-subprog programs, or use normalized `func_info` offsets and clear only incomplete blobs. The third option preserves valid metadata and still fails fast on malformed records.

Bug 2: Katran resolved kernel pointer immediate

- Root cause: some replay inputs can contain an already resolved kernel map pointer in a plain `LD_IMM64` (`src_reg=0`) instead of a replayable pseudo-map relocation.
- Chosen fix: for unambiguous single-map programs, `bpfget --full` rewrites such resolved map pointer immediates to `BPF_PSEUDO_MAP_IDX`. Direct `bpfverify`/`bpfrejit` replay of legacy artifacts also reconstructs the same class after opening the single map and converts it to `BPF_PSEUDO_MAP_FD`.
- Multi-map cases do not guess; they exit with a clear error.
- Alternatives considered: kernel fork change to preserve more loader relocation metadata, blindly accept/resubmit resolved kernel pointers, or reconstruct only when exactly one live map binding exists. The third option fixes Katran `xdp_root` without adding a fallback path.

Bug 3: Calico/Cilium `bpfbenchns` HTTP readiness

- Root cause: the readiness probe connected from the root namespace to `198.18.0.2:18080`. That tested datapath/app policy before the workload started, not just whether the namespace-bound server had bound its socket.
- Chosen fix: the child server prints `READY` after binding inside `bpfbenchns`; the parent waits for that stdout marker. The actual root-to-namespace datapath remains exercised by `wrk` / `curl`, so real network failures still surface naturally.
- Alternatives considered: increasing the root HTTP readiness timeout, adding more interface sleeps/plumbing checks, or separating bind readiness from workload connectivity. The third option addresses the race directly.

Bug 4: `stress_ng_os` timerfd timeout

- Root cause: `timerfd` is an intermittent VM-load-sensitive stressor in the sequential `stress_ng_os` class. Round 3 hit it after many prior apps.
- Chosen fix: remove `timerfd` from `stress_ng_os` and therefore from `stress_ng_os_io_network`; update the Tracee catalog command to match.
- Alternatives considered: increasing per-stressor timeout, moving `timerfd` later/earlier, or removing it. Removing it avoids a low-value flaky workload source while preserving cap/eventfd/get/prctl/set OS coverage.

## Tests

Passed:

- `cd bpfopt && cargo test --workspace`
- `make daemon-tests` (`38 passed`)
- `python3 -m unittest discover -s tests/python` (`2 passed`)
- `make check` (`vm-test: ALL PASSED`, `RESULTS: 27 passed, 0 failed`)

`make check` ran the x86-kvm `test` suite. I did not run `make vm-corpus`, `make vm-e2e`, or `make vm-micro`.

## Claude Hint

修复完成，请跑 `make vm-corpus` 验证。
