# Q5 wide_mem-only 7-app KVM kernel panic investigation

Date: 2026-05-07

Scope: Q5 `BPFREJIT_BENCH_PASSES=wide_mem`, x86 KVM corpus, 7-app queue window `2026-05-07T23:16:42Z` to `2026-05-07T23:37:01Z`, `rc=2`.

Constraints observed: no changes were made to `vendor/linux-framework`; this is read-only investigation.

## Sources

- Queue log: `docs/tmp/bench_queue_post_refactor_20260507.log`
- Q5 partial result dir: `corpus/results/x86_kvm_corpus_20260507_231837_529348`
- Q5 metadata: `enabled_passes=["wide_mem"]`, `samples=3`, `workload_seconds=30.0`, `started_at=2026-05-07T23:18:37.529348Z`
- Q5 app JSONs that reached disk: `bcc__set.json`, `otelcol-ebpf-profiler__profiling.json`, `cilium__agent.json`
- Tetragon proxy data: `corpus/results/x86_kvm_corpus_20260507_200821_664435/details/apps/tetragon__observer.json`. Q5 panicked before `tetragon__observer.json` was written, so this successful same-day 287-program Tetragon run is used only to identify the stable program set and wide_mem shape. Q5 log's `program_count=287` matches this proxy exactly.
- The queue script path named in the prompt, `scripts/bench_queue_post_refactor_20260507.sh`, is not present in this checkout. The log and result metadata were sufficient to reconstruct the run.

## Executive finding

The panic is best explained as a ReJIT refresh/tail-call-poke lifecycle bug exposed by `wide_mem` on Tetragon, not as a direct verifier failure and not as a `bpf_bulk_memory` module-signing issue.

The important distinction is where the kernel warning is printed. `bpf_rejit: retaining old JIT image after refresh failure` is emitted only after `BPF_PROG_REJIT` has already verified/JITed a temporary program and swapped `prog->bpf_func` to the new image. The subsequent refresh step failed, the syscall returned an error, and the runner still started the post-ReJIT workload. About 0.24 seconds after the last Tetragon retain line, execution entered BPF from a kprobe and landed at `0xffffffffc00ad8d5`, where the bytes were all `0xcc` (`int3` fill).

That means the kernel did not crash inside the ReJIT syscall. It returned an error after leaving a mixed old/new JIT-image state that was later executed by Tetragon's kprobe/tail-call workload.

## Panic timeline

Kernel wall-clock conversion uses the Q5 boot line:

- kernel `[0.473556]` set clock to `2026-05-07T23:16:44Z`
- estimated wall time = `23:16:44Z + (kernel_ts - 0.473556)s`

