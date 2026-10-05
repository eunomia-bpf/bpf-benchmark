# ARM64 BPF_PROG_REJIT Failure Root Cause - 2026-05-06

Scope: read-only investigation of ARM64 noop-only 7-app smoke failures, focused on
`BPF_PROG_REJIT`, ARM64 multi-subprogram JIT final-pass image accounting, and the
special bpftrace/set failure.

Primary files inspected:

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `docs/tmp/arm64_*.md`
- `docs/tmp/arm64_x86_jit_diff_diagnosis_20260506.md`
- `docs/tmp/20260319/arm64_micro_eval_20260319.md`
- `docs/tmp/20260320/aws_arm64_benchmark_run_20260320.md`
- current result artifacts under `corpus/results/aws_arm64_corpus_20260506_*`
- logs under `.cache/aws-arm64/results/logs/`

## A. 真 bug 还是 design?

Conclusion: it is an upstream ARM64 JIT design invariant that becomes a real
BpfReJIT capability bug for live multi-subprogram REJIT. It is not an ARM64
verifier rejection, and the bailout itself was not added by the BpfReJIT fork.

### ARM64 multi-function JIT invariant

Current ARM64 JIT stores a first-pass image/accounting state in
`struct arm64_jit_data`:

- `header`
- `ro_image`
- `ro_header`
- `ctx`

Relevant code:

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2056-2061`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2121-2130`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2147-2177`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2196-2227`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2242-2253`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2267-2272`

The flow is:

1. First pass estimates the maximum ARM64 image size and computes offsets.
2. The JIT allocates a fixed packed RW/RX image with
   `bpf_jit_binary_pack_alloc(image_size, ...)`.
3. For multi-function finalization, a later `extra_pass` reuses the previously
   allocated `jit_data` image and offset accounting.
4. ARM64 expects the final pass to be no larger than the saved first-pass
   `jit_data->ctx.idx`.
5. The comment says the image may shrink because BPF-to-BPF calls can change
   from indirect to direct calls. Growth is treated as impossible/buggy.

The bailout is:

```c
if (extra_pass && ctx.idx > jit_data->ctx.idx) {
        pr_err_once("multi-func JIT bug %d > %d\n",
                    ctx.idx, jit_data->ctx.idx);
        prog->bpf_func = NULL;
        prog->jited = 0;
        prog->jited_len = 0;
        goto out_free_hdr;
}
```

This bailout is necessary with the current allocator contract. In
`kernel/bpf/core.c`, `bpf_jit_binary_pack_alloc()` allocates a fixed-size pack:

- `vendor/linux-framework/kernel/bpf/core.c:1131-1174`
- size is `round_up(proglen + sizeof(*ro_header) + 16, BPF_PROG_CHUNK_SIZE)`
- `image_ptr` and `rw_image` are placed at a randomized offset inside that fixed
  pack

`bpf_jit_binary_pack_finalize()` then copies `rw_header->size` bytes to the RO
pack and frees the RW buffer:

- `vendor/linux-framework/kernel/bpf/core.c:1176-1191`

