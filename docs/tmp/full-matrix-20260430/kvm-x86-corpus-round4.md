# KVM x86 corpus round 4 follow-up

Date: 2026-05-01

## Round 4 result

Latest result dir:

`corpus/results/x86_kvm_corpus_20260501_080144_647592/`

Round 4 ended with `status=error`, but produced 127 usable per-program samples:

- per-program geomean: `0.8267806927735911` post/baseline (`< 1.0` means faster)
- wins/losses: `76/51`
- compared with historical build #42 speedup-style values (`exec 1.046x`, `Calico 1.097x`, `suricata 1.538x`, `tracee 1.230x`), round 4 still has too many no-apply and regression-looking successful samples in bcc/bpftrace. Calico did not reach ratio measurement because baseline workload failed.

Selected successful app status:

| app | status | requested | applied | not_applied | per-program geomean |
| --- | --- | ---: | ---: | ---: | ---: |
| bcc/capable | ok | 1 | 1 | 0 | 0.991963 |
| bcc/execsnoop | ok | 2 | 0 | 2 | 1.089277 |
| bcc/bindsnoop | ok | 3 | 2 | 1 | 1.128039 |
| bcc/biosnoop | ok | 3 | 0 | 3 | 1.024598 |
| bcc/vfsstat | ok | 5 | 0 | 5 | 0.973694 |
| bcc/opensnoop | ok | 3 | 0 | 3 | 1.021295 |
| bcc/syscount | ok | 2 | 0 | 2 | 1.023341 |
| bcc/tcpconnect | ok | 3 | 2 | 1 | 0.914489 |
| bcc/tcplife | ok | 1 | 1 | 0 | 0.930963 |
| bcc/runqlat | ok | 3 | 1 | 2 | 1.010054 |
| otelcol-ebpf-profiler/profiling | ok | 13 | 13 | 0 | 0.932227 |
| bpftrace/capable | ok | 1 | 1 | 0 | 1.104406 |
| bpftrace/biosnoop | ok | 2 | 1 | 1 | 0.984291 |
| bpftrace/vfsstat | ok | 2 | 1 | 1 | 0.987386 |
| bpftrace/runqlat | ok | 3 | 1 | 2 | 1.032107 |
| bpftrace/tcplife | ok | 1 | 1 | 0 | 1.024115 |
| bpftrace/tcpretrans | ok | 1 | 1 | 0 | no included per-program sample |

Programs at or above `0.99` ratio in the requested successful apps:

- bcc/capable: `cap_capable` 0.991963
- bcc/execsnoop: `syscall__execve` 1.015070, `do_ret_sys_execve` 1.168908
- bcc/bindsnoop: `bindsnoop_entry` 1.099658, `bindsnoop_v4_re` 1.157153
- bcc/biosnoop: `trace_pid_start_tp` 1.024045, `trace_req_start` 1.035913, `trace_req_completion_tp` 1.013954
- bcc/vfsstat: `vfs_open` 1.011933
- bcc/opensnoop: `__x64_sys_open` 1.025703, `kretfunc__vmlinux____x64_sys_openat` 1.028936, `kretfunc__vmlinux____x64_sys_openat2` 1.009354
- bcc/syscount: `tracepoint__raw_syscalls__sys_enter` 1.000020, `tracepoint__raw_syscalls__sys_exit` 1.047206
- bcc/runqlat: `sched_switch` 1.013097, `sched_wakeup` 1.025058, `raw_tracepoint__sched_wakeup_new` 0.992280
- bpftrace/capable: `cap_capable` 1.104406
- bpftrace/biosnoop: `block_io_done` 1.018408
- bpftrace/vfsstat: `vfs_create` 1.034025
- bpftrace/runqlat: `sched_wakeup` 1.072384, `tracepoint_sched_sched_wakeup_new` 1.009330, `sched_switch` 1.015760
- bpftrace/tcplife: `tcp_set_state` 1.024115

## Fixes

### 1. `bpfverify --verifier-states-out` 5s timeout

Root cause: commit `441ad97f` made every daemon CLI stage use the same 5s timeout. That avoids true hangs, but it also killed verifier-heavy Tetragon programs, e.g. prog 432. The same 5s cap also hit `bpfopt optimize`, final `bpfverify`, post-failure report capture, and `bpfrejit` in round 4.

Fix:

- `daemon/src/commands.rs` now uses stage-specific timeouts.
- Lightweight discovery stays at 5s.
- verifier-state capture, final verification, post-rejit report capture, `bpfopt optimize`, and `bpfrejit` get a bounded 60s timeout.
- Failure workdir normalization no longer requires `verifier.log` for failures that happen before a verifier report can be written, but still rejects an existing empty/non-regular verifier log.

Alternatives tried/considered:

- Remove verifier-state capture: rejected because `const_prop` needs real verifier states.
- Global 5s -> 60s: rejected because it weakens hang detection for all subprocesses.
- Stage-specific bounded timeout: chosen.