| Log line | Time | Event | App | Program info |
| --- | --- | --- | --- | --- |
| 2626 | `2026-05-07T23:18:36.272269Z` (`[112.745825]`) | `bpf_bulk_memory: module verification failed` | boot/module load | Noise. Same module-signing warning appears in Q4/Q6/Q7/Q8/Q9 boots. |
| 2627 | no kernel ts | `app_start` | `bcc/set` | workload `stress_ng_os_io_network` |
| 2823 | no kernel ts | `rejit_start` | `bcc/set` | `program_count=21`; Q5 exact prog ids `6-7,10-14,19,22-24,27-29,32-34,37-40`; all `wide_mem sites_applied=0` |
| 2824 | no kernel ts | `rejit_done status=ok` | `bcc/set` | no retain lines |
| 3012 | no kernel ts | `app_done status=ok` | `bcc/set` | app completed |
| 3013 | no kernel ts | `app_start` | `otelcol-ebpf-profiler/profiling` | workload `otel_mixed_workload` |
| 3020 | no kernel ts | `rejit_start` | `otelcol-ebpf-profiler/profiling` | `program_count=13`; Q5 exact prog ids `43-55`; total `wide_mem sites_applied=132` |
| 3021 | no kernel ts | `rejit_done status=ok` | `otelcol-ebpf-profiler/profiling` | no retain lines |
| 3024 | no kernel ts | `app_done status=ok` | `otelcol-ebpf-profiler/profiling` | app completed |
| 3025 | no kernel ts | `app_start` | `cilium/agent` | workload `network_lossy_multi` |
| 3046 | no kernel ts | `rejit_start` | `cilium/agent` | `program_count=62`; Q5 exact prog ids `63-64,159-194,196-214,216-220`; all `wide_mem sites_applied=0` |
| 3047 | `2026-05-07T23:31:20.734194Z` (`[877.207750]`) | `retaining old JIT image after refresh failure` | `cilium/agent` | corresponds to a post-swap refresh failure, not cleanup |
| 3048 | `2026-05-07T23:31:22.316888Z` (`[878.790444]`) | `retaining old JIT image after refresh failure` | `cilium/agent` | second cilium post-swap refresh failure |
| 3049 | no kernel ts | `rejit_done status=error` | `cilium/agent` | app JSON still later records app `status=ok` |
| 3073 | no kernel ts | `ConnectionResetError: [Errno 104]` | `cilium/agent` | HTTP server saw wrk peer reset during post-ReJIT workload |
| 3077 | no kernel ts | `app_done status=ok` | `cilium/agent` | cilium completed despite ReJIT errors |
| 3078 | no kernel ts | `app_start` | `tetragon/observer` | workload `stress_ng_os_io_network` |
| 3275 | no kernel ts | `rejit_start` | `tetragon/observer` | `program_count=287`; Q5 panicked before app JSON was flushed |
| 3276 | `2026-05-07T23:36:24.305921Z` (`[1180.779477]`) | `retaining old JIT image after refresh failure` | `tetragon/observer` | first Tetragon post-swap refresh failure |
| 3277 | `2026-05-07T23:36:25.233855Z` (`[1181.707411]`) | retain old image | `tetragon/observer` | second |
| 3278 | `2026-05-07T23:36:25.993641Z` (`[1182.467197]`) | retain old image | `tetragon/observer` | third |
| 3279 | `2026-05-07T23:36:26.952129Z` (`[1183.425685]`) | retain old image | `tetragon/observer` | fourth |
| 3280 | `2026-05-07T23:36:28.275583Z` (`[1184.749139]`) | retain old image | `tetragon/observer` | fifth |
| 3281 | `2026-05-07T23:36:28.714192Z` (`[1185.187748]`) | retain old image | `tetragon/observer` | sixth |
| 3282 | `2026-05-07T23:36:29.045055Z` (`[1185.518611]`) | retain old image | `tetragon/observer` | seventh |
| 3283 | no kernel ts | `rejit_done status=error` | `tetragon/observer` | ReJIT returned error |
| 3284 | no kernel ts | `measurement_start phase=post_rejit` | `tetragon/observer` | runner immediately started workload despite ReJIT error |
| 3320 | `2026-05-07T23:36:29.281717Z` (`[1185.755273]`) | `Oops: int3` | kernel | crash in BPF execution path |
| 3386 | `2026-05-07T23:36:29.281822Z` (`[1185.755378]`) | `Kernel panic - not syncing: Fatal exception in interrupt` | kernel | VM panicked |

The cilium retain lines are not cleanup-on-app-detach. They occur between `cilium rejit_start` and `cilium rejit_done`. They look unrelated to the panic because cilium had zero `wide_mem` sites, the app completed, and its programs should not be active during the later Tetragon workload. They are still important evidence that the post-swap refresh failure path can trigger even for unchanged bytecode.

Q5 cilium per-program ReJIT failures:

| Prog id | Name | Status | wide_mem sites | Error |
| --- | --- | --- | --- | --- |
| 64 | `dump_bpf_prog` | `failed_rejit` | 0 | `EPERM`: verifier rejected BTF struct access |
| 184 | `tail_handle_ipv...` | `failed_rejit` | 0 | `EBUSY`: `BPF_PROG_REJIT errno 16` |
| 218 | `tail_drop_notif...` | `failed_rejit` | 0 | `EBUSY`: `BPF_PROG_REJIT errno 16` |

Only the two `EBUSY` failures line up with the two cilium retain lines. The `EPERM` verifier rejection happens before swap and does not print the retain warning.

## Panic stack and RIP interpretation

Panic excerpt:

```text
[ 1185.755273] Oops: int3: 0000 [#1] SMP NOPTI
[ 1185.755278] CPU: 1 UID: 0 PID: 3131 Comm: stress-ng-epoll Tainted: G           OE       7.0.0-rc2+ #1 PREEMPT(lazy)
[ 1185.755281] RIP: 0010:0xffffffffc00ad8d5
[ 1185.755289] Code: cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc <cc> cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
[ 1185.755297] Call Trace:
[ 1185.755299]  <TASK>
[ 1185.755302]  trace_call_bpf+0x19f/0x260
[ 1185.755307]  ? __sk_free+0x1/0xc0
[ 1185.755313]  kprobe_perf_func+0x4e/0x260
[ 1185.755319]  aggr_pre_handler+0x40/0x80
[ 1185.755322]  kprobe_ftrace_handler+0x139/0x1c0
[ 1185.755327]  0xffffffffc04050da
[ 1185.755334]  __sk_free+0x5/0xc0
...
[ 1185.755378] Kernel panic - not syncing: Fatal exception in interrupt
[ 1185.755645] Kernel Offset: 0x10000000 from 0xffffffff81000000 (relocation range: 0xffffffff80000000-0xffffffffbfffffff)
```

Interpretation:

- `RIP=0xffffffffc00ad8d5` is outside the kernel text relocation range and inside the module/BPF JIT executable area.
- The instruction stream is all `0xcc`, which is the x86 `int3` fill used for illegal padding/freed/unusable executable regions. This is not a normal verifier data-access fault.
- The call path is `trace_call_bpf -> kprobe_perf_func -> kprobe_ftrace_handler -> __sk_free`, so stress-ng closed a socket, hit a kprobe, entered Tetragon's BPF program array, and then jumped into invalid JIT text.
- "Fatal exception in interrupt" here means the trap happened while servicing the kprobe/ftrace path, not in the userspace `BPF_PROG_REJIT` syscall itself.

The module warning right before app execution is unrelated:

```text
bpf_bulk_memory: module verification failed: signature and/or required key missing - tainting kernel
```

It appears in every Q4-Q9 VM boot. Q6/Q7/Q8/Q9 complete successfully after the same warning.

## Kernel path for "retaining old JIT image after refresh failure"

The string is in `vendor/linux-framework/kernel/bpf/syscall.c:3937`.

Relevant path:

1. `bpf_prog_rejit()` builds `tmp`, replays verifier state and JITs replacement bytecode (`syscall.c:3610-3789`).
2. If the old program has direct tail-call poke descriptors, it snapshots them (`3791-3799`) and prepares rollback state (`3802-3804`).
3. It updates the existing program's `poke_tab` to point at `tmp`'s new JIT image before publishing `bpf_func` (`3810-3819`; helper at `3218-3290`).
4. It untracks `tmp`'s own poke entries from PROG_ARRAY tracking (`3822-3826`; helper at `3299-3308`).
5. It runs target-side phase 1 before the swap: for every PROG_ARRAY slot currently holding this `prog`, patch callers from `jmp old_addr` to NOP (`3828-3834`; helper at `3332-3384`).
6. It swaps the program metadata and publishes `prog->bpf_func = tmp->bpf_func` using `smp_store_release()` (`3387-3500`, publish at `3495-3500`).
7. It runs target-side phase 2 after the swap: patch callers from NOP to `jmp new_addr` (`3838-3850`).
8. It refreshes BPF trampoline users (`3853-3863`) and struct_ops trampolines (`3866-3884`) where applicable.
9. If phase 2 or trampoline refresh fails after the swap, it sets `retain_old_image=true`, synchronizes RCU, and prints the retain warning instead of freeing `tmp` (`3892-3939`).