There is no grow/realloc operation after `image_ptr` has been chosen. Also,
ARM64 places PLT target and exception-table space after the estimated program
text:

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2170-2177`

If the final pass grows past the saved `ctx.idx`, it can overwrite the PLT or
exception-table region, invalidate line-info and instruction-pointer offsets,
or exceed the allocated pack. So the current code must either bail out or rerun
layout/allocation; silently continuing would be unsafe.

### Kernel-original or BpfReJIT-added?

The image-budget bailout is kernel-original ARM64 JIT behavior, not a BpfReJIT
fork addition.

Evidence from the fork history:

- base: `c23719abc (grafted, origin/master, origin/HEAD, master)`
- current branch: `81cb8848b (HEAD -> rejit-v2)`
- `git diff c23719abc..HEAD -- arch/arm64/net/bpf_jit_comp.c` shows only
  BpfReJIT/KOperation-related additions around native ARM64 emit for
  `BPF_PSEUDO_KOP_CALL`.
- The diff does not add the `extra_pass && ctx.idx > jit_data->ctx.idx`
  bailout.
- diff stat for the three relevant files:
  - `arch/arm64/net/bpf_jit_comp.c | 54 +++`
  - `kernel/bpf/core.c | 2 +`
  - `kernel/bpf/syscall.c | 965 +...`

ARM64-specific BpfReJIT commits in the path are about KOperation emit and cleanup,
not this bailout:

- `1d040ec0c bpf: REJIT Phase 0-2 fixes + ARM64 inline kfunc + selftest`
- `20831c82d kop: implement bpf_kop_ops with verifier modeling and packed ABI`
- `cb06f7908 bpf: Refactor kop handling and improve verifier region management`
- `81608ed9e bpf: fix 4 review issues (insn_buf overflow, callchain_buf swap, debug code, ARM64 scratch)`

BpfReJIT did not create the bailout. It made the bailout reachable for live
multi-subprogram REJIT by relaxing earlier support gates.

### Verifier or JIT compile stage?

This is ARM64 JIT compile/runtime-selection failure, not verifier rejection.

The REJIT syscall path verifies the temporary program first:

- `vendor/linux-framework/kernel/bpf/syscall.c:3771-3774` calls `bpf_check()`
- `vendor/linux-framework/kernel/bpf/syscall.c:3776-3778` calls
  `bpf_prog_select_runtime()`
- `vendor/linux-framework/kernel/bpf/syscall.c:3784-3786` returns
  `-EOPNOTSUPP` if the post-JIT temporary program is unsupported or not jited

The support gate is:

```c
err = -EOPNOTSUPP;
if (!bpf_prog_rejit_supported(tmp) || !tmp->jited)
        goto free_tmp_noref;
```

For the direct Katran failure in this run:

- result: `corpus/results/aws_arm64_corpus_20260506_221220_160792/details/result.json`
- app result status: `ok`
- ReJIT status: `error`
- failing program: `prog 86`, `balancer_ingress`, type `xdp`
- baseline BPF metadata: `bytes_xlated=23824`, `bytes_jited=14320`
- error prefix:
  - `BPF_PROG_REJIT errno 95: Operation not supported`
  - verifier log begins with `func#0 @0`, `func#1 @2320`, `func#2 @2468`
  - verifier log ends with `processed 67941 insns ...`

That verifier log means the verifier accepted the temporary program. The errno
95 appears after `bpf_prog_select_runtime()`, because ARM64 JIT cleared
`tmp->jited` on the final-pass budget bailout and the syscall support gate then
converted that into `EOPNOTSUPP`.

## B. 之前为什么能跑通?

Conclusion: the earlier successful ARM64 evidence is not equivalent to the
current ARM64 live-corpus `BPF_PROG_REJIT` path. Earlier runs were either x86
authoritative micro results, ARM64 smoke/extra micro runs using the older
`BPF_PROG_JIT_RECOMPILE` path, or small/single-function-style programs. Current
daemon runs attempt live real-app multi-subprogram programs that earlier gates
would have rejected.

### Git history changed what REJIT attempts

Relevant commits:

- `4d46ee609 bpf: add minimal prog rejit syscall`
  - initial `bpf_prog_rejit_supported()` was very conservative
  - rejected many aux features, including `aux->func_cnt` and
    `aux->real_func_cnt`
- `4bcbc8e21 bpf: kernel POC fixes (#305) ...`
  - still kept broad unsupported cases
- `21c1b1f89 bpf: multi-subprog REJIT support + remove selftest from kernel tree`
  - explicitly removed the `func_cnt` / `real_func_cnt` gate
  - added a subprogram layout-match check
  - commit message says it unblocks multi-subprogram programs like Katran
- `0b2d749c2 bpf: code review cleanup + st_ops REJIT + relax constraints`
  - removed the layout-match size check so REJIT can change subprogram length
  - this made ARM64 more likely to reach the final-pass image-budget invariant
- later commits mostly handled swap safety, trampolines, poke tables, KOperation
  cleanup, and related review fixes

Current `bpf_prog_rejit_supported()` no longer rejects multi-subprogram programs:

- `vendor/linux-framework/kernel/bpf/syscall.c:3167-3200`
- it rejects `!prog->jited`, `prog->is_func`, offload/dev-bound programs, and
  attached EXT without `dst_prog`
- it does not reject `aux->func_cnt` or `aux->real_func_cnt`

So the answer is not "ARM64 regressed from working multi-subprogram REJIT to
broken multi-subprogram REJIT". The current branch now attempts a class of
programs that the first REJIT syscall implementation intentionally refused.

### 2026-03 paper/micro evidence is not the same workload

Local evidence does not show an ARM64 authoritative paper run on
2026-03-14. The file named `micro/results/vm_micro_authoritative_20260314.json`
has:

- platform: `Linux-7.0.0-rc2-g7de19ef03692-x86_64-with-glibc2.39`
- suite: `micro_staged_codegen`
- 62 benchmark entries

ARM64 evidence in local docs is later smoke/extra work:

- `docs/tmp/20260319/arm64_micro_eval_20260319.md`
  - goal was to get ARM64 `micro_exec` smoke working
  - used `BPF_PROG_JIT_RECOMPILE`
  - exercised `simple`, `cmov_dense`, and `rotate_dense`
- `docs/tmp/20260320/aws_arm64_benchmark_run_20260320.md`
  - AWS ARM64 smoke/extra run
  - successful cases included `simple`, `cmov_dense`, `bounds_ladder`, and
    `bpf_call_chain`
  - still described as `kernel_recompile` / `BPF_PROG_JIT_RECOMPILE`, not the
    current daemon `BPF_PROG_REJIT` live-corpus path

The micro representativeness docs also show the structural gap:

- `docs/paper-comparison.md:467`: BPF-to-BPF calls in the suite were `0`
- `docs/paper-comparison.md:474-475`: real corpus multi-function programs
  `97.2%`, suite multi-function programs `0%`
- `docs/micro-bench-status.md:483`: the suite had a multi-function structural
  gap, with only `bpf_call_chain` added later as a single local-call benchmark
- `docs/micro-bench-status.md:547`: `bpf_call_chain` is small
  (`3 __noinline subprograms x 64 rounds`)

That small `bpf_call_chain` smoke passing on ARM64 does not prove that ARM64 can
REJIT a large real app program like Katran `balancer_ingress` with thousands of
BPF instructions and multiple subprograms.

### Did corpus apps previously run ARM64?

I did not find local evidence that the March paper-authoritative path ran the
same 7-app live corpus on ARM64 with the current daemon socket +
`BPF_PROG_REJIT` syscall path.

The most likely explanation is:

1. v1/micro did not cover the current ARM64 real-app corpus path.
2. early REJIT support gates rejected multi-subprogram programs, so the ARM64
   final-pass bailout was not reached for them.
3. current v3 daemon/corpus runs now discover and attempt real live app programs,
   many of which are multi-function.
4. commits `21c1b1f89` and `0b2d749c2` widened REJIT to multi-subprogram and
   length-changing cases; ARM64's upstream final-pass invariant is now exposed.

## C. 如果允许改 kernel

There are three possible kernel directions. Only dynamic grow/re-layout is a
root fix for ARM64 real-app multi-subprogram REJIT.

### Option A: dynamic image budget grow / re-layout

This is the principled fix.

Idea: if the final `extra_pass` produces `ctx.idx > jit_data->ctx.idx`, do not
publish failure immediately. Instead, throw away the stale pack, rerun layout
with a larger budget, allocate a fresh pack, rebuild offsets/PLT/extable, then
finalize. The key is to preserve the existing safety property: never write past
the currently allocated image and never publish partial metadata.

Pseudo-code sketch:

```c
struct arm64_jit_data {
        struct bpf_binary_header *header;
        struct bpf_binary_header *ro_header;
        u8 *ro_image;
        struct jit_ctx ctx;
        u32 budget_idx;
};

again:
        if (jit_data->ctx.offset) {
                ctx = jit_data->ctx;
                budget_idx = jit_data->budget_idx ?: jit_data->ctx.idx;
                reuse_saved_image();
                extra_pass = true;
                goto skip_init_ctx;
        }

        run_sizing_pass();
        budget_idx = max(ctx.idx, requested_min_idx);
        image_size = compute_image_size_from_budget(budget_idx);
        allocate_pack(image_size);
        run_position_and_final_pass();

        if (extra_pass && ctx.idx > budget_idx) {
                u32 new_min = ctx.idx + arm64_jit_growth_slack(ctx.idx);

                /* The old RO header size must be valid before free. */
                bpf_arch_text_copy(&ro_header->size, &header->size,
                                   sizeof(header->size));
                bpf_jit_binary_pack_free(ro_header, header);

                clear_jit_data_but_keep_requested_min(new_min);
                if (++attempts > 2)
                        goto out_fail;
                goto again;
        }

        finalize_pack();
        publish_bpf_func_and_metadata();
```

Implementation notes:

- The grow path must re-run layout, not only allocate more bytes.
- It must recompute `ctx.offset`, PLT target position, `extable_offset`,
  line-info, and instruction pointers.
- It must avoid leaking or double-freeing the old packed image.
- It must cap retry attempts to avoid an infinite loop if sizing is unstable.
- It must handle `prog->aux->jit_data`, `prog->aux->extable`,
  `priv_stack_ptr`, and subprogram publication/kallsyms carefully.

Estimated cost:

- LoC: roughly 80-150 for a minimal robust ARM64-only grow loop; 150-250 if
  cleaned up into clearer helpers and tested.
- Risk: medium-high. This touches ARM64 JIT memory ownership, metadata offsets,
  and multi-subprogram finalization.
- Paper necessity: high if the paper needs ARM64 real-app corpus results.

### Option B: increase/reserve image budget

This is a mitigation, not a complete fix, unless implemented as an explicit
budget model.

Just increasing the bytes passed to `bpf_jit_binary_pack_alloc()` is not enough:
the bailout compares `ctx.idx` against `jit_data->ctx.idx`, not against the
rounded pack size. Also, line-info, PLT, and exception-table placement are based
on the estimated text length. A safe version needs a separate `budget_idx` and
must compute `image_size` / `extable_offset` from that budget.

Possible sketch:

```c
u32 estimated_idx = ctx.idx;
u32 budget_idx = estimated_idx + arm64_jit_static_slack(prog);

jit_data->ctx = ctx;
jit_data->budget_idx = budget_idx;

prog_size = sizeof(u32) * budget_idx;
extable_offset = round_up(prog_size + PLT_TARGET_SIZE, extable_align);
image_size = extable_offset + extable_size;

...

if (extra_pass && ctx.idx > jit_data->budget_idx)
        fail_or_retry_with_dynamic_grow();
```

Estimated cost:

- LoC: 30-80 if added narrowly.
- Risk: medium. It can hide the current failure for observed programs but still
  fail on larger or different codegen growth.
- Paper necessity: medium. It might unblock enough smoke runs quickly, but it
  is a weaker story for a kernel patch because the slack formula is hard to
  justify.

### Option C: abandon final-pass image accounting

Deleting the check is not safe. The check exists because final image growth can
overwrite the allocated JIT pack or make metadata inconsistent.

If "abandon final-pass" means "do not reuse the first-pass image, always do a
full re-layout before finalization", then this becomes Option A under a
different name.

If "abandon final-pass" means "disable multi-function ARM64 REJIT and allow only
single-function programs", that is safe but not a root fix:

```c
static bool bpf_prog_rejit_supported(const struct bpf_prog *prog)
{
        ...
        if (IS_ENABLED(CONFIG_ARM64) &&
            (prog->aux->func_cnt || prog->aux->real_func_cnt))
                return false;
        ...
}
```

Better would be an arch hook instead of a raw `CONFIG_ARM64` check:

```c
if (!bpf_arch_prog_rejit_supported(prog))
        return false;
```

Estimated cost:

- LoC: 5-30 for a blunt gate, 30-70 with an arch hook.
- Risk: low for stability, high for paper scope.
- Paper necessity: acceptable only if ARM64 real-app corpus is reported as N/A.

### Recommended kernel patch priority