Tests:

- `commands::tests::verifier_and_optimizer_stages_have_heavy_timeouts`
- `commands::tests::failure_workdir_preserves_pre_report_failures_without_verifier_log`

### 2. Resolved pseudo map pointer replay

Root cause: `bpfget`/`bpfverify` only reconstructed resolved kernel map pointers when a program had exactly one map. Round 4 hit both single-map and multi-map cases:

- katran prog 1946: raw map pointer loaded into `r2` before `bpf_tail_call`.
- tracee prog 2009: final verification failed before report generation because `map_fds.json cannot reconstruct resolved kernel map pointer at insn 14223 with 16 map bindings`.

Fix:

- `bpfget` rewrites resolved map pointer `LD_IMM64` back to `BPF_PSEUDO_MAP_IDX` using `prog_info.map_ids` order.
- `bpfverify` reconstructs resolved map pointers back to real map fds using the same map-id order.
- Detection is not a raw `0xffff...` heuristic anymore: the loaded pointer must be consumed as a map argument to known map helpers (`r1`) or `bpf_tail_call` (`r2`). This avoids rewriting BTF/kfunc/FUNC-like kernel addresses that are not map arguments.
- If the number of distinct resolved map pointers does not match the exposed map ids, the tool exits 1 instead of guessing.

Alternatives tried/considered:

- Keep the single-map special case: insufficient for tracee multi-map programs.
- Let raw kernel pointers through: kernel verifier rejects user-supplied kernel pointers.
- Add a kernel-side metadata API: too broad for this round and not needed because `prog_info.map_ids` follows `used_maps` order.

Tests:

- `bpfget`: multi-map rewrite by used-map order, mismatch error, and non-map kernel pointer no-rewrite.
- `bpfverify`: multi-map binding by map-id order, mismatch error, and non-map kernel pointer no-rewrite.

### 3. Calico/Cilium baseline `wrk` EADDRNOTAVAIL

Root cause: interface-bound workloads start the HTTP server in `bpfbenchns` at `198.18.0.2`, but `wrk`/`curl` were launched from the host namespace. Round 4 failed baseline for Calico and Cilium with:

`unable to connect to 198.18.0.2:18080 Cannot assign requested address`

Fix:

- `runner/libs/workload.py` now prefixes interface-bound network clients with `ip netns exec bpfbenchns`.
- Loopback workloads still run in the current namespace.
- The existing app-level startup model is unchanged.

Alternatives tried/considered:

- Add a host-side alias/route for `198.18.0.2`: more fragile and depends on host namespace setup.
- Move the server out of `bpfbenchns`: would stop matching the interface-bound workload model.
- Move the client into `bpfbenchns`: chosen.

Tests:

- `WorkloadContractTests.test_interface_bound_network_client_runs_inside_benchmark_netns`
- `WorkloadContractTests.test_loopback_network_client_stays_in_current_namespace`

### 4. Preserved workdir availability

Round 4 logs claimed paths like `/home/yunwei37/workspace/bpf-benchmark/bpfrejit-failures/432`, but the top-level `bpfrejit-failures/` directory was empty on the host after the run. One direct cause is visible in `/tmp/vm-corpus.log`: timeouts happened before `verifier.log` existed, then artifact normalization failed with `failure verifier.log ... is missing`.

Fix is included with Bug 1: preserve bytecode, metadata, and replay script even when a failure happens before verifier report/log creation.

Host check:

- `find bpfrejit-failures -maxdepth 2` showed only the empty root.
- Older preserved prog 432 artifacts exist under `corpus/results/aws_x86_corpus_20260430_014417_532765/details/failures/432/`.
- Replaying that old workdir on this host is blocked by host capabilities:
  - live replay: `BPF_MAP_GET_FD_BY_ID: Operation not permitted`
  - dummy-map replay: `BPF_MAP_CREATE: Operation not permitted`

### 5. Tracee prog 2009 final verification

The user note described a pass-generated verifier rejection. The actual round 4 result for prog 2009 failed earlier in `bpfverify final verification` because the candidate still contained resolved map pointers and `bpfverify` could not reconstruct them with 16 map bindings. This is fixed by the same multi-map resolved pointer replay change in Bug 2.

If a true pass-generated kprobe verifier rejection remains after this fix, it should now surface with preserved artifacts and a verifier log instead of being hidden by pseudo relocation reconstruction.

## Verification

Commands run:

- `cargo test --workspace` from `bpfopt/`: passed
- `make daemon-tests`: passed, 40 tests
- `PYTHONPATH=. python3 tests/python/test_workload.py`: passed, 4 tests
- `make check`: passed; this ran `vm-test`, not `vm-corpus`, `vm-e2e`, or `vm-micro`

## Claude handoff

修复完成，请跑 `make vm-corpus` 验证。