So the retain warning means:

- The failure is post-swap, not a clean verifier rejection.
- The new image is already installed as `prog->bpf_func`.
- `tmp` now owns the old image after `bpf_prog_rejit_swap()`.
- The code intentionally does not call `__bpf_prog_put_noref(tmp, ...)`, so the old image is not deliberately freed on that path.
- The syscall still returns `ret` as an error to userspace.

Why this can still panic:

- The post-swap error leaves a mixed graph: some callsites may still point to old images, some to new images, some may be NOPs.
- `bpf_prog_rejit_update_poke_tab()` updates the live `prog->aux->poke_tab` to the new image and `bpf_prog_rejit_untrack_tmp_pokes()` removes `tmp`'s new-image tracking. `bpf_prog_rejit_swap()` does not swap `aux->poke_tab`; instead, live tracking remains with `prog`.
- If the old image is retained and still executable through an old kprobe/trampoline/tail-call edge, its own direct-tail-call sites are no longer the tracked poke sites for future target repokes. A later ReJIT of a tail-call target can free or invalidate an address that a retained old caller still jumps to.
- This is consistent with landing in `0xcc` only after the runner starts the post-ReJIT Tetragon workload.

This is an inference from the local code and the timing. The Q5 log does not identify which of the seven Tetragon ReJIT failures produced which exact `prog_id` because panic prevented Tetragon's app JSON from being flushed.

## wide_mem pass behavior

Implementation: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs`.

What it matches:

- It scans for byte-ladder loads: `LDX_MEM B` followed by repeated `LSH K` and `OR X`.
- It supports low-byte-first and high-byte-first clang orderings (`scan_wide_mem`, `try_match_wide_mem_at`, lines `48-285`).
- It only emits replacement widths 2, 4, and 8 (`BPF_H`, `BPF_W`, `BPF_DW`) and rejects other widths (`307-314`, `560-567`).

What it emits:

```text
old: rD = *(u8 *)(base + off)
     rT = *(u8 *)(base + off + i)
     rT <<= 8*i
     rD |= rT
     ...

new: rD = *(u16/u32/u64 *)(base + off)
```

It is a pure BPF bytecode rewrite. It does not emit a `KFUNC_INLINE_EMIT` call and does not depend on a wide-memory kop module. The relevant emission is a single `BpfInsn::ldx_mem(size, dst, base, off)` at line `314`.

Safety filters in the pass:

- no interior branch target inside the replaced instruction window
- scratch registers must be dead after the site
- natural alignment for the wide load
- skip likely packet pointers in XDP/TC programs
- skip BTF struct pointers when verifier states show the base register has field-boundary semantics
- branch offsets and BTF metadata are remapped after rewrite (`700-705`)

For x86 JIT, `BPF_LDX | BPF_MEM | BPF_DW` lowers to normal scalar `mov r64, [base+off]` in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1114-1141`. No kfunc or module callback is involved.

## Tetragon programs processed by wide_mem

Q5 facts:

- Tetragon `rejit_start` reports `program_count=287`.
- Q5 panicked before `details/apps/tetragon__observer.json` was written.

Proxy facts from same-day successful Tetragon run `x86_kvm_corpus_20260507_200821_664435`:

- `baseline.bpf` count: 287
- `post_rejit.bpf` count: 287
- Program id set: `235,237-242,245-524`
- Program shape matches the Tetragon observer workload documented elsewhere in the repo: directly attached `generic_*_event` programs plus tail-called `process_event`, `filter_arg`, `actions`, `output`, `setup_event`, and `process_filter` helpers.