1. For a real ARM64 corpus claim: implement Option A.
2. For a short-term stable branch: add a temporary ARM64 multi-subprogram
   support gate and clearly report ARM64 real-app corpus as unsupported.
3. Avoid a pure slack-only patch unless it is paired with a grow retry. Slack
   without grow is hard to defend and will be sensitive to workload mix.
4. Do not delete the `ctx.idx > jit_data->ctx.idx` check.

## D. bpftrace/set ARM64 失败根因

Conclusion: current bpftrace/set ARM64 smoke failure is not the ARM64
multi-subprogram image-budget bailout. It fails before REJIT. A previous ARM64
bpftrace/set artifact reached BPF snapshot/ReJIT setup and failed with
`BPF_OBJ_GET_INFO_BY_FD: Argument list too long`, also not a multi-subprogram
JIT failure.

### Current ARM64 bpftrace/set smoke

Artifact:

- `corpus/results/aws_arm64_corpus_20260506_233838_355468/details/result.json`

Observed:

- app: `bpftrace/set`
- status: `error`
- baseline BPF program count: `0`
- `rejit_result`: empty
- error prefix:

```text
stress_ng_os_io_network workload failed: stress-ng: ... failed: 1: fcntl (1)
... unsuccessful run completed in 8.65 secs
```

So this run failed during baseline workload measurement. It did not snapshot
live BPF programs and did not call `BPF_PROG_REJIT`.

### Older ARM64 bpftrace/set artifact with attached programs

Artifact:

- `corpus/results/aws_arm64_corpus_20260506_182715_378083/details/result.json`

This artifact has bpftrace attached programs:

| id | name | type | bytes_xlated | bytes_jited |
| --- | --- | --- | ---: | ---: |
| 119 | block_io_start | tracepoint | 408 | 320 |
| 120 | block_io_done | tracepoint | 1576 | 1048 |
| 126 | sched_wakeup | tracepoint | 136 | 152 |
| 127 | tracepoint_sched_sched_wakeup_new | tracepoint | 136 | 152 |
| 128 | sched_switch | tracepoint | 896 | 648 |
| 134 | 1 | perf_event | 680 | 488 |
| 135 | vfs_create | kprobe | 224 | 216 |
| 143 | tcp_set_state | kprobe | 3384 | 2072 |
| 148 | cap_capable | kprobe | 1360 | 856 |

Program type distribution:

- tracepoint: 5
- kprobe: 3
- perf_event: 1

The error was metadata/snapshot, not JIT:

```text
prog 119: snapshot live BPF program 119: read map ids for BPF program id 119:
BPF_OBJ_GET_INFO_BY_FD: Argument list too long (os error 7);
...
prog 148: snapshot live BPF program 148: read map ids for BPF program id 148:
BPF_OBJ_GET_INFO_BY_FD: Argument list too long (os error 7)
```

No `func#1` / `func#2` evidence appears here, and the program sizes/types look
like normal single-entry bpftrace probe programs, not large multi-subprogram
real-app programs.

### x86 KVM "passed" caveat

Artifact:

- `corpus/results/x86_kvm_corpus_20260506_223639_781587/details/result.json`

This x86 bpftrace/set app status is `ok`, but ReJIT itself still reports an
error:

```text
prog 24: kernel rejected BPF_PROG_REJIT:
BPF_PROG_REJIT errno 13: Permission denied
verifier log:
func#0 @0
```

So x86 "passed" here means the app/workload completed. It does not mean all
bpftrace programs were successfully ReJITed. The x86 error is verifier
`EACCES` on a single-function program, a different problem from ARM64
multi-function final-pass image accounting.

## Other app failure evidence from current ARM64 smoke

The current run artifacts do not all prove the same root cause.

### Katran

Artifact:

- `corpus/results/aws_arm64_corpus_20260506_221220_160792/details/result.json`

Evidence:

- app status: `ok`
- baseline BPF programs: 3
- ReJIT status: `error`
- direct failing program: `prog 86`, `balancer_ingress`, type `xdp`
- error:

```text
BPF_PROG_REJIT errno 95: Operation not supported
verifier log:
func#0 @0
func#1 @2320
func#2 @2468
...
processed 67941 insns ...
```

This is the cleanest direct artifact for ARM64 multi-subprogram post-verifier
JIT failure.

### Cilium

Artifact:

- `corpus/results/aws_arm64_corpus_20260506_222705_228991/details/result.json`

Evidence:

- app status: `error`
- baseline BPF program count: 0
- `rejit_result`: empty
- error:

```text
interface-bound HTTP server in namespace bpfbench-cepa did not report ready
at http://10.244.0.177:18080/
```

This current artifact does not reach REJIT. It is not direct evidence of the
ARM64 multi-function JIT bailout, even if Cilium likely has multi-function BPF
programs in successful-startup runs.

### Tracee

Artifact/log:

- `corpus/results/aws_arm64_corpus_20260506_224119_258222/`
- `.cache/aws-arm64/results/logs/corpus_run.aws-arm64.corpus.de9931e2_20260506_224116.remote.log`

Evidence:

- baseline measurement succeeded
- `rejit_start` logged `program_count: 158`
- `rejit_done` status was `error`
- post-ReJIT workload timed out
- no final detailed `result.json` is present locally, so there is no exact
  per-program errno string in this artifact

This strongly suggests a ReJIT-stage failure, but the local artifact is not as
diagnostic as Katran.

### Tetragon

Artifact:

- `corpus/results/aws_arm64_corpus_20260506_230917_077168/details/result.json`

Evidence:

- app status: `error`
- baseline BPF programs: 287
- `rejit_result`: empty
- error:

```text
daemon socket returned an empty response
daemon serve rc=-9
daemon log tail:
serve: listening on /var/tmp/bpfrejit-daemon.sock
```

This is daemon death or external kill during/around the ReJIT flow, not a
captured per-program `BPF_PROG_REJIT errno 95`. Prior
`docs/tmp/arm64_corpus_hang_analysis_20260506.md` points at large verifier logs
and daemon rc=-9 style failures for Tetragon. It may share the broader ARM64
ReJIT stress path, but the current artifact alone does not prove the final-pass
budget bailout.

## E. 推荐 (paper-perf priority)

### If not changing kernel

Recommended paper position:

- report x86 real-app corpus as the main corpus result
- report ARM64 only for single-function/small micro coverage
- mark ARM64 real-app multi-subprogram corpus as N/A / unsupported by current
  ARM64 BpfReJIT kernel path
- explicitly cite the ARM64 JIT final-pass image-accounting invariant:
  `arch/arm64/net/bpf_jit_comp.c:2247-2253`

Do not silently replace multi-function apps with "equivalent" single-function
workloads and call it the same ARM64 corpus. If such a subset is useful, label
it as an ARM64 single-function stress subset.

Also separate bpftrace from the multi-subprogram story:

- current bpftrace/set failure is baseline workload `stress-ng fcntl`, before
  REJIT
- earlier ARM64 bpftrace/set failure is `BPF_OBJ_GET_INFO_BY_FD E2BIG`
- x86 bpftrace app status can be `ok` while ReJIT itself still has verifier
  `EACCES`

### If changing kernel

Priority:

1. P0: implement ARM64 dynamic grow/re-layout on final-pass growth.
   - required for honest ARM64 real-app corpus
   - medium-high kernel risk
   - estimate 80-150+ LoC
2. P1: add a temporary ARM64 multi-subprogram support gate only if stable
   paper runs are needed before P0 is ready.
   - low kernel risk
   - ARM64 real-app corpus remains unsupported
3. P2: separately fix bpftrace metadata snapshot `E2BIG` and workload
   stability.
   - not part of the multi-subprogram image-budget root cause
4. P3: improve daemon handling for huge verifier logs / rc=-9 so Tetragon-like
   failures produce per-program errors instead of empty socket responses.

Patch posture:

- dynamic grow/re-layout is the only clean kernel fix
- reserve/slack can be a mitigation only if backed by an explicit `budget_idx`
  and a grow retry
- deleting the bailout is unsafe
- single-function-only ARM64 REJIT is safe but a scope limitation, not a fix

