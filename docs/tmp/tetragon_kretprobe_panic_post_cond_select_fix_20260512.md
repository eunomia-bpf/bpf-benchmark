# Tetragon kretprobe panic after cond_select preserve-join fix

Date: 2026-05-12

Scope: read-only investigation. I did not run benchmarks. I only inspected saved artifacts and ran host-side `bpfopt --pass cond_select` bytecode scans into `/tmp`.

## Artifact state

The result directory is incomplete because the VM panicked before corpus finalization:

- `corpus/results/x86_kvm_corpus_20260512_215625_527684/details/progress.json` still says `"status": "running"`.
- `details/daemon.stdout.log` only contains `serve: listening on /var/tmp/bpfrejit-daemon.sock`.
- `details/daemon.stderr.log` is empty.
- There is no app JSON and no saved daemon `per_program` response, so the exact live `prog_id -> JIT address` mapping is not recoverable from the result directory.

The pty log does contain the runtime sequence:

- baseline completed normally at `/tmp/vng-pty-log.44zp4pp_:532`.
- ReJIT started for 287 tetragon programs at `/tmp/vng-pty-log.44zp4pp_:535`.
- 22 kernel-side refresh failures printed `bpf_rejit: retaining old JIT image after refresh failure` at `/tmp/vng-pty-log.44zp4pp_:536-557`.
- daemon-level ReJIT status was `"error"` at `/tmp/vng-pty-log.44zp4pp_:558`.
- post-ReJIT measurement started at `/tmp/vng-pty-log.44zp4pp_:559`.
- the panic hit `RIP: 0xffffffffc00de6dd` in INT3-filled JIT text at `/tmp/vng-pty-log.44zp4pp_:562-619`.

The faulting kernel path is a return-probe path:

```text
trace_call_bpf
kretprobe_perf_func
kretprobe_dispatcher
kretprobe_rethook_handler
...
inet_create.part.0.constprop.0
__sock_create
__sys_socket
```

That points at Tetragon's generic retkprobe chain. The stack alone identifies the directly attached entry program class as `generic_retkprobe_event`; it does not distinguish the entry program from a tail-called helper because BPF tail calls do not add a kernel stack frame.

## Likely crashing BPF program

The saved artifacts do not contain enough data to map `0xffffffffc00de6dd` to one live program. By elimination, the best candidate is the tail-called retprobe filter helper:

```text
generic_retkprobe_filter_arg
```

Reasoning:

1. The direct kretprobe entry programs are the `generic_retkprobe_event` copies. The helper chain includes `generic_retkprobe_filter_arg`, `generic_retkprobe_actions`, and `generic_retkprobe_output`.
2. Host-side post-fix scans over every `bpfopt/testbin/tetragon_observer/*retkprobe*` snapshot show repeated identical retprobe helper results:

   ```text
   generic_retkprobe_event       9 / 9 applied
   generic_retkprobe_filter_arg 24 / 31 applied, 7 skipped (no dead register)
   generic_retkprobe_actions     2 / 2 applied
   generic_retkprobe_output      0 / 0 applied
   ```

3. The new external/shared-join preserve mode is present in `generic_retkprobe_filter_arg`, not in `generic_retkprobe_event` or `generic_retkprobe_actions`. A static CFG scan of `274_generic_retkprobe_filter_arg/canonicalize_output.bin` finds 10 Pattern C preserve candidates; `273_generic_retkprobe_event` and `276_generic_retkprobe_actions` find zero.
4. The same `generic_retkprobe_filter_arg` bytecode shape appears at testbin IDs `274`, `298`, `354`, `363`, `373`, `384`, `398`, `461`, and `495`. Any of those live copies could be reached by a return-probe policy. The `inet_create` stack is consistent with the `sk_alloc` return probes in the Tetragon policies.

So: the directly attached kretprobe program is likely a `generic_retkprobe_event` copy, but the bad rewritten program is most likely the tail-called `generic_retkprobe_filter_arg` helper.

## The breaking CFG shape

The important shape is Pattern C with a shared join, and sometimes with a shared false branch:

```text
P:
  dst = true_value
  if cond goto J
F:
  dst = false_value
  goto J
J:
  ...

E1/E2/... -> J        # external join predecessors
E3/...     -> F -> J  # sometimes false branch is also shared
```

The current implementation detects sharing in `replace_diamond_with_insns_in_place()`:

- branch sharing is computed at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:488).
- `preserve_join` is forced when any branch or the join is shared at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:495).
- shared branches are not removed at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:509).
- the preserve path replaces the predecessor body and changes its terminator to `Jump -> join` at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:521).

Concrete tetragon example from `274_generic_retkprobe_filter_arg`:

Original bytecode around one new preserve site:

```text
pc 719: r0 = 1
pc 720: if r1 == 0 goto pc 722
pc 721: r0 = 0
pc 722: r0 &= 1
```

Static CFG classification for that site:

```text
Pattern C, start pc 719
predecessor = BlockId(211)
false_branch = BlockId(212)
join = BlockId(213)
false_branch external predecessors = [BlockId(192), BlockId(203), BlockId(210)]
join external predecessors = [BlockId(189), BlockId(191), BlockId(202), BlockId(208), BlockId(209)]
```