Program shape count from proxy:

| Count | Program name | Type |
| ---: | --- | --- |
| 1 | `event_exit_acct_process` | kprobe |
| 1 | `event_wake_up_new_task` | kprobe |
| 1 | `execve_rate` | tracepoint |
| 1 | `execve_send` | tracepoint |
| 1 | `event_execve` | tracepoint |
| 1 | `tg_kp_bprm_committing_creds` | kprobe |
| 1 | `execve_map_update` | socket_filter |
| 33 each | `generic_kprobe_event`, `generic_kprobe_process_event`, `generic_kprobe_filter_arg`, `generic_kprobe_actions`, `generic_kprobe_output`, `generic_kprobe_setup_event`, `generic_kprobe_process_filter` | kprobe |
| 9 each | `generic_retkprobe_event`, `generic_retkprobe_filter_arg`, `generic_retkprobe_actions`, `generic_retkprobe_output` | kprobe |
| 1 each | `generic_tracepoint_event`, `generic_tracepoint_arg`, `generic_tracepoint_actions`, `generic_tracepoint_output`, `generic_tracepoint_filter`, `generic_tracepoint_process_event` | tracepoint |
| 1 each | `generic_rawtp_event`, `generic_rawtp_filter_arg`, `generic_rawtp_actions`, `generic_rawtp_output`, `generic_rawtp_process_event`, `generic_rawtp_process_filter`, `generic_rawtp_setup_event` | raw_tracepoint |

wide_mem shape from proxy, considering only programs that reached the `wide_mem` pass in that multi-pass run:

| Count | sites_applied | wide_mem insns before -> after | Program family | Status |
| ---: | ---: | --- | --- | --- |
| 42 | 0 | unchanged | non-byte-ladder or skipped programs | ok |
| 33 | 1 | `399 -> 396` | `generic_kprobe_event` shape | ok |
| 33 | 3 | `255 -> 246` | `generic_kprobe_setup_event` shape | ok |
| 30 | 5 | `3592 -> 3577` | `generic_kprobe_process_event` shape | ok |
| 33 | 6 | `2192 -> 2174` | `generic_kprobe_process_filter` shape | ok |
| 31 | 8 | `1021 -> 997` | `generic_kprobe_actions` shape | ok |
| 30 | 47 | `2167 -> 2026` | `generic_kprobe_filter_arg` shape | ok |
| 1 | 47 | `2167 -> 2026` | `generic_kprobe_filter_arg` shape | failed_rejit, `EBUSY` |
| 9 | 47 | `2142 -> 2001` | `generic_retkprobe_filter_arg` shape | ok |
| 9 | 4 | `3059 -> 3047` | `generic_retkprobe_event` shape | ok |
| 9 | 5 | `773 -> 758` | `generic_retkprobe_actions` shape | ok |
| 1 each | 1, 4, 5, 6, 7, 8, 47 | rawtp/tracepoint shapes | ok |

The proxy's only `wide_mem` failed ReJIT was:

| Prog id | Program | sites_applied | before -> after | Error |
| --- | --- | ---: | --- | --- |
| 292 | `generic_kprobe_filter_arg` | 47 | `2167 -> 2026` | `BPF_PROG_REJIT errno 16: Device or resource busy` |

This proxy is not Q5 itself, but it is useful evidence: wide_mem heavily shrinks the Tetragon tail-call helper shapes, especially the `filter_arg` family, and the same program family can hit post-swap `EBUSY`.

## Why Q4/Q6-Q9 did not panic

Observations:

- Q4 `prefetch-only-7app` also printed retain lines: cilium 2, Tetragon 6, tracee 1. Q4 finished with `rc=0`.
- Q5 `wide_mem-only-7app` printed cilium 2, Tetragon 7, then panicked immediately after starting Tetragon post-ReJIT measurement.
- Q6/Q7/Q8/Q9 were OTEL-only runs and completed with `rc=0`.
- The module-signing warning appears in all these boots, so it is not discriminating.