Post-fix bytecode around the rewritten site:

```text
pc 723: r0 = 0
pc 724: r2 = 1
pc 725: kinsn sidecar, payload dst=r0, a=r0, b=r2, cond=r1
pc 726: call_kinsn bpf_select64
pc 727: ja pc 729
pc 728: r0 = 0          # preserved shared false branch
pc 729: r0 &= 1         # preserved shared join
```

That is the new preserve-join mode in action: the optimized predecessor bypasses the still-live false branch and jumps to the preserved join; external paths into the false branch still execute the old `r0 = 0`.

## What did not look like the root cause

Block ordering: no evidence of a silent fallthrough adjacency failure. Lowering explicitly rejects non-adjacent fallthroughs and conditional fallthroughs at [bbprogram_lower.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:106) and [bbprogram_lower.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:123). Host-side `bpfopt` produced lowered bytecode for the candidate programs without this error.

Stack state: `cond_select` does not emit stack stores. The relevant builders emit MOV/ALU/JMP plus the kinsn sidecar/call in `condition_prefix()` and `materialize_value()` at [cond_select.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/cond_select.rs:430) and [cond_select.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/cond_select.rs:519).

Plain register liveness: the pass computes `live_after` at [cond_select.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/cond_select.rs:110), and temp selection avoids live-after registers except the selected destination at [cond_select.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/cond_select.rs:547). For the shown Pattern C site, the replacement only changes `r0` on the optimized path; external paths into `F` and `J` are left intact.

The native symptom is still important: landing in mostly `cc` bytes is more consistent with a bad native control-flow target than with a wrong scalar result. The new bytecode shape in `generic_retkprobe_filter_arg` adds `call_kinsn bpf_select64; ja <shared join>` continuations at several formerly skipped sites.

## Concrete implementation defect

The preserve path mutates both the predecessor body and predecessor terminator, but if no block is removed, CFG/use-def data are not rebuilt.

The mutation is here:

- predecessor body replacement at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:527)
- predecessor terminator retarget to `Jump -> join` at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:529)

The only unconditional cleanup call is:

- `self.remove_blocks_in_place(&remove)?` at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:586)

But `remove_blocks_in_place()` returns immediately when `remove` is empty:

- early return at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:590)
- CFG/use-def rebuild only happens after actual removal at [bbprogram_api.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:631)

That is a real invariant violation. `BBProgram::successors()` and `predecessors()` read cached vectors, not terminators directly, at [bbprogram.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:229). After a preserve rewrite with `remove.is_empty()`, later cond_select applications in the same pass can make branch-sharing and join-sharing decisions from stale predecessor/successor lists even though the actual terminator has already changed from `CondBranch` to `Jump`.

This case exists in the retprobe filter helper. Example: the Pattern C site at original pc 719 has a shared false branch, so `true_branch == predecessor`, `false_branch` is preserved, `join` is preserved, and `remove` is empty. The predecessor terminator changes, but cached CFG edges do not.

## Pre-fix comparison

The old external-join guard would not have rewritten these `generic_retkprobe_filter_arg` sites. The 10 preserve candidates in `274_generic_retkprobe_filter_arg` all have external join predecessors; two also have a shared false branch.

Current post-fix host-side result:

```text
274_generic_retkprobe_filter_arg: 24 applied / 31 matched / 7 skipped
skip reason: no dead register available to materialize immediate operand
```

Under the old guard, those 10 external-join Pattern C sites would be left unchanged, so the expected pre-fix count for this helper shape is 14 applied plus the 7 no-dead-register skips. I did not checkout the tree; this comparison comes from the old guard condition documented in `docs/tmp/cond_select_external_predecessor_root_cause_20260512.md` and from the static current-CFG scan.

## Fix direction

Do not add a guard. Fix the preserve algorithm.

Minimum required fix:

1. Treat preserve-join as a full CFG mutation even when no blocks are removed.
2. After replacing the predecessor body/terminator, rebuild cached CFG edges and use-def state unconditionally, or make `remove_blocks_in_place()` rebuild when `remove` is empty but a caller already mutated CFG.
3. Add a regression test for Pattern C where `false_branch` is shared and `remove` is empty; the test should assert that `predecessors(false_branch)` no longer includes the optimized predecessor after rewrite.

Safer algorithmic hardening:

Instead of making the optimized path jump into a shared join, duplicate the join continuation for the optimized path while leaving the original join alive for external paths:

```text
P':
  select replacement
  cloned J body/terminator

F:
  old false mov
  goto original J

external predecessors:
  goto original J
```

This is the old join-hoist idea without deleting the original join. It avoids relying on a shared join to merge an optimized kinsn path with unoptimized external paths and avoids introducing the new `call_kinsn; ja shared_join` continuation shape at formerly skipped sites.

## Verdict

Algorithm fix: make preserve-join a real CFG mutation by unconditionally rebuilding CFG/use-def after predecessor retargeting, and preferably clone/inline the shared join for the optimized path while leaving the original join for external predecessors.