Likely explanation:

- The retain path is a generic ReJIT post-swap refresh-failure hazard, but it needs an executable stale edge to be hit after the failure.
- Tetragon has the right shape: many kprobe entry programs and many PROG_ARRAY tail-called helper chains. Repo documentation notes `generic_kprobe_event -> process_event/filter_arg/actions/output` tail-call chains, and that only the directly attached event programs account runtime while helper programs are tail targets.
- `wide_mem` is a strong trigger because it rewrites many Tetragon helper programs and changes instruction and JIT layout substantially. The `filter_arg` shape shrinks by 141 BPF instructions in the proxy (`2167 -> 2026`) with 47 applied sites.
- `prefetch` can also trigger post-swap refresh errors, but it did not hit a stale invalid edge during Q4's post workload. That makes the bug probabilistic or graph-position-dependent, not proof that prefetch is fully safe.
- OTEL-only Q6-Q9 do not exercise Tetragon's kprobe/tail-call graph, so they do not cover this crash condition.

## Root-cause hypotheses

### 1. Most likely: generic ReJIT tail-call refresh bug exposed by wide_mem

Evidence:

- All fatal symptoms point to control-flow into invalid JIT text, not verifier-accepted bad memory access: `RIP` is in JIT/module area and bytes are `0xcc`.
- The retain warning only prints after swap. The kernel has already published a new `bpf_func`, then failed target-side phase 2 or trampoline refresh.
- Tetragon is tail-call heavy. The crash happens under `trace_call_bpf` from a kprobe workload.
- `wide_mem` changes instruction counts and JIT addresses for many tail-called Tetragon helper programs.
- The code updates live `prog->aux->poke_tab` to the new image and untracks `tmp`'s poke entries. If an old image remains executable because refresh failed, old-image direct tail-call sites can become stale relative to later target ReJITs.

Potential concrete failure sequence:

1. ReJIT of a Tetragon program with direct tail-call sites succeeds through swap.
2. Post-swap refresh fails and the kernel retains the old image, but live poke tracking now points to the new image.
3. A retained old caller image remains reachable through an old edge.
4. Subsequent ReJIT of one of its tail-call targets moves/frees the target image.
5. Post-ReJIT workload executes the retained old caller, which direct-jumps into an address that is now `0xcc` fill.

This matches the timing: seven retain lines during Tetragon ReJIT, then panic 237 ms after the final retain line when post-ReJIT workload starts.

### 2. Likely contributing factor: wide_mem-specific shrink changes tail-call/JIT layout

Evidence:

- Q5 is the only 7-app run in this queue that panicked.
- In proxy Tetragon data, wide_mem applies heavily to `generic_kprobe_filter_arg`, `generic_retkprobe_filter_arg`, and related helper shapes.
- The pass collapses multi-instruction byte ladders to one wide load and remaps branches/BTF metadata. It does not change explicit tail-call maps/keys, but it changes program length and native layout.
- The old kernel comment says moved instruction indices are now allowed for `poke_tab` as long as map/key order matches. That is intended, but this crash suggests post-swap failure handling has not fully covered the mixed old/new-image case.

### 3. Possible but less supported: post-swap `EBUSY` from text_poke mismatch leaves a partially refreshed caller graph

Evidence:

- Cilium Q5 had two `EBUSY` failures with zero applied sites and two retain lines. Q4 also had multiple `EBUSY` failures.
- `EBUSY` is the common user-visible errno for the retain-producing failures in app JSONs from neighboring runs.
- The code's target-side phase 2 treats an error as keep-new-image/retain-old-image and does not roll back. Some PROG_ARRAY slots may stay NOP or stale until a future repoke.

This explains the general class, but not why Q5 specifically panicked. The wide_mem/Tetragon graph likely supplies the missing trigger.

### 4. Unlikely: bad wide_mem data semantics directly caused the panic

Evidence against:

- A bad wide load would normally produce verifier rejection, data corruption, or a data access fault, not execution at all-`0xcc`.
- The pass has BTF pointer, packet pointer, alignment, branch-target, and liveness filters.
- The crash address is code, not data.

### 5. Rejected: `bpf_bulk_memory` module-signing warning

Evidence against:

- The same warning appears in Q4/Q6/Q7/Q8/Q9.
- Q5 pass list is only `wide_mem`.
- The warning happens at boot/module load, about 18 minutes before the panic.

## Userspace mitigation candidates

These do not require changing `vendor/linux-framework`, but they have policy tradeoffs.

1. Fail fast after any ReJIT syscall returns a post-swap refresh-style error for a live app, and do not start post-ReJIT measurement.
   - This does not prevent the kernel from entering the retain path, because userspace only learns after the syscall returns.
   - It does avoid executing the potentially mixed graph, which is when Q5 panicked.
   - It is consistent with fail-fast behavior, but it changes corpus behavior: a ReJIT error would end the app instead of measuring post-ReJIT raw counters.

2. Quarantine `wide_mem` Tetragon runs in the queue until the kernel retain path is understood.
   - This is operationally safe for queue scheduling.
   - It must not be encoded as in-framework per-program or per-app ReJIT filtering. Current project rules forbid pass exclusions and ReJIT filtering in framework code.

3. Avoid no-change ReJIT calls for `sites_applied=0`.
   - This would prevent cilium-style no-op `wide_mem` refresh failures.
   - It conflicts with the current "No ReJIT Filtering" rule, because the framework intentionally lets all ReJIT failures surface. Do not implement this without explicitly changing the project rule.

4. Kernel-side robust fix, not attempted here.
   - Roll back fully on post-swap refresh failure, or keep old images with valid old poke tracking, or make post-swap target refresh atomic with respect to all reachable old callers.
   - This is the real fix class, but it is outside this task because kernel modification is explicitly forbidden.

## Reproduction recipe

Use Makefile entrypoints only.

Minimal first repro:

```bash
BPFREJIT_CORPUS_APPS="tetragon/observer" \
BPFREJIT_BENCH_PASSES=wide_mem \
SAMPLES=1 \
WORKLOAD_DURATION=30 \
KEEP_WORKDIRS=1 \
make vm-corpus
```

If single-app Tetragon does not reproduce, use the same prefix that Q5 reached before panic:

```bash
BPFREJIT_CORPUS_APPS="bcc/set,otelcol-ebpf-profiler/profiling,cilium/agent,tetragon/observer" \
BPFREJIT_BENCH_PASSES=wide_mem \
SAMPLES=1 \
WORKLOAD_DURATION=30 \
KEEP_WORKDIRS=1 \
make vm-corpus
```

Expected failure signature:

- `tetragon/observer` reaches `rejit_start` with `program_count=287`
- multiple `bpf_rejit: retaining old JIT image after refresh failure`
- `rejit_done status=error`
- panic shortly after `measurement_start phase=post_rejit`
- `Oops: int3` with RIP in `0xffffffffc...` JIT/module range and `Code: cc cc ...`

## Open questions for follow-up

- Which exact Q5 Tetragon `prog_id`s produced the seven retain lines? Q5 lacks `tetragon__observer.json`; a repro should capture daemon per-program progress before post workload starts.
- Did each retain line return `EBUSY`, or did any come from `bpf_trampoline_refresh_prog()`? Neighboring app JSONs suggest `EBUSY`, but Q5 Tetragon's exact per-program errors were lost.
- Is the invalid `RIP` an old caller's direct tail-call target, a retained old directly attached program, or a stale subprog call target? Capturing kallsyms/JIT address ranges during repro would answer this.
- Does stopping immediately after `rejit_done status=error` avoid the panic reliably? That would strongly confirm the mixed-graph execution hypothesis.
